// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveAimAtTarget.h"
#include "Robot.h"

CmdDriveAimAtTarget::CmdDriveAimAtTarget() 
{
  AddRequirements(&robotcontainer.m_drivetrain);
}

void CmdDriveAimAtTarget::Initialize() 
{
  m_count = 0;  

  if( robotcontainer.m_PhotonVision.IsTargetValid())
    m_calcAngle = robotcontainer.m_drivetrain.GetGyroAngle() + robotcontainer.m_PhotonVision.GetTargetYaw();
  else
    std::cout<< "CmdDriveAimAtTarget: Target Not found" << std::endl;
}

void CmdDriveAimAtTarget::Execute() 
{

  float const MAX_POWER = 0.08;    //0.1;
  float const MIN_POWER = 0.020;   //0.0625;       //Must be > MINIMUM_NEEDED_POWER in drivetrain
  float const TURN_Kp   = 0.010;  //0.005;

  float delta_angle = m_calcAngle - robotcontainer.m_drivetrain.GetGyroAngle();

  float turn_power = abs( delta_angle * TURN_Kp ) + MIN_POWER;

  if( turn_power > MAX_POWER ) turn_power = MAX_POWER;
  if( turn_power < MIN_POWER ) turn_power = MIN_POWER;

  if( delta_angle > 0)
    robotcontainer.m_drivetrain.RobotcentricDrive(0,0,  -turn_power);
  else
    robotcontainer.m_drivetrain.RobotcentricDrive(0,0,   turn_power);

}

void CmdDriveAimAtTarget::End(bool interrupted) 
{
  robotcontainer.m_drivetrain.Stop();
}

bool CmdDriveAimAtTarget::IsFinished() 
{
  float delta_angle = m_calcAngle - robotcontainer.m_drivetrain.GetGyroAngle();
  if(  abs(delta_angle) < 0.5 )
  {

    m_count++;
    if( m_count > 5)
    {
      std::cout << "CmdDriveAimAtTarget final Delta" << delta_angle << std:: endl;
      return true;
    }
  }


  return false;
}
