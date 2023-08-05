/*
Autho:r Dharmendra Kumar Yadav
*/

const int joystick_x_pin = A0; 
const int joystick_y_pin = A3;

void setup() {
  Serial.begin(115200);   /* Define baud rate for serial communication */
}

void loop() {
  int x_adc_val, y_adc_val; 
  float x_volt, y_volt;
  x_adc_val = analogRead(joystick_x_pin); 
  y_adc_val = analogRead(joystick_y_pin);
  x_volt = ( ( x_adc_val * 3.3 ) / 4095 );  /*Convert digital value to voltage */
  y_volt = ( ( y_adc_val * 3.3 ) / 4095 );  /*Convert digital value to voltage */
  Serial.print("X_Voltage = ");
  Serial.print(x_volt);
  Serial.print("\t");
  Serial.print("Y_Voltage = ");
  Serial.println(y_volt);
  delay(100);
}

