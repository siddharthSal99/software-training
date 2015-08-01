// Import library definitions from header files
#include <Wire.h>
#include <Bricktronics.h>
#include <Button.h>

// Declare global variables
Bricktronics brick;
Button button{&brick, 1};

// run once at startup
void setup() {
  // Set serial baud rate to 9600
  Serial.begin(9600);
  // initialize NXT objects
  brick.begin();
  button.begin();
}

// called repeatedly until reset
void loop() {
  if(button.is_pressed())
    Serial.println("Pressed");
  else
    Serial.println("Released");
}
