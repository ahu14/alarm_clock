#ifndef SETDISPLAY_H
#define SETDISPLAY_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define WIDTH 128
#define HEIGHT 64

class SetDisplay{
  public:
    void checkNSetDisplay();
    void printDisplay(String msg);
    void addPrint(String msg);
    void closePrint();
    void show();

  private:
    Adafruit_SSD1306 display{WIDTH, HEIGHT, &Wire, -1};
};

#endif
