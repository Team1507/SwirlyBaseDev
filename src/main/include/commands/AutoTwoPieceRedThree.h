#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

class AutoTwoPieceRedThree
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoTwoPieceRedThree> {
 public:
  AutoTwoPieceRedThree();
};
