#ifndef SETSTATE_H
#define SETSTATE_H

#include <Arduino.h>

class State{
  public:
    void setState(String newState);
    String editMode();
    String getState();

  private:
    String state = "Normal";
};

#endif
