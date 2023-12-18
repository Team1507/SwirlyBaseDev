// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveToPoint.h"
#include "Robot.h"

CmdDriveToPoint::CmdDriveToPoint(float x, float y, float heading, float velocity, bool stop, float timeout) 
{

  m_finalX   = x;
  m_finalY   = y;
  m_finalH   = heading;

  m_velocity = velocity;
  m_stop     = stop;
  m_timeout  = timeout;

  m_closeEnough = false;

  
  AddRequirements( &robotcontainer.m_drivetrain );
}

void CmdDriveToPoint::Initialize() 
{

  m_closeEnough = false;

  //Start Timer if Timeout is set
  if( m_timeout > 0.0 )
  {
      m_timer.Reset();
      m_timer.Start();
  }
}


void CmdDriveToPoint::Execute() 
{

  //-------------------------------------
  //  Directional Computations

  //distance
  float delta_x  = m_finalX - robotcontainer.m_drivetrain.GetOdometryX();
  float delta_y  = m_finalY - robotcontainer.m_drivetrain.GetOdometryY();
  float distance = sqrtf( delta_x*delta_x + delta_y*delta_y );


  //Are we close enough?
  const float CLOSE_ENOUGH = 2.0; 
  if( distance <= CLOSE_ENOUGH )
  {
    m_closeEnough = true;
  }


  //Unit vectors
  float ux = delta_x / distance;
  float uy = delta_y / distance;

  //velocity
  float vx = ux * m_velocity;
  float vy = uy * m_velocity;

  //ToDo:  Slow down approaching coordinate.


  //-------------------------------------
  //  Rotational correction

  //Min turn power is 0.0625.
  //  Set Kp to reach min turn power at 2 deg error  (Kp = min/error = 0.0625/2  )
  float const TURN_MAX_VELOCITY = 5300;   // .25 power
  float const TURN_Kp           = 300 ;   //0.0175;

  float delta_angle   = m_finalH - robotcontainer.m_drivetrain.GetGyroAngle();

  float vr = abs( delta_angle * TURN_Kp );

  //Limit max drive
  if( vr > TURN_MAX_VELOCITY ) vr = TURN_MAX_VELOCITY;


  //ToDo:  Handle -180/180 crossover.


  //Write answers to drivetrain.....

  if( delta_angle > 0)
    robotcontainer.m_drivetrain.FieldcentricDriveVelocity( vy, vx, -vr);
  else
    robotcontainer.m_drivetrain.FieldcentricDriveVelocity( vy, vx,  vr);




}


void CmdDriveToPoint::End(bool interrupted) 
{
  if(m_stop)
    robotcontainer.m_drivetrain.Stop();
}


bool CmdDriveToPoint::IsFinished() 
{


  //Check Distance
  if( m_closeEnough )
  {
      std::cout<<"CmdDriveToPoint: CloseEnough"<<std::endl;
      return true;
  }

  //Check timer
  if ((m_timeout>0.0) && m_timer.HasElapsed( units::second_t(m_timeout) ) )
  {
      m_timer.Stop();
      std::cout<<"CmdDriveToPoint: Timeout"<<std::endl;
      return true;
  }


  return false;
}
