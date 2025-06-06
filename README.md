# CodePrinter Library

`CodePrinter` is an Arduino library designed to print pre-defined example codes directly to the Serial Monitor. It’s a great tool for beginners, educators, and quick demonstrations.

## Features

- Blink example
- DHT11 sensor example
- OLED display with DHT example
- Button and LED logic example
- Soil moisture sensor example
- Ultrasonic sensor example
- ESP8266 ThingSpeak example (read/write)

## Installation

1. Download the ZIP or clone this repository.
2. In Arduino IDE, go to **Sketch > Include Library > Add .ZIP Library...** and select the ZIP file.
3. Or copy the `CodePrinter` folder to your Arduino `libraries` directory.

## Example Usage

```cpp
#include <IOT.h>

void setup() {
  Serial.begin(9600);
  delay(1000);

  CodePrinter::Blink();  // Call any example
}

void loop() {
}
```

## License

MIT License
