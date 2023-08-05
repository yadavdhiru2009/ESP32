/*
Author :Dharmendra Kumar Yadav
*/
int sensorPin = 18;
int motionState = LOW;
 
void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}
 
void loop() {
  if (digitalRead(sensorPin) == HIGH) {
    if (motionState == LOW) {
     Serial.println("Motion detected!");
      motionState = HIGH;
    }
  }
 
  else {   
    if (motionState == HIGH) {
     Serial.println("Motion ended!");
      motionState = LOW;
    }
  }
}
