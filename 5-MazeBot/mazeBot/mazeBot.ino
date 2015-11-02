#include <PID_v1.h>
#include <Wire.h>
#include <Encoder.h>
#include <Adafruit_MCP23017.h>
#include <BricktronicsShield.h>
#include <BricktronicsMotor.h>
#include <BricktronicsLight.h>
#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include "BitMap.h"
#include "DifferentialDrive.h"

using namespace std;

BitMap maze;
Coordinate position;
DifferentialDrive robot;
BricktronicsLight light(BricktronicsShield::SENSOR_1);

void setup() {
  BricktronicsShield::begin();
  light.begin();
  light.setFloodlightAlways(true);
  Serial.begin(9600);
  robot.init(BricktronicsShield::MOTOR_2, BricktronicsShield::MOTOR_1);
  position.x = 0;
  position.y = 0;

}

void loop() {
}
