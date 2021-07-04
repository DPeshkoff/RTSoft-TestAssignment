// Copyright 2021 DPeshkoff;
// Distributed under the GNU General Public License, Version 3.0. (See
// accompanying file LICENSE)

#pragma once

#include <coroutine>
#include <thread>

/// Структура задачи для корутины.
struct task {
    struct promise_type {
        task get_return_object() {
            return {};
        }
        std::suspend_never initial_suspend() {
            return {};
        }
        std::suspend_never final_suspend() noexcept {
            return {};
        }
        void return_void() {}
        void unhandled_exception() {}
    };
};