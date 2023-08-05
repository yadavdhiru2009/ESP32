/*
Author:Dharmendra Kumar Yaav
*/
#include <FastLED.h>

#define DATA_PIN    2
#define NUM_LEDS    1
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];
#define UPDATES_PER_SECOND 100

void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  int ms = 100;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(100, 0, 0);
    FastLED.show();
    delay(ms);
  }
   
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 100, 0);
    FastLED.show();
    delay(ms);
  }
 
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 100);
    FastLED.show();
    delay(ms);
  }
}