#include "commands/AutoFourPieceRedOne.h"

#include "frc2/command/WaitCommand.h"
#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdDriveForceSteerAngle.h"
#include "Robot.h"

AutoFourPieceRedOne::AutoFourPieceRedOne() 
{
  AddCommands(
    CmdPrintText("Auto Four Piece Red One Strated"),
    CmdDriveClearAll(),
    //Turn To Shoot
    CmdDriveTurn2Angle(0.2, -45),
    //Drive Back & Turn To Pickup Piece
    CmdDriveToPoint(0, 50, 0, 2000, true, 10),
    //Shoot Second Piece
    CmdDriveTurn2Angle(0.2, -45),
    //Go to grab third piece
    CmdDriveToPoint(56.5, 65, 90, 2000, true, 10),
    //Turn to shoot
    CmdDriveTurn2Angle(0.2, -90),
    //Drive and turn to note
    CmdDriveToPoint(115.5, 65, 90, 2000, true, 10),
    //Turn to shoot
    CmdDriveTurn2Angle(0.2, -45),
    //Code End
    CmdPrintText("Auto Four Piece Red One Ended"),
    CmdDriveStop()
    ); 
}
