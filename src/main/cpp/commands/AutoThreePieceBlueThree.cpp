#include "commands/AutoThreePieceBlueThree.h"

#include "frc2/command/WaitCommand.h"
#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdDriveForceSteerAngle.h"
#include "Robot.h"

AutoThreePieceBlueThree::AutoThreePieceBlueThree()
{
 AddCommands(
    CmdPrintText("Auto Three Piece Blue Strated"),
    CmdDriveClearAll(),
    //Turn To Shoot
    CmdDriveTurn2Angle(0.2, -45),
    //Drive Back & Turn To Pickup Piece
    CmdDriveToPoint(0, 50, 0, 2000, true, 10),
    //Shoot Second Piece
    CmdDriveTurn2Angle(0.2,-45),
    //Go to grab third piece
    CmdDriveToPoint(56.5, 55, 90, 2000, true, 10),
    //Turn to shoot
    CmdDriveToPoint(0,0,0,3000,true,10),
    //Code End
    CmdPrintText("Auto Three Piece Blue Ended"),
    CmdDriveStop()
    );
}
