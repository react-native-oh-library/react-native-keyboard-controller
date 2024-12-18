/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */


#include "RNKeyboardController.h"

namespace rnoh {
using namespace facebook;
KeyboardController::KeyboardController(const ArkTSTurboModule::Context ctx, const std::string name) : ArkTSTurboModule(ctx, name)
{
    methodMap_ = {
        ARK_METHOD_METADATA(getConstants, 0),
        ARK_METHOD_METADATA(setInputMode, 1),
        ARK_METHOD_METADATA(setDefaultMode, 0),
        ARK_METHOD_METADATA(dismiss, 0),
        ARK_METHOD_METADATA(setFocusTo, 1),
        ARK_METHOD_METADATA(addListener, 1),
        ARK_METHOD_METADATA(removeListeners, 1),
    };
}

} // namespace rnoh
