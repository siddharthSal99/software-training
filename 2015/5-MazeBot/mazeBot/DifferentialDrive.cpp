#include "DifferentialDrive.h"

DifferentialDrive::DifferentialDrive()
{
}

DifferentialDrive::DifferentialDrive(
    const BricktronicsMotorSettings& left_settings,
    const BricktronicsMotorSettings& right_settings)
{
  init(left_settings, right_settings);
}

DifferentialDrive::~DifferentialDrive()
{
  delete left;
  delete right;
}

void DifferentialDrive::init(
    const BricktronicsMotorSettings& left_settings,
    const BricktronicsMotorSettings& right_settings)
{
  if(left != nullptr) {
    delete left;
    left = nullptr;
  }
  if(right != nullptr) {
    delete right;
    right = nullptr;
  }
  left = new BricktronicsMotor(left_settings);
  right = new BricktronicsMotor(right_settings);
  left->begin();
  right->begin();
}

void DifferentialDrive::stop() {
  left->brake();
  right->brake();
}

void DifferentialDrive::driveForward(int speed) {
  left->setFixedDrive(speed);
  right->setFixedDrive(speed);
}

void DifferentialDrive::driveBackward(int speed) {
  left->setFixedDrive(-speed);
  right->setFixedDrive(-speed);
}

void DifferentialDrive::turnLeft(int speed) {
  left->setFixedDrive(-speed);
  right->setFixedDrive(speed);
}

void DifferentialDrive::turnRight(int speed) {
  left->setFixedDrive(speed);
  right->setFixedDrive(-speed);
}

void DifferentialDrive::turnRight90() {
  turnRight(140);
  delay(1000);
  stop();
}

void DifferentialDrive::turnLeft90() {
  turnLeft(140);
  delay(1000);
  stop();
}

void DifferentialDrive::forward1Block() {
  driveForward(100);
  delay(250);
  stop();
}

void DifferentialDrive::backward1Block() {
  driveBackward(100);
  delay(250);
  stop();
}

