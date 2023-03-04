// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer* RobotContainer::mp_RobotContainer = NULL;
RobotContainer::RobotContainer() {
  // Set drive with controller to run as default
  m_DriveTrain.SetDefaultCommand(std::move(m_DriveWithController));
  m_ArmSubsystem.SetDefaultCommand(std::move(m_MoveArmWithController));
  // Set auto state to false
  m_DriveTrain.setAutoState(false);

  //Zero Gyro
  m_Gyro.zeroGyro();

  // Configure the button bindings
  ConfigureButtonBindings();
  
  // Auto
  m_AutoMode.SetDefaultOption("Default", new frc2::PrintCommand("Default"));
  m_AutoMode.AddOption("None", new frc2::PrintCommand("No Auto"));
  //m_AutoMode.AddOption("Middle Without Score", new MiddleAutoNoScore(&m_DriveTrain, &m_Gyro));
  //m_AutoMode.AddOption("Blue Short Without Score", new BlueShortAutoNoScore(&m_DriveTrain, &m_Gyro));
  //m_AutoMode.AddOption("Blue Long Without Score", new BlueLongAutoNoScore(&m_DriveTrain, &m_Gyro));
  //m_AutoMode.AddOption("Red Short Without Score", new RedShortAutoNoScore(&m_DriveTrain, &m_Gyro));
  //m_AutoMode.AddOption("Red Long Without Score", new RedLongAutoNoScore(&m_DriveTrain, &m_Gyro));

  frc::Shuffleboard::GetTab("Drive").Add("AutoMode", m_AutoMode).WithWidget(frc::BuiltInWidgets::kComboBoxChooser);
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  m_DriverAButton.OnTrue(&m_ToggleDriveMode);
}

// Runs when auto starts
void RobotContainer::AutoStart() {
   m_LimeLight.setMode(LimeLightSubsystem::CamMode::vision);
}

// Runs when TeleOp Starts
void RobotContainer::TeleOpStart() {
  m_LimeLight.setMode(LimeLightSubsystem::CamMode::driveCam);
}


frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return m_AutoMode.GetSelected();
}
