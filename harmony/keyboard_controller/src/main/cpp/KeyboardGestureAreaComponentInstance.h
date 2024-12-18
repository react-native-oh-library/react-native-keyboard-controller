/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#ifndef KEYBOARDGESTUREAREACOMPONENTINSTANCE_H
#define KEYBOARDGESTUREAREACOMPONENTINSTANCE_H

#ifndef TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_KEYBOARDGESTUREAREACOMPONENTINSTANCE_H
#define TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_KEYBOARDGESTUREAREACOMPONENTINSTANCE_H

#include <iostream>
#include <deque>
#include  "RNOH/CppComponentInstance.h"
#include "KeyboardGestureAreaComponentDescriptor.h"
#include "RNOH/arkui/StackNode.h"
#include "RNOH/arkui/ArkUINodeRegistry.h"
namespace rnoh {

class KeyboardGestureAreaComponentInstance
    : public CppComponentInstance<facebook::react::KeyboardGestureAreaShadowNode>,
      public TouchEventHandler {
public:
    KeyboardGestureAreaComponentInstance(Context context);
    ~KeyboardGestureAreaComponentInstance()
    {
        // Clean-up code here
        std::cout << "KeyboardGestureAreaComponentInstance destroyed." << std::endl;
        NativeNodeApi::getInstance()->unregisterNodeEvent(m_stackNode.getArkUINodeHandle(), NODE_TOUCH_EVENT);
        ArkUINodeRegistry::getInstance().unregisterTouchHandler(&m_stackNode);
    }
    void onTouchEvent(ArkUI_UIInputEvent *e) override;
    void onChildInserted(ComponentInstance::Shared const &childComponentInstance, std::size_t index) override;
    void onChildRemoved(ComponentInstance::Shared const &childComponentInstance) override;
    void onPropsChanged(SharedConcreteProps const &props) override;
    void onCommandReceived(std::string const &commandName, folly::dynamic const &args) override;
    ArkUINode &getLocalRootArkUINode() override;
protected:
private:
    bool showOnSwipeUp;
    bool enableSwipeToDismiss;
    std::string interpolator;
    double keyboardHeight;
    size_t maxSize;
    std::deque<folly::dynamic> buffer;
    StackNode m_stackNode;
    struct TouchPoint {
        facebook::react::Float pointerId;
        facebook::react::Float windowX;
        facebook::react::Float windowY;
    };
    folly::dynamic convertNodeTouchPointToDynamic(ArkUI_UIInputEvent *e, int32_t index);
    void swipeToUp();
    void swipeToDismiss();
    void executeInterpolator();
    void handleTouchEvent(ArkUI_UIInputEvent *e);
};
} // namespace rnoh

#endif

#endif
