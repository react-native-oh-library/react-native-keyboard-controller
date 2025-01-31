/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */
 
#include "keyboardControllerPackage.h"
#include "KeyboardControllerViewJSIBinder.h"
#include "KeyboardGestureAreaJSIBinder.h"


using namespace facebook;
using namespace rnoh;

std::vector<facebook::react::ComponentDescriptorProvider>
KeyboardControllerPackage::createComponentDescriptorProviders() {
    return {facebook::react::concreteComponentDescriptorProvider<
                facebook::react::KeyboardControllerViewComponentDescriptor>(),
            facebook::react::concreteComponentDescriptorProvider<
                facebook::react::KeyboardGestureAreaComponentDescriptor>()};
}
ComponentJSIBinderByString KeyboardControllerPackage::createComponentJSIBinderByName() {
    return {{"RNKeyboardControllerView", std::make_shared<KeyboardControllerViewJSIBinder>()},
            {"RNKeyboardGestureArea", std::make_shared<KeyboardGestureAreaJSIBinder>()}};
}

std::unique_ptr<TurboModuleFactoryDelegate> KeyboardControllerPackage::createTurboModuleFactoryDelegate() {
    return std::make_unique<KeyboardControllerTurboModuleFactoryDelegate>();
}

ComponentInstanceFactoryDelegate::Shared KeyboardControllerPackage::createComponentInstanceFactoryDelegate() {
    return std::make_shared<KeyboardControllerComponentInstanceFactoryDelegate>();
};

ComponentInstance::Shared KeyboardControllerPackage::createComponentInstance(const ComponentInstance::Context &ctx) {
    if (ctx.componentName == "RNKeyboardControllerView") {
        return std::make_shared<KeyboardControllerViewComponentInstance>(ctx);
    }
    if (ctx.componentName == "RNKeyboardGestureArea") {
        return std::make_shared<KeyboardGestureAreaComponentInstance>(ctx);
    }
    return nullptr;
};
