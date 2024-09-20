/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
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
    return {{"KeyboardControllerView", std::make_shared<KeyboardControllerViewJSIBinder>()},
            {"KeyboardGestureArea", std::make_shared<KeyboardGestureAreaJSIBinder>()}};
}

std::unique_ptr<TurboModuleFactoryDelegate> KeyboardControllerPackage::createTurboModuleFactoryDelegate() {
    return std::make_unique<KeyboardControllerTurboModuleFactoryDelegate>();
}

ComponentInstanceFactoryDelegate::Shared KeyboardControllerPackage::createComponentInstanceFactoryDelegate() {
    return std::make_shared<KeyboardControllerComponentInstanceFactoryDelegate>();
};

ComponentInstance::Shared KeyboardControllerPackage::createComponentInstance(const ComponentInstance::Context &ctx) {
    if (ctx.componentName == "KeyboardControllerView") {
        return std::make_shared<KeyboardControllerViewComponentInstance>(ctx);
    }
    if (ctx.componentName == "KeyboardGestureArea") {
        return std::make_shared<KeyboardGestureAreaComponentInstance>(ctx);
    }
    return nullptr;
};
