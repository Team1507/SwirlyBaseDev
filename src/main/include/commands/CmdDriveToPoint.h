// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Timer.h>

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdDriveToPoint
    : public frc2::CommandHelper<frc2::Command, CmdDriveToPoint> {
 public:
  CmdDriveToPoint( float x, float y, float heading, float velocity, bool stop, float timeout);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:

  float m_finalX;
  float m_finalY;
  float m_finalH;

  float m_velocity;
  bool  m_stop;
  float m_timeout;

  bool  m_closeEnough;

  frc::Timer m_timer;


};
