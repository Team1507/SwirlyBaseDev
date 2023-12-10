// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveTypeToggle.h"
#include "Robot.h"
#include "subsystems/Drivetrain.h"


CmdDriveTypeToggle::CmdDriveTypeToggle() 
{

}

// Called when the command is initially scheduled.
void CmdDriveTypeToggle::Initialize() 
{
  switch( robotcontainer.m_drivetrain.GetDriveType() )
  {
    case Drivetrain::ROBOTCENTRIC:
      robotcontainer.m_drivetrain.SetDriveType( Drivetrain::FIELDCENTRIC );
      break;
    case Drivetrain::FIELDCENTRIC:
      robotcontainer.m_drivetrain.SetDriveType( Drivetrain::ROBOTCENTRIC );
      break;
  }
}
