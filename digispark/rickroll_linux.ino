/*
* This works on a international US keyboard only.
* To properly use it with anything else, look for modified 'scancode-ascii-table.h', or manually send the correct keystrokes.
*/

#include "DigiKeyboard.h"
int iterationCounter = 0;

void setup() {
  
  // initialize the digital pin as an output.
  pinMode(0, OUTPUT); //LED on Model B
  pinMode(1, OUTPUT); //LED on Model A     
  digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(1, LOW); 
  // don't need to set anything up to use DigiKeyboard

}


void loop() {
  if(iterationCounter == 0){
    // delay 1s because recognizing devices apparently takes a while?
    DigiKeyboard.delay(1000);
    iterationCounter++;
  }
  
  if(iterationCounter < 20){
  DigiKeyboard.delay(300);
  DigiKeyboard.sendKeyStroke(KEY_F2,MOD_ALT_LEFT);
  DigiKeyboard.delay(300);
  DigiKeyboard.print("firefox www.youtube.com/watch");
  DigiKeyboard.sendKeyStroke(KEY_W,MOD_ALT_RIGHT); // char '?'
  DigiKeyboard.print("v=dQw4w9WgXcQ");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  iterationCounter +=1;
  }

}
