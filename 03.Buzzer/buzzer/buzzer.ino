/* 
 *  Author:dharmendra Kumar Yadav
 
 */
#define Buzzer 4
void setup(){
    Serial.begin(115200);
    Serial.println("Hello Buzz!");
    pinmode(Buzzer, OUTPUT);
}

void loop(){
    delay(1000);
    digitalwrite(Buzzer, HIGH);
    delay(1000);
    digitalwrite(Buzzer, LOW);
}