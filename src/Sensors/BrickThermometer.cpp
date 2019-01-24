#include "BrickThermometer.h"

const int PRECISION_FACTOR_SCALER = 100;

BrickThermometer::BrickThermometer(int sensor) {
  changeSensor(sensor);
}

BrickThermometer::~BrickThermometer() {}

void BrickThermometer::changeSensor(int sensor) {
  i_sensor = sensor;
}

void BrickThermometer::changePrecisionFactor(float pf) {

  if (pf < 0) pf = 0;
  if (pf > 1) pf = 1; 

  i_precisionFactor = (pf < 0) ? 0 : (pf > 1) ? 1 : pf;
}

float BrickThermometer::readTemperature() {
  int samples = (int)(i_precisionFactor * PRECISION_FACTOR_SCALER);

  samples = samples ? samples : 1;
  
  float sum = 0;
  for (int count = 0; count < samples; count++) {
    sum += readInstantTemp(i_sensor);
  }
  
  return -1 * sum / samples;
}

float BrickThermometer::readInstantTemp(int sensor) {
  return (analogRead(sensor) - 500.0) / 10.0;
}
