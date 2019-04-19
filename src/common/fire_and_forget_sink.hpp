#pragma once

template <typename Implementation>
struct fire_and_forget_sink {
  void ping(int value){
    static_cast<Implementation*>(this)->do_ping(value);
  }

  void do_ping(int value);
};
