/*
Autor:Dharmendra Kumar Yadav
*/

const int IR_SENSOR = 14;  // infrared sensor Pin
byte lastSt = 0xFF;       
byte fixedSt = 0xFF;      
unsigned long smpltmr = 0;  
 
void setup() {
  pinMode(IR_SENSOR, INPUT);
  Serial.begin(115200);
}
 
void loop() {
  if(millis() - smpltmr < 40) return;
  smpltmr = millis();
 
  byte st = digitalRead(IR_SENSOR);
  int cmp = (st == lastSt);
  lastSt = st;
   
  if(!cmp) return;
   
  if(st != fixedSt){
    fixedSt = st;
    st = (~st) & 0x01;
    if(st==1){
    Serial.println("obstacle is detected");
    
    }else{
      Serial.println("obstacle is cleared");
      
      }
  }
}