#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;  /* Use this for the 16-bit version */
//Adafruit_ADS1015 ads;     /* Use this for the 12-bit version */

void setup() {
  Serial.begin(115200);
  Serial.println("Getting single-ended readings from AIN0..3");
  ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 3mV      0.1875mV (default)
  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
}

void loop() {
  int16_t adc0;
  float volts0;

  adc0 = ads.readADC_SingleEnded(0);

  volts0 = ads.computeVolts(adc0);


  float current = (volts0 - 2.5) / 0.066;//    sensitivity    \\
                                         //ACS712 ELC-05 = 0.185
                                         //ACS712 ELC-20 = 0.100
                                         //ACS712 ELC-30 = 0.066

  if (current < 0.1) {
    current = 0;
  }
  Serial.print("AIN0: "); Serial.print(adc0); Serial.print("  "); Serial.print(volts0); Serial.println("V");
  Serial.print("current : ");
  Serial.println(current);

  delay(1000);


}
