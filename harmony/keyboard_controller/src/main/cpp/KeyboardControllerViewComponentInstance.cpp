/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#include "KeyboardControllerViewComponentInstance.h"
#include <folly/dynamic.h>
#include <iostream>

namespace rnoh {
using KeyboardControllerStatus = rnoh::KeyboardControllerStatus;
KeyboardControllerViewComponentInstance::KeyboardControllerViewComponentInstance(Context context)
    : CppComponentInstance(std::move(context)), ArkTSMessageHub::Observer(m_deps->arkTSMessageHub) {
    DLOG(INFO) << "KeyboardControllerViewComponentInstance";

    m_customNode.setCustomNodeDelegate(this);
}
void KeyboardControllerViewComponentInstance::onChildInserted(ComponentInstance::Shared const &childComponentInstance,
                                                              std::size_t index) {
    CppComponentInstance::onChildInserted(childComponentInstance, index);
    m_customNode.insertChild(childComponentInstance->getLocalRootArkUINode(), index + 1);
    DLOG(INFO) << "###111" << childComponentInstance->getComponentName();
    findTextInputComponents(childComponentInstance);
}

void KeyboardControllerViewComponentInstance::onChildRemoved(ComponentInstance::Shared const &childComponentInstance) {
    CppComponentInstance::onChildRemoved(childComponentInstance);
    m_customNode.removeChild(childComponentInstance->getLocalRootArkUINode());
}

void KeyboardControllerViewComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
    DLOG(INFO) << "###onPropsChanged" << props->enabled << props->statusBarTranslucent
               << props->navigationBarTranslucent;
    CppComponentInstance::onPropsChanged(props);
    if (this->enabled != props->enabled) {
        this->enabled = props->enabled;
        this->startKeyboardObserver();
    }
    if (this->navigationBarTranslucent != props->navigationBarTranslucent) {
        this->navigationBarTranslucent = props->navigationBarTranslucent;
        this->setWindowSystemBarEnable();
    }
    if (this->statusBarTranslucent != props->statusBarTranslucent) {
        this->statusBarTranslucent = props->statusBarTranslucent;
        this->setWindowSystemBarEnable();
    }
}

void KeyboardControllerViewComponentInstance::onCommandReceived(std::string const &commandName,
                                                                folly::dynamic const &args) {
    CppComponentInstance::onCommandReceived(commandName, args);
}

ArkUINode &KeyboardControllerViewComponentInstance::getLocalRootArkUINode() { return m_customNode; }
void KeyboardControllerViewComponentInstance::onClick() {}
void KeyboardControllerViewComponentInstance::onMessageReceived(ArkTSMessage const &message) {
    DLOG(INFO) << "onMessageReceived";
    if (message.name == "keyboardHeightChange") {
        double height = message.payload.getDouble();
        DLOG(INFO) << "keyboardHeightChange: " << height;
        if (height > 0) {
            this->keyboardStatus = KeyboardControllerStatus::SHOW;
            this->keyboardHeight = height;
        }
        if (height == 0) {
            this->keyboardStatus = KeyboardControllerStatus::HIDE;
        }
        this->keyboardHeightChangeHandle();
    }
    if (message.name == "setFocusTo") {
        // to do
    }
}
void KeyboardControllerViewComponentInstance::setWindowSystemBarEnable() {
    auto rnInstancePtr = this->m_deps->rnInstance.lock();
    if (rnInstancePtr != nullptr) {
        auto turboModule = rnInstancePtr->getTurboModule("KeyboardController");
        auto arkTsTurboModule = std::dynamic_pointer_cast<rnoh::ArkTSTurboModule>(turboModule);
        arkTsTurboModule->callSync("setWindowSystemBarEnable", {this->statusBarTranslucent, this->navigationBarTranslucent});
    }
}

void KeyboardControllerViewComponentInstance::startKeyboardObserver() {
    auto rnInstancePtr = this->m_deps->rnInstance.lock();
    if (rnInstancePtr != nullptr) {
        auto turboModule = rnInstancePtr->getTurboModule("KeyboardController");
        auto arkTsTurboModule = std::dynamic_pointer_cast<rnoh::ArkTSTurboModule>(turboModule);
        arkTsTurboModule->callSync("startKeyboardObserver", {this->enabled});
    }
}

void KeyboardControllerViewComponentInstance::keyboardHeightChangeHandle() {
    auto rnInstancePtr = this->m_deps->rnInstance.lock();
    if (rnInstancePtr != nullptr && this->enabled) {
        if (this->keyboardStatus == KeyboardControllerStatus::HIDE) {
            facebook::react::KeyboardControllerViewEventEmitter::MoveEvent start = {this->keyboardHeight, 0, 0, m_tag};
            facebook::react::KeyboardControllerViewEventEmitter::MoveEvent end = {0, 0, 0, m_tag};
            m_eventEmitter->onKeyboardMoveStart(start);
              m_eventEmitter->onKeyboardMove(end);
            m_eventEmitter->onKeyboardMoveEnd(end);
        } else {
            facebook::react::KeyboardControllerViewEventEmitter::MoveEvent start = {0, 0, 0, m_tag};
            facebook::react::KeyboardControllerViewEventEmitter::MoveEvent end = {this->keyboardHeight, 1, 0, m_tag};
            m_eventEmitter->onKeyboardMoveStart(start);
             m_eventEmitter->onKeyboardMove(end);
            m_eventEmitter->onKeyboardMoveEnd(end);
        }
    }
}

/**
 * 遍历查找TextInput
 * */
void KeyboardControllerViewComponentInstance::findTextInputComponents(
    ComponentInstance::Shared const &childComponentInstance) {
    std::string name = childComponentInstance->getComponentName();
    DLOG(INFO) << "###" << name;
    if (name.find("TextInput") != std::string::npos || name.find("TextArea") != std::string::npos) {
        auto input = std::dynamic_pointer_cast<TextInputComponentInstance>(childComponentInstance);
        ArkUINode &node = input->getLocalRootArkUINode();
        TextInputNode *inputNodePtr = dynamic_cast<TextInputNode *>(&node);
        if (!inputNodePtr) {
            TextAreaNode *textAreaNodePtr = dynamic_cast<TextAreaNode *>(&node);
            textAreaNodePtr->setTextAreaNodeDelegate(this);
        } else {
            inputNodePtr->setTextInputNodeDelegate(this);
        }
        this->textInputVector.push_back(input);
    }
    auto childrenComponentInstances = childComponentInstance->getChildren();
    if (childrenComponentInstances.empty()) {
        return;
    }

    std::vector<ComponentInstance::Shared>::iterator it1;
    for (it1 = childrenComponentInstances.begin(); it1 != childrenComponentInstances.end(); ++it1) {
        ComponentInstance::Shared const &t = *it1;
        findTextInputComponents(t);
    }
}

void KeyboardControllerViewComponentInstance::onChange(std::string text) {
    facebook::react::KeyboardControllerViewEventEmitter::TextChangeEvent event = {text};
    if(this->enabled){
        m_eventEmitter->onFocusedInputTextChanged(event);
     }

}
void KeyboardControllerViewComponentInstance::onTextSelectionChange(int32_t location, int32_t length) {
    DLOG(INFO) << " onKeyboardControllerView onTextSelectionChange";
    // to do
};
void KeyboardControllerViewComponentInstance::onFocus() { DLOG(INFO) << " onKeyboardControllerView onFocus"; }
void KeyboardControllerViewComponentInstance::onBlur() { DLOG(INFO) << " onKeyboardControllerView onBlur"; }


} // namespace rnoh