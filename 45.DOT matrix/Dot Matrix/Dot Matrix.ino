/*
Author:Dharmendra kumar Yadav
*/
#include <LedControl.h>

int DIN = 23;
int CS =  15;
int CLK = 18;

LedControl lc=LedControl(DIN,CLK,CS,0);

byte smile[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
byte neutral[8]= {0x3C,0x42,0xA5,0x81,0xBD,0x81,0x42,0x3C};
byte frown[8]=   {0x3C,0x42,0xA5,0x81,0x99,0xA5,0x42,0x3C};
    
void setup(){
  lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
  lc.setIntensity(0,15);      // Set the brightness to maximum value
  lc.clearDisplay(0);         // and clear the display
}

void loop(){ 
  printByte(smile);
  delay(1000);
  printByte(neutral);
  delay(1000);
  printByte(frown);    
  delay(1000);
  lc.clearDisplay(0);
  delay(100);
}

void printByte(byte character []){
  int i = 0;
  for(i=0;i<9;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}