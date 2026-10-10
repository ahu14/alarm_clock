#include "SetWiFi.h"

#include <Wire.h>
#include <WiFi.h>

char *ssid = "ikan";
char *password = "ikannn12";

void tryToConnect(){
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  Serial.println("WiFi connected.");
}
