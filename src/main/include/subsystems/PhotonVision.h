// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <photon/PhotonCamera.h>

class PhotonVision : public frc2::SubsystemBase {
 public:
  PhotonVision();


  void Periodic() override;

 private:

  //photon::PhotonCamera camera{"photonvision"};
  photon::PhotonCamera camera{"Shooter-cam"};



};
