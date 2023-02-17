#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ProfiledPIDCommand.h>

#include "subsystems/DriveTrainSubsystem.h"

// Uses PID controlls to drive in a straight line for a given distance in meters
class DriveStraightPID: public frc2::CommandHelper<frc2::ProfiledPIDCommand<units::meters>, DriveStraightPID> {
 
 public:
  DriveStraightPID(DriveTrainSubsystem* p_drive, units::meter_t);

  void Initialize() override;
  bool IsFinished() override;

  private:
  DriveTrainSubsystem* mp_DriveTrain;
};