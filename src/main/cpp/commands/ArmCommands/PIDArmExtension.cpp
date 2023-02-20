#include "commands/ArmCommands/PIDArmExtension.h"

/*PIDArmExtension::PIDArmExtension(ArmSubsystem* arm, double extentionRotations) : CommandHelper{frc2::PIDController{ARM_PID_CONST::EXTEND_P, ARM_PID_CONST::EXTEND_I, ARM_PID_CONST::EXTEND_D},
                    // Close loop on heading
                    [arm] { return arm->getExtentionMotorEncoderPOS(); },
                    // Set reference to target
                    extentionRotations,
                    // Pipe output to run extenstion motor
                    [arm](double output) { arm->runExtentionMotor(output); },
                    {}} {
  m_controller.SetTolerance(ARM_PID_CONST::EXTEND_A_TOL, ARM_PID_CONST::EXTEND_R_TOL);
}

bool PIDArmExtension::IsFinished() {
  return GetController().AtSetpoint();
}*/
