#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

class AutoTwoPieceBlueOne
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoTwoPieceBlueOne> {
 public:
  AutoTwoPieceBlueOne();
};
