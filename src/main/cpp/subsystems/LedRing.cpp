// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LedRing.h"

#include "frc/DriverStation.h"
#include "Robot.h"

LedRing::LedRing()
{
    m_led.SetLength(kLEDLength);
    m_led.SetData(m_ledBuffer);
    m_led.Start();

    m_index = 0;
    m_count = 0;

};

void LedRing::Periodic() {}


void LedRing::LedRingPeriodic(void) 
{

    if( frc::DriverStation::IsDisabled() )
    {
        //20ms = 50 tick/sec
        if( m_count++ > 1 )
        {
            m_count = 0;
            ClearBuffer();

            const int   led_tail_length = 6;
            const float led_tail_gain   = 0.6;

            int r = 0;
            int g = 0;
            int b = 255;

            SetOneLEDColor(m_index,    r,g,b); 
            SetOneLEDColor(m_index+12 ,r,g,b); 
            SetOneLEDColor(m_index+24 ,r,g,b); 
            
            for(int i=0;i<led_tail_length;i++)
            {
                r =  (int)((float)r * led_tail_gain);
                g =  (int)((float)g * led_tail_gain);
                b =  (int)((float)b * led_tail_gain);
                SetOneLEDColor(m_index-i,   r,g,b);    
                SetOneLEDColor(m_index-i+12,r,g,b);    
                SetOneLEDColor(m_index-i+24,r,g,b);    
            }

            m_index++;
            if( m_index>=kLEDLength)
                m_index=0;

            SetData();
        }        
    }

    //FieldCentric Drive
    if( frc::DriverStation::IsEnabled() && (robotcontainer.m_drivetrain.GetDriveType() == robotcontainer.m_drivetrain.FIELDCENTRIC) )
    {


        float heading  = robotcontainer.m_drivetrain.GetGyroYaw();
        int   frontLed = (int)(heading/10);

        frontLed = -frontLed;

        ClearBuffer();
        SetOneLEDColor(frontLed,    0,0,175);
        SetOneLEDColor(frontLed+9,  0,175,0);
        SetOneLEDColor(frontLed-9,  175,0,0);
        SetOneLEDColor(frontLed+18, 100,100,100); //White
        SetData();
    }

    //RobotCentric Drive
    if( frc::DriverStation::IsEnabled() && (robotcontainer.m_drivetrain.GetDriveType() == robotcontainer.m_drivetrain.ROBOTCENTRIC) )
    {
        ClearBuffer();
        SetOneLEDColor(0,   0,0,175);
        SetOneLEDColor(9,   0,175,0);
        SetOneLEDColor(27,  175,0,0);
        SetOneLEDColor(18,  100,100,100); //White
        SetData();
    }



}


void LedRing::SetAllLEDColor(int r, int g, int b)
{
    for(int i = 0; i < kLEDLength; i++)
    {
        m_ledBuffer[i].SetRGB( r, g, b);
    }
    m_led.SetData(m_ledBuffer);
}

//Adjusts for negative and overloaded Led Number
void LedRing::SetOneLEDColor(int LEDNum, int r, int g, int b)
{
    if( LEDNum < 0)
        m_ledBuffer[LEDNum+kLEDLength].SetRGB( r, g, b);
    else if( LEDNum >= kLEDLength)
        m_ledBuffer[LEDNum-kLEDLength].SetRGB( r, g, b); 
    else
        m_ledBuffer[LEDNum].SetRGB( r, g, b); 
}


void LedRing::ClearBuffer( void )
{
    for(int i = 0; i < kLEDLength; i++)
    {
        m_ledBuffer[i].SetRGB(0,0,0);
    }
}
void LedRing::SetData(void)
{
    m_led.SetData(m_ledBuffer);
}

