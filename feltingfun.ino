/**************************************************************************
   Textile Game Controllers : Fun with Felting
   Working with Circuit Playground and Conductive Fibers

   This is made to control KidDisco game using Left,Right,Up and Down keys
   http://kiddisco.asmallgame.com/ 
 
    This is a small sample to run in the browser to see if your keys are working
   https://editor.p5js.org/2sman/sketches/rkGp1alib

   Arduino Example code: 
   https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardwrite/
   https://www.arduino.cc/en/Reference/KeyboardModifiers

   Keyboard Ascii References:
   http://www.asciitable.com/

   Social Body Lab, 2020 Jan.
**************************************************************************/

#include <Adafruit_CircuitPlayground.h>  

#define CAP_THRESHOLD   65 //increase this number if unintentional keypresses occur and 
                           //decrease if buttons aren't sensitive enough
#define DEBOUNCE        100
 
#include <Keyboard.h>

//Change the below values according to how you have connected your felted areas with your circuit playground
int LeftPin = 9; // Set Pin 9 on Arduino to Left key
int RightPin = 12; // Set Pin 12 on Arduino to Right key
int UpPin = 10; // Set Pin 10 on Arduino to Up key
int DownPin = 6;     // Set Pin 6 on Arduino to Down key
int APin = 2; // Set Pin 2 on Arduino to Space Key
int BPin = 1; // Set Pin 1 on Arduino to Shift Key 

   //Change the below values according to what keys you want to
int KeyVal1 = 216; // Set ASCII value for Left key
int KeyVal2 = 215; // Set ASCII value for Right key
int KeyVal3 = 218; // Set ASCII value for Up key
int KeyVal4 = 217; // Set ASCII value for Down key     
int KeyVal5 = 32; // Set ASCII value for Space key 
int KeyVal6 = 15; // Set ASCII value for Shift key
  
  /* 
  Other Common Keyboard ASCII Codes  ar e 
  "a" key = 92
  "w" key = 119
  "s" key = 115
  "d" key = 100
*/


boolean capButton(uint8_t pad) {    
  if (CircuitPlayground.readCap(pad) > CAP_THRESHOLD) {
    return true;
  } else {
    return false;
  }
}

void setup() {
  // Initialize serial.
  Serial.begin(9600);

  // Initialize Circuit Playground library.
  CircuitPlayground.begin();
}

