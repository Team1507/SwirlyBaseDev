// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>


//THIS IS A GLOBAL VARIABLE
RobotContainer robotcontainer;

void WriteToSmartDashboard(void);


void Robot::RobotInit() 
{
  //*************************** INIT ******************************
  std::cout<<"RobotInit"<<std::endl;
  std::cout<<"FRC2024: SwirlyBaseDev2024"<<std::endl;
  std::cout<<"Version: " << __DATE__ <<"  "<<__TIME__<<std::endl<<std::endl; 
  //GithubTest



  //Drivetrain Init
  robotcontainer.m_drivetrain.Stop();
  robotcontainer.m_drivetrain.HardResetDriveEncoders();
  robotcontainer.m_drivetrain.ResetSteerEncoders();
  robotcontainer.m_drivetrain.ZeroGyro(); 
  robotcontainer.m_drivetrain.ResetOdometry();

  //Subsystem Initialization


}

void Robot::RobotPeriodic() 
{

  robotcontainer.m_logFile.LogFilePeriodic();

  frc2::CommandScheduler::GetInstance().Run();
  WriteToSmartDashboard();

  robotcontainer.m_ledRing.LedRingPeriodic();
}

void Robot::DisabledInit() 
{
  std::cout<<"Disabled Init"<<std::endl;
}

void Robot::DisabledPeriodic() {}

void Robot::DisabledExit() {}

void Robot::AutonomousInit() 
{
  std::cout<<" **** Auto Init ******"<<std::endl;
  m_autonomousCommand = robotcontainer.GetAutonomousCommand();

  if (m_autonomousCommand) {
    m_autonomousCommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}
void Robot::AutonomousExit() {}

void Robot::TeleopInit() 
{
  std::cout<<"Teleop Init"<<std::endl;

  //Clean up any leftovers from Autonomous
  if (m_autonomousCommand) {
    m_autonomousCommand->Cancel();
  }
}

void Robot::TeleopPeriodic() {}
void Robot::TeleopExit() {}
void Robot::TestInit() {
  frc2::CommandScheduler::GetInstance().CancelAll();
}
void Robot::TestPeriodic() {}
void Robot::TestExit() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif



void WriteToSmartDashboard(void)
{


  //XBox Controllers
  frc::SmartDashboard::PutNumber("Xbox Left-Y",   robotcontainer.m_botDriver.GetLeftY()    ); 
  frc::SmartDashboard::PutNumber("Xbox Left-X",   robotcontainer.m_botDriver.GetLeftX()    ); 
  frc::SmartDashboard::PutNumber("Xbox Right-X",  robotcontainer.m_botDriver.GetRightX()   ); 


  //Nax-X
  frc::SmartDashboard::PutBoolean("navx_IsConn",  robotcontainer.m_drivetrain.IsGyroConnected() );
  frc::SmartDashboard::PutNumber("navx_Yaw",      robotcontainer.m_drivetrain.GetGyroYaw()      );
  frc::SmartDashboard::PutNumber("navx_Angle",    robotcontainer.m_drivetrain.GetGyroAngle()    );

  //Odometry
  frc::SmartDashboard::PutNumber("odo_X",         robotcontainer.m_drivetrain.GetOdometryX()       );
  frc::SmartDashboard::PutNumber("odo_Y",         robotcontainer.m_drivetrain.GetOdometryY()       );
  frc::SmartDashboard::PutNumber("odo_H",         robotcontainer.m_drivetrain.GetOdometryHeading() );

  //Time
  frc::SmartDashboard::PutNumber("FPGATime1",  (double)robotcontainer.m_timer.GetFPGATimestamp() );   //(double) sec
  frc::SmartDashboard::PutNumber("FPGATime2",  (double)frc::Timer::GetFPGATimestamp() );              //(double) sec
  frc::SmartDashboard::PutNumber("TimeGet",    (double)robotcontainer.m_timer.Get() );                //Manual Timer sec
  frc::SmartDashboard::PutNumber("MatchTime",  (double)robotcontainer.m_timer.GetMatchTime() );       //Match Time

  //Debug/Logging
  frc::SmartDashboard::PutBoolean("Logging",  robotcontainer.m_logFile.IsLogFileEnabled() );


}


