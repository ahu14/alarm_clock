#ifndef SETSTATE_H
#define SETSTATE_H

#include <Arduino.h>

class State{
  public:
    void changeState(int addition);
    String getState();

  private:
    String state[6] = {"Normal", "Set Alarm", "Set Hour", "Set Minute", "Save", "Snooze"};
    int stateIndex = 0;
    int stateLength = sizeof(state) / sizeof(state[0]);
};

#endif
