/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

import { TurboModule } from "@rnoh/react-native-openharmony/ts";
import window from '@ohos.window';
import common from '@ohos.app.ability.common';
import { BusinessError } from '@kit.BasicServicesKit';
import Logger  from './Logger';


interface StatusBarManagerCompatSpec {
  getConstants(): {};
  setHidden(hidden: boolean): void;
  setColor(color: number, animated: boolean): void;
  setTranslucent(translucent: boolean): void;
  setStyle(style: string): void;

}
export  class RNStatusBarManagerCompatTurboModule extends TurboModule implements StatusBarManagerCompatSpec{
  private context: common.UIAbilityContext;
  constructor(ctx) {
    super(ctx);
    this.context = this.ctx.uiAbilityContext;
  }
  private  async  setWindowSystemBarProperties(properties:window.SystemBarProperties){
    let windowInstance: window.Window | undefined = undefined;
    windowInstance = await window.getLastWindow(this.context);
    let systemBarProperty = windowInstance.getWindowSystemBarProperties();
    let newSystemBarProperty: window.SystemBarProperties = {
      ...systemBarProperty,
      ...properties
    };
    try {
      let promise = windowInstance.setWindowSystemBarProperties(newSystemBarProperty);
      promise.then(() => {
        Logger.info('Succeeded in setting the system bar properties.');
      }).catch((err: BusinessError) => {
        Logger.error(`Failed to set the system bar properties. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      Logger.error(`Failed to set the system bar properties. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }
  readonly  getConstants:()=>{};
  // set mode
  async  setHidden(hidden: boolean): Promise<void> {
    Logger.info("###turboModule setHidden");
    let windowInstance: window.Window | undefined = undefined;
    windowInstance = await window.getLastWindow(this.context);
    let names: Array<'status' | 'navigation'> = ['navigation'];
    hidden && names.push('status');
    try {
      let promise = windowInstance.setWindowSystemBarEnable(names);
      promise.then(() => {
        Logger.info('Succeeded in setting the system bar to be invisible.');
      }).catch((err: BusinessError) => {
        Logger.error(`Failed to set the system bar to be invisible. Cause code: ${err.code}, message: ${err.message}`);
      });
    } catch (exception) {
      Logger.error(`Failed to set the system bar to be invisible. Cause code: ${exception.code}, message: ${exception.message}`);
    }
  }

  async  setColor(color: number, animated: boolean): Promise<void> {
    Logger.info("###turboModule setColor");
    let newSystemBarProperty: window.SystemBarProperties = {
      statusBarColor: color.toString(),
      enableStatusBarAnimation:animated
    };
    this.setWindowSystemBarProperties(newSystemBarProperty)
  }

  async  setTranslucent(translucent: boolean): Promise<void> {
    Logger.info("###turboModule setTranslucent");
    let windowInstance: window.Window | undefined = undefined;
    windowInstance = await window.getLastWindow(this.context);
    let systemBarProperty = windowInstance.getWindowSystemBarProperties();
    let newSystemBarProperty: window.SystemBarProperties = {
      statusBarColor:translucent?'#00000000':systemBarProperty.statusBarColor,
    };
    this.setWindowSystemBarProperties(newSystemBarProperty)
  }

  setStyle(style: 'dark-content'|'light-content'): void {
    Logger.info("###turboModule setStyle");
     let themeFlag= style == "dark-content"
    let newSystemBarProperty: window.SystemBarProperties = {
      statusBarContentColor:themeFlag?"#000000":"#ffffff",
    };
    this.setWindowSystemBarProperties(newSystemBarProperty)
  }

}


