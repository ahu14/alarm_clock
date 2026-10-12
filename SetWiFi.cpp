#include "SetWiFi.h"

#include <Wire.h>
#include <WiFi.h>

#include "WiFiConfig.h"

char *ssid = SSID;
char *password = PASSWORD;

void tryToConnect(){
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  Serial.println("WiFi connected.");
}
