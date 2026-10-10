#include <WiFi.h>
#include "time.h"

#include "GetTime.h"
#include "SetWiFi.h"
#include "SetDisplay.h"
#include "SetState.h"

#define MODE 19
#define UP 23

GetTime getTimee;
SetDisplay disp;
State state;

int lastButtonState;
int buttonState;
int upState;

int startTime;
int currentTime;
int timeTick = 1000;

void setup(){
  Serial.begin(115200);
  startTime = millis();
  
  pinMode(MODE, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  
  tryToConnect();
  disp.checkNSetDisplay();
  getTimee.setTheTime();

  buttonState = digitalRead(MODE);
  currentTime = millis();

  disp.closePrint();
  if (currentTime - startTime >= timeTick){
    startTime = millis();
    disp.printDisplay(getTimee.printTime());
  }
  
  disp.addPrint(state.getState());
  disp.show();
}

void loop(){
  lastButtonState = buttonState;
  buttonState = digitalRead(MODE);
  upState = digitalRead(UP);

  Serial.print("Last Button State: ");
  Serial.print(lastButtonState);
  Serial.print("\Button State: ");
  Serial.println(buttonState);

  if (lastButtonState == HIGH && buttonState == LOW){
    state.setState(state.getState() == "Normal" ? "Set Alarm" : "Normal");
    delay(50);
  }
  
  currentTime = millis();
  
  if (state.getState() != "Set Alarm" && (currentTime - startTime >= timeTick || true)){
    startTime = millis();

    disp.closePrint();
    disp.printDisplay(getTimee.printTime());
    disp.addPrint("Mode: " + state.getState());
    disp.show();
  }

  if (state.getState() == "Set Alarm"){
    disp.closePrint();
    disp.printDisplay(state.editMode());
    disp.show();
  }

  if (state.getState() == "Set Alarm" && upState == LOW){
    Serial.println("UP UP UP");
  }
}
