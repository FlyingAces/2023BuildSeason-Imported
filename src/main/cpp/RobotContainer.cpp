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
  m_AutoMode.SetDefaultOption("Main Auto", new MainAuto(&m_DriveTrain, &m_Gyro));
  m_AutoMode.AddOption("None", new frc2::PrintCommand("No Auto"));
  frc::Shuffleboard::GetTab("Drive").Add("AutoMode", m_AutoMode).WithWidget(frc::BuiltInWidgets::kComboBoxChooser);
  frc::Shuffleboard::GetTab("Drive").Add("Pitch", 0).GetEntry();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  //m_DriverYButton.WhileTrue(&m_PIDLevel);

  // Should run both tilt and extend pid commands to attain a certain hieght/extension
  // Needs Testing
  //m_DriverAButton.OnTrue(new frc2::ParallelCommandGroup(m_ArmExtendTopCone, m_ArmTiltTopCone));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return m_AutoMode.GetSelected();
}
