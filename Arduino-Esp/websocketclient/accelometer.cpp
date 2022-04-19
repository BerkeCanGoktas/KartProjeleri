#include "accelometer.h"

void Accelometer::initialiseSensor(){ 
 /* Initialise the sensor */
 if(!this->accel.begin())
 {
 /* There was a problem detecting the ADXL345 ... check your connections */
 Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
 }
 
 /* Set the range to whatever is appropriate for your project */
 this->accel.setRange(ADXL345_RANGE_16_G);
 // displaySetRange(ADXL345_RANGE_8_G);
 // displaySetRange(ADXL345_RANGE_4_G);
 // displaySetRange(ADXL345_RANGE_2_G);
}

void Accelometer::getNewEvent(){
  this->accel.getEvent(&(this->event));
  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("X: "); Serial.print(this->event.acceleration.x); Serial.print(" ");
  Serial.print("Z: "); Serial.print(this->event.acceleration.z); Serial.print(" ");
  Serial.println("");
  this->x = this->event.acceleration.x;
  this->z = this->event.acceleration.z;
}

double Accelometer::getCurrentX(){
  this->accel.getEvent(&(this->event));
  return this->event.acceleration.x;
}

double Accelometer::getCurrentZ(){
  this->accel.getEvent(&(this->event));
  return this->event.acceleration.z;
}

double Accelometer::calculateSpeed(int state, int initVelocity){
  double firstX = this->getCurrentX();
  double firstZ = this->getCurrentZ();
  delay(800);
  double diffX = firstX - this->getCurrentX();
  double diffZ = firstZ - this->getCurrentZ();
  double calculateAccel = sqrt(pow(diffX, 2) + pow(diffZ, 2));
  double velocity;
  switch(state){
    case 0:
      velocity = initVelocity + calculateAccel/2;
      break;
    case 1:
      velocity = initVelocity - calculateAccel/2;
      break;
    default:
      velocity = -1;
  }
  return velocity;
}

void Accelometer::displaySensorDetails(void)
{
 
 this->accel.getSensor(&(this->sensor));
 Serial.println("------------------------------------");
 Serial.print ("Sensor: "); Serial.println(this->sensor.name);
 Serial.print ("Driver Ver: "); Serial.println(this->sensor.version);
 Serial.print ("Unique ID: "); Serial.println(this->sensor.sensor_id);
 Serial.print ("Max Value: "); Serial.print(this->sensor.max_value); Serial.println(" m/s^2");
 Serial.print ("Min Value: "); Serial.print(this->sensor.min_value); Serial.println(" m/s^2");
 Serial.print ("Resolution: "); Serial.print(this->sensor.resolution); Serial.println(" m/s^2"); 
 Serial.println("------------------------------------");
 Serial.println("");
 delay(500);
}
void Accelometer::displayDataRate(void)
{
 Serial.print ("Data Rate: "); 
 
 switch(this->accel.getDataRate())
 {
 case ADXL345_DATARATE_3200_HZ:
 Serial.print ("3200 "); 
 break;
 case ADXL345_DATARATE_1600_HZ:
 Serial.print ("1600 "); 
 break;
 case ADXL345_DATARATE_800_HZ:
 Serial.print ("800 "); 
 break;
 case ADXL345_DATARATE_400_HZ:
 Serial.print ("400 "); 
 break;
 case ADXL345_DATARATE_200_HZ:
 Serial.print ("200 "); 
 break;
 case ADXL345_DATARATE_100_HZ:
 Serial.print ("100 "); 
 break;
 case ADXL345_DATARATE_50_HZ:
 Serial.print ("50 "); 
 break;
 case ADXL345_DATARATE_25_HZ:
 Serial.print ("25 "); 
 break;
 case ADXL345_DATARATE_12_5_HZ:
 Serial.print ("12.5 "); 
 break;
 case ADXL345_DATARATE_6_25HZ:
 Serial.print ("6.25 "); 
 break;
 case ADXL345_DATARATE_3_13_HZ:
 Serial.print ("3.13 "); 
 break;
 case ADXL345_DATARATE_1_56_HZ:
 Serial.print ("1.56 "); 
 break;
 case ADXL345_DATARATE_0_78_HZ:
 Serial.print ("0.78 "); 
 break;
 case ADXL345_DATARATE_0_39_HZ:
 Serial.print ("0.39 "); 
 break;
 case ADXL345_DATARATE_0_20_HZ:
 Serial.print ("0.20 "); 
 break;
 case ADXL345_DATARATE_0_10_HZ:
 Serial.print ("0.10 "); 
 break;
 default:
 Serial.print ("???? "); 
 break;
 } 
 Serial.println(" Hz"); 
}

void Accelometer::displayRange(void)
{
 Serial.print ("Range: +/- "); 
 
 switch(this->accel.getRange())
 {
 case ADXL345_RANGE_16_G:
 Serial.print ("16 "); 
 break;
 case ADXL345_RANGE_8_G:
 Serial.print ("8 "); 
 break;
 case ADXL345_RANGE_4_G:
 Serial.print ("4 "); 
 break;
 case ADXL345_RANGE_2_G:
 Serial.print ("2 "); 
 break;
 default:
 Serial.print ("?? "); 
 break;
 } 
 Serial.println(" g"); 
}
 
