/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#ifndef KEYBOARDCONTROLLERVIEWCOMPONENTINSTANCE_H
#define KEYBOARDCONTROLLERVIEWCOMPONENTINSTANCE_H

#ifndef TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_KEYBOARDCONTROLLERVIEWCOMPONENTINSTANCE_H
#define TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_KEYBOARDCONTROLLERVIEWCOMPONENTINSTANCE_H

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
