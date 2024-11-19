/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */
#ifndef KEYBOARDGESTUREAREACOMPONENTINSTANCE_H
#define KEYBOARDGESTUREAREACOMPONENTINSTANCE_H

#ifndef TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_KEYBOARDGESTUREAREACOMPONENTINSTANCE_H
#define TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_KEYBOARDGESTUREAREACOMPONENTINSTANCE_H

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
