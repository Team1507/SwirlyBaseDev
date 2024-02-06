#include "frc2/command/WaitCommand.h"
#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdDriveForceSteerAngle.h"
#include "Robot.h"
#include "commands/AutoTwoPieceBlueThree.h"


AutoTwoPieceBlueThree::AutoTwoPieceBlueThree() {
  
  AddCommands(
    CmdPrintText("Auto Two Piece Blue One Strated"),
    CmdDriveClearAll(),
    frc2::WaitCommand(0.5_s),
    CmdDriveTurn2Angle( 0.2, 45.0 ),
    frc2::WaitCommand( 1.0_s ),
    CmdDriveTurn2Angle( 0.2, -45.0 ),
    CmdDriveToPoint( 0, 60, 0, 2000, true, 10),
    CmdDriveTurn2Angle( 0.2, 45.0 ),
    frc2::WaitCommand( 0.5_s ),
    CmdDriveTurn2Angle( 0.2, -45.0 ),
    CmdPrintText("Auto Two Piece Blue One Ended"),
    CmdDriveStop()
  );
}