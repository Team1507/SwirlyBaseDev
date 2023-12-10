// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "commands/CmdDriveWithGamepad.h"
#include <cmath>

CmdDriveWithGamepad::CmdDriveWithGamepad() 
{
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

  //Get Gamepad input;
  float leftY  = robotcontainer.m_xbox.GetLeftY();
  float leftX  = robotcontainer.m_xbox.GetLeftX();
  float rightX = robotcontainer.m_xbox.GetRightX();

  const float xyMaxVelocity = 19600; //
  const float rMaxVelocity  = 13000; //

  const float xyScaleValue  = 0.5;
  const float rScaleValue   = 0.3;


  //Square Inputs???
  leftY  = ( leftY  < 0 ) ? -pow(  leftY,  2) : pow(  leftY,  2);
  leftX  = ( leftX  < 0 ) ? -pow(  leftX,  2) : pow(  leftX,  2);
  rightX = ( rightX < 0 ) ? -pow( rightX,  2) : pow( rightX,  2);

  //Apply max velocity and scaling
  float fwdrev    = -(leftY  * xyMaxVelocity * xyScaleValue);    //Invert Axis, make positive forward
  float rightleft =  (leftX  * xyMaxVelocity * xyScaleValue);    
  float rotate    = -(rightX * rMaxVelocity  * rScaleValue);     //Invert Axis, make positive CCW

  if( robotcontainer.m_drivetrain.GetDriveType() == Drivetrain::ROBOTCENTRIC )
    robotcontainer.m_drivetrain.RobotcentricDriveVelocity( fwdrev,  rightleft,  rotate );
  else
    robotcontainer.m_drivetrain.FieldcentricDriveVelocity( fwdrev,  rightleft,  rotate );


}


void CmdDriveWithGamepad::End(bool interrupted) 
{
  std::cout<<"End CmdDriveWithGamepad " << interrupted <<std::endl;
}

bool CmdDriveWithGamepad::IsFinished() 
{
  return false;
}
