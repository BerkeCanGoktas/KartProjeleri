#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

class Accelometer{

private:
/* Assign a unique ID to this sensor at the same time */
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
sensor_t sensor;
sensors_event_t event; 
double x;
double z;

public: 
void displaySensorDetails(void);
 
void displayDataRate(void);
 
void displayRange(void);

void initialiseSensor();

void getNewEvent();

double getCurrentX();

double getCurrentZ();

double calculateSpeed(int state, int initVelocity);
};
