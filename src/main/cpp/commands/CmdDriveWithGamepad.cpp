// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/smartdashboard/SmartDashboard.h>

#include "Robot.h"
#include "commands/CmdDriveWithGamepad.h"
#include <cmath>

CmdDriveWithGamepad::CmdDriveWithGamepad() 
{

  m_max_loop_time = -1.0;
  m_min_loop_time =  1.0;

  SetName("CmdDriveWithGamepad");
  AddRequirements( &robotcontainer.m_drivetrain );
}


void CmdDriveWithGamepad::Initialize() 
{
  std::cout<<"Starting CmdDriveWithGamepad"<<std::endl;


}

//Running in Velocity Mode
void CmdDriveWithGamepad::Execute() 
{

  //
  float loop_start_time = (float)frc::Timer::GetFPGATimestamp();

  //Get Gamepad input;
  float leftY  = robotcontainer.m_botDriver.GetLeftY();
  float leftX  = robotcontainer.m_botDriver.GetLeftX();
  float rightX = robotcontainer.m_botDriver.GetRightX();

  bool  testA  = robotcontainer.m_botDriver.GetAButton();  //while pressed

  const float xyMaxVelocity = 19600; //
  const float rMaxVelocity  = 13000; //


  const float xyScaleValue  = 0.7;
  const float rScaleValue   = 0.7;

  const float DEADBAND  = 0.20;

  // //Square Inputs???
  // leftY  = ( leftY  < 0 ) ? -pow(  leftY,  2) : pow(  leftY,  2);
  // leftX  = ( leftX  < 0 ) ? -pow(  leftX,  2) : pow(  leftX,  2);
  // rightX = ( rightX < 0 ) ? -pow( rightX,  2) : pow( rightX,  2);

  // Re-apply deadband - bad controller
  //Apply DeadBand
  if (fabs(leftY)  < DEADBAND) leftY  = 0;
  if (fabs(leftX)  < DEADBAND) leftX  = 0;
  if (fabs(rightX) < DEADBAND) rightX = 0;

  //Subtract off deadband for smooth transition 
  if (fabs(leftY) >= DEADBAND) leftY  +=   (leftY>0)? -DEADBAND : +DEADBAND;
  if (fabs(leftX) >= DEADBAND) leftX  +=   (leftX>0)? -DEADBAND : +DEADBAND;
  if (fabs(rightX)>= DEADBAND) rightX +=  (rightX>0)? -DEADBAND : +DEADBAND;


  //Apply max velocity and scaling
  float fwdrev    = -(leftY  * xyMaxVelocity * xyScaleValue);    //Invert Axis, make positive forward
  float rightleft =  (leftX  * xyMaxVelocity * xyScaleValue);    
  float rotate    = -(rightX * rMaxVelocity  * rScaleValue);     //Invert Axis, make positive CCW


  //On the move aim test
  if(testA )
  {

    float delta_angle = robotcontainer.m_PhotonVision.GetTargetYaw();

    float turn_velocity = delta_angle *400.0;

    if( turn_velocity >  3000.0 ) turn_velocity =  3000.0;
    if( turn_velocity < -3000.0 ) turn_velocity = -3000.0;

    rotate = -turn_velocity;

    frc::SmartDashboard::PutNumber("TestA TurnVelocity", turn_velocity);
    
  }


  if( robotcontainer.m_drivetrain.GetDriveType() == Drivetrain::ROBOTCENTRIC )
    robotcontainer.m_drivetrain.RobotcentricDriveVelocity( fwdrev,  rightleft,  rotate );
  else
    robotcontainer.m_drivetrain.FieldcentricDriveVelocity( fwdrev,  rightleft,  rotate );


  float loop_time = (float)frc::Timer::GetFPGATimestamp() - loop_start_time;

  if( loop_time > m_max_loop_time ) m_max_loop_time = loop_time;
  if( loop_time < m_min_loop_time ) m_min_loop_time = loop_time;

  frc::SmartDashboard::PutNumber("Loop Max", m_max_loop_time);
  frc::SmartDashboard::PutNumber("Loop Min", m_min_loop_time);

  frc::SmartDashboard::PutNumber("DrvleftY", leftY);
  frc::SmartDashboard::PutNumber("DrvleftX", leftX);
  frc::SmartDashboard::PutNumber("DrvrightX", rightX);

}


void CmdDriveWithGamepad::End(bool interrupted) 
{
  std::cout<<"End CmdDriveWithGamepad " << interrupted <<std::endl;
}

bool CmdDriveWithGamepad::IsFinished() 
{
  return false;
}
