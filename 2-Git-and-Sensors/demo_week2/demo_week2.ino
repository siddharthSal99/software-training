/* Included headers
 * We use the #include <...> statement to import functions,
 * classes, and constants defined in other files. Here, the
 * first four header files are Arduino libraries that Bricktronics
 * needs to work, and the rest are the actual bricktronics libraries
 * we'll be using.
 */
#include <PID_v1.h>
#include <Wire.h>
#include <Encoder.h>
#include <Adafruit_MCP23017.h>
#include <BricktronicsShield.h>
#include <BricktronicsMotor.h>
#include <BricktronicsLight.h>
#include <BricktronicsButton.h>
#include <BricktronicsUltrasonic.h>

/* Global variables
 * We declare our Bricktronics instances as global
 * variables so they can be used inside both of the
 * methods below. (If we declared them in setup, they
 * would go "out of scope" at the end of the setup
 * method and be unusable in loop().
 */
BricktronicsMotor right(BricktronicsShield::MOTOR_1);
BricktronicsMotor left(BricktronicsShield::MOTOR_2);
BricktronicsButton button(BricktronicsShield::SENSOR_2);
BricktronicsUltrasonic us(BricktronicsShield::SENSOR_4);
BricktronicsLight light(BricktronicsShield::SENSOR_3);

// This method is called once when the board resets.
void setup() {
  // All Bricktronics classes have a begin() method that must be called to initialize them.
  BricktronicsShield::begin();
  right.begin();
  left.begin();
  button.begin();
  us.begin();
  light.begin();
}

// This method is called repeatedly after the setup method finishes.
void loop() {
  // Examples of getting sensor data
  auto distance = us.getDistance();
  auto button_pressed = button.isPressed();
  auto light = ls.scaledValue();
  /* Example of using sensor data to pick motor commands.
   * In this case, the robot tries to stay between 20 and
   * 30 cm away from whatever is infront of it.
   */
  if(distance > 30) {
    left.setFixedDrive(-150);
    right.setFixedDrive(-150);
  } else if(distance < 20) {
    left.setFixedDrive(150);
    right.setFixedDrive(150);
  } else {
    left.brake();
    right.brake();
  }
}
