#pragma once

#include "../common/fire_and_forget_sink.hpp"
#include <atomic>

struct sync_fire_and_forget_sink: fire_and_forget_sink<sync_fire_and_forget_sink> {
    long long state = 0;

    void do_ping(int value) {
        state += value;
    }
};

struct atomic_fire_and_forget_sink : fire_and_forget_sink<atomic_fire_and_forget_sink> {
    std::atomic<long long> state = 0;

    void do_ping(int value) {
        state += value;
    }
};
