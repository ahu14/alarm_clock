#include <iostream>
#include "GetTime.h"
#include <time.h>

char *ntp_server = "pool.ntp.org";
long gmtOffset_sec = 28800;
int daylightOffset_sec = 0;

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
