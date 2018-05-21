#include "Arduino.h"
#include "pitches.h"
 
// notes in the melody:
int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6
};

int buzzer = 8;
int button = 10;
int playing = 1; // Keeps track of the button
int noteDuration = 500;
 
void appSetup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
}
 
void appLoop() {  
  if (playing % 2 == 0) {
    for (int thisNote = 0; thisNote < 8; thisNote++) {

      // pin8 output the voice, every scale is 0.5 second
      tone(8, melody[thisNote], noteDuration);
      
      // Output the voice after several minutes
      delay(10);
    }
  }
  if (digitalRead(button) == LOW) {
    playing++;
    delay(500);
  }
}
