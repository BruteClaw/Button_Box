# Button_Box
Button Box code for 4*4 matirix and 4 additional buttons
Designed for Milky for use with Elite: Dangerous
 
Written By:
Leslie "BruteClaw" Holdeman
Feb 4th 2020   
 
Code pulled from the AdaFruit Keypad Example that comes with the library and repurposed
https://github.com/adafruit/Adafruit_Keypad

Debounce programing bassed on the Debounce example by David A. Mellis
http://www.arduino.cc/en/Tutorial/Debounce
 
This code is writen for a total of 20 buttons.  16 of them in a 4x4 matrix that is scanned bassed on the Adafruit Keypad library  
The other 4 have their own imputs and can be used for more important actions that might need faster response times 
Acts as a keyboard in the operating system.
 
This sketch is for the Leonardo or Pro Mini boards. 

On the Pro Mini boards:
Matrix Rows will be on Pins 5, 4, 3 & 2.
Matrix Columns will be on Pins 9, 8, 7 & 6 
Both on the Power LED side of the board.
Seperate buttons will be on the other side on pins 10, 16, 14 & 15 tied to ground.

On Leonardo boards:
Matrix Rows will be on Pins 5, 4, 3 & 2.
Matrix Columns will be on Pins 9, 8, 7 & 6 
Seperate buttons will be on pins 10, 11, 12 & 13 tied to ground.
