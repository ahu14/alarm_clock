#ifndef GETTIME_H
#define GETTIME_H

#include <Arduino.h>
#include <time.h>
#include <iostream>


class GetTime{
  private:
    struct tm alarmTime;
    bool alarmEnabled = false;
    bool snoozeEnabled = false;
    unsigned long snoozeStart = 0;
    const unsigned long SNOOZE_MS = 5 * 60 * 1000UL;

  public:
    GetTime();
    void addHour();
    void addMinute();

    void enableAlarm();
    void disableAlarm();
    bool getAlarm();
    bool checkTime();

    void enableSnooze();
    void disableSnooze();
    bool checkSnooze();
    
    void setTheTime();  
    String printTime();  
    String printAlarm();
};

#endif
