#include <PID_v1.h>
#include <Wire.h>
#include <Encoder.h>
#include <Adafruit_MCP23017.h>
#include <BricktronicsShield.h>
#include <BricktronicsMotor.h>
#include <BricktronicsUltrasonic.h>
#include <system_configuration.h>
#include <utility.h>
#include <unwind-cxx.h>
#include <StandardCplusplus.h>

#include <algorithm>
#include <vector>

/* User-Defined Class
 * Here we define our own class, Differential Drive, to abstract
 * away the individual motor commands that make our robot move.
 */
class DifferentialDrive {
// Everything under public: is viewable to any other code
public:
  /* Constructor
   * The constructor is called to initialize an object. Here we've
   * added a parameter list to our constructor so we can properly
   * initialize the private motor variables.
   */
  DifferentialDrive(const BricktronicsMotorSettings& left_settings,
                    const BricktronicsMotorSettings& right_settings)
	// This syntax allows us to call the private member variables' constructors with the right arguments
    : left(left_settings),
      right(right_settings)
  {
    left.begin();
    right.begin();
  }

  void stop() {
    left.brake();
    right.brake();
  }

  void driveForward(int speed) {
    left.setFixedDrive(-speed);
    right.setFixedDrive(-speed);
  }

  void driveBackward(int speed) {
    left.setFixedDrive(speed);
    right.setFixedDrive(speed);
  }

  void turnLeft(int speed) {
    left.setFixedDrive(speed);
    right.setFixedDrive(-speed);
  }

  void turnRight(int speed) {
    left.setFixedDrive(-speed);
    right.setFixedDrive(speed);
  }

// Anything under private: is only viewable to code inside this class.
private:
  BricktronicsMotor right;
  BricktronicsMotor left;
};

void setup() {
  BricktronicsShield::begin();
  BricktronicsUltrasonic us(BricktronicsShield::SENSOR_4);
  us.begin();
  DifferentialDrive robot(BricktronicsShield::MOTOR_2,
                          BricktronicsShield::MOTOR_1);

  // Declare a new vector, named 'data', with 60 slots for integers
  std::vector<int> data(60);

  robot.turnLeft(80);
  // Loop through each element in data and set it to the reading from the Ultrasonic
  for(auto& i : data) {
    i = us.getDistance();
    delay(100);
  }
  robot.stop();
  // Replace all invalid (255) data entries with 0
  std::replace(data.begin(), data.end(), 255, 0);
  // Find the location of the largest data entry
  auto max_iterator = std::max_element(data.begin(), data.end());
  // Initialize serial-over-USB connection to the computer.
  Serial.begin(9600);
  // Send the value at max_iterator (using the * operator) to the computer.
  Serial.println(*max_iterator);
}

void loop() {
}
