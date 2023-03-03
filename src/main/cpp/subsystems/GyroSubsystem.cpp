#include "subsystems/GyroSubsystem.h"

GyroSubsystem::GyroSubsystem() = default;

void GyroSubsystem::zeroGyro(){
    m_Gyro.Reset();
}

units::degree_t GyroSubsystem::getAngleDegrees() {
    return units::degree_t{m_Gyro.GetAngle()};
}

double GyroSubsystem::getPitch() {
    return m_Gyro.GetPitch();
}

void GyroSubsystem::Periodic() {}