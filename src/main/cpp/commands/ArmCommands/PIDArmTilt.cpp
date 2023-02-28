#include "commands/ArmCommands/PIDArmTilt.h"

PIDArmTilt::PIDArmTilt(ArmSubsystem* arm, double tiltRotations) : CommandHelper{frc2::PIDController{ARM_PID_CONST::TILT_P, ARM_PID_CONST::TILT_I, ARM_PID_CONST::TILT_D},
                    // Close loop on heading
                    [arm] { return arm->getExtentionMotorEncoderPOS(); },
                    // Set reference to target
                    tiltRotations,
                    // Pipe output to run extenstion motor
                    [arm](double output) { arm->runExtentionMotor(output); },
                    {}} {
  m_controller.SetTolerance(ARM_PID_CONST::TILT_R_TOL, ARM_PID_CONST::TILT_A_TOL);
}

bool PIDArmTilt::IsFinished() {
  return GetController().AtSetpoint();
}
