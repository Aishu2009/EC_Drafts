#include "Arduino.h"
#include <Keypad.h>
int buzzerPin = 9; // Frequencies for alarm tones int tone1 = 880; // A5 int tone2 = 1046; // C6
int tone1 = 880; // A5 
int tone2 = 1046; // C6
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
  pinMode(buzzerPin, OUTPUT);
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
    if(){
      
    }
  
  //char variable is the value that is got when a key is pressed 
  char pressedButton = heroKeypad.waitForKey();  
  //Serial print that charcter that is gotten form the pin pad
  Serial.println(pressedButton);
}
void SetCurrentTime(){
  char pressedButton = heroKeypad.waitForKey();
  //print Time on the seven segment diaplsy
}
void SetAlarmTime(){
  //Print alarm on the 7 seg display
  
}
void SetPassword(){
  //Print Pass on the seven segment display
  
  
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
