/*
Author:Dharmendra Kumar Yadav
*/
#include <DHT.h>  
// Set up the DHT sensor 
DHT dht(4, DHT22);
float temperature ;
float  humidity;
int counter;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");
}

void loop() {
  // put your main code here, to run repeatedly:
  temperature  = dht.readTemperature();
  humidity     = dht.readHumidity();
  Serial.println("Data: "+ String(counter));
  // Print the values of temperature in Celsus
  Serial.print("Temperatue:\t");
  Serial.print(dht.readTemperature(false));
  Serial.println("C");
   // Print the values of temperature in Fahrenheit
  Serial.print("Temperatue:\t");
  Serial.print(dht.readTemperature(true));
  Serial.println("F");
  // print Humidity in perscent 
  Serial.println("Humidity: \t"+String(humidity)+ "%");
  // Print the values of the heat Index for both Units
  Serial.print("Heat Index In Celsus: ");
  Serial.println(dht.computeHeatIndex(temperature, humidity, false));
  
  Serial.print("Heat Index In Fahrenheit: ");
  Serial.println(dht.computeHeatIndex(temperature, humidity, true));
  Serial.println(" ");
  delay(1000); // this speeds up the simulation
  counter++;
}