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
    const int ARM_EXTENTION_MOTOR_ID = 6;
    const int ARM_TILT_MOTOR_ID = 0;
    const int CLAW_MOTOR_ID = 62;

    // Gear Ratios
    double EXTEND_MOTOR_RATIO = 1;
    double TILT_MOTOR_RATIO = 1;
    double CLAW_MOTOR_RATIO = 1;
}

namespace ARM_PID_CONST
{
    // Extension Arm PID values
    const double EXTEND_P = 0.4;
    const double EXTEND_I = 0;
    const double EXTEND_D = 0;
    
    // Extension Rotation and accelleration tollarance values
    const double EXTEND_R_TOL = 0.1;
    const double EXTEND_A_TOL = 0.1;

    // Extension rotation values needed for game pieces
    const double EX_CONE_TOP = 4;

    // Tilt Mechanism PID values
    const double TILT_P = 0.01;
    const double TILT_I = 0;
    const double TILT_D = 0;
    
    // Tilt Rotation and accelleration tollarance values
    const double TILT_R_TOL = 100;
    const double TILT_A_TOL = 10;

    // Tilt rotation values needed for game pieces
    const double TL_CONE_TOP = 10;

    // Claw PID values
    const double CLAW_P = 0.01;
    const double CLAW_I = 0;
    const double CLAW_D = 0;
    
    // Extension Rotation and accelleration tollarance values for claw
    const double CLAW_R_TOL = 100;
    const double CLAW_A_TOL = 10;
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

    // Returns rotation position of tilt motor
    double getTiltMotorEncoderPOS();

    // Returns rotation position of extention motor
    double getExtentionMotorEncoderPOS();

    // Returns encoder position of claw motor
    double getClawMotorEncoderPOS();

    void moveArmWithController();

    private:
    // Xbox controller
    frc::XboxController* mp_Controller;

    // Drive with controller values;
    double tiltWithController;
    double extendWithController;

    // Motor objects
    WPI_TalonSRX m_TiltMotor{ARM_CONST::ARM_TILT_MOTOR_ID};
    WPI_TalonSRX m_ExtentionMotor{ARM_CONST::ARM_EXTENTION_MOTOR_ID};
    rev::CANSparkMax m_ClawMotor{ARM_CONST::CLAW_MOTOR_ID, rev::CANSparkMax::MotorType::kBrushless};
    
    // Encoder objects
    rev::SparkMaxRelativeEncoder m_ClawEncoder = m_ClawMotor.GetEncoder();
};