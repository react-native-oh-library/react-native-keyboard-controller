/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

export  enum  KeyboardControllerEventName {
  KEYBOARD_WILL_SHOW="KeyboardController::keyboardWillShow",
  KEYBOARD_DID_SHOW="KeyboardController::keyboardDidShow",
  KEYBOARD_WILL_HIDE="KeyboardController::keyboardWillHide",
  KEYBOARD_DID_HIDE="KeyboardController::keyboardDidHide",
  FOCUS_DID_SET="KeyboardController::focusDidSet"
}
export type KeyboardChangeResult = {
  code:number;
  message:string;
  data:number | undefined
}
export  type KeyboardEvent ={
     height:number;
     duration:number;
    timestamp:number;
    target:number;
}
export  enum KeyboardStatusType {
  HIDE = 0,
  SHOW = 1
};
export  type RawTouchPoint={
  pointerId: number;
  windowX: number;
  windowY: number;
}
export  type RawTouchEvent = {
  action: number;
  actionTouch: RawTouchPoint;
  touchPoints: RawTouchPoint[];
  sourceType: number;
  timestamp: number;
  rootTag:number;
};
