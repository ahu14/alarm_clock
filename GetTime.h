#ifndef GETTIME_H
#define GETTIME_H

#include <Arduino.h>
#include <time.h>
#include <iostream>


class GetTime{
  private:
    struct tm alarmTime;
    bool alarmEnabled = false;

  public:
    GetTime();
    void addHour();
    void addMinute();

    void enableAlarm();
    void disableAlarm();
    bool getAlarm();
    bool checkTime();
    
    void setTheTime();  
    String printTime();  
    String printAlarm();
};

#endif
