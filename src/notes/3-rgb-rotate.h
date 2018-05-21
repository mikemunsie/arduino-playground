#include "Arduino.h"
using namespace std;

int RED = 3;
int GREEN = 5;
int BLUE = 6;

int maxBrightness = 100;

int redFade = maxBrightness / ((rand() % 50)+10);
int blueFade = maxBrightness / ((rand() % 50)+10);
int greenFade = maxBrightness / ((rand() % 50)+10);

int redCounter = 0;
int blueCounter = 0;
int greenCounter = 0;

// the setup routine runs once when you press reset:
void appSetup() {
  pinMode(RED, OUTPUT); 
  pinMode(GREEN, OUTPUT); 
  pinMode(BLUE, OUTPUT); 
  digitalWrite(RED, LOW); 
  digitalWrite(GREEN, LOW); 
  digitalWrite(BLUE, LOW);
}

// the loop routine runs over and over again forever:
void appLoop() {

  redCounter+=redFade;
  blueCounter+=blueFade;
  greenCounter+=greenFade;


  if (redCounter > maxBrightness) { 
    redFade = -redFade;
  }
  if (blueCounter > maxBrightness) { 
    blueFade = -blueFade;
  }
  if (greenCounter > maxBrightness) { 
    greenFade = -greenFade;
  }

  // set the brightness of pin 9:
  analogWrite(RED, redCounter);
  analogWrite(GREEN, greenCounter);
  analogWrite(BLUE, blueCounter);
  
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}