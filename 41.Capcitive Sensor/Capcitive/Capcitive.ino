/*
Author:Dharmendra Kumar Yadav
*/
const int SENSOR_OUTPUT_PIN = 16;  /* Capacitive sensor O/P pin */

void setup() {
  pinMode(SENSOR_OUTPUT_PIN, INPUT);
  Serial.begin(9600);             /* Define baud rate for serial communication */
  delay(1000);                    /* Power On Delay */
}

void loop() {
  int sensor_output;
  sensor_output = digitalRead(SENSOR_OUTPUT_PIN);
  if( sensor_output == HIGH)  {
    Serial.print("Object detected\n\n"); 
  }
  delay(100);
}