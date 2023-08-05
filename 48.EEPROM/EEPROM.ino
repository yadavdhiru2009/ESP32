/*
Author :Dharmendra KUmar Yadav
*/
#include"Wire.h"
#define EEPROM_I2C_ADDRESS 0x50
void writeEEPROM(int address, byte val, int i2c_address)
 {
  Wire.beginTransmission(i2c_address);//Begin Transmission to I2C EEPROM
  //send memory address as two 8 bit bytes
  Wire.write((int)(address >>8));// MSB
  Wire.write((int)(address&0xFF)); //LSB
  Wire.write(val);// send sata to be store
  Wire.endTransmission(); //END transmission

delay(10);
}

byte readEEPROM(int address, int i2c_address)
{
  byte rcvData=0xFF;//define byte for received data
  Wire.beginTransmission(i2c_address);//Begin Transmission to I2C EEPROM
  //send memory address as two 8 bit bytes
  Wire.write((int)(address >>8));// MSB
  Wire.write((int)(address&0xFF)); //LSB
  Wire.endTransmission();//END transmission
  Wire.requestFrom(i2c_address, 1);//Request one byte of data at current memory address
  rcvData=Wire.read();//read the data and assign to variable
  return rcvData;//return the data as funtion output
}

char readVal =0;

void setup()
 {
   Wire.begin();
   Serial.begin(115200);
   delay(1000);
   for(int i=0;i<94;i++)
   {
   writeEEPROM(i,(33+i),EEPROM_I2C_ADDRESS);
   }
  Serial.println("reading data from eeprom");
  for(int i=0;i<94;i++)
  {
  readVal=(char)readEEPROM(i,EEPROM_I2C_ADDRESS);
  Serial.print("value at ");
  Serial.print(i);
  Serial.print(" = ");
  Serial.println(readVal);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
