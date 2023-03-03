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
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/PrintCommand.h>
#include <frc2/command/button/Trigger.h>

#include "subsystems/DriveTrainSubsystem.h"
#include "subsystems/GyroSubsystem.h"
#include "subsystems/LimeLightSubsystem.h"

#include "commands/LevelCommands/AutoLevel.h"
#include "commands/DriveCommands/DriveWithController.h"
#include "commands/DriveCommands/DriveStraightPID.h"
#include "commands/ArmCommands/MoveArmWithController.h"
#include "commands/ToggleCommands/ToggleDriveMode.h"
#include "commands/AimingCommands/VisionAim.h"
#include "commands/ArmCommands/PIDArmExtension.h"
#include "commands/ArmCommands/PIDArmTilt.h"
#include "commands/LevelCommands/PIDLevel.h"
#include "commands/ArmCommands/PIDClawMove.h"

#include "commands/AutoCommands/MiddleAutoNoScore.h"
#include "commands/AutoCommands/BlueShortAutoNoScore.h"
#include "commands/AutoCommands/BlueLongAutoNoScore.h"
#include "commands/AutoCommands/RedShortAutoNoScore.h"
#include "commands/AutoCommands/RedLongAutoNoScore.h"

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

  frc2::Trigger m_DriverYButton{[&] { return m_DriverController.GetYButton(); }};
  frc2::Trigger m_DriverBButton{[&] { return m_DriverController.GetBButton(); }};
  frc2::Trigger m_DriverXButton{[&] { return m_DriverController.GetXButton(); }};
  frc2::Trigger m_DriverAButton{[&] { return m_DriverController.GetAButton(); }};

  frc2::Trigger m_DriverLeftBumper{[&] {return m_DriverController.GetLeftBumper();}};
  frc2::Trigger m_DriverRightBumper{[&] {return m_DriverController.GetRightBumper();}};

  // Controller DPAD
  // THIS SHOULD WORK (NEEDS TESTING)
  frc2::Trigger m_DriverDpadUP{[&] { return m_DriverController.GetPOV() == 0; }};
  frc2::Trigger m_DriverDpadRIGHT{[&] { return m_DriverController.GetPOV() == 90; }};
  frc2::Trigger m_DriverDpadDOWN{[&] { return m_DriverController.GetPOV() == 180; }};
  frc2::Trigger m_DriverDpadLEFT{[&] { return m_DriverController.GetPOV() == 270; }};


  // Subsystem objects
  DriveTrainSubsystem m_DriveTrain{&m_DriverController};
  ArmSubsystem m_ArmSubsystem{&m_DriverController};
  GyroSubsystem m_Gyro;
  LimeLightSubsystem m_LimeLight;
  

  // Basic Commands
  PIDLevel m_PIDLevel{&m_DriveTrain, &m_Gyro};
  DriveWithController m_DriveWithController{&m_DriveTrain};
  MoveArmWithController m_MoveArmWithController{&m_ArmSubsystem};
  ToggleDriveMode m_ToggleDriveMode{&m_DriveTrain};
  VisionAim m_VisionAim{&m_DriveTrain, &m_LimeLight};

  // Commands for arm
  frc2::ParallelCommandGroup m_ArmLiftHigh{PIDArmExtension{&m_ArmSubsystem, ARM_PID_CONST::EXTEND_HIGH}, PIDArmTilt{&m_ArmSubsystem, ARM_PID_CONST::TILT_HIGH}};
  frc2::ParallelCommandGroup m_ArmLiftLow{PIDArmExtension{&m_ArmSubsystem, ARM_PID_CONST::EXTEND_LOW}, PIDArmTilt{&m_ArmSubsystem, ARM_PID_CONST::TILT_LOW}};
  frc2::ParallelCommandGroup m_ArmLiftGround{PIDArmExtension{&m_ArmSubsystem, ARM_PID_CONST::EXTEND_GROUND}, PIDArmTilt{&m_ArmSubsystem, ARM_PID_CONST::TILT_GROUND}};

  // Commands for claw
  PIDClawMove m_ClawPickupCube{&m_ArmSubsystem, ARM_PID_CONST::CLAW_PICKUP_CUBE};
  PIDClawMove m_ClawPickupCone{&m_ArmSubsystem, ARM_PID_CONST::CLAW_PICKUP_CONE};
  PIDClawMove m_ClawDropPiece{&m_ArmSubsystem, ARM_PID_CONST::CLAW_DROP_PIECE};

  // Drive Straight test when button pressed
  DriveStraightPID m_DriveStraightWhenPress{&m_DriveTrain, 1_m};
};
