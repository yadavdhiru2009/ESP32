/* 
 *  Author:dharmendra Kumar Yadav
 
 */
#define ldrPin 2
const float gama = 0.7;
const float rl10 = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
  int Value = analogRead(ldrPin);
  Value = map(Value, 4095, 0, 1024, 0); 
  float Voltage = Value / 1024.*5;
  float resistansi = 2000 * Voltage / (1-Voltage/5);
  float Final = pow(rl10*1e3*pow(10,gama)/resistansi,(1/gama));
  Serial.print("Final = ");
  Serial.println(Final);
}
