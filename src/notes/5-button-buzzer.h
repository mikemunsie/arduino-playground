#include "Arduino.h"
#include "pitches.h"
using namespace std;

int buzzer = 9;
int button = 10;
int melodyCounter = -1;

int red = 6;
int blue = 3;
int green = 5;
int playing = 1;

int melody[] = {
  NOTE_C3, NOTE_D3, NOTE_E3, NOTE_F3, NOTE_G3, NOTE_A4, NOTE_B4, NOTE_C4
};

void appSetup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(red, OUTPUT); 
  pinMode(green, OUTPUT); 
  pinMode(blue, OUTPUT); 
  digitalWrite(red, LOW); 
  digitalWrite(green, LOW); 
  digitalWrite(blue, LOW);
}

void appLoop() {
  if (playing % 2 == 0) {
    melodyCounter++;
    if (melodyCounter > 7) {
      melodyCounter = 0;
      delay(500);
    }
    tone(buzzer, melody[melodyCounter], 200);
    analogWrite(red, rand() % 255);
    analogWrite(green, rand() % 255);
    analogWrite(blue, rand() % 255);
    delay(200);
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(blue, 0);
  }
  if (digitalRead(button) == LOW) {
    playing++;
    delay(200);
  } else {
    //analogWrite(red, 0);
    //analogWrite(green, 0);
    //analogWrite(blue, 0);
    //noTone(buzzer);
  }
}