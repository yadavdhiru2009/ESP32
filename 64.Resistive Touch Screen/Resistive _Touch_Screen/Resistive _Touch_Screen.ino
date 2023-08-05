/*
Author:Dharmendra Kumar Yadav
*/

const int X1 = 26;  /* ADC2-9 */
const int X2 = 27;  /* ADC2-7 */
const int Y1 = 14;  /* ADC2-6 */
const int Y2 = 12;  /* ADC2-5 */

#define Xresolution 240
#define Yresolution 288

void setup(){
   Serial.begin(9600);
}

void loop(){
  int X,Y;
   pinMode(Y1,INPUT);
   pinMode(Y2, OUTPUT_OPEN_DRAIN);
   digitalWrite(Y2, HIGH); //Set Y2 in in tri-state mode
   pinMode(X1,OUTPUT); digitalWrite(X1,HIGH);
   pinMode(X2,OUTPUT); digitalWrite(X2,LOW);
   
   /*Reads X axis of touch screen*/
   X = (analogRead(Y1))/(4096/Xresolution); //Reads Y axis touch position
   
   pinMode(X1,INPUT);   
   pinMode(X2, OUTPUT_OPEN_DRAIN);
   digitalWrite(X2, HIGH); // Set X2 in in tri-state mode
   pinMode(Y1,OUTPUT); digitalWrite(Y1,HIGH);
   pinMode(Y2,OUTPUT); digitalWrite(Y2,LOW);
   
   /*Reads Y axis of touch screen*/
   Y = (analogRead(X1))/(4096/Yresolution); //Reads X axis touch position
 
   /*Display X and Y on Serial Monitor*/
   Serial.print("X = "); 
   Serial.print(X);
   Serial.print(" Y = ");
   Serial.println(Y);
   delay(100);
}


