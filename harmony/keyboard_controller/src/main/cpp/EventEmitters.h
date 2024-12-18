/*
 * Copyright (c) 2024 Huawei Device Co., Ltd. All rights reserved
 * Use of this source code is governed by a MIT license that can be
 * found in the LICENSE file.
 */

#ifndef TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_EVENTEMITTERS_H
#define TESTER_HARMONY_KEYBOARD_CONTROLLER_SRC_MAIN_CPP_EVENTEMITTERS_H

#ifndef EVENTEMITTERS_H
#define EVENTEMITTERS_H

#pragma once
#include <react/renderer/components/view/ViewEventEmitter.h>
#include <react/renderer/core/EventEmitter.h>
#include <jsi/jsi.h>

namespace facebook {
namespace react {
class JSI_EXPORT KeyboardController : public EventEmitter {
public:
    using EventEmitter::EventEmitter;
    struct KeyboardEvent {
        double height;
        float duration;
        double timestamp;
        int target;
    };
    void keyboardWillShow(KeyboardEvent value) const;
    void keyboardDidShow(KeyboardEvent value) const;
    void keyboardWillHide(KeyboardEvent value) const;
    void keyboardDidHide(KeyboardEvent value) const;
    void focusDidSet(KeyboardEvent value) const;
};
class JSI_EXPORT KeyboardControllerViewEventEmitter : public ViewEventEmitter {
public:
    using ViewEventEmitter::ViewEventEmitter;

    struct MoveEvent {
        double height;
        double progress;
        float duration;
        int target;
    };

    struct InputLayoutEvent {
        int parentScrollViewTarget;
        int target;
        struct layout {
            double absoluteX;
            double absoluteY;
            double x;
            double y;
            double width;
            double height;
        };
    };
    struct TextChangeEvent {
        std::string text;
    };
    struct InputSectionEvent {
        int target;
        struct selection {
            struct start {
                double x;
                double y;
                int position;
            };
            struct end {
                double x;
                double y;
                int position;
            };
        };
    };

    void onKeyboardMoveStart(MoveEvent value) const;
    void onKeyboardMove(MoveEvent value) const;
    void onKeyboardMoveEnd(MoveEvent value) const;
    void onKeyboardMoveInteractive(MoveEvent value) const;
    void onFocusedInputLayoutChanged(InputLayoutEvent value) const;
    void onFocusedInputTextChanged(TextChangeEvent value) const;
    void onFocusedInputSelectionChanged(InputSectionEvent value) const;
};
} // namespace react
} // namespace facebook

#endif

#endif
