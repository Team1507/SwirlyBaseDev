#include "commands/AutoFourPieceBlueTwo.h"

#include "frc2/command/WaitCommand.h"
#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdDriveForceSteerAngle.h"
#include "Robot.h"

AutoFourPieceBlueTwo::AutoFourPieceBlueTwo() 
{
  AddCommands(
    CmdPrintText("Auto Four Piece Blue Two Started"),
    CmdDriveClearAll(),
    //Shoot Note
    CmdDriveToPoint(0, 40, 0, 2000, true, 10),
    //Shoot Note
    CmdDriveToPoint(-50, 0, 0, 2000, true, 10),
    CmdDriveTurn2Angle(0.2, -45),
    //Shoot Note
    CmdDriveTurn2Angle(0.2, 45),
    CmdDriveToPoint(-19, 0, 0, 2000, true, 10),
    CmdDriveToPoint(0, -211, 0, 2000, true, 10),
    CmdDriveToPoint(0, 96, 0, 2000, true, 10),
    CmdDriveTurn2Angle(0.2, -45),
    //Shoot Note
    CmdPrintText("Auto Four Piece Blue Two Ended"),
    CmdDriveStop()
  );
}
