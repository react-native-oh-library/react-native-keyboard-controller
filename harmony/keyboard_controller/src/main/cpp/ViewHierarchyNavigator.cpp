/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */
/**
 * MIT License
 *
 * Copyright (C) 2026 Huawei Device Co., Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "ViewHierarchyNavigator.h"
#include <glog/logging.h>
#include <algorithm>

namespace rnoh {
TextInputComponentInstance::Shared ViewHierarchyNavigator::setFocusTo(
    const std::string& direction, ComponentInstance::Shared currentFocus) {
    if (!currentFocus) {
        DLOG(INFO) << "ViewHierarchyNavigator::setFocusTo - currentFocus is null";
        return nullptr;
    }
    DLOG(INFO) << "ViewHierarchyNavigator::setFocusTo direction=" << direction
        << " currentFocus->getTag(): " << currentFocus->getTag();
    auto textInput = findTextInputInDirection(currentFocus, direction);
    if (textInput) {
        DLOG(INFO) << "ViewHierarchyNavigator::setFocusTo - found target input";
    } else {
        DLOG(INFO) << "ViewHierarchyNavigator::setFocusTo - no target input found";
    }
    return textInput;
}

std::vector<TextInputComponentInstance::Shared> ViewHierarchyNavigator::getAllInputFields(
    ComponentInstance::Shared rootComponent) {
    std::vector<TextInputComponentInstance::Shared> textInputs;
    if (!rootComponent) {
        return textInputs;
    }
    // 递归查找所有输入框
    std::function<void(ComponentInstance::Shared)> findTextInputs = 
        [&textInputs, &findTextInputs](ComponentInstance::Shared component) {
            if (!component) return;
            auto textInput = isValidTextInput(component);
            if (textInput) {
                textInputs.push_back(textInput);
            } else {
                // 递归查找子组件
                const auto& children = component->getChildren();
                for (const auto& child : children) {
                    findTextInputs(child);
                }
            }
        };
    findTextInputs(rootComponent);
    return textInputs;
}

TextInputComponentInstance::Shared ViewHierarchyNavigator::findTextInputInDirection(
    ComponentInstance::Shared currentFocus, const std::string& direction) {
    if (!currentFocus) {
        return nullptr;
    }
    DLOG(INFO) << "jjtest currentFocus.name" << currentFocus->getComponentName();
    // 获取父组件
    auto parentComponent = currentFocus->getParent().lock();
    if (!parentComponent) {
        DLOG(INFO) << "jjtest ViewHierarchyNavigator - no parent found";
        return nullptr;
    }
    // 获取父组件的所有子组件
    const auto& siblings = parentComponent->getChildren();
    // 找到当前组件在父组件中的索引
    int currentIndex = -1;
    for (size_t i = 0; i < siblings.size(); ++i) {
        if (siblings[i].get() == currentFocus.get()) {
            currentIndex = static_cast<int>(i);
            break;
        }
    }
    if (currentIndex == -1) {
        DLOG(INFO) << "ViewHierarchyNavigator - current focus not found in parent's children";
        return nullptr;
    }
    DLOG(INFO) << "ViewHierarchyNavigator - currentIndex=" << currentIndex
        << " siblings.size()=" << siblings.size();
    // 根据方向确定遍历范围
    if (direction == "next") {
        // 向后遍历：从 currentIndex+1 到末尾
        for (size_t i = currentIndex + 1; i < siblings.size(); ++i) {
            auto result = findTextInputOrGoDeeper(siblings[i], direction);
            if (result) {
                return result;
            }
        }
    } else {
        // 向前遍历：从 currentIndex-1 到 0（倒序）
        for (int i = currentIndex - 1; i >= 0; --i) {
            auto result = findTextInputOrGoDeeper(siblings[i], direction);
            if (result) {
                return result;
            }
        }
    }
    // 如果同级没找到，递归到父级继续查找
    DLOG(INFO) << "ViewHierarchyNavigator - searching in parent's parent";
    return findTextInputInDirection(parentComponent, direction);
}

TextInputComponentInstance::Shared ViewHierarchyNavigator::findTextInputInHierarchy(
    ComponentInstance::Shared component, const std::string& direction) {
    if (!component) {
        return nullptr;
    }
    const auto& children = component->getChildren();
    if (direction == "next") {
        // 正序遍历
        for (const auto& child : children) {
            auto result = findTextInputOrGoDeeper(child, direction);
            if (result) {
                return result;
            }
        }
    } else {
        // 倒序遍历
        for (auto it = children.rbegin(); it != children.rend(); ++it) {
            auto result = findTextInputOrGoDeeper(*it, direction);
            if (result) {
                return result;
            }
        }
    }
    return nullptr;
}

TextInputComponentInstance::Shared ViewHierarchyNavigator::findTextInputOrGoDeeper(
    ComponentInstance::Shared child, const std::string& direction) {
    if (!child) {
        return nullptr;
    }
    // 首先检查当前组件是否是有效输入框
    auto textInput = isValidTextInput(child);
    if (textInput) {
        return textInput;
    }
    // 如果不是输入框，递归查找其子组件
    return findTextInputInHierarchy(child, direction);
}

TextInputComponentInstance::Shared ViewHierarchyNavigator::isValidTextInput(
    ComponentInstance::Shared component) {
    if (!component) {
        return nullptr;
    }
    // 检查组件名称是否包含 TextInput 或 TextArea
    const std::string& name = component->getComponentName();
    if (name.find("TextInput") != std::string::npos || 
        name.find("TextArea") != std::string::npos) {
        // 尝试转换为 TextInputComponentInstance
        auto textInput = std::dynamic_pointer_cast<TextInputComponentInstance>(component);
        if (textInput) {
            // TODO: 可以在这里添加 enabled 状态检查
            // 类似于 iOS 的 textField.isEnabled 或 textView.isEditable
            DLOG(INFO) << "ViewHierarchyNavigator - found valid TextInput: " << name;
            return textInput;
        }
    }
    return nullptr;
}
} // namespace rnoh
