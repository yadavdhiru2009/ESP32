/*
Author:Dharmendra Kumar Yadav
*/
#define analog_pin 0
float sensor_value;  

void setup() {
  Serial.begin(115200); 
  Serial.println("MQ3 is warming up");
  delay(120000);  //2 min warm up time
}

void loop() {
  sensor_value = analogRead(analog_pin); 
  Serial.print("Sensor Value: ");
  Serial.println(sensor_value);
  delay(2000); 
}