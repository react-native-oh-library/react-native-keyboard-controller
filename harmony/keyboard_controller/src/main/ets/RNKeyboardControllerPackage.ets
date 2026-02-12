/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

import {TurboModulesFactory} from  '@rnoh/react-native-openharmony/ts';
import type { TurboModule, TurboModuleContext, } from '@rnoh/react-native-openharmony/ts';
import {RNKeyboardControllerTurboModule} from  './RNKeyboardControllerTurboModule';
import {RNStatusBarManagerCompatTurboModule} from './RNStatusBarManagerCompatTurboModule';
import { RNOHPackage } from '@rnoh/react-native-openharmony'

class RNKeyboardControllerTurboModuleFactory extends TurboModulesFactory {
  createTurboModule(name: string): TurboModule | null {
    if (name === 'KeyboardController') {
      return new RNKeyboardControllerTurboModule(this.ctx);
    } else if (name === 'StatusBarManagerCompat') {
      return new RNStatusBarManagerCompatTurboModule(this.ctx);
    }
    return null;
  }
  
  hasTurboModule(name: string): boolean {
    return name === 'KeyboardController' || name === 'StatusBarManagerCompat';
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

export  class  RNKeyboardControllerPackage extends RNOHPackage {
  createTurboModulesFactory(ctx: TurboModuleContext): TurboModulesFactory {
     return new RNKeyboardControllerTurboModuleFactory(ctx);
  }
}
export  class  RNStatusBarManagerCompatPackage extends RNOHPackage {
  createTurboModulesFactory(ctx: TurboModuleContext): TurboModulesFactory {
    return new RNStatusBarManagerCompatTurboModuleFactory(ctx);
  }
}
