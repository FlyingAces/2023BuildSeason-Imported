#include "commands/ArmCommands/PIDClawMove.h"

// Add Claw Consts
PIDClawMove::PIDClawMove(ArmSubsystem* arm, double clawRotations) : CommandHelper{frc2::PIDController{ARM_PID_CONST::CLAW_P, ARM_PID_CONST::CLAW_I, ARM_PID_CONST::CLAW_D},
                    // Close loop on heading
                    [arm] { return arm->getClawMotorEncoderPOS(); },
                    // Set reference to target
                    clawRotations,
                    // Pipe output to run extenstion motor
                    [arm](double output) { arm->runClawMotor(output); },
                    {}} {
  m_controller.SetTolerance(ARM_PID_CONST::CLAW_R_TOL, ARM_PID_CONST::CLAW_A_TOL);
}

bool PIDClawMove::IsFinished() {
  return GetController().AtSetpoint();
}
