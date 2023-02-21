#include "commands/LevelCommands/PIDLevel.h"

PIDLevel::PIDLevel(DriveTrainSubsystem* drive, GyroSubsystem* gyro) : CommandHelper{frc2::PIDController{PID_LEVEL_CONST::L_P, PID_LEVEL_CONST::L_I, PID_LEVEL_CONST::L_D},
                    // Close loop on heading
                    [gyro] { return gyro->getPitch();},
                    // Set reference to target
                    0,
                    // Pipe output to run extenstion motor
                    [drive](double output) { drive->arcadeDrive(output, 0);},
                    {}} {
  m_controller.SetTolerance(PID_LEVEL_CONST::L_DEG_TOL, PID_LEVEL_CONST::L_ACEL_TOL);
}

bool PIDLevel::IsFinished() {
  return GetController().AtSetpoint();
}