void loop() {
  // Check if capacitive touch exceeds threshold.
  if (capButton(UpPin)) {

    Serial.println("Up Button Touched!"); // Print Message.

    // turn on the LEDs to make an up arrow
    CircuitPlayground.setPixelColor(0, 255, 0, 0);
    CircuitPlayground.setPixelColor(1, 255, 0, 0);
    CircuitPlayground.setPixelColor(2, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);

    Keyboard.press(KeyVal3);  //Press the Up key

    delay(DEBOUNCE);

  } else {

    // clear the colour of the LEDs in the up arrow
    CircuitPlayground.setPixelColor(0, 0, 0, 0);
    CircuitPlayground.setPixelColor(1, 0, 0, 0);
    CircuitPlayground.setPixelColor(2, 0, 0, 0);
    CircuitPlayground.setPixelColor(7, 0, 0, 0);
    CircuitPlayground.setPixelColor(8, 0, 0, 0);
    CircuitPlayground.setPixelColor(9, 0, 0, 0);

    Keyboard.release(KeyVal3); //Release the Up Key

  }
  if (capButton(LeftPin)) {

    Serial.println("Left Button Touched!"); // Print message.

    // turn on the LEDs to make a left arrow
    CircuitPlayground.setPixelColor(1, 255, 0, 0);
    CircuitPlayground.setPixelColor(2, 255, 0, 0);
    CircuitPlayground.setPixelColor(3, 255, 0, 0);
    CircuitPlayground.setPixelColor(4, 255, 0, 0);
    CircuitPlayground.setPixelColor(0, 255, 0, 0);

    Keyboard.press(KeyVal1);  //Press the Left key

    delay(DEBOUNCE);

  } else {

    // clear the colour of the LEDs in the left arrow
    CircuitPlayground.setPixelColor(1, 0, 0, 0);
    CircuitPlayground.setPixelColor(2, 0, 0, 0);
    CircuitPlayground.setPixelColor(3, 0, 0, 0);
    CircuitPlayground.setPixelColor(4, 0, 0, 0);
    CircuitPlayground.setPixelColor(0, 0, 0, 0);

    Keyboard.release(KeyVal1); //Release the Left Key

  }
  if (capButton(RightPin)) {

    Serial.println("Right Button Touched!"); // Print message.

    // turn on the LEDs to make a right arrow
    CircuitPlayground.setPixelColor(5, 255, 0, 0);
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);
    CircuitPlayground.setPixelColor(8, 255, 0, 0);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);

    Keyboard.press(KeyVal2);  //Press the Right key

    delay(DEBOUNCE);

  } else {

    // clear the colour of the LEDs in the right arrow
    CircuitPlayground.setPixelColor(5, 0, 0, 0);
    CircuitPlayground.setPixelColor(6, 0, 0, 0);
    CircuitPlayground.setPixelColor(7, 0, 0, 0);
    CircuitPlayground.setPixelColor(8, 0, 0, 0);
    CircuitPlayground.setPixelColor(9, 0, 0, 0);

    Keyboard.release(KeyVal2); //Release the Right key

  }
  if (capButton(DownPin)) {

    Serial.println("Down Button Touched!"); // Print message.

    // turn on the LEDs to make a down arrow
    CircuitPlayground.setPixelColor(2, 255, 0, 0);
    CircuitPlayground.setPixelColor(3, 255, 0, 0);
    CircuitPlayground.setPixelColor(4, 255, 0, 0);
    CircuitPlayground.setPixelColor(5, 255, 0, 0);
    CircuitPlayground.setPixelColor(6, 255, 0, 0);
    CircuitPlayground.setPixelColor(7, 255, 0, 0);

    Keyboard.press(KeyVal4);  //Press the Down key

    delay(DEBOUNCE);

  } else {

    // clear the colour of the LEDs in the down arrow
    CircuitPlayground.setPixelColor(2, 0, 0, 0);
    CircuitPlayground.setPixelColor(3, 0, 0, 0);
    CircuitPlayground.setPixelColor(4, 0, 0, 0);
    CircuitPlayground.setPixelColor(5, 0, 0, 0);
    CircuitPlayground.setPixelColor(6, 0, 0, 0);
    CircuitPlayground.setPixelColor(7, 0, 0, 0);

    Keyboard.release(KeyVal4); //Release the Down key

  }
  if (capButton(2)) {
    Serial.println("A Button Touched"); // Print message.

    // set the colour of all the LEDs to blue
    CircuitPlayground.setPixelColor(0, 0, 0, 255);
    CircuitPlayground.setPixelColor(1, 0, 0, 255);
    CircuitPlayground.setPixelColor(2, 0, 0, 255);
    CircuitPlayground.setPixelColor(3, 0, 0, 255);
    CircuitPlayground.setPixelColor(4, 0, 0, 255);
    CircuitPlayground.setPixelColor(5, 0, 0, 255);
    CircuitPlayground.setPixelColor(6, 0, 0, 255);
    CircuitPlayground.setPixelColor(7, 0, 0, 255);
    CircuitPlayground.setPixelColor(8, 0, 0, 255);
    CircuitPlayground.setPixelColor(9, 0, 0, 255);

    Keyboard.press(KeyVal5);  //Press the Space key

    delay(DEBOUNCE);

  } else {

    // clear the colour of the LEDs
    CircuitPlayground.setPixelColor(0, 0, 0, 0);
    CircuitPlayground.setPixelColor(1, 0, 0, 0);
    CircuitPlayground.setPixelColor(2, 0, 0, 0);
    CircuitPlayground.setPixelColor(3, 0, 0, 0);
    CircuitPlayground.setPixelColor(4, 0, 0, 0);
    CircuitPlayground.setPixelColor(5, 0, 0, 0);
    CircuitPlayground.setPixelColor(6, 0, 0, 0);
    CircuitPlayground.setPixelColor(7, 0, 0, 0);
    CircuitPlayground.setPixelColor(8, 0, 0, 0);
    CircuitPlayground.setPixelColor(9, 0, 0, 0);

    Keyboard.release(KeyVal5);  //Release the space Space key

  }
  if (capButton(1)) {
    Serial.println("B Button Touched"); // Print message
    // set the colour of all the LEDs to green
    CircuitPlayground.setPixelColor(0, 0, 255, 0);
    CircuitPlayground.setPixelColor(1, 0, 255, 0);
    CircuitPlayground.setPixelColor(2, 0, 255, 0);
    CircuitPlayground.setPixelColor(3, 0, 255, 0);
    CircuitPlayground.setPixelColor(4, 0, 255, 0);
    CircuitPlayground.setPixelColor(5, 0, 255, 0);
    CircuitPlayground.setPixelColor(6, 0, 255, 0);
    CircuitPlayground.setPixelColor(7, 0, 255, 0);
    CircuitPlayground.setPixelColor(8, 0, 255, 0);
    CircuitPlayground.setPixelColor(9, 0, 255, 0);

    Keyboard.press(KeyVal6);  //Press the Enter key

    delay(DEBOUNCE);

  } else {

    // clear the colour of the LEDs
    CircuitPlayground.setPixelColor(0, 0, 0, 0);
    CircuitPlayground.setPixelColor(1, 0, 0, 0);
    CircuitPlayground.setPixelColor(2, 0, 0, 0);
    CircuitPlayground.setPixelColor(3, 0, 0, 0);
    CircuitPlayground.setPixelColor(4, 0, 0, 0);
    CircuitPlayground.setPixelColor(5, 0, 0, 0);
    CircuitPlayground.setPixelColor(6, 0, 0, 0);
    CircuitPlayground.setPixelColor(7, 0, 0, 0);
    CircuitPlayground.setPixelColor(8, 0, 0, 0);
    CircuitPlayground.setPixelColor(9, 0, 0, 0);

    Keyboard.release(KeyVal6);  //Release the Enter key
  }
}
