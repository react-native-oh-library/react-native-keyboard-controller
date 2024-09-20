/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */
#include "KeyboardGestureAreaComponentInstance.h"
#include <folly/dynamic.h>


namespace rnoh {
KeyboardGestureAreaComponentInstance::KeyboardGestureAreaComponentInstance(Context context)
    : CppComponentInstance(std::move(context)) {
    DLOG(INFO) << "KeyboardGestureAreaComponentInstance";
    ArkUINodeRegistry::getInstance().registerTouchHandler(&m_stackNode, this);
    NativeNodeApi::getInstance()->registerNodeEvent(m_stackNode.getArkUINodeHandle(), NODE_TOUCH_EVENT,
                                                    NODE_TOUCH_EVENT, 0);
}
void KeyboardGestureAreaComponentInstance::onTouchEvent(ArkUI_UIInputEvent *e) {
    auto action = OH_ArkUI_UIInputEvent_GetAction(e);
    DLOG(INFO) << "KeyboardGestureAreaComponentInstance onTouchEvent" << action;
    if (action == UI_TOUCH_EVENT_ACTION_DOWN) {
        this->swipeToDismiss();
    }
    if (action == UI_TOUCH_EVENT_ACTION_UP) {
        this->swipeToUp();
    }
}
void KeyboardGestureAreaComponentInstance::onChildInserted(ComponentInstance::Shared const &childComponentInstance,
                                                           std::size_t index) {
    CppComponentInstance::onChildInserted(childComponentInstance, index);
    m_stackNode.insertChild(childComponentInstance->getLocalRootArkUINode(), index + 1);
}

void KeyboardGestureAreaComponentInstance::onChildRemoved(ComponentInstance::Shared const &childComponentInstance) {
    CppComponentInstance::onChildRemoved(childComponentInstance);
    m_stackNode.removeChild(childComponentInstance->getLocalRootArkUINode());
}
ArkUINode &KeyboardGestureAreaComponentInstance::getLocalRootArkUINode() { return m_stackNode; }
void KeyboardGestureAreaComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
    DLOG(INFO) << "###onPropsChanged";
    CppComponentInstance::onPropsChanged(props);
    this->showOnSwipeUp = props->showOnSwipeUp;
    this->enableSwipeToDismiss = props->enableSwipeToDismiss;
    this->interpolator = props->interpolator;
}

void KeyboardGestureAreaComponentInstance::onCommandReceived(std::string const &commandName,
                                                             folly::dynamic const &args) {
    CppComponentInstance::onCommandReceived(commandName, args);
}

void KeyboardGestureAreaComponentInstance::handleTouchEvent(ArkUI_UIInputEvent *e) {
    auto action = OH_ArkUI_UIInputEvent_GetAction(e);
    if (action == UI_TOUCH_EVENT_ACTION_DOWN) {
        this->swipeToDismiss();
    }
    if (action == UI_TOUCH_EVENT_ACTION_UP) {
        this->swipeToUp();
    }
}
void KeyboardGestureAreaComponentInstance::swipeToDismiss() {
    if (!this->enableSwipeToDismiss) {
        return;
    }
    auto rnInstancePtr = this->m_deps->rnInstance.lock();
    if (rnInstancePtr != nullptr) {
        auto turboModule = rnInstancePtr->getTurboModule("KeyboardController");
        auto arkTsTurboModule = std::dynamic_pointer_cast<rnoh::ArkTSTurboModule>(turboModule);
        arkTsTurboModule->callSync("dismiss", {});
    }
}
void KeyboardGestureAreaComponentInstance::swipeToUp() {
    if (!this->showOnSwipeUp) {
        return;
    }
    auto rnInstancePtr = this->m_deps->rnInstance.lock();
    if (rnInstancePtr != nullptr) {
        auto turboModule = rnInstancePtr->getTurboModule("KeyboardController");
        auto arkTsTurboModule = std::dynamic_pointer_cast<rnoh::ArkTSTurboModule>(turboModule);
        arkTsTurboModule->callSync("show", {});
    }
}
void KeyboardGestureAreaComponentInstance::executeInterpolator() {
    // to do
}

} // namespace rnoh
// namespace rnoh