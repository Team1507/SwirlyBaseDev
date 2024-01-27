// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc/XboxController.h>
#include <frc/Timer.h>

#include <frc2/command/button/JoystickButton.h>


#include "subsystems/Drivetrain.h"
#include "subsystems/LogFile.h"
#include "subsystems/LedRing.h"
#include "subsystems/PhotonVision.h"


class RobotContainer {
 public:
  RobotContainer();

  //****************Controllers*******************
  frc::XboxController m_botDriver{0};

  frc::Timer m_timer;

  //****************Subsystems*******************
  Drivetrain   m_drivetrain;
  LogFile      m_logFile;

  LedRing      m_ledRing;

  PhotonVision m_PhotonVision;



  frc2::CommandPtr GetAutonomousCommand();

 private:
  void ConfigureBindings();


  frc2::JoystickButton m_botDriver_Start   {&m_botDriver, frc::XboxController::Button::kStart };
  frc2::JoystickButton m_botDriver_Rbumper {&m_botDriver, frc::XboxController::Button::kRightBumper };


};
