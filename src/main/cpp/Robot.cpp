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
  std::cout<<"FRC2023: SwirlyBaseDev"<<std::endl;
  std::cout<<"Version: " << __DATE__ <<"  "<<__TIME__<<std::endl<<std::endl; 
}

void Robot::RobotPeriodic() 
{
  frc2::CommandScheduler::GetInstance().Run();
  WriteToSmartDashboard();
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
  frc::SmartDashboard::PutNumber("Xbox Left-Y",   robotcontainer.m_xbox.GetLeftY()    ); 
  frc::SmartDashboard::PutNumber("Xbox Left-X",   robotcontainer.m_xbox.GetLeftX()    ); 
  frc::SmartDashboard::PutNumber("Xbox Right-X",  robotcontainer.m_xbox.GetRightX()   ); 





  //Time
  frc::SmartDashboard::PutNumber("FPGATime1",  (double)robotcontainer.m_timer.GetFPGATimestamp() );   //(double) sec
  frc::SmartDashboard::PutNumber("FPGATime2",  (double)frc::Timer::GetFPGATimestamp() );              //(double) sec
  frc::SmartDashboard::PutNumber("TimeGet",    (double)robotcontainer.m_timer.Get() );                //Manual Timer sec
  frc::SmartDashboard::PutNumber("MatchTime",  (double)robotcontainer.m_timer.GetMatchTime() );       //Match Time


}


