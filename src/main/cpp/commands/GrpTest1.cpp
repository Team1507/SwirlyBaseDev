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
#include "commands/CmdDriveTurn2Angle.h"

GrpTest1::GrpTest1() {
  AddCommands
  (

    CmdPrintText("GrpTest1 Start"),
    CmdDriveClearAll(),
    frc2::WaitCommand(0.5_s),
    //---------------------------------------


    //CmdLogFileEnable(true),

    // CmdDriveToPoint(   0, 60, 0, 2000, false, 10.0 ),
    // CmdDriveToPoint( -60, 60, 0, 2000, false, 10.0 ),
    // CmdDriveToPoint( -60,  0, 0, 2000, false, 10.0 ),
    // CmdDriveToPoint(   0,  0, 0, 2000, true, 10.0 ),

    // CmdDriveToPoint( -60, 60, 0, 2000, false, 10.0 ),
    // CmdDriveToPoint(   0, 60, 0, 2000, false, 10.0 ),
    // CmdDriveToPoint( -60,  0, 0, 2000, false, 10.0 ),
    // CmdDriveToPoint(   0,  0, 0, 2000, true,  10.0 ),

    // CmdDriveToPoint( -60, 60, -90, 2000, false, 10.0 ),
    // CmdDriveToPoint(   0, 60,   0, 2000, false, 10.0 ),
    // CmdDriveToPoint( -60,  0,  90, 2000, false, 10.0 ),
    // CmdDriveToPoint(   0,  0,   0, 2000, true,  10.0 ),


    //CmdLogFileEnable(false),

    
    //Auto Testing....

    //Turn towards target and shoot
    CmdDriveTurn2Angle( 0.35, 45.0 ),
    frc2::WaitCommand( 1.0_s ),
    CmdDriveTurn2Angle( 0.35, -45.0 ),

    //Drive to next note
    CmdDriveToPoint(   0, 45, 0, 6000, true, 10.0 ),

    frc2::WaitCommand( 0.5_s ),


    //Shoot second note
    CmdDriveTurn2Angle( 0.35, 30.0 ),
    frc2::WaitCommand( 1.0_s ),
    CmdDriveTurn2Angle( 0.35, -30.0 ),


    //Drive to Third note and back
    CmdDriveToPoint(   0, 100, 0, 8000, true, 10.0 ),
    CmdDriveToPoint(   0, 45,  0, 8000, true, 10.0 ),


    //Shoot Third note
    CmdDriveTurn2Angle( 0.25, 30.0 ),
    frc2::WaitCommand( 1.0_s ),
    CmdDriveTurn2Angle( 0.25, -30.0 ),


    //---------------------------------------
    //All Done
    CmdPrintText("GrpTest1 Finished"),
    CmdDriveStop()
  );
}
