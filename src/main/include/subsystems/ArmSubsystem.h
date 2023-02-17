#pragma once

#include <units/angle.h>
#include <units/angular_velocity.h>
#include <units/acceleration.h>
#include <units/time.h>
#include <units/length.h>
#include <units/velocity.h>
#include <numbers>

#include <frc/XboxController.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>

#include <frc2/command/SubsystemBase.h>

#include <rev/CANSparkMax.h>

#include <ctre/Phoenix.h>

namespace ARM_CONST
{
    // Motor IDs
    int ARM_EXTENTION_MOTOR_ID = 0;
    int ARM_TILT_MOTOR_ID = 0;
    int CLAW_MOTOR_ID = 0;

    // Gear Ratios
    double EXTEND_MOTOR_RATIO = 1;
    double TILT_MOTOR_RATIO = 1;
    double CLAW_MOTOR_RATIO = 1;
}

class ArmSubsystem : public frc2::SubsystemBase {
    public:
    ArmSubsystem(frc::XboxController* p_Controller);

    // Takes in values between -1 and 1
    // Runs Motor Controlling Tilt Mechanism
    void runTiltMotor(double speed);

    // Takes in values between -1 and 1
    // Runs Motor Controlling Extention Mechanism (Repurposed Climber In A Box)
    void runExtentionMotor(double speed);

    // Takes in values between -1 and 1
    // Runs Motor Controlling Claw
    void runClawMotor(double speed);

    // Zeros tilt motor encoder
    void zeroTiltMotorEncoder();

    // Zeros extention motor encoder
    void zeroExtentionMotorEncoder();

    // Zeros claw motor encoder
    void zeroClawMotorEncoder();

    // Returns encoder position of tilt motor
    double getTiltMotorEncoderPOS();

    // Returns encoder position of extention motor
    double getExtentionMotorEncoderPOS();

    // Returns encoder position of claw motor
    double getClawMotorEncoderPOS();

    private:
    // Xbox controller
    frc::XboxController* mp_Controller;

    // Motor objects
    WPI_TalonFX m_TiltMotor{ARM_CONST::ARM_TILT_MOTOR_ID};
    WPI_TalonFX m_ExtentionMotor{ARM_CONST::ARM_TILT_MOTOR_ID};
    rev::CANSparkMax m_ClawMotor{ARM_CONST::CLAW_MOTOR_ID, rev::CANSparkMax::MotorType::kBrushless};
};