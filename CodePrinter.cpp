#include "CodePrinter.h"

void CodePrinter::Blink() {
  Serial.println(F("#define LED_PIN 1"));
  Serial.println(F("void setup() { pinMode(LED_PIN, OUTPUT); }"));
  Serial.println(F("void loop() {"));
  Serial.println(F("  digitalWrite(LED_PIN, HIGH); delay(1000);"));
  Serial.println(F("  digitalWrite(LED_PIN, LOW); delay(2000);"));
  Serial.println(F("}"));
}

void CodePrinter::DHT() {
  Serial.println(F("#include <DHT.h>"));
  Serial.println(F("#define DHTPIN 2"));
  Serial.println(F("#define DHTTYPE DHT11"));
  Serial.println(F("DHT dht(DHTPIN, DHTTYPE);"));
  Serial.println(F("void setup() { Serial.begin(9600); dht.begin(); }"));
  Serial.println(F("void loop() {"));
  Serial.println(F("  float h = dht.readHumidity();"));
  Serial.println(F("  float t = dht.readTemperature();"));
  Serial.println(F("  Serial.print("Humidity: "); Serial.print(h);"));
  Serial.println(F("  Serial.print(" %\tTemperature: "); Serial.print(t); Serial.println(" °C");"));
  Serial.println(F("  delay(2000);"));
  Serial.println(F("}"));
}

void CodePrinter::OLED() {
  Serial.println(F("#include <Wire.h>"));
  Serial.println(F("#include <Adafruit_SSD1306.h>"));
  Serial.println(F("#include <DHT.h>"));
  Serial.println(F("Adafruit_SSD1306 display(128, 64, &Wire, -1);"));
  Serial.println(F("DHT dht(2, DHT11);"));
  Serial.println(F("void setup() {"));
  Serial.println(F("  dht.begin(); Serial.begin(9600);"));
  Serial.println(F("  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);"));
  Serial.println(F("}"));
  Serial.println(F("void loop() {"));
  Serial.println(F("  float temp = dht.readTemperature();"));
  Serial.println(F("  float hum = dht.readHumidity();"));
  Serial.println(F("  display.clearDisplay();"));
  Serial.println(F("  display.setTextSize(1); display.setTextColor(SSD1306_WHITE);"));
  Serial.println(F("  display.setCursor(0, 10);"));
  Serial.println(F("  display.print("Temp: "); display.print(temp); display.println(" C");"));
  Serial.println(F("  display.print("Humidity: "); display.print(hum); display.println(" %");"));
  Serial.println(F("  display.display(); delay(200);"));
  Serial.println(F("}"));
}

void CodePrinter::PushButton() {
  Serial.println(F("#define LED_PIN 1"));
  Serial.println(F("#define BUTTON_PIN 2"));
  Serial.println(F("void setup() {"));
  Serial.println(F("  pinMode(LED_PIN, OUTPUT);"));
  Serial.println(F("  pinMode(BUTTON_PIN, INPUT_PULLUP);"));
  Serial.println(F("}"));
  Serial.println(F("void loop() {"));
  Serial.println(F("  int buttonState = digitalRead(BUTTON_PIN);"));
  Serial.println(F("  if (buttonState == LOW) digitalWrite(LED_PIN, HIGH);"));
  Serial.println(F("  else digitalWrite(LED_PIN, LOW);"));
  Serial.println(F("}"));
}

void CodePrinter::SoilMoisture() {
  Serial.println(F("#define SOIL_PIN A0"));
  Serial.println(F("void setup() { Serial.begin(9600); pinMode(SOIL_PIN, INPUT); }"));
  Serial.println(F("void loop() {"));
  Serial.println(F("  int moisture = analogRead(SOIL_PIN);"));
  Serial.println(F("  Serial.print("Soil Moisture: "); Serial.println(moisture);"));
  Serial.println(F("  if (moisture < 400) Serial.println("Soil is Dry!");"));
  Serial.println(F("  else if (moisture < 700) Serial.println("Soil is Moist!");"));
  Serial.println(F("  else Serial.println("Soil is Wet!");"));
  Serial.println(F("  delay(2000);"));
  Serial.println(F("}"));
}

void CodePrinter::Ultrasonic() {
  Serial.println(F("#define TRIG_PIN 9"));
  Serial.println(F("#define ECHO_PIN 10"));
  Serial.println(F("void setup() {"));
  Serial.println(F("  Serial.begin(9600); pinMode(TRIG_PIN, OUTPUT); pinMode(ECHO_PIN, INPUT);"));
  Serial.println(F("}"));
  Serial.println(F("void loop() {"));
  Serial.println(F("  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);"));
  Serial.println(F("  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);"));
  Serial.println(F("  digitalWrite(TRIG_PIN, LOW);"));
  Serial.println(F("  long duration = pulseIn(ECHO_PIN, HIGH);"));
  Serial.println(F("  float distance = duration * 0.034 / 2;"));
  Serial.println(F("  Serial.print("Distance: "); Serial.print(distance); Serial.println(" cm");"));
  Serial.println(F("  delay(500);"));
  Serial.println(F("}"));
}

void CodePrinter::ThingSpeakUpload() {
  Serial.println(F("#include <ESP8266WiFi.h>"));
  Serial.println(F("#include "DHT.h""));
  Serial.println(F("#include "ThingSpeak.h""));
  Serial.println(F("const char* ssid = "MANOJ 2593";"));
  Serial.println(F("const char* password = "26052004";"));
  Serial.println(F("#define DHTPIN D3"));
  Serial.println(F("#define DHTTYPE DHT11"));
  Serial.println(F("#DHT dht(DHTPIN, DHTTYPE);"));
  Serial.println(F("WiFiClient client;"));
  Serial.println(F("unsigned long myChannelNumber = 2915464;"));
  Serial.println(F("const char* myWriteAPIKey = "2U9S0J7OG7D7TU5Q"; // <-- Replace with your WRITE API Key"));
  Serial.println(F("void setup() { "));
  Serial.println(F("      Serial.begin(115200);"));
  Serial.println(F("      WiFi.begin(ssid, password); "));
  Serial.println(F("      dht.begin();"));
  Serial.println(F("      ThingSpeak.begin(client); "));
  Serial.println(F("      while (WiFi.status() != WL_CONNECTED) { "));
  Serial.println(F("           delay(1000);"));
  Serial.println(F("           Serial.print(".");"));
  Serial.println(F("      }"));
  Serial.println(F("      Serial.println("Connected.");"));
  Serial.println(F("} "));
  Serial.println(F("void loop() {"));
  Serial.println(F("  float h = dht.readHumidity();"));
  Serial.println(F("  float t = dht.readTemperature(); // Celsius"));
  Serial.println(F("  if (isnan(h) || isnan(t)) {"));
  Serial.println(F("     Serial.println("Failed to read from DHT sensor!");"));
  Serial.println(F("     delay(2000);"));
  Serial.println(F("     return;"));
  Serial.println(F("  }"));
  Serial.println(F("  Serial.print("Temp: ");"));
  Serial.println(F("  Serial.print(t);"));
  Serial.println(F("  Serial.print(" °C, Humidity: ");"));
  Serial.println(F("  Serial.print(h);"));
  Serial.println(F("  Serial.println(" %");"));
  Serial.println(F("  ThingSpeak.setField(1, t); // Field 1 - Temperature"));
  Serial.println(F("  ThingSpeak.setField(2, h); // Field 2 - Humidity"));
  Serial.println(F("  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);"));
  Serial.println(F("  if (x == 200) {"));
  Serial.println(F("     Serial.println("Data sent to ThingSpeak successfully");"));
  Serial.println(F("  } else {"));
  Serial.println(F("     Serial.print("Problem sending data. HTTP error code: ");"));
  Serial.println(F("     Serial.println(x);"));
  Serial.println(F("  }"));
  Serial.println(F("  delay(20000);"));
  Serial.println(F("}"));
}

void CodePrinter::ThingSpeakReader() {
  Serial.println(F("#include <ESP8266WiFi.h>"));
  Serial.println(F("#include "DHT.h""));
  Serial.println(F("#include "ThingSpeak.h""));
  Serial.println(F("const char* ssid = "MANOJ 2593";"));
  Serial.println(F("const char* password = "26052004";"));
  Serial.println(F("WiFiClient client;"));
  Serial.println(F("unsigned long myChannelNumber = 2915464;"));
  Serial.println(F("const char* myReadAPIKey = "2U9S0J7OG7D7TU5Q"; // <-- Replace with your READ API Key"));
  Serial.println(F("void setup() { "));
  Serial.println(F("      Serial.begin(115200);"));
  Serial.println(F("      WiFi.begin(ssid, password); "));
  Serial.println(F("      dht.begin();"));
  Serial.println(F("      ThingSpeak.begin(client); "));
  Serial.println(F("      while (WiFi.status() != WL_CONNECTED) { "));
  Serial.println(F("           delay(1000);"));
  Serial.println(F("           Serial.print(".");"));
  Serial.println(F("      }"));
  Serial.println(F("      Serial.println("Connected.");"));
  Serial.println(F("} "));
  Serial.println(F("void loop() {"));
  Serial.println(F("  float h = dht.readHumidity();"));
  Serial.println(F("  float t = dht.readTemperature(); // Celsius"));
  Serial.println(F("  if (isnan(h) || isnan(t)) {"));
  Serial.println(F("     Serial.println("Failed to read from DHT sensor!");"));
  Serial.println(F("     delay(2000);"));
  Serial.println(F("     return;"));
  Serial.println(F("  }"));
  Serial.println(F("  Serial.print("Temp: ");"));
  Serial.println(F("  Serial.print(t);"));
  Serial.println(F("  Serial.print(" °C, Humidity: ");"));
  Serial.println(F("  Serial.print(h);"));
  Serial.println(F("  Serial.println(" %");"));
  Serial.println(F("  ThingSpeak.setField(1, t); // Field 1 - Temperature"));
  Serial.println(F("  ThingSpeak.setField(2, h); // Field 2 - Humidity"));
  Serial.println(F("  int x = ThingSpeak.writeFields(myChannelNumber, myReadAPIKey);"));
  Serial.println(F("  if (x == 200) {"));
  Serial.println(F("     Serial.println("Data sent to ThingSpeak successfully");"));
  Serial.println(F("  } else {"));
  Serial.println(F("     Serial.print("Problem sending data. HTTP error code: ");"));
  Serial.println(F("     Serial.println(x);"));
  Serial.println(F("  }"));
  Serial.println(F("  delay(20000);"));
  Serial.println(F("}"));
}
