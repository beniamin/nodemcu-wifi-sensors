#ifndef BrickThermometer_H
#define BrickThermometer_H

#include <Arduino.h>

const uint8_t PRECISION_SCALER = 10;

class BrickThermometer {
  private:
    float i_precisionFactor = 0.5;
    int   i_sensor = 0;

    float readInstantTemp(int sensor);

  public:
    BrickThermometer(int sensor = 0);
    ~BrickThermometer();
    void changeSensor(int sensor);
    void changePrecisionFactor(float pf);
    float readTemperature();
};


#endif
