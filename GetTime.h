#ifndef GETTIME_H
#define GETTIME_H

#include <Arduino.h>

class GetTime{
  public:
    void setTheTime();  
    String printTime();  

  private:
    int hour = 0;
    int minute = 0;
};

#endif
