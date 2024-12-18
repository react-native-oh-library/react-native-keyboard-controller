/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */
 
#ifndef TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_RNSTATUSBARMANAGERCOMPAT_H
#define TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_RNSTATUSBARMANAGERCOMPAT_H

#ifndef RNSTATUSBARMANAGERCOMPAT_H
#define RNSTATUSBARMANAGERCOMPAT_H

#pragma once

#include "RNOH/ArkTSTurboModule.h"

namespace rnoh {

class JSI_EXPORT StatusBarManagerCompat : public ArkTSTurboModule {
  public:
    StatusBarManagerCompat(const ArkTSTurboModule::Context ctx, const std::string name);
};

} // namespace rnoh

#endif

#endif
