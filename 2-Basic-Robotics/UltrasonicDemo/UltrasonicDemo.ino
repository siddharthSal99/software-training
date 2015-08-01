// Import library definitions from header files
#include <Encoder.h>
#include <PID_v1.h>
#include <Adafruit_MCP23017.h>
#include <Wire.h>
#include <BricktronicsMotor.h>
#include <BricktronicsUltrasonic.h>
#include <BricktronicsShield.h>

// Declare global variables
BricktronicsMotor left{BricktronicsShield::MOTOR_1};
BricktronicsMotor right{BricktronicsShield::MOTOR_2};
BricktronicsUltrasonic ultrasonic{BricktronicsShield::SENSOR_4};

void setup() {
  BricktronicsShield::begin();
  left.begin();
  right.begin();
  ultrasonic.begin();
}

void loop() {
  auto distance = ultrasonic.getDistance();
  
  if(distance == 255) {
    left.brake();
    right.brake();
  } else if(distance > 30) {
    left.setFixedDrive(-150);
    right.setFixedDrive(-150);
  } else if(distance < 25) {
    left.setFixedDrive(150);
    right.setFixedDrive(150);
  } else {
    left.brake();
    right.brake();
  }
}
