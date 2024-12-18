/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

import {RNPackage,TurboModulesFactory} from  '@rnoh/react-native-openharmony/ts';
import type { TurboModule, TurboModuleContext, } from '@rnoh/react-native-openharmony/ts';
import {RNKeyboardControllerTurboModule} from  './RNKeyboardControllerTurboModule';
import {RNStatusBarManagerCompatTurboModule} from './RNStatusBarManagerCompatTurboModule';

class RNKeyboardControllerTurboModuleFactory extends TurboModulesFactory {
  createTurboModule(name: string): TurboModule | null {
    if (this.hasTurboModule(name)) {
      return new RNKeyboardControllerTurboModule(this.ctx);
    }
    return null;
  }
  hasTurboModule(name: string): boolean {
    return name === 'KeyboardController';
  }

}
class RNStatusBarManagerCompatTurboModuleFactory extends TurboModulesFactory {
  createTurboModule(name: string): TurboModule | null {
    if(this.hasTurboModule(name)){
      return new RNStatusBarManagerCompatTurboModule(this.ctx);
    }
    return null;
  }
  hasTurboModule(name: string): boolean {
    return name === 'StatusBarManagerCompat';
  }
}

export  class  RNKeyboardControllerPackage extends RNPackage {
  createTurboModulesFactory(ctx: TurboModuleContext): TurboModulesFactory {
     return new RNKeyboardControllerTurboModuleFactory(ctx);
  }
}
export  class  RNStatusBarManagerCompatPackage extends RNPackage {
  createTurboModulesFactory(ctx: TurboModuleContext): TurboModulesFactory {
    return new RNStatusBarManagerCompatTurboModuleFactory(ctx);
  }
}
