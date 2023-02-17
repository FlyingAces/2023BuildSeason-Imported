#include "commands/DriveCommands/DriveStraightPID.h"

#include <frc/controller/ProfiledPIDController.h>

#include <iostream>

DriveStraightPID::DriveStraightPID(DriveTrainSubsystem* mp_drive, units::meter_t target) : CommandHelper(
          frc::ProfiledPIDController<units::meters>(PID_DRIVE_CONSTANTS::DRIVE_P , PID_DRIVE_CONSTANTS::DRIVE_I, PID_DRIVE_CONSTANTS::DRIVE_D, {PID_DRIVE_CONSTANTS::MAX_SPEED, PID_DRIVE_CONSTANTS::MAX_ACCEL}),
          // Close loop on heading
          // Negitive To Fix Direction
          [mp_drive] { return ((mp_drive->getRightDist()+mp_drive->getLeftDist())/2); },
          // Set reference to target
          target,
          // Pipe output to drive robot
          [mp_drive](double output, auto setpointState) {
            mp_drive->arcadeDrive(output, 0);
          },
          // Require the drive
          {mp_drive}) {
  GetController().SetTolerance(PID_DRIVE_CONSTANTS::DIST_TOLERANCE, PID_DRIVE_CONSTANTS::ACCEL_TOLERANCE);
  AddRequirements({mp_drive});
  GetController().Reset(0_m);
}
void DriveStraightPID::Initialize() {
    GetController().Reset(0_m);
}
bool DriveStraightPID::IsFinished() {
  return GetController().AtGoal();
}