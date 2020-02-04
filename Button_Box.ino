/*  Button Box code for 4*4 matirix and 4 additional buttons
 *  Designed for Milky for use with Elite: Dangerous
 *  
 *  Written By:
 *  Leslie "BruteClaw" Holdeman
 *  Feb 4th 2020   
 *  
 *  Code pulled from the AdaFruit Keypad Example that comes with the library and repurposed
 *  https://github.com/adafruit/Adafruit_Keypad
 *  
 *  Debounce programing bassed on the Debounce example by David A. Mellis
 *  http://www.arduino.cc/en/Tutorial/Debounce
 *  
 *  This code is writen for a total of 20 buttons.  16 of them in a 4x4 matrix that is scanned bassed on the Adafruit Keypad library  
 *  The other 4 have their own imputs and can be used for more important actions that might need faster response times 
 *  Acts as a keyboard in the operating system.
 *  
 *  This sketch is for the Leonardo or Pro Mini boards. 
 *  
 *  On the Pro Mini boards:
 *  Matrix Rows will be on Pins 5, 4, 3 & 2.
 *  Matrix Columns will be on Pins 9, 8, 7 & 6 
 *  Both on the Power LED side of the board.
 *  Seperate buttons will be on the other side on pins 10, 16, 14 & 15 tied to ground.
 * 
 * On Leonardo boards:
 *  Matrix Rows will be on Pins 5, 4, 3 & 2.
 *  Matrix Columns will be on Pins 9, 8, 7 & 6 
 *  Seperate buttons will be on pins 10, 11, 12 & 13 tied to ground.
 * 
 */

//Libraries needed:
#include <Keyboard.h>
#include "Adafruit_Keypad.h"

//configuration for the matrix of buttons:
const byte ROWS = 4; // How many rows
const byte COLS = 4; // How Many columns
//define the output off the buttons of the matrix:
char keys[ROWS][COLS] = {
  {'1','2','3','a',},
  {'4','5','6','b',},
  {'7','8','9','c',},
  {'*','0','\n','d',}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the rows of the button matrix
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the columns of the button matrix

//Configuration for the seperate buttons:
//Input Pins, **Changes these for the Leonardo Boards**:
const byte btn1Pin = 10; //Button 1 Input pin
const byte btn2Pin = 16; //Button 2 Input pin
const byte btn3Pin = 14; //Button 3 Input pin
const byte btn4Pin = 15; //Button 4 Input pin
//output of the buttons when pressed:
char btn1Out = 'e';
char btn2Out = 'f';
char btn3Out = 'g';
char btn4Out = 'h';
//Variables for Software Debounce
int btn1State;           // the current reading from the input pin
int lstBtn1Ste = LOW;   // the previous reading from the input pin
int btn2State;          
int lstBtn2Ste = LOW;
int btn3State;          
int lstBtn3Ste = LOW;
int btn4State;          
int lstBtn4Ste = LOW;
// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lstDebTime1 = 0;  // the last time the output pin was toggled
unsigned long debDelay1 = 50;    // the debounce time; increase if the output flickers
unsigned long lstDebTime2 = 0;
unsigned long debDelay2 = 50;
unsigned long lstDebTime3 = 0;
unsigned long debDelay3 = 50;
unsigned long lstDebTime4 = 0;
unsigned long debDelay4 = 50;

//initialize an instance of class NewKeypad with the above layout:
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  //Initialize the input pins with pullups for seperate buttons:
  pinMode(btn1Pin, INPUT_PULLUP);
  pinMode(btn2Pin, INPUT_PULLUP);
  pinMode(btn3Pin, INPUT_PULLUP);
  pinMode(btn4Pin, INPUT_PULLUP);
    
  // initialize control over the keyboard:
  Keyboard.begin();
  
  // start the custom button keypad:
  customKeypad.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  customKeypad.tick();
  
  //handeling button presses on the matrix and sending them out as keystrokes:
  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    if(e.bit.EVENT == KEY_JUST_PRESSED) Keyboard.print((char)e.bit.KEY);
  }

  //handeling the seperate buttons pressed and sending them out as keystrokes:
  //Button 1
    // read the state of the switch into a local variable:
  int reading1 = digitalRead(btn1Pin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading1 != lstBtn1Ste) {
    // reset the debouncing timer
    lstDebTime1 = millis();
  }

  if ((millis() - lstDebTime1) > debDelay1) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading1 != btn1State) {
      btn1State = reading1;

      // only send the keystroke if the new button state is HIGH
      if (btn1State == HIGH) {
        Keyboard.print(btn1Out);
      }
    }
  }
  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lstBtn1Ste = reading1;
    
  //Button 2
  // Same code as above with diffrent Variables
  int reading2 = digitalRead(btn2Pin);

  if (reading2 != lstBtn2Ste) {
    lstDebTime2 = millis();
  }

  if ((millis() - lstDebTime2) > debDelay2) {

    if (reading2 != btn2State) {
      btn2State = reading2;

      if (btn2State == HIGH) {
        Keyboard.print(btn2Out);
      }
    }
  }
  lstBtn2Ste = reading2;

  //Button 3
  // Same code as above with diffrent Variables
  int reading3 = digitalRead(btn3Pin);

  if (reading3 != lstBtn3Ste) {
    lstDebTime3 = millis();
  }

  if ((millis() - lstDebTime3) > debDelay3) {

    if (reading3 != btn3State) {
      btn3State = reading3;

      if (btn3State == HIGH) {
        Keyboard.print(btn3Out);
      }
    }
  }
  lstBtn3Ste = reading3;

  //Button 4
  // Same code as above with diffrent Variables
  int reading4 = digitalRead(btn4Pin);

  if (reading4 != lstBtn4Ste) {
    lstDebTime4 = millis();
  }

  if ((millis() - lstDebTime4) > debDelay4) {

    if (reading4 != btn4State) {
      btn4State = reading4;

      if (btn4State == HIGH) {
        Keyboard.print(btn4Out);
      }
    }
  }
  lstBtn4Ste = reading4;

  delay(1);
}
