#include "commands/DriveCommands/DriveStraightPID.h"

#include <frc/controller/ProfiledPIDController.h>

DriveStraightPID::DriveStraightPID(DriveTrainSubsystem* p_drive, units::meter_t target) : CommandHelper(
          frc::ProfiledPIDController<units::meters>(PID_DRIVE_CONSTANTS::DRIVE_P , PID_DRIVE_CONSTANTS::DRIVE_I, PID_DRIVE_CONSTANTS::DRIVE_D, {PID_DRIVE_CONSTANTS::MAX_SPEED, PID_DRIVE_CONSTANTS::MAX_ACCEL}),
          // Close loop on heading
          [p_drive] { return ((p_drive->getRightDist()+p_drive->getLeftDist())/2); },
          // Set reference to target
          target,
          // Pipe output to drive robot
          [p_drive](double output, auto setpointState) {
            p_drive->arcadeDrive(output, 0);
          },
          // Require the drive
          {p_drive}), mp_DriveTrain{p_drive} {
  GetController().SetTolerance(PID_DRIVE_CONSTANTS::DIST_TOLERANCE, PID_DRIVE_CONSTANTS::ACCEL_TOLERANCE);
  AddRequirements({p_drive});
}
void DriveStraightPID::Initialize() {
  mp_DriveTrain->zeroDTEncoders();
}

bool DriveStraightPID::IsFinished() {
  return GetController().AtGoal();
}

void DriveStraightPID::End(bool interupted) {
  mp_DriveTrain->zeroDTEncoders();
}