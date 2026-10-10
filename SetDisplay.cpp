#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include "SetDisplay.h"

#define SCL 22
#define SDA 21

void SetDisplay::checkNSetDisplay(){
  Wire.begin(SDA, SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.print(F("SSD1306 allocation failed"));
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.display();
}

void SetDisplay::printDisplay(String msg){
  display.setCursor(0, 0);
  display.println(msg);
}

void SetDisplay::addPrint(String msg){
  display.println(msg);
}

void SetDisplay::closePrint(){
  display.clearDisplay();
}

void SetDisplay::show(){
  display.display();
}
