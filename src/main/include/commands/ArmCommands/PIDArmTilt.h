#pragma once

#include <frc/controller/PIDController.h>

#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>

#include "subsystems/ArmSubsystem.h"

// Takes in pointer to arm subsystem and target rotation value for titl motor
// Uses PID control to reach target tilt rotations
class PIDArmTilt : public frc2::CommandHelper<frc2::PIDCommand, PIDArmTilt> {
     public:
     PIDArmTilt(ArmSubsystem* arm, double tiltRotations);

     bool IsFinished() override;
     void End(bool interrupted);
};