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
