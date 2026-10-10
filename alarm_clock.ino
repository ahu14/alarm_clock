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

  /*Serial.print("Last Button State: ");
  Serial.print(lastButtonState);
  Serial.print("\tButton State: ");
  Serial.print(buttonState);
  Serial.print("\tUp State: ");
  Serial.println(upState);*/

  Serial.print(getTimee.printAlarm());
  Serial.print("\t" + getTimee.printTime());
  Serial.println("\t" + getTimee.checkTime());
  
  if (lastButtonState == HIGH && buttonState == LOW){
    state.changeState(1);
    delay(50);
  }
  
  currentTime = millis();
  
  if (currentTime - startTime >= timeTick){
    startTime = millis();
  }

  if (getTimee.checkTime() && getTimee.getAlarm() && state.getState() == "Normal"){
    if (upState == LOW){
      getTimee.disableAlarm();
    }

    else{
      disp.closePrint();
      disp.addPrint("Mode: " + state.getState());
      disp.printDisplay("Wakey wakeyyy");
      disp.show(); 
    }
  }
  
  else if (state.getState() == "Normal" && !getTimee.checkTime()){
    disp.closePrint();
    disp.printDisplay(getTimee.printTime());
    disp.addPrint("Mode: " + state.getState());
    disp.addPrint("Alarm is " + String(getTimee.getAlarm()));
    disp.addPrint("Alarm is set at " +getTimee.printAlarm());
    disp.show(); 
  }

  else if (state.getState() == "Alarm"){
    if (!getTimee.checkTime() && upState == LOW){
      getTimee.disableAlarm();
    }

    disp.closePrint();
    disp.printDisplay(getTimee.printTime());
    disp.addPrint("Mode: " + state.getState());
    disp.addPrint("Alarm is " + String(getTimee.getAlarm()));
    disp.addPrint("Alarm is set at " +getTimee.printAlarm());
    disp.show(); 
  }

  else{
    if (state.getState() == "Set Hour" && upState == LOW){
      getTimee.enableAlarm();
      getTimee.addHour();
      delay(50); 
    }
  
    if (state.getState() == "Set Minute" && upState == LOW){
      getTimee.enableAlarm();
      getTimee.addMinute();
      delay(70);
    }

    disp.closePrint();
    disp.printDisplay("Mode: Set Alarm");
    disp.addPrint(state.getState());
    disp.addPrint(getTimee.printAlarm());
    disp.show();
  }
}
