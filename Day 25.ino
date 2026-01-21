#include "Arduino.h"
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

const byte ROW_PINS[ROWS] = { 5, 4, 3, 2 };
const byte COL_PINS[COLS] = { 6, 7, 8, 9 };

const char BUTTONS[ROWS][COLS] = {
  { '1', '2', '3', 'A' },  
  { '4', '5', '6', 'B' },  
  { '7', '8', '9', 'C' },  
  { '*', '0', '#', 'D' }   
};
//Use the buttons index to setup/ initialize pin setup for all the pinpad pins
Keypad heroKeypad = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

void setup() {
  
}

void loop() {
  str currentTime= ' ';
  SetAlaramTime();  
  SetCurrentTime();
  SetPassword();
  while (//alarm time != Current time
    ){
    RunClock();
    }
    
  if (//Alaram time =
    ){
    Alarm();
    }
  
  //char variable is the value that is got when a key is pressed 
  char pressedButton = heroKeypad.waitForKey();  
  //Serial print that charcter that is gotten form the pin pad
  Serial.println(pressedButton);
}
void SetCurrentTime(){
  char pressedButton = heroKeypad.waitForKey();
}
void SetAlarmTime(){
  
}
void SetPassword(){
  
}
void RunClock(){
  
}
void Alarm(){
  tone(buzzerPin, tone1, 200); 
  delay(250); 
  tone(buzzerPin, tone2, 200); 
  delay(250); 
  tone(buzzerPin, tone1, 200); 
  delay(250); 
  tone(buzzerPin, tone2, 200); 
  delay(250);
}
void AlarmStop(){
  noTone(buzzerPin); 
  delay(500);
}
