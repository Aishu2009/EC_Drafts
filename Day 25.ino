#include "Arduino.h"
#include <Keypad.h>
#include <TM1637Display.h>

//Buzzer
int buzzerPin = 9; // Frequencies for alarm tones int tone1 = 880; // A5 int tone2 = 1046; // C6
int tone1 = 880; // A5 
int tone2 = 1046; // C6


//7-Segment Display
const byte AlarmDisplay[] = {          // d
  SEG_A | SEG_B | SEG_C | SEG_G | SEG_E | SEG_F  // O    // E
};
const byte CurrentDisplay[] = {                   // n
  SEG_A | SEG_D | SEG_E | SEG_F          // E
};
const byte PassCorrect[] = {                   // n
  SEG_A | SEG_B | SEG_G | SEG_E | SEG_F,
  SEG_A | SEG_B | SEG_C | SEG_G | SEG_E | SEG_F,
  SEG_A |SEG_C | SEG_D | SEG_G | SEG_F,
};

const byte CLK_PIN = 12;
const byte DIO_PIN = 11;

//PINPAD
const byte ROWS = 4;
const byte COLS = 4;
const byte ROW_PINS[ROWS] = { 5, 4, 3, 2 };
const byte COL_PINS[COLS] = { 6, 7, 8, 9 };
//pinpad index/array
const char BUTTONS[ROWS][COLS] = {
  { '1', '2', '3', 'A' },  
  { '4', '5', '6', 'B' },  
  { '7', '8', '9', 'C' },  
  { '*', '0', '#', 'D' }   
};
//Use the buttons index to setup/ initialize pin setup for all the pinpad pins
Keypad heroKeypad = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

//Clock setup
int currentTime= 0;
int AlarmTime = 0;
int Password = 0; 
int H1, H2, M1, M2; 
int S1 = 0, S2 = 0; 
unsigned long lastTick = 0;


void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  str currentTime= ' ';
  SetPassword();
  SetAlarmTime();  
  SetCurrentTime();
  RunClock();

  while (alarm time != Current time){
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
  lander_display.clear();
  delay(1000);
  lander_display.setSegments(CurrentDisplay);
  delay(5000);
  lander_display.clear();
  for (int i = 0; i < 4; i++) { 
    char key = heroKeypad.waitForKey();
    int digit= key-'0';
    currentTime = currentTime * 10 + digit;
  }
  display.showNumberDecEx( currentTime, 0x40, true);
  delay(10000);
  lander_display.clear();
  //print Time on the seven segment diaplsy
}
void SetAlarmTime(){
  //Print alarm on the 7 seg display
  lander_display.clear();
  delay(1000);
  lander_display.setSegments(AlarmDisplay);
  delay(5000);
  lander_display.clear();
  for (int i = 0; i < 4; i++) { 
    char key = heroKeypad.waitForKey();
    int digit= key-'0';
    AlarmTime = AlarmTime * 10 + digit;
  display.showNumberDecEx(AlarmTime, 0x40, true);
  delay(10000);
  lander_display.clear();
}
void SetPassword(){
  //Print Pass on the seven segment display
  lander_display.clear();
  delay(1000);
  lander_display.setSegments(AlarmDisplay);
  delay(5000);
  lander_display.clear();
  for (int i = 0; i < 4; i++) { 
    char key = heroKeypad.waitForKey();
    int digit= key-'0';
    Password = Password * 10 + digit;
  }
  display.showNumberDecEx( currentTime, 0x40, true);
  delay(10000);
  lander_display.clear();
}
//RunClock  
  int RunClock()() { 
  unsigned long now = millis(); 
  if (now - lastTick >= 1000) { // 1 second 
  lastTick = now; // ------------------------- // Break HHMM into digits // ------------------------- 
    H1 = currentTime / 1000; // thousands 
    H2 = (currentTime / 100) - (H1 * 10); // hundreds 
    M1 = (currentTime / 10) - (H1 * 100 + H2 * 10); // tens 
    M2 = currentTime - (H1 * 1000 + H2 * 100 + M1 * 10); // ones // ------------------------- // Seconds // ------------------------- 
    S2++; 
    if (S2 > 9) { 
      S2 = 0; S1++; 
    } 
    if (S1 > 5) { 
      S1 = 0; M2++; 
    } // ------------------------- // Minutes // ------------------------- 
    if (M2 > 9) { 
      M2 = 0; M1++; 
    } 
    if (M1 > 5) { 
      M1 = 0; H2++; 
    } // ------------------------- // Hours // ------------------------- 
    if (H1 == 2 && H2 > 3) {
      H1 = 0; H2 = 0; 
    } 
    if (H2 > 9) {
      H2 = 0; H1++; 
    } // ------------------------- // Reassemble HHMM // ------------------------- 
    currentTime = H1 * 1000 + H2 * 100 + M1 * 10 + M2; 
    display.showNumberDecEx(currentTime, 0x40, true);
  }
return currentTime; }


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
