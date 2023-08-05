/*
Author:Dharmendra Kumar Yadav
*/
#include <QMC5883LCompass.h>
 
QMC5883LCompass compass;
 
int calibrationData[3][2];
bool changed = false;
bool done = false;
int t = 0;
int c = 0;
 
bool calibrated = false;
 
void setup() {
  Serial.begin(9600);
  // Initialize device with i2c 0x0D address
  compass.init();
}
 
void loop() {
    if (!calibrated){
        // If not calibrated
      int x, y, z;
 
      // Read compass values
      compass.read();
 
      // Return XYZ readings
      x = compass.getX();
      y = compass.getY();
      z = compass.getZ();
 
      changed = false;
 
      if(x < calibrationData[0][0]) {
        calibrationData[0][0] = x;
        changed = true;
      }
      if(x > calibrationData[0][1]) {
        calibrationData[0][1] = x;
        changed = true;
      }
 
      if(y < calibrationData[1][0]) {
        calibrationData[1][0] = y;
        changed = true;
      }
      if(y > calibrationData[1][1]) {
        calibrationData[1][1] = y;
        changed = true;
      }
 
      if(z < calibrationData[2][0]) {
        calibrationData[2][0] = z;
        changed = true;
      }
      if(z > calibrationData[2][1]) {
        calibrationData[2][1] = z;
        changed = true;
      }
 
      if (changed && !done) {
        Serial.println("CALIBRATING... Keep moving your sensor around.");
        c = millis();
      }
        t = millis();
 
 
      if ( (t - c > 5000) && !done) {
        done = true;
        Serial.println("DONE.");
        Serial.println();
 
        Serial.print("compass.setCalibration(");
        Serial.print(calibrationData[0][0]);
        Serial.print(", ");
        Serial.print(calibrationData[0][1]);
        Serial.print(", ");
        Serial.print(calibrationData[1][0]);
        Serial.print(", ");
        Serial.print(calibrationData[1][1]);
        Serial.print(", ");
        Serial.print(calibrationData[2][0]);
        Serial.print(", ");
        Serial.print(calibrationData[2][1]);
        Serial.println(");");
 
        compass.setCalibration( calibrationData[0][0], calibrationData[0][1], calibrationData[1][0],
                                calibrationData[1][1], calibrationData[2][0], calibrationData[2][1]);
        calibrated = true;
        }
    }else{
        // If calibrating
          int x, y, z;
 
          // Read compass values
          compass.read();
 
          // Return XYZ readings
          x = compass.getX();
          y = compass.getY();
          z = compass.getZ();
 
          int azimut = compass.getAzimuth();
 
          float bearing = compass.getBearing(azimut);
 
          Serial.println();
 
          // Write direction
          if((azimut < 22.5)  || (azimut > 337.5 ))  Serial.print("North     ");
          if((azimut > 22.5)  && (azimut < 67.5 ))   Serial.print("North-East");
          if((azimut > 67.5)  && (azimut < 112.5 ))  Serial.print("East      ");
          if((azimut > 112.5) && (azimut < 157.5 ))  Serial.print("South-East");
          if((azimut > 157.5) && (azimut < 202.5 ))  Serial.print("South     ");
          if((azimut > 202.5) && (azimut < 247.5 ))  Serial.print("SOuth-West");
          if((azimut > 247.5) && (azimut < 292.5 ))  Serial.print("West      ");
          if((azimut > 292.5) && (azimut < 337.5 ))  Serial.print("North-West");
 
          Serial.print(" Azimuth: ");Serial.print(azimut);
          Serial.print(" Bearing: ");Serial.print(bearing);
 
          Serial.print(" - X: ");
          Serial.print(x);
          Serial.print(" Y: ");
          Serial.print(y);
          Serial.print(" Z: ");
          Serial.print(z);
 
          delay(250);
    }
}