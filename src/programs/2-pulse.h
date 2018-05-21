#include "Arduino.h"

int blueLED = 9;
int greenLED = 10;
int brightness = 0;    // how bright the LED is
int maxBrightness = 255;
int fadeAmount = maxBrightness / 25;    // how many points to fade the LED by


// the setup routine runs once when you press reset:
void appSetup() {
  // declare pin 9 to be an output:
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

// the loop routine runs over and over again forever:
void appLoop() {

  // set the brightness of pin 9:
  analogWrite(greenLED, abs(maxBrightness - brightness));
  analogWrite(blueLED, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= maxBrightness) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}