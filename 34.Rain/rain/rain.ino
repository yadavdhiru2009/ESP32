/*
Author:Dharmendra Kumar Yadavd
*/
// for Arduino Microcontroller

#define rainAnalog 35
#define rainDigital 34

void setup() {
  Serial.begin(9600);
  pinMode(rainDigital,INPUT);
}
void loop() {
  int rainAnalogVal = analogRead(rainAnalog);
  int rainDigitalVal = digitalRead(rainDigital);

  Serial.print(rainAnalogVal);
  Serial.print("\t");
  Serial.println(rainDigitalVal);
  delay(200);
}