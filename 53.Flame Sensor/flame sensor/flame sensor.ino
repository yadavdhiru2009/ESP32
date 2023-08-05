/*
Author:Dharmndra Kumar YAdav
*/
int Led = 2;        // used for ESP32
int Fire_analog = 34;    // used for ESP32


void setup() {
  Serial.begin(115200);
  pinMode(Led, OUTPUT);      
}

void loop() {
  int firesensorAnalog = analogRead(Fire_analog);

  Serial.print("Fire Sensor: ");
  Serial.print(firesensorAnalog);
  Serial.print("\t");
  
  if (firesensorAnalog < 1000) {
    Serial.println("Fire");
    digitalWrite (Led, HIGH) ; //send tone
    delay(1000);
    digitalWrite (Led, LOW) ;  //no tone
  }
  else {
    Serial.println("No Fire");
  }
  delay(100);
}
