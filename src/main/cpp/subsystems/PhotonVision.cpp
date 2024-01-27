// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "frc/smartdashboard/SmartDashboard.h"

#include "subsystems/PhotonVision.h"
#include <photon/PhotonUtils.h>
#include <iostream>




PhotonVision::PhotonVision()
{
    frc::SmartDashboard::PutNumber("PV-MT Id",    4 );
};


void PhotonVision::Periodic() 
{
    // Query the latest result from PhotonVision
    photon::PhotonPipelineResult result = camera.GetLatestResult();


    bool hasTargets = result.HasTargets();

    frc::SmartDashboard::PutBoolean("PV HasTarget", hasTargets);


    std::string strTargetList = "";

    if( hasTargets )
    {

        //---- Best Target --------------------------

        photon::PhotonTrackedTarget bestTarget = result.GetBestTarget();

        frc::SmartDashboard::PutNumber("PV-BT Id",    bestTarget.GetFiducialId() );
        frc::SmartDashboard::PutNumber("PV-BT Yaw",   bestTarget.GetYaw() );
  

        //---- All Target List --------------------------

        std::span<const photon::PhotonTrackedTarget> targetList = result.GetTargets();

        frc::SmartDashboard::PutNumber("PV Tsize",  targetList.size() );

        for( unsigned int i=0; i<targetList.size(); i++ )
        {
            strTargetList += std::to_string(  targetList[i].GetFiducialId() );
            strTargetList += " ";
        }
        frc::SmartDashboard::PutString("PV Tlist", strTargetList );


        //---- Specific Target --------------------------

        int  myTargetId    = (int)frc::SmartDashboard::GetNumber("PV-MT Id",    0 );

        bool myTargetFound = false;
        int  myTargetIndex = 0;

        //Look for Target Id in list
        for( unsigned int i=0; i<targetList.size(); i++ )
        {
            if( targetList[i].GetFiducialId() == myTargetId)
            {

                myTargetFound = true;
                myTargetIndex = i;
                break;
            }
        }

        //Is target found?
        frc::SmartDashboard::PutBoolean("PV-MT Target", myTargetFound);

        if(myTargetFound )
        {
            frc::SmartDashboard::PutNumber("PV-MT Yaw",   targetList[myTargetIndex].GetYaw() );
        }


    }
    else
    {
        //NO TARGETS DETECTED
        frc::SmartDashboard::PutNumber("PV Tsize", 0  );
        frc::SmartDashboard::PutString("PV Tlist", "" );

        frc::SmartDashboard::PutBoolean("PV-MT Target", false);
    }


    


}
