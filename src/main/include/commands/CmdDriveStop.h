

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/InstantCommand.h>

class CmdDriveStop
    : public frc2::CommandHelper<frc2::InstantCommand,
                                 CmdDriveStop> {
 public:
  CmdDriveStop();

  void Initialize() override;
};
