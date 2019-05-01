// Funciona em teclados ABNT sem modificar arquivos da tabela ascii. Enjoy

#include "DigiKeyboard.h"

#define BARRA_DIREITA 84
#define PONTO_VIRGULA 56


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
  if(iterationCounter < 30){
  DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);
  DigiKeyboard.delay(300);
  DigiKeyboard.print("http");
  DigiKeyboard.sendKeyStroke(PONTO_VIRGULA,MOD_SHIFT_LEFT); 
  DigiKeyboard.sendKeyStroke(BARRA_DIREITA); // /
  DigiKeyboard.sendKeyStroke(BARRA_DIREITA); // /
  DigiKeyboard.print("youtu.be");
  DigiKeyboard.sendKeyStroke(BARRA_DIREITA); // /
  DigiKeyboard.print("dQw4w9WgXcQ");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  iterationCounter +=1;
  }
  
 
}
