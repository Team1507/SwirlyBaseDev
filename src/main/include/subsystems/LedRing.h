// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/AddressableLED.h>

class LedRing : public frc2::SubsystemBase {
 public:
  LedRing();

  void Periodic() override;
  void LedRingPeriodic(void);


 private:

  static const int kLEDLength  = 36;
  static const int kLEDPWMPort = 0;
  frc::AddressableLED m_led{kLEDPWMPort};
  std::array<frc::AddressableLED::LEDData, kLEDLength> m_ledBuffer;

  //Rotation
  int m_index;
  int m_count;


  void SetData(void);
  void SetAllLEDColor( int r, int g, int b);
  void SetOneLEDColor(int LEDNum, int r, int g, int b);
  void ClearBuffer( void );


};
