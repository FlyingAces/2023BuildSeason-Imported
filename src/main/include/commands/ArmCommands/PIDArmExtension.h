#pragma once

#include <frc/controller/PIDController.h>

#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>

#include "subsystems/ArmSubsystem.h"

// Takes in pointer to arm subsystem and target rotation value for extension motor
// Uses PID control to reach target extension rotations
class PIDArmExtension : public frc2::CommandHelper<frc2::PIDCommand, PIDArmExtension> {
     public:
     PIDArmExtension(ArmSubsystem* arm, double extentionRotations);

     bool IsFinished() override;
};