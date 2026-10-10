#include "SetState.h"
#include <Arduino.h>

String State::getState(){
  return state;
}

void State::setState(String newState){
  state = newState;
}

String State::editMode(){
  return "Mode: Set Alarm\nWhat time do you want to edit ? \n 00 : 00 : 00";
}
