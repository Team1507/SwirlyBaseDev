#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

class AutoTwoPieceRedOne
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoTwoPieceRedOne> {
 public:
  AutoTwoPieceRedOne();
};
