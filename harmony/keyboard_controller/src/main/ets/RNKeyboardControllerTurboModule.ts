import { TurboModule } from "@rnoh/react-native-openharmony/ts";
import common from '@ohos.app.ability.common';
import window from '@ohos.window';
import inputMethod from '@ohos.inputMethod';
import Logger from './Logger';
import { KeyboardControllerEventName, KeyboardStatusType } from './Type';
import { BusinessError } from '@kit.BasicServicesKit';
import { JSON } from '@kit.ArkTS';

declare function px2vp(px: number): number;

interface RNKeyboardControllerSpec {
  getConstants(): {};

  setInputMode(mode: number): void;

  setDefaultMode(): void;

  dismiss(): void;

  setFocusTo(direction: string): void;

  addListener(eventName: string, listener: (event) => void,): void;

  removeListeners(count: number): void;
}

export class RNKeyboardControllerTurboModule extends TurboModule implements RNKeyboardControllerSpec {
  private context: common.UIAbilityContext;
  private keyboardHeight: number;
  private keyboardStatus: KeyboardStatusType;
  private eventListeners: KeyboardControllerEventName[];
  private currentWindow:window.Window;
  private enabled:boolean;
  constructor(ctx) {
    super(ctx);
    this.context = this.ctx.uiAbilityContext;
    this.eventListeners = this.supportListeners();
  }

  readonly getConstants: () => {};

  // set mode
  setInputMode(mode: number): void {
    Logger.info('harmonyOS not support setInputMode')
  }

  setDefaultMode(): void {
    Logger.info('harmonyOS not support setDefaultMode')
  }

  /**
   * @description 键盘隐藏
   * */
  dismiss(): void {
    let inputMethodController = inputMethod.getController();
    inputMethodController.stopInputSession()

  }
  /**
   * @description 键盘隐藏
   * */
  private  show(): void {
    let inputMethodController = inputMethod.getController();
    inputMethodController.showSoftKeyboard()

  }

  setFocusTo(direction: string): void {
    this.ctx.rnInstance.postMessageToCpp('setFocusTo', direction);
  }

  /**
   * @description 添加监听键盘事件
   */
  addListener(eventName: KeyboardControllerEventName) {
    let supportEvents = this.supportListeners()
    let bo = supportEvents.includes(eventName)
    if (bo && !this.eventListeners.includes(eventName)) {
      this.eventListeners.push(eventName)
    }
  }

  /**
   * @description 删除监听事件
   * */
  removeListeners(count: number): void {
    let num = this.eventListeners.length;
    if (num>0) {
      this.eventListeners = [];
    }
  }

  private supportListeners() {
    return [
      KeyboardControllerEventName.KEYBOARD_WILL_SHOW,
      KeyboardControllerEventName.KEYBOARD_DID_SHOW,
      KeyboardControllerEventName.KEYBOARD_WILL_HIDE,
      KeyboardControllerEventName.KEYBOARD_DID_HIDE,
      KeyboardControllerEventName.FOCUS_DID_SET
    ];
  }

  private async setWindowSystemBarEnable(statusBarTranslucent: boolean, navigationBarTranslucent: boolean) {

    let windowInstance: window.Window | undefined = undefined;
    windowInstance = await window.getLastWindow(this.context);
    let systemBarProperty = windowInstance.getWindowSystemBarProperties();
    let newSystemBarProperty: window.SystemBarProperties = {
      ...systemBarProperty,
      statusBarColor: statusBarTranslucent ? "#00000000" : systemBarProperty.statusBarColor,
      navigationBarColor: navigationBarTranslucent ? "#00000000" : systemBarProperty.navigationBarColor
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

  private keyboardControllerEventHandle(keyboardStatus: number, height: number) {
    Logger.info('###turboModule keyboardControllerEventHandle', String(keyboardStatus) + ',' + String(height));
    if(!this.enabled){
      return
    }

    if (this.keyboardStatus == KeyboardStatusType.HIDE) {
      // 键盘隐藏
      Logger.info('###turboModule keyboardControllerEventHandle');
      this.eventListeners.includes(KeyboardControllerEventName.KEYBOARD_DID_HIDE) &&
      this.ctx.rnInstance.emitDeviceEvent(KeyboardControllerEventName.KEYBOARD_DID_HIDE, {
        duration: 0,
        timestamp: new Date().getTime(),
        target: 0,
        height: height,
        tag:0
      });
    }
    if (this.keyboardStatus == KeyboardStatusType.SHOW) {
      // 键盘显示
      Logger.info('###turboModule keyboardControllerEventHandle');
      this.eventListeners.includes(KeyboardControllerEventName.KEYBOARD_DID_SHOW) &&
      this.ctx.rnInstance.emitDeviceEvent(KeyboardControllerEventName.KEYBOARD_DID_SHOW, {
        duration: 0,
        timestamp: new Date().getTime(),
        target: 0,
        height:height,
        tag:0
      });
    }
  }

  private async startKeyboardObserver(open:boolean) {
    Logger.info("###turboModule startKeyboardObserver",String(open));
    this.enabled=open;
    this.currentWindow = await window.getLastWindow(this.context);
    if (!this.currentWindow) {
      throw ('windowInstance is null')
      return
    }
    if(!open){
      try {
        Logger.info("###turboModule Close KeyboardObserver");
        this.currentWindow.off('keyboardHeightChange', (data) => {
          this.keyboardStatus = KeyboardStatusType.HIDE;
          this.keyboardHeight = 0;
          Logger.info('### close keyboardHeightChange observer');
        });
      } catch (exception) {
        Logger.error('### Failed to close the listener for keyboard height changes. Cause: ' + JSON.stringify(exception));
      }
    }else{
      try {
        this.currentWindow.on('keyboardHeightChange', (data) => {
          const keyboardAvoidArea = this.currentWindow?.getWindowAvoidArea(window.AvoidAreaType.TYPE_KEYBOARD).bottomRect;
          let height = Math.ceil(px2vp(keyboardAvoidArea.height))
          if(open){
            if(this.keyboardHeight == height ){
              return
            }
            if (height > 0) {
              this.keyboardStatus = KeyboardStatusType.SHOW;
            } else {
              this.keyboardStatus = KeyboardStatusType.HIDE;
            }
            this.keyboardHeight = height;
            this.keyboardControllerEventHandle(this.keyboardStatus, height);
            this.ctx.rnInstance.postMessageToCpp('keyboardHeightChange', height);
          }

        });
      } catch (exception) {
        Logger.error('Failed to enable the listener for keyboard height changes. Cause: ' + JSON.stringify(exception));
      }
    }

  }

}
