/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */
 
#ifndef TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_KEYBOARDGESTUREAREACOMPONENTDESCRIPTOR_H
#define TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_KEYBOARDGESTUREAREACOMPONENTDESCRIPTOR_H

#ifndef KEYBOARDGESTUREAREACOMPONENTDESCRIPTOR_H
#define KEYBOARDGESTUREAREACOMPONENTDESCRIPTOR_H


#pragma once


#include <react/renderer/core/ConcreteComponentDescriptor.h>
#include <react/renderer/components/view/ConcreteViewShadowNode.h>
#include <react/renderer/components/view/ViewShadowNode.h>
#include <react/renderer/core/propsConversions.h>
#include "EventEmitters.h"

namespace facebook {
namespace react {

inline const char KeyboardGestureAreaComponentName[] = "RNKeyboardGestureArea";

class KeyboardGestureAreaProps : public ViewProps {
public:
    bool showOnSwipeUp;
    bool enableSwipeToDismiss;
    std::string interpolator;
    KeyboardGestureAreaProps() = default;

    KeyboardGestureAreaProps(const PropsParserContext &context, const KeyboardGestureAreaProps &sourceProps,
                             const RawProps &rawProps)
        : ViewProps(context, sourceProps, rawProps),
          showOnSwipeUp(CoreFeatures::enablePropIteratorSetter
                            ? sourceProps.showOnSwipeUp
                            : convertRawProp(context, rawProps, "showOnSwipeUp", sourceProps.showOnSwipeUp, {false})),
          enableSwipeToDismiss(CoreFeatures::enablePropIteratorSetter
                                   ? sourceProps.enableSwipeToDismiss
                                   : convertRawProp(context, rawProps, "enableSwipeToDismiss",
                                                    sourceProps.enableSwipeToDismiss, {false})),
          interpolator(CoreFeatures::enablePropIteratorSetter
                           ? sourceProps.interpolator
                           : convertRawProp(context, rawProps, "interpolator", sourceProps.interpolator, {"linear"})) {}
};

using KeyboardGestureAreaShadowNode =
    ConcreteViewShadowNode<KeyboardGestureAreaComponentName, KeyboardGestureAreaProps, ViewEventEmitter>;

class KeyboardGestureAreaComponentDescriptor final : public ConcreteComponentDescriptor<KeyboardGestureAreaShadowNode> {
public:
    KeyboardGestureAreaComponentDescriptor(ComponentDescriptorParameters const &parameters)
        : ConcreteComponentDescriptor(parameters) {}
};

} // namespace react
} // namespace facebook

#endif

#endif
