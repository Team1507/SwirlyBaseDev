#include "commands/AutoThreePieceRedThree.h"

#include "frc2/command/WaitCommand.h"
#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdDriveForceSteerAngle.h"
#include "commands/CmdDriveAimAtTarget.h"
#include "Robot.h"


AutoThreePieceRedThree::AutoThreePieceRedThree() 
{
  AddCommands(
    CmdPrintText("Auto Three Piece Red Three Strated"),
    CmdDriveClearAll(),
    //Turn to shoot
    CmdDriveTurn2Angle(0.2,45),
    //Drive to grab second piece
    CmdDriveToPoint(0,55,0,3000,true,10),
    //Turn to shoot
    CmdDriveTurn2Angle(0.2,45),
    //Back Up To Grab Third Piece
    CmdDriveToPoint(7,212,0,3000,true,10),
    //Drive close to speaker
    CmdDriveToPoint(0,150,0,3000,true,10),
    CmdDriveAimAtTarget(),
    CmdPrintText("Auto Three Piece Red Ended"),
    CmdDriveStop()
  );
}
