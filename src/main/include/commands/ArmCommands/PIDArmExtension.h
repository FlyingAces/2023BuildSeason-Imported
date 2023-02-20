#pragma once

#include <frc/controller/PIDController.h>

#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>

#include "subsystems/ArmSubsystem.h"

class TurnToAngle : public frc2::CommandHelper<frc2::PIDCommand, TurnToAngle> {
 public:
  /**
   * Turns to robot to the specified angle.
   *
   * @param targetAngleDegrees The angle to turn to
   * @param drive              The drive subsystem to use
   */
  TurnToAngle(double target);

  bool IsFinished() override;
};