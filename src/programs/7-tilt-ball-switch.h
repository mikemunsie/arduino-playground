#include "Arduino.h"

const int ledPin = 13;
const int tiltSensor = 2;

void appSetup() { 
  pinMode(ledPin,OUTPUT);
  pinMode(tiltSensor,INPUT);
  digitalWrite(tiltSensor, HIGH);
} 

void appLoop() {  
  int digitalVal = digitalRead(2);

  if (digitalVal == HIGH) {
    digitalWrite(ledPin,LOW);
  }
  else {
    digitalWrite(ledPin,HIGH);
  }
}
