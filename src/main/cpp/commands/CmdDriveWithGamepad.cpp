// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "commands/CmdDriveWithGamepad.h"

CmdDriveWithGamepad::CmdDriveWithGamepad() 
{


  AddRequirements( &robotcontainer.m_drivetrain );
}


void CmdDriveWithGamepad::Initialize() 
{
  std::cout<<"Starting CmdDriveWithGamepad"<<std::endl;


}


void CmdDriveWithGamepad::Execute() 
{

}


void CmdDriveWithGamepad::End(bool interrupted) 
{
  std::cout<<"End CmdDriveWithGamepad " << interrupted <<std::endl;
}

bool CmdDriveWithGamepad::IsFinished() 
{
  return false;
}
