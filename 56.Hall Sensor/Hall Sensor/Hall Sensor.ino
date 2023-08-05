int hall_sensor_value = 0;
void setup()

{
Serial.begin(9600);  // It defines the baud rate of 9600 bits per second to serial monitor
}
void loop()

{
hall_sensor_value = hallRead();
Serial.print("Hall sensor value = ");
Serial.println(hall_sensor_value);
delay(500);
}
