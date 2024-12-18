/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */


#include "RNStatusBarManagerCompat.h"

namespace rnoh {
using namespace facebook;

StatusBarManagerCompat::StatusBarManagerCompat(const ArkTSTurboModule::Context ctx, const std::string name) : ArkTSTurboModule(ctx, name)
{
    methodMap_ = {
        ARK_METHOD_METADATA(getConstants, 0),
        ARK_METHOD_METADATA(setHidden, 1),
        ARK_METHOD_METADATA(setColor, 2),
        ARK_METHOD_METADATA(setTranslucent, 1),
        ARK_METHOD_METADATA(setStyle, 1),
    };
}

} // namespace rnoh
