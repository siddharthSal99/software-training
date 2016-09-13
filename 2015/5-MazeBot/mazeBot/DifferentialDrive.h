#pragma once
#include <PID_v1.h>
#include <Wire.h>
#include <Encoder.h>
#include <Adafruit_MCP23017.h>
#include <BricktronicsShield.h>
#include <BricktronicsMotor.h>

class DifferentialDrive {
public:
  DifferentialDrive();

  DifferentialDrive(const BricktronicsMotorSettings& left_settings,
                    const BricktronicsMotorSettings& right_settings);
                    
  ~DifferentialDrive();

  void init(const BricktronicsMotorSettings& left_settings,
            const BricktronicsMotorSettings& right_settings);

  void stop();

  void driveForward(int speed);

  void driveBackward(int speed);

  void turnLeft(int speed);

  void turnRight(int speed);
  
  void turnRight90();
  
  void turnLeft90();
  
  void forward1Block();
  
  void backward1Block();

private:
  BricktronicsMotor *right;
  BricktronicsMotor *left;
};
