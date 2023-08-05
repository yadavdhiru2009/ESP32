/* 
 *  Author:dharmendra Kumar Yadav
 
 */
#include <LiquidCrystal.h>
LiquidCrystal lcd(19, 23, 18, 21, 5, 15);
 
void setup() {
  lcd.begin(16, 2);
  lcd.print("Hello World");
}
 
void loop() {
  lcd.setCursor(0, 1);
    //lcd.print("");
}