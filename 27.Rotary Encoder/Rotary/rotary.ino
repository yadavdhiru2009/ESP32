/*
Author Dharmendra Kumar Yadav
*/
#include <ESP32Encoder.h>

#define CLK 22 // CLK ENCODER
#define DT 23 // DT ENCODER

ESP32Encoder encoder;

void setup () {
  encoder.attachHalfQuad(DT, CLK);
  encoder.setCount(0);
  Serial.begin ( 115200 );
}

void loop () {
  long newPosition = encoder.getCount();
  Serial.println(newPosition);
  delay(25);
}
