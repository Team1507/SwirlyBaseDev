// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/Commands.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "commands/CmdDriveWithGamepad.h"
#include "commands/CmdDriveTypeToggle.h"
#include "commands/CmdCalibrateSwerveEncoders.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveForceSteerAngle.h"
#include "commands/GrpTest1.h"
#include "commands/GrpTest2.h"
#include "commands/CmdDriveZeroGyro.h"
#include "commands/CmdDriveAimAtTarget.h"
#include "commands/AutoTwoPieceRedThree.h"
#include "commands/AutoThreePieceRedOne.h"

#include "commands/AutoTestGroup.h"


RobotContainer::RobotContainer() 
{

  //******************** Subsystem Defaults ******************************
  m_drivetrain.SetDefaultCommand( CmdDriveWithGamepad() );



  //******************** Dashboard Buttons *******************************
  frc::SmartDashboard::PutData( "CmdDriveTypeToggle",    new CmdDriveTypeToggle());

  frc::SmartDashboard::PutData( "CmdDriveClearAll",      new CmdDriveClearAll());
  frc::SmartDashboard::PutData( "GrpTest1",              new GrpTest1());
  frc::SmartDashboard::PutData( "GrpTest2",              new GrpTest2());


  frc::SmartDashboard::PutData( "AutoTestGroup",         new AutoTestGroup());
  frc::SmartDashboard::PutData( "AutoTwoPieceRedThree",  new AutoTwoPieceRedThree());
  frc::SmartDashboard::PutData( "AutoThreePieceRedOne",  new AutoThreePieceRedOne());

  //Smartdashboard SwerveDrive test/calibration buttons
  frc::SmartDashboard::PutData( "SteerAngle=0",          new CmdDriveForceSteerAngle( &m_drivetrain, 0.0));
  frc::SmartDashboard::PutData( "SteerAngle=90",         new CmdDriveForceSteerAngle(&m_drivetrain,  90.0));
  frc::SmartDashboard::PutData( "CmdCalSwerveEnc_1",     new CmdCalibrateSwerveEncoders(&m_drivetrain, 1));
  frc::SmartDashboard::PutData( "CmdCalSwerveEnc_2",     new CmdCalibrateSwerveEncoders(&m_drivetrain, 2));


  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() 
{
  
  m_botDriver_Start.OnTrue(new CmdDriveZeroGyro());

  m_botDriver_Rbumper.OnTrue(new CmdDriveAimAtTarget());

}



frc2::CommandPtr RobotContainer::GetAutonomousCommand() 
{
  return frc2::cmd::Print("No autonomous command configured");
}
