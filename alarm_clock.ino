#include <WiFi.h>
#include "time.h"

#include "GetTime.h"
#include "SetWiFi.h"
#include "SetDisplay.h"
#include "SetState.h"

#define MODE 19
#define UP 23
#define ALARM 5

GetTime getTimee;
SetDisplay disp;
State state;

int lastButtonState;
int buttonState;

int lastUpState;
int upState;

int startTime;
int currentTime;
int timeTick = 1000;
unsigned long lastBeep = 0;

void setup(){
  Serial.begin(115200);
  startTime = millis();
  
  pinMode(MODE, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(ALARM, OUTPUT);
  
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
  lastUpState = upState;
  
  buttonState = digitalRead(MODE);
  upState = digitalRead(UP);
  

  if (lastButtonState == HIGH && buttonState == LOW){
    if (getTimee.checkTime() && getTimee.getAlarm()){
      getTimee.disableAlarm();
      getTimee.disableSnooze();
      noTone(ALARM);
    }
    
    else{
      state.changeState(1);
    }
    
    delay(50);
  }

  if (lastUpState == HIGH && upState == LOW){
    if (getTimee.checkTime() && getTimee.getAlarm() && state.getState() == "Normal"){
      getTimee.enableSnooze();
    }
  }
  
  currentTime = millis();
  
  if (currentTime - startTime >= timeTick){
    startTime = millis();
  }

  if (getTimee.checkTime() && getTimee.getAlarm() && state.getState() == "Normal"){
    disp.closePrint();
    disp.printDisplay("Mode: " + state.getState());
    disp.addPrint("Wakey wakeyyy");

    if (getTimee.getSnooze()){
      disp.addPrint(" 5 minutes pass already");
    }
    
    disp.show(); 

    if (millis() - lastBeep >= 600){
      lastBeep = millis();
      tone(ALARM, 500, 200);
    }
  }
  
  else if (state.getState() == "Normal" && !getTimee.checkTime()){
    disp.closePrint();
    disp.printDisplay(getTimee.printTime());
    disp.addPrint("Mode: " + state.getState());

    if (getTimee.getAlarm()){
      disp.addPrint("Alarm is on");
    }

    else{
      disp.addPrint("Alarm is off");  
    }
    
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

    if (getTimee.getAlarm()){
      disp.addPrint("Alarm is on");
    }

    else{
      disp.addPrint("Alarm is off");  
    }
    
    disp.addPrint("Alarm is set at " +getTimee.printAlarm());
    disp.show(); 
  }

  else{
    if (state.getState() == "Set Hour" && upState == LOW){
      getTimee.enableAlarm();
      getTimee.disableSnooze();
      getTimee.addHour();
      delay(70); 
    }
  
    if (state.getState() == "Set Minute" && upState == LOW){
      getTimee.enableAlarm();
      getTimee.disableSnooze();
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
