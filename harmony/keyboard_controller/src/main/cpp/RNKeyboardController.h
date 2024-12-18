/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */
 
#ifndef TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_RNKEYBOARDCONTROLLER_H
#define TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_RNKEYBOARDCONTROLLER_H

#ifndef RNKEYBOARDCONTROLLER_H
#define RNKEYBOARDCONTROLLER_H
#pragma once

#include "RNOH/ArkTSTurboModule.h"

namespace rnoh {

class JSI_EXPORT KeyboardController : public ArkTSTurboModule {
  public:
    KeyboardController(const ArkTSTurboModule::Context ctx, const std::string name);
};

} // namespace rnoh

#endif

#endif
