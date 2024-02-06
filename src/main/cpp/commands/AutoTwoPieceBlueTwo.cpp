
#include "frc2/command/WaitCommand.h"
#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdDriveForceSteerAngle.h"
#include "Robot.h"

#include "commands/AutoTwoPieceBlueTwo.h"


AutoTwoPieceBlueTwo::AutoTwoPieceBlueTwo() {

  AddCommands(
    CmdPrintText("Auto Two Piece Blue Two Started"),
    CmdDriveClearAll(),
    CmdDriveToPoint(0, 60, 0, 2000, true, 10),
    CmdDriveStop(),
    CmdPrintText("Auto Two Piece Blue Two Started")
  );
}
