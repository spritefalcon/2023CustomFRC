// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/PWMSparkMax.h>

/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with tank steering and an Xbox controller.
 */
class Robot : public frc::TimedRobot {
  frc::PWMSparkMax m_shooterMotor{4};
  frc::PWMSparkMax m_rightMotorF{0};
  frc::PWMSparkMax m_rightMotorB{1};
  frc::PWMSparkMax m_leftMotorF{2};
  frc::PWMSparkMax m_leftMotorB{3};
  //frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};
  frc::XboxController m_driverController{0};

 public:
  void RobotInit() override {
    
  }
  void TeleopPeriodic() override {
    m_leftMotorF.Set(-m_driverController.GetLeftY());
    m_leftMotorB.Set(-m_driverController.GetLeftY());
    m_rightMotorF.Set(m_driverController.GetRightY());
    m_rightMotorB.Set(m_driverController.GetRightY());
    m_shooterMotor.Set(m_driverController.GetAButton());
  }
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
