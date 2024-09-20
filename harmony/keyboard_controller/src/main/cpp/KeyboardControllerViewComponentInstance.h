/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */
#ifndef KEYBOARDCONTROLLERVIEWCOMPONENTINSTANCE_H
#define KEYBOARDCONTROLLERVIEWCOMPONENTINSTANCE_H

#ifndef TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_KEYBOARDCONTROLLERVIEWCOMPONENTINSTANCE_H
#define TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_KEYBOARDCONTROLLERVIEWCOMPONENTINSTANCE_H

/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */
/**
 * MIT License
 *
 * Copyright (C) 2024 Huawei Device Co., Ltd.
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


#include <any>
#include "RNOH/CppComponentInstance.h"
#include "KeyboardControllerViewComponentDescriptor.h"
#include "RNOHCorePackage/ComponentInstances/TextInputComponentInstance.h"
#include "RNOH/arkui/CustomNode.h"
#include "RNOH/ArkTSMessageHub.h"
#include "RNOH/arkui/TextInputNode.h"
#include "RNOH/arkui/TextAreaNode.h"

namespace rnoh {
enum KeyboardControllerStatus { HIDE = 0, SHOW = 1 };
class KeyboardControllerViewComponentInstance
    : public CppComponentInstance<facebook::react::KeyboardControllerViewShadowNode>,
      public CustomNodeDelegate,
      public TextAreaNodeDelegate,
      public TextInputNodeDelegate,
      public ArkTSMessageHub::Observer {
public:
    KeyboardControllerViewComponentInstance(Context context);
    void onKeyboardMoveStart();
    void onKeyboardMove();
    void onKeyboardMoveEnd();
    void onKeyboardMoveInteractive();
    void onFocusedInputLayoutChanged();
    void onFocusedInputTextChanged();
    void onFocusedInputSelectionChanged();

    void onChildInserted(ComponentInstance::Shared const &childComponentInstance, std::size_t index) override;
    void onChildRemoved(ComponentInstance::Shared const &childComponentInstance) override;
    void onPropsChanged(SharedConcreteProps const &props) override;
    void onCommandReceived(std::string const &commandName, folly::dynamic const &args) override;
    void onMessageReceived(ArkTSMessage const &message) override;
    ArkUINode &getLocalRootArkUINode() override;
    void onClick() override;
    // textArea textInput delegate
    void onChange(std::string text) override;
    void onBlur() override;
    void onFocus() override;
    void onTextSelectionChange(int32_t location, int32_t length) override;

protected:
private:
    bool enabled;
    bool statusBarTranslucent;
    bool navigationBarTranslucent;
    double keyboardHeight;
    std::map<std::string, std::any> dictionary;
    int keyboardStatus;
    std::vector<TextInputComponentInstance::Shared> textInputVector{};
    CustomNode m_customNode{};
    ComponentInstance::Shared currentResponder;
    void findTextInputComponents(ComponentInstance::Shared const &parentComponentInstance);
    void setWindowSystemBarEnable();
    void startKeyboardObserver();
    void closeKeyboardObserver();
    void keyboardHeightChangeHandle();
};
} // namespace rnoh

#endif

#endif
