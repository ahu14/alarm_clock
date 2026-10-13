# Alarm Clock

Alarm Clock that is made by using ESP32 DevKit v1 as the brain, one OLED 0.96 inch as the screen, and two buttons for its functionalities.
The two button functionality:
1. Blue button for [Change mode]
2. White button for [Add time or cancel alarm]


## Alarm explanation and usage
* There's four modes inside this alarm clock: Normal, Set Alarm, Set Hour and Set Minute
  * For normal, the OLED will display the time, is there any alarm that is being set, and show what time does the alarm is being set (if there's not any alarm set, default will be 00:00)
  * For set alarm, the OLED will display like the normal one with cancel the alarm feature by clicking the white button
  * For set hour, the OLED will display 00:00 to let user edit the hour part (using the 24 hour format)
  * For set minute, the OLED will display like the set hour one but let user edit the minute instead of hour (added 1 hour automatically if user clicked passed 59 minute and reset to 0 minute)
* To use the alarm, user need to set the hour and minute to the desired time and wait for it to ring at the exact desired time
* After the alarm rings, the user can either snooze the alarm (by clicking the white button) or close the alarm (by clicking the blue button)
  * If the user snooze the alarm, the alarm will stop and will ring again 5 minutes later
  * If the user close the alarm, the alarm will stop and will not ring anymore until user set the new alarm time


## How to run this project
* git clone https://github.com/ahu14/alarm_clock.git
* Edit the WiFiConfig.h file and set the your own ssid and password
* Open the project on Arduino
* Download all the necessary libraries like Adafruit SSD1306 and Adafruit GFX Library
* Do all the wiring and stuff


## How do I make the wiring
* Coming soon


## Showcase
* Coming soon
