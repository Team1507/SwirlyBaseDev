// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/GrpTest1.h"
#include "frc2/command/WaitCommand.h"
#include "commands/CmdPrintText.h"
#include "commands/CmdDriveClearAll.h"
#include "commands/CmdDriveStop.h"

#include "commands/CmdLogFileEnable.h"
#include "commands/CmdDriveToPoint.h"

GrpTest1::GrpTest1() {
  AddCommands
  (

    CmdPrintText("GrpTest1 Start"),
    CmdDriveClearAll(),
    frc2::WaitCommand(0.5_s),
    //---------------------------------------


    CmdLogFileEnable(true),

    CmdDriveToPoint( 0.0, 24, 0, 2000, true, 5.0 ),

    CmdLogFileEnable(false),



    //---------------------------------------
    //All Done
    CmdPrintText("GrpTest1 Finished"),
    CmdDriveStop()
  );
}
