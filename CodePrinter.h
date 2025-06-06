#ifndef CODE_PRINTER_H
#define CODE_PRINTER_H

#include <Arduino.h>

class CodePrinter {
  public:
    static void Blink();
    static void DHT();
    static void OLED();
    static void PushButton();
    static void SoilMoisture();
    static void Ultrasonic();
    static void ThingSpeakUpload();
    static void ThingSpeakReader();
};

#endif
