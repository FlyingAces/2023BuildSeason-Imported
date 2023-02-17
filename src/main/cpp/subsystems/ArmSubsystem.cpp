#include "subsystems/ArmSubsystem.h"

ArmSubsystem::ArmSubsystem(frc::XboxController* p_Controller) : mp_Controller{p_Controller} {
    SetName("ArmSubsystem");
    SetSubsystem("ArmSubystem");

    //Config
    m_ExtentionMotor.ConfigFactoryDefault();
    m_TiltMotor.ConfigFactoryDefault();

    m_ExtentionMotor.SetNeutralMode(Brake);
    m_TiltMotor.SetNeutralMode(Brake);

    m_ClawMotor.RestoreFactoryDefaults();
}

void ArmSubsystem::runTiltMotor(double speed) {
    m_TiltMotor.Set(ControlMode(0), speed);
}

void ArmSubsystem::runExtentionMotor(double speed) {
    m_ExtentionMotor.Set(ControlMode(0), speed);
}

void ArmSubsystem::runClawMotor(double speed) {
    m_ClawMotor.Set(speed);
}

void ArmSubsystem::zeroTiltMotorEncoder() {
    m_TiltMotor.SetSelectedSensorPosition(0.0);
}

void ArmSubsystem::zeroExtentionMotorEncoder() {
    m_ExtentionMotor.SetSelectedSensorPosition(0.0);
}

void ArmSubsystem::zeroClawMotorEncoder() {
    // DONT KNOW HOW TO IMPLIMENT
    // m_ClawMotor.GetEncoder().SetPosition(0.0);
}

double ArmSubsystem::getTiltMotorEncoderPOS() {
    return m_TiltMotor.GetSelectedSensorPosition();
}

double ArmSubsystem::getExtentionMotorEncoderPOS() {
    return m_ExtentionMotor.GetSelectedSensorPosition();
}

double ArmSubsystem::getClawMotorEncoderPOS() {
    // I DONT KNOW HOW THIS WORKS
    //return m_ClawMotor.GetEncoder().GetPosition();
    return 0;
}  