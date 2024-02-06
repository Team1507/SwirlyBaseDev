#include "commands/AutoTwoPieceTest.h"

#include "frc2/command/WaitCommand.h"
#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"
#include "commands/CmdDriveToPoint.h"
#include "commands/CmdDriveTurn2Angle.h"
#include "commands/CmdDriveForceSteerAngle.h"
#include "commands/CmdDriveAimAtTarget.h"
#include "Robot.h"

AutoTwoPieceTest::AutoTwoPieceTest() 
{
  AddCommands(
    CmdPrintText("Test Auto Started"),
    CmdDriveClearAll(),
    CmdDriveAimAtTarget(),
    CmdDriveToPoint(60,0,0,2000,true,10),
    CmdDriveAimAtTarget(),
    CmdDriveStop(),
    CmdPrintText("Test Auto Finished")
  );
}
