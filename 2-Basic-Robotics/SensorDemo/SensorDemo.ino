// Import library definitions from header files
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <BricktronicsButton.h>
#include <BricktronicsShield.h>


// Declare global variables
BricktronicsButton button{BricktronicsShield::SENSOR_2};

// run once at startup
void setup() {
  // Set serial baud rate to 9600
  Serial.begin(9600);
  // initialize NXT objects
  BricktronicsShield::begin();
  button.begin();
}

// called repeatedly until reset
void loop() {
  if(button.isPressed())
    Serial.println("Pressed");
  else
    Serial.println("Released");
}
