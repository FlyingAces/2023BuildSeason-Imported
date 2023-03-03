#pragma once

#include <frc/controller/PIDController.h>

#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>

#include "subsystems/ArmSubsystem.h"

// Takes in pointer to arm subsystem and target rotation value for claw motor
// Uses PID control to reach target claw motor rotations
class PIDClawMove : public frc2::CommandHelper<frc2::PIDCommand, PIDClawMove> {
     public:
     PIDClawMove(ArmSubsystem* arm, double clawRotations);

     bool IsFinished() override;
};