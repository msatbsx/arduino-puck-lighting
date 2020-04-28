/*
  Addressable LED permanent light with color calibration & individual led test on power-up.
  version: 0.1
  repo: https://github.com/msatbsx/arduino-puck-lighting
  Author: Michal S
*/

#include "src/FastLED-3.2.1/FastLED.h"

//Setup - PLEASE CHECK VALUES
#define LED_PIN           30      // first pin (using one side of connector, only even pin numbers)
#define NUM_STRIPS        5       // number of strips
#define NUM_LEDS          24      // number of leds in each strip
#define LED_TYPE          WS2811  // LED type (check FastLED docs if doubts)
#define COLOR_ORDER       RBG     // change the order (for ex. GRB) if during the test order is not cool/warm/amber

CRGB color_calibrated = CRGB(255, 255, 255); // set the expected color temperature here
CRGB color_cool = CRGB(255, 0, 255);
CRGB color_warm = CRGB(0, 255, 0);
CRGB color_amber = CRGB(0, 0, 255);
CRGB color_black = CRGB(0, 0, 0);
CRGB leds[NUM_STRIPS][NUM_LEDS];

void setup()
{
  delay(1000); // power-up safety delay

  //check if matches no of strips - NUM_STRIPS (due to templates used in FastLED pin needs to be passed as const.)
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds[0], NUM_LEDS);
  FastLED.addLeds<LED_TYPE, LED_PIN + 2, COLOR_ORDER>(leds[1], NUM_LEDS);
  FastLED.addLeds<LED_TYPE, LED_PIN + 4, COLOR_ORDER>(leds[2], NUM_LEDS);
  FastLED.addLeds<LED_TYPE, LED_PIN + 6, COLOR_ORDER>(leds[3], NUM_LEDS);
  FastLED.addLeds<LED_TYPE, LED_PIN + 8, COLOR_ORDER>(leds[4], NUM_LEDS);

  for (int strip = 0; strip < NUM_STRIPS; strip++)
  {
    for (int dot = 0; dot < NUM_LEDS; dot++)
    {
      leds[strip][dot] = color_cool;
      FastLED.show();
      delay(300);
      leds[strip][dot] = color_warm;
      FastLED.show();
      delay(300);
      leds[strip][dot] = color_amber;
      FastLED.show();
      delay(300);

      //set the permanent light here
      leds[strip][dot] = color_calibrated;
      FastLED.show();
    }
  }

}

void loop(){
  // nothing here, permanent light 
}
