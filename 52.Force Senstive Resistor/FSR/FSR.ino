/*
Author:Dharmendra Kumar Yadav
*/
#define FORCE_SENSOR_PIN 36  // ESP32 pin GIOP36 (ADC0): the FSR and 10K pulldown are connected to A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int analogReading = analogRead(FORCE_SENSOR_PIN);

  Serial.print("The force sensor value = ");
  Serial.print(analogReading);  // print the raw analog reading

  if (analogReading < 100)  // from 0 to 99
    Serial.println(" -> no pressure");
  else if (analogReading < 1500)  // from 100 to 1499
    Serial.println(" -> light touch");
  else if (analogReading < 2500)  // from 1500 to 2499
    Serial.println(" -> light squeeze");
  else if (analogReading < 3500)  // from 2500 to 3499
    Serial.println(" -> medium squeeze");
  else  // from 3500 to 5000
    Serial.println(" -> big squeeze");

  delay(1000);
}