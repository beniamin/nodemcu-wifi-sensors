#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "Sensors/BrickThermometer.h"

BrickThermometer Thermometer;

void setup() {
  Serial.begin(115200);
  delay(10);

  Thermometer.changePrecisionFactor(0.1);
  Thermometer.changeSensor(PIN_A0);
}

void loop() {
  float temp = Thermometer.readTemperature();
  String serial_out = "Sensor value[";
  serial_out += PIN_A0;
  serial_out += "]: ";
  serial_out += temp;

  Serial.println(serial_out);

  delay(1000);
}
