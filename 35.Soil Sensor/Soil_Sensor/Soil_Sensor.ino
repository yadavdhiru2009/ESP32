/*
Author:Dharmendra KUmar Yadav
*/

int _moisture,sensor_analog;
const int sensor_pin = A0;  /* Soil moisture sensor O/P pin */

void setup(void){
  Serial.begin(115200);     /* Set the baudrate to 115200*/
}

void loop(void){
  sensor_analog = analogRead(sensor_pin);
  _moisture = ( 100 - ( (sensor_analog/4095.00) * 100 ) );
  Serial.print("Moisture = ");
  Serial.print(_moisture);  /* Print Temperature on the serial window */
  Serial.println("%");
  delay(1000);              /* Wait for 1000mS */
}