/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */
 
#ifndef TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_KEYBOARDCONTROLLERVIEWCOMPONENTDESCRIPTOR_H
#define TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_KEYBOARDCONTROLLERVIEWCOMPONENTDESCRIPTOR_H

#ifndef KEYBOARDCONTROLLERVIEWCOMPONENTDESCRIPTOR_H
#define KEYBOARDCONTROLLERVIEWCOMPONENTDESCRIPTOR_H

/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */

/**
 * This code was generated by "react-native codegen-harmony"
 *
 * Do not edit this file as changes may cause incorrect behavior and will be
 * lost once the code is regenerated.
 *
 * @generatorVersion: 1
 */
#pragma once

#include <react/renderer/core/ConcreteComponentDescriptor.h>
#include <react/renderer/components/view/ConcreteViewShadowNode.h>
#include <react/renderer/components/view/ViewShadowNode.h>
#include <react/renderer/core/propsConversions.h>
#include "EventEmitters.h"

namespace facebook {
namespace react {

inline const char KeyboardControllerViewName[] = "RNKeyboardControllerView";

class KeyboardControllerViewProps : public ViewProps {
public:
    bool enabled;
    bool statusBarTranslucent;
    bool navigationBarTranslucent;
    KeyboardControllerViewProps() = default;

    KeyboardControllerViewProps(const PropsParserContext &context, const KeyboardControllerViewProps &sourceProps,
                                const RawProps &rawProps)
        : ViewProps(context, sourceProps, rawProps),
          enabled(CoreFeatures::enablePropIteratorSetter
                      ? sourceProps.enabled
                      : convertRawProp(context, rawProps, "enabled", sourceProps.enabled, {false})),
          statusBarTranslucent(CoreFeatures::enablePropIteratorSetter
                                   ? sourceProps.statusBarTranslucent
                                   : convertRawProp(context, rawProps, "statusBarTranslucent",
                                                    sourceProps.statusBarTranslucent, {false})),
          navigationBarTranslucent(CoreFeatures::enablePropIteratorSetter
                                       ? sourceProps.navigationBarTranslucent
                                       : convertRawProp(context, rawProps, "navigationBarTranslucent",
                                                        sourceProps.navigationBarTranslucent, {false})) {}
};

using KeyboardControllerViewShadowNode =
    ConcreteViewShadowNode<KeyboardControllerViewName, KeyboardControllerViewProps, KeyboardControllerViewEventEmitter>;

class KeyboardControllerViewComponentDescriptor final
    : public ConcreteComponentDescriptor<KeyboardControllerViewShadowNode> {
public:
    KeyboardControllerViewComponentDescriptor(ComponentDescriptorParameters const &parameters)
        : ConcreteComponentDescriptor(parameters) {}
};


} // namespace react
} // namespace facebook

#endif

#endif
