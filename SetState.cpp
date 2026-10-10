#include "SetState.h"
#include <Arduino.h>

String State::getState(){
  return state[stateIndex];
}

void State::changeState(int addition){
  stateIndex = (stateIndex + addition + stateLength) % stateLength;
}
