// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc/XboxController.h>
#include <frc/Timer.h>

class RobotContainer {
 public:
  RobotContainer();

  //****************Controllers*******************
  frc::XboxController m_xbox {0};

  frc::Timer m_timer;

  //****************Subsystems*******************
  //Drivetrain m_drivetrain;




  frc2::CommandPtr GetAutonomousCommand();

 private:
  void ConfigureBindings();
};
