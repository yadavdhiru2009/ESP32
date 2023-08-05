/*
Author:Dharmendra Kumar yadav
*/
define S2 0 /*Define S2 Pin Number of ESP32*/
#define S3 4 /*Define S3 Pin Number of ESP32*/
#define sensorOut 16 /*Define Sensor Output Pin Number of ESP32*/

/*Define int variables*/
int Red = 0;
int Green = 0;
int Blue = 0;
int Frequency = 0;

void setup() {
  pinMode(S2, OUTPUT); /*Define S2 Pin as a OUTPUT*/
  pinMode(S3, OUTPUT); /*Define S3 Pin as a OUTPUT*/
  pinMode(sensorOut, INPUT); /*Define Sensor Output Pin as a INPUT*/
  Serial.begin(115200); /*Set the baudrate to 115200*/
  Serial.print("This is TCS3200 Calibration Code");
}

void loop() {
  Red = getRed();
  delay(200); /*wait a 200mS*/
  Green = getGreen();
  delay(200); /*wait a 200mS*/
  Blue = getBlue();
  delay(200); /*wait a 200mS*/
  Serial.print("Red Freq = ");
  Serial.print(Red); /*Print Red Color Value on Serial Monitor*/
  Serial.print("   ");
  Serial.print("Green Freq = ");
  Serial.print(Green); /*Print Green Color Value on Serial Monitor*/
  Serial.print("   ");
  Serial.print("Blue Freq = ");
  Serial.println(Blue); /*Print Blue Color Value on Serial Monitor*/
}

int getRed() {
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Frequency = pulseIn(sensorOut, LOW); /*Get the Red Color Frequency*/
  return Frequency;
}

int getGreen() {
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  Frequency = pulseIn(sensorOut, LOW); /*Get the Green Color Frequency*/
  return Frequency;
}

int getBlue() {
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  Frequency = pulseIn(sensorOut, LOW); /*Get the Blue Color Frequency*/
  return Frequency;
}