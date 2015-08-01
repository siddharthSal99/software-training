// Import library definitions from header files
#include <Wire.h>
#include <Ultrasonic.h>
#include <Motor.h>
#include <Bricktronics.h>

// Declare global variables
Bricktronics brick;
Motor left_motor{&brick, 1};
Motor right_motor{&brick, 2};
Ultrasonic ultrasonic{&brick, 4};

void setup() {
  Serial.begin(9600);
  brick.begin();
  left_motor.begin();
  right_motor.begin();
  ultrasonic.begin();
}

void loop() {
  auto distance = ultrasonic.getDistance();
  if(distance == 255) {
    left_motor.stop();
    right_motor.stop();
  } else if(distance > 30) {
    left_motor.set_speed(255);
    right_motor.set_speed(255);
  } else if(distance < 25) {
    left_motor.set_speed(-255);
    right_motor.set_speed(-255);
  } else {
    left_motor.stop();
    right_motor.stop();
  }
}
