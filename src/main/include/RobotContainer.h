// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/XboxController.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardLayout.h>
#include <frc/shuffleboard/ShuffleboardTab.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include <frc2/command/Command.h>
#include <frc2/command/button/Button.h>

#include "subsystems/DriveTrainSubsystem.h"
#include "subsystems/GyroSubsystem.h"
#include "subsystems/LimeLightSubsystem.h"

#include "commands/DriveCommands/AutoLevel.h"
#include "commands/DriveCommands/DriveWithController.h"
#include "commands/ToggleCommands/ToggleDriveMode.h"
#include "commands/AimingCommands/VisionAim.h"
#include "commands/AutoCommands/MainAuto.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  static RobotContainer* mp_RobotContainer;
  static RobotContainer* GetInstance(){
    if(mp_RobotContainer == NULL) mp_RobotContainer = new RobotContainer();
    return mp_RobotContainer;
  }

  frc2::Command* GetAutonomousCommand();
  void RobotInit();

 private:
  RobotContainer();

  void ConfigureButtonBindings();
  // Choose Auto
  frc::SendableChooser<frc2::Command*> m_AutoMode;


  // Create controller and button objects
  frc::XboxController m_DriverController{0};
  frc2::Button m_DriverButtonY { [&] { return m_DriverController.GetYButton(); }};
  frc2::Button m_DriverButtonA { [&] { return m_DriverController.GetAButton(); }};

  // Create subsystem objects
  DriveTrainSubsystem m_DriveTrain{&m_DriverController};
  GyroSubsystem m_Gyro;
  LimeLightSubsystem m_LimeLight;

  // Create Commands
  AutoLevel m_AutoLevel{&m_DriveTrain, &m_Gyro};
  DriveWithController m_DriveWithController{&m_DriveTrain};
  ToggleDriveMode m_ToggleDriveMode{&m_DriveTrain};
  VisionAim m_VisionAim{&m_DriveTrain, &m_LimeLight};

  // Drive Straight test when button pressed
  DriveStraightPID m_DriveStraightWhenPress{&m_DriveTrain, 1_m};
};
