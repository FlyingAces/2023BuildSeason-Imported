#pragma once

#include <units/angle.h>
#include <units/angular_velocity.h>
#include <units/acceleration.h>
#include <units/time.h>
#include <units/length.h>
#include <units/velocity.h>
#include <numbers>

#include <frc2/command/SubsystemBase.h>

#include <ctre/Phoenix.h>

namespace GYRO_CONSTANTS{
    const int GYRO_ID = 5;
}

class GyroSubsystem : public frc2::SubsystemBase {
    public:
    GyroSubsystem();

    // Resets all values to zero
    void zeroGyro();

    // Return the gyro heading in degree_t units
    units::degree_t getAngleDegrees();

    // Returns gyro pitch
    double getPitch();

    void Periodic() override;

    private:
    WPI_Pigeon2 m_Gyro{GYRO_CONSTANTS::GYRO_ID};
};