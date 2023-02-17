// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveTrainSubsystem.h"

// Uses inputs from controller to control the drivetrain
class DriveWithController
    : public frc2::CommandHelper<frc2::CommandBase, DriveWithController> {
 public:
  explicit DriveWithController(DriveTrainSubsystem * p_DriveTrain);
  
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;
 private:
  DriveTrainSubsystem* mp_DriveTrain;
};