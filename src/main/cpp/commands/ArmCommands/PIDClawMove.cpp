#include "commands/ArmCommands/PIDClawMove.h"

// Add Claw Consts
PIDClawMove::PIDClawMove(ArmSubsystem* arm, double clawRotations) : CommandHelper{frc2::PIDController{0.2, 0, 0},
                    // Close loop on heading
                    [arm] { return arm->getClawMotorEncoderPOS(); },
                    // Set reference to target
                    clawRotations,
                    // Pipe output to run extenstion motor
                    [arm](double output) { arm->runClawMotor(output); },
                    {}} {
  m_controller.SetTolerance(1, 1);
}

bool PIDClawMove::IsFinished() {
  return GetController().AtSetpoint();
}
