#include "subsystems/ArmSubsystem.h"

#include <iostream>

ArmSubsystem::ArmSubsystem(frc::XboxController* p_Controller) : mp_Controller{p_Controller} {
    SetName("ArmSubsystem");
    SetSubsystem("ArmSubystem");

    //Config
    m_ExtentionMotor.ConfigFactoryDefault();
    m_TiltMotor.ConfigFactoryDefault();

    m_ExtentionMotor.SetNeutralMode(Brake);
    m_TiltMotor.SetNeutralMode(Brake);

    m_ClawMotor.RestoreFactoryDefaults();

    m_ExtentionMotor.SetSelectedSensorPosition(0.0);
    m_TiltMotor.SetSelectedSensorPosition(0.0);
    m_ClawEncoder.SetPosition(0.0);

    m_ExtentionMotor.ConfigOpenloopRamp(2);

    m_ExtentionMotor.SetInverted(false);
    m_ClawMotor.SetInverted(false);
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
    m_ClawEncoder.SetPosition(0.0);
}

double ArmSubsystem::getTiltMotorEncoderPOS() {
    // 4096 is encoder pulses per potation
    return m_TiltMotor.GetSelectedSensorPosition() / 4096;
}

double ArmSubsystem::getExtentionMotorEncoderPOS() {
    // 4096 is encoder pulses per potation
    return m_ExtentionMotor.GetSelectedSensorPosition() / 4096;
}

double ArmSubsystem::getClawMotorEncoderPOS() {
    return m_ClawEncoder.GetPosition();
} 

// Right joystick controls extension and pully motors
// X axis is tilt
// Y axis is extension
// TEMP: RIGHT AND LEFT TRIGGERS ARE CLAW
void ArmSubsystem::moveArmWithController() {
    extendWithController = mp_Controller->GetRightY();
    tiltWithController = mp_Controller->GetRightX(); 
    clawWithController = (mp_Controller->GetRightTriggerAxis() - mp_Controller->GetLeftTriggerAxis()) * 0.5;

    runExtentionMotor(extendWithController);
    runTiltMotor(tiltWithController);
    runClawMotor(clawWithController);
    /* - mp_Controller->GetRightTriggerAxis()) * 0.5;
    if(getExtentionMotorEncoderPOS() < ARM_CONST::EXTEND_MAX) {
        runExtentionMotor(extendWithController);
    } else {
        //runExtentionMotor(-0.2);
    }
    if(getTiltMotorEncoderPOS() < ARM_CONST::TILT_MAX && getTiltMotorEncoderPOS() > ARM_CONST::TILT_MIN) {
       runTiltMotor(tiltWithController);
    } else if (getTiltMotorEncoderPOS() > ARM_CONST::TILT_MAX) {
        //runTiltMotor(-0.1);
    } else {
        //runTiltMotor(0.1);
    }
    if(getClawMotorEncoderPOS() >= ARM_CONST::CLAW_MIN && getClawMotorEncoderPOS() < ARM_CONST::CLAW_MAX) { 
        runClawMotor(clawWithController);
    } else if (getClawMotorEncoderPOS() > ARM_CONST::CLAW_MAX) {
        runClawMotor(-0.2);
    } else {
        //runClawMotor(0.2);
    }

    std::cout << "Extend Encoder: " << getExtentionMotorEncoderPOS() << std::endl;
    std::cout << "Tilt Encoder: " << getTiltMotorEncoderPOS() << std::endl;
    std::cout << "Claw Encoder: " << getClawMotorEncoderPOS() << std::endl;
    */
}