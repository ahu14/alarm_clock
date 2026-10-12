#include <iostream>
#include "GetTime.h"
#include <time.h>

char *ntp_server = "pool.ntp.org";
long gmtOffset_sec = 28800;
int daylightOffset_sec = 0;

GetTime::GetTime(){
  alarmTime.tm_hour = 0;
  alarmTime.tm_min = 0;
  alarmTime.tm_sec = 0;
}

void GetTime::addHour(){
  alarmTime.tm_hour = alarmTime.tm_hour >= 23 ? 0 : alarmTime.tm_hour + 1;
}

void GetTime::addMinute(){
  if (alarmTime.tm_min >= 59){
    alarmTime.tm_min = 0;
    addHour();
  }

  else{
    alarmTime.tm_min += 1; 
  }
}

void GetTime::enableAlarm(){
  alarmEnabled = true;
}

void GetTime::disableAlarm(){
  alarmEnabled = false;
}

bool GetTime::getAlarm(){
  return alarmEnabled;
}

void GetTime::enableSnooze(){
  snoozeEnabled = true;

  if (alarmTime.tm_min >= 55){
    alarmTime.tm_min = alarmTime.tm_min + 5 - 60;
    alarmTime.tm_hour = alarmTime.tm_hour >= 23 ? 0 : alarmTime.tm_hour + 1;
  }

  else{
    alarmTime.tm_min += 5; 
  }
}

void GetTime::disableSnooze(){
  snoozeEnabled = false;
}

bool GetTime::getSnooze(){
  return snoozeEnabled;
}


bool GetTime::checkTime(){
  struct tm timeinfo;
  getLocalTime(&timeinfo);

  return (alarmEnabled && timeinfo.tm_hour == alarmTime.tm_hour && timeinfo.tm_min == alarmTime.tm_min);
}


void GetTime::setTheTime(){
  configTime(gmtOffset_sec, daylightOffset_sec, ntp_server);
}

String GetTime::printTime() {
  struct tm timeinfo;
  
  if (!getLocalTime(&timeinfo)){
    return "Failed to obtain time";
  }

  char buffer[64];
  strftime(buffer, sizeof(buffer), "%A, %d %B %Y %H:%M:%S", &timeinfo);

  return String(buffer);
}

String GetTime::printAlarm(){
  char buffer[64];
  strftime(buffer, sizeof(buffer), "%H:%M", &alarmTime);
  return String(buffer);
}
