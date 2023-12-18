// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdLogFileEnable.h"
#include "Robot.h"


CmdLogFileEnable::CmdLogFileEnable( bool enable ) 
{
  m_enable = enable;
}

void CmdLogFileEnable::Initialize() 
{
  robotcontainer.m_logFile.LogFileEnable(m_enable);
}
