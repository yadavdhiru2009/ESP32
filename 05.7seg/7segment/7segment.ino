/**
 Author:Dharmendra Kumar Yadav
*/

#include "SevSeg.h"

SevSeg sevseg;
void setup() {
  byte numDigits = 4;
  byte digitPins[] = {14, 15, 2, 5};
  byte segmentPins[] = {12, 4, 19, 26, 27, 13, 18, 25};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected. Then, you only need to specify 7 segmentPins[]

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
               updateWithDelays, leadingZeros, disableDecPoint);
}

void loop() {
  sevseg.setNumber(millis() / 250);
  sevseg.refreshDisplay();
  delay(1); // This speeds up the simulation
}