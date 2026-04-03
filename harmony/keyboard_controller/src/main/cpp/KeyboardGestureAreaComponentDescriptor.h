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
