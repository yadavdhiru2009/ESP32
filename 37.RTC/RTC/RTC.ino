/*
Author:Dharmendra Kumar Yadav
*/
#include <DS1307.h>

uint8_t sec, minute, hour, day, month;
uint16_t year;
DS1307 rtc;

void setup(void){
  Serial.begin(115200); /*Set the baudrate to 115200*/
  rtc.begin();
  rtc.start();          /*start RTC*/
  delay(1000);          /*Wait for 1000mS*/
}

void loop(void){
  /*get time from RTC*/
  rtc.get(&sec, &minute, &hour, &day, &month, &year);

  /*serial output*/
  Serial.print("\nTime: ");
  Serial.print(hour, DEC);
  Serial.print(":");
  Serial.print(minute, DEC);
  Serial.print(":");
  Serial.print(sec, DEC);

  Serial.print("\nDate: ");
  Serial.print(day, DEC);
  Serial.print(".");
  Serial.print(month, DEC);
  Serial.print(".");
  Serial.print(year, DEC);
  Serial.println("");
  /*wait a second*/
  delay(1000);
}

