// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveTrainSubsystem.h"

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>

DriveTrainSubsystem::DriveTrainSubsystem(frc::XboxController* p_Controller) : mp_Controller{p_Controller} {
    // Implementation of subsystem constructor goes here.
    SetName("DriveTrain");
    SetSubsystem("DriveTrain");

    // Config
    m_RightLeader.ConfigFactoryDefault();
    m_RightFollower.ConfigFactoryDefault();
    m_LeftLeader.ConfigFactoryDefault();
    m_LeftFollower.ConfigFactoryDefault();

    m_RightLeader.SetNeutralMode(Brake);
    m_RightFollower.SetNeutralMode(Brake);
    m_LeftLeader.SetNeutralMode(Brake);
    m_LeftFollower.SetNeutralMode(Brake);

    m_RightLeader.ConfigOpenloopRamp(0.2);
    m_RightFollower.ConfigOpenloopRamp(0.2);
    m_LeftLeader.ConfigOpenloopRamp(0.2);
    m_LeftFollower.ConfigOpenloopRamp(0.2);

    m_LeftLeader.SetInverted(true);
    m_LeftFollower.SetInverted(true);

    m_DifferentialDrive.SetSafetyEnabled(false);

    m_RightLeader.SetSelectedSensorPosition(0.0);
    m_RightFollower.SetSelectedSensorPosition(0.0);
    m_LeftLeader.SetSelectedSensorPosition(0.0);
    m_LeftFollower.SetSelectedSensorPosition(0.0);

    setAutoState(false);
}

void DriveTrainSubsystem::arcadeDrive(double speed, double rotation) {

    m_DifferentialDrive.ArcadeDrive(speed, rotation, false);

}

// Now fully drives with left joystick
// Y axis is forward/backwards
// X axis is right/left
void DriveTrainSubsystem::driveWithController() {
  m_controllerDriveSpeed = (mp_Controller->GetRightTriggerAxis() - mp_Controller->GetLeftTriggerAxis()) * m_DriveSpeedMult;
  m_controllerRotation = mp_Controller->GetLeftX() * m_RotationSpeedMult;
  m_DifferentialDrive.ArcadeDrive(m_controllerDriveSpeed, m_controllerRotation, false);
}

void DriveTrainSubsystem::tankDrive(double left, double right){

  m_DifferentialDrive.TankDrive(left, right);
}

double DriveTrainSubsystem::getAvgEncoderPosition(){

  return (m_LeftLeader.GetSelectedSensorPosition(0) + m_RightLeader.GetSelectedSensorPosition(0)) / 2;
}


// NOT WORK
void DriveTrainSubsystem::zeroDTEncoders(){

  m_LeftLeader.SetSelectedSensorPosition(0);
  m_RightLeader.SetSelectedSensorPosition(0);
}

void DriveTrainSubsystem::toggleDriveMode(){
  m_DriveMode = !m_DriveMode;
  if(m_DriveMode){
    m_DriveSpeedMult = DT_CONSTANTS::CONTROLLER_TURN_MULT_FULL;
    m_RotationSpeedMult = DT_CONSTANTS::CONTROLLER_TURN_MULT_FULL;
  }
  else{
    m_DriveSpeedMult = DT_CONSTANTS::CONTROLLER_DRIVE_MULT_HALF;
    m_RotationSpeedMult = DT_CONSTANTS::CONTROLLER_TURN_MULT_HALF;
  }
}

units::meter_t DriveTrainSubsystem::getLeftDist() {
  return units::meter_t((m_LeftLeader.GetSelectedSensorPosition()/(DT_CONSTANTS::PULSES_PER_REV*DT_CONSTANTS::GEAR_RATIO)) * (DT_CONSTANTS::PI*DT_CONSTANTS::WHEEL_DIAMETER_M));
}

units::meter_t DriveTrainSubsystem::getRightDist() {
  return units::meter_t((m_RightLeader.GetSelectedSensorPosition()/(DT_CONSTANTS::PULSES_PER_REV*DT_CONSTANTS::GEAR_RATIO)) * (DT_CONSTANTS::PI*DT_CONSTANTS::WHEEL_DIAMETER_M));
}

void DriveTrainSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}
