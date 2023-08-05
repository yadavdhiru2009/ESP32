/*
Author:Dharmendra Kumar Yadav
*/
#include <DS1307.h>

uint8_t set_Sec = 0;            /* Set the Seconds */
uint8_t set_Minute = 47;        /* Set the Minutes */
uint8_t set_Hour = 3;           /* Set the Hours */
uint8_t set_Day = 13;           /* Set the Day */
uint8_t set_Month = 05;         /* Set the Month */
uint16_t set_Year = 2022;     /* Set the Year */

uint8_t sec, minute, hour, day, month;
uint16_t year;
DS1307 rtc;

void setup(void){
  Serial.begin(115200);       /*Set the baudrate to 115200*/
  rtc.begin();
  /*03:47:00 13.05.2022 //sec, min, hour, day, month, year*/
  rtc.set(set_Sec, set_Minute, set_Hour, set_Day, set_Month, set_Year);
  rtc.stop();                 /*stop/pause RTC*/

  rtc.start();                /*start RTC*/
  delay(1000);                /*Wait for 1000mS*/
  Serial.print("You have set: ");
  Serial.print("\nTime: ");
  Serial.print(set_Hour, DEC);
  Serial.print(":");
  Serial.print(set_Minute, DEC);
  Serial.print(":");
  Serial.print(set_Sec, DEC);

  Serial.print("\nDate: ");
  Serial.print(set_Day, DEC);
  Serial.print(".");
  Serial.print(set_Month, DEC);
  Serial.print(".");
  Serial.print(set_Year, DEC);
  Serial.println("");
}

void loop(void){}