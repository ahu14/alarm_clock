#ifndef SETSTATE_H
#define SETSTATE_H

#include <Arduino.h>

class State{
  public:
    void changeState(int addition);
    String getState();

  private:
    String state[4] = {"Normal", "Alarm", "Set Hour", "Set Minute"};
    int stateIndex = 0;
    int stateLength = sizeof(state) / sizeof(state[0]);
};

#endif
