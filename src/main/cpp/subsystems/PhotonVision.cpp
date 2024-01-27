// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "frc/smartdashboard/SmartDashboard.h"

#include "subsystems/PhotonVision.h"
#include <photon/PhotonUtils.h>
#include <iostream>

#include <units/angle.h>
#include <units/length.h>


PhotonVision::PhotonVision()
{
    frc::SmartDashboard::PutNumber("PV-MT Id",    4 );
};


void PhotonVision::Periodic() 
{

    //Assune the worst
    m_targetValid    = false;
    m_targetYaw      = 0.0;
    m_targetDistance = 0.0;

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

        int  m_targetId    = (int)frc::SmartDashboard::GetNumber("PV-MT Id",    0 );
        int  myTargetIndex = 0;

        //Look for Target Id in list
        for( unsigned int i=0; i<targetList.size(); i++ )
        {
            if( targetList[i].GetFiducialId() == m_targetId)
            {

                m_targetValid = true;
                myTargetIndex = i;
                break;
            }
        }


        //Is target found?
        if(m_targetValid )
        {
            m_targetYaw =  targetList[myTargetIndex].GetYaw();

            const units::meter_t  CAMERA_HEIGHT = 10_in;
            const units::meter_t  TARGET_HEIGHT = 57_in;
            const units::radian_t CAMERA_PITCH  = 25_deg;

            //This function may calculate the floor X-Y distance rather than the hypotenuse distance
            //from camera to AprilTag
            units::meter_t range = photon::PhotonUtils::CalculateDistanceToTarget(
                                        CAMERA_HEIGHT,
                                        TARGET_HEIGHT,
                                        CAMERA_PITCH,
                                        units::degree_t{ targetList[myTargetIndex].GetPitch() }
                                    );

            m_targetDistance = (float)(units::inch_t)range;

        }

    }
    else
    {
        //NO TARGETS DETECTED
        frc::SmartDashboard::PutNumber("PV Tsize", 0  );
        frc::SmartDashboard::PutString("PV Tlist", "" );
    }


    //Status Update
    frc::SmartDashboard::PutBoolean("PV-MT Target", m_targetValid);
    frc::SmartDashboard::PutNumber("PV-MT Yaw",     m_targetYaw  );
    frc::SmartDashboard::PutNumber("PV-MT Range",   m_targetDistance  );

}





  void  PhotonVision::SetTargetId(int id)
  {
    //Using smartdashboard to pick target ID
    //m_targetId = id;
  }
  int   PhotonVision::GetTargetId(void)
  {
    return m_targetId;
  }
  bool  PhotonVision::IsTargetValid(void)
  {
    return m_targetValid;
  }
  float PhotonVision::GetTargetYaw(void)
  {
    if( m_targetValid)
        return m_targetYaw;
    else
        return 0.0;
  }