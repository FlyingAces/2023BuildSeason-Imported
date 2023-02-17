#include "commands/TurnCommands/TurnToAnglePID.h"

#include <frc/controller/ProfiledPIDController.h>

TurnToAnglePID::TurnToAnglePID(DriveTrainSubsystem* mp_drive, GyroSubsystem* mp_gyro, units::degree_t target) : CommandHelper(
          frc::ProfiledPIDController<units::radians>(PID_TURN_CONSTANTS::TURN_P, PID_TURN_CONSTANTS::TURN_I, PID_TURN_CONSTANTS::TURN_D, {PID_TURN_CONSTANTS::MAX_TURN_RATE, PID_TURN_CONSTANTS::MAX_TURN_ACCEL}),
          // Close loop on heading
          [mp_gyro] { return mp_gyro->getAngleDegrees(); },
          // Set reference to target
          target,
          // Pipe output to turn robot
          [mp_drive](double output, auto setpointState) {
            mp_drive->arcadeDrive(0, output);
          },
          // Require the drive
          {mp_drive}) {
  // Set the controller to be continuous (because it is an angle controller)
  GetController().EnableContinuousInput(0_deg, 360_deg);
  // Set the controller tolerance - the delta tolerance ensures the robot is
  // stationary at the setpoint before it is considered as having reached the
  // reference
  GetController().SetTolerance(PID_TURN_CONSTANTS::TURN_TOLERANCE, PID_TURN_CONSTANTS::TURN_RATE_TOLERANCE);

  AddRequirements({mp_drive});
}

bool TurnToAnglePID::IsFinished() {
  return GetController().AtGoal();
}