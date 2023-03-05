#pragma once

#include <frc/controller/PIDController.h>

#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>

#include "subsystems/DriveTrainSubsystem.h"
#include "subsystems/GyroSubsystem.h"

namespace PID_LEVEL_CONST {
    const double L_P = 0.007;
    const double L_I = 0;
    const double L_D = 0;

    const double L_DEG_TOL = 1;
    const double L_ACEL_TOL = 1;
}

// Takes in pointer to drive subsystem and gyro subsestem
// Uses PID control to level robot to 0 degrees
class PIDLevel : public frc2::CommandHelper<frc2::PIDCommand, PIDLevel> {
     public:
     PIDLevel(DriveTrainSubsystem* drive, GyroSubsystem* gyro);

     bool IsFinished() override;
};