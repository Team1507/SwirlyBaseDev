#include "commands/AutoFivePieceRedOne.h"

#include "frc2/command/WaitCommand.h"
#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdDriveForceSteerAngle.h"
#include "commands/CmdDriveAimAtTarget.h"
#include "Robot.h"

AutoFivePieceRedOne::AutoFivePieceRedOne() 
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
    CmdDriveToPoint(56.5, 60, 90, 2000, true, 10),
    //Turn to shoot
    CmdDriveTurn2Angle(0.2, -90),
    //Drive and turn to note
    CmdDriveToPoint(115.5, 60, 90, 2000, true, 10),
    //Turn to shoot
    CmdDriveTurn2Angle(0.2, -45),
    //Back Up To Grab Third Piece
    CmdDriveToPoint(132,250,0,3000,true,10),
    //Drive close to speaker
    CmdDriveToPoint(132, 179,0,3000,true,10),
    //Turn to speaker
    CmdDriveTurn2Angle(.2, 45),
    //Code End
    CmdPrintText("Auto Four Piece Red One Ended"),
    CmdDriveStop()
);
}
