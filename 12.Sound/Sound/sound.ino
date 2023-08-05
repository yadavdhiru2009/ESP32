/*
Author:Dharmendra KUmar Yadav
*/
 

int raw_Value = A0;

void setup(){
  Serial.begin(9600);
  //pinMode(D0_Value, OUTPUT); // Set pin D8 as digital output
  pinMode(raw_Value, INPUT); //Set pin A0 as an input
}

void loop(){
  //int val_digital = digitalRead(D0_Value);
  int val_analog = analogRead(raw_Value );

  Serial.print(raw_Value);
  Serial.print("\t");
  //Serial.println(D0_Value);

}