#include "Arduino.h"
using namespace std;

int button1Pin = 3;
int ledPin = 5;

void appSetup() 
{
  pinMode(button1Pin, INPUT_PULLUP);  
  pinMode(ledPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void appLoop() 
{
  if (digitalRead(button1Pin) == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    analogWrite(ledPin, 50);    
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    analogWrite(ledPin, 0);   
  }
}