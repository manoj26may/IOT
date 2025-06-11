#ifndef IOT_H
#define IOT_H

#include <Arduino.h>

class IOT {
  public:
    static void Blink();
    static void DHT();
    static void OLED();
    static void PushButton();
    static void SoilMoisture();
    static void Ultrasonic();
    static void ThingSpeakUpload();
    static void ThingSpeakRead();
};

#endif
