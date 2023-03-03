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

#include <ctre/Phoenix.h>

// Drivetrain Constants
namespace DT_CONSTANTS {
    // Can bus ID's of the motors on the drivetrain
    const int RIGHT_LEADER = 4;
    const int RIGHT_FOLLOWER = 3;
    const int LEFT_LEADER = 1;
    const int LEFT_FOLLOWER = 2;

    // Diameter of our wheels in meters
    const double WHEEL_DIAMETER_M = 0.1524;
    // The amount of encoder pulses produced per revolution of the motors
    const int PULSES_PER_REV = 2048;
    // The number of motor revolutions per revolution of the drive train wheels
    const double GEAR_RATIO = 4;
    // The ratio between the circumfrence of a circle diveded by the diamer
    // Better known as half of Tau :)
    const double PI = 3.1415926535897932;

    // Constants controlling the speeds of the two drive modes
    // See toggleDriveMode();
    const double CONTROLLER_DRIVE_MULT_FULL = 0.5;
    const double CONTROLLER_TURN_MULT_FULL = 0.5;
    const double CONTROLLER_DRIVE_MULT_HALF = 0.25;
    const double CONTROLLER_TURN_MULT_HALF = 0.25;

    // Is the gyro reversed
    const bool GYRO_REVERSED = false;
}


namespace PID_TURN_CONSTANTS {
    // PID constants
    const double TURN_P = 0.7;
    const double TURN_I = 0.02;
    const double TURN_D = 0.04;
    // Max degree tolerance for stopping the loop
    const auto TURN_TOLERANCE = 2_deg;
    // Max speed tolerance for stopping the loop
    const auto TURN_RATE_TOLERANCE = 10_deg_per_s;
    // Max turn speed
    const auto MAX_TURN_RATE = 100_deg_per_s;
    // Max turn accelaeration 
    const auto MAX_TURN_ACCEL = 300_deg_per_s / 1_s;
}

namespace PID_DRIVE_CONSTANTS {
    // PID constatns
    const double DRIVE_P = 0.2;
    const double DRIVE_I = 0.0;
    const double DRIVE_D = 0.0;
    // Max distance tolerance for stoping the loop
    const auto DIST_TOLERANCE = 0.05_m;
    // Max acceleration tolerance for stopping the loop
    const auto ACCEL_TOLERANCE = 0.05_mps;
    // Max driving speed 
    // originally 1
    const auto MAX_SPEED = 0.3_mps;
    // Max acceleration
    // origunally 3
    const auto MAX_ACCEL = 1_mps / 1_s;
}

class DriveTrainSubsystem : public frc2::SubsystemBase {
 public:
    DriveTrainSubsystem(frc::XboxController* p_Controller);

    // Takes in values between -1 and 1
    // Speed drives forward and backwards
    // Rotation Turns Left and Right
    void arcadeDrive(double speed, double rotation);

    // Takes i nvalues between -1 and 1
    // Left controlls the speed of left side
    // Right controlls the spide of right side
    void tankDrive(double left, double right);

    // Drives the robot based on controller inputs
    void driveWithController();

    // Returns the average encoder position
    double getAvgEncoderPosition();

    // Sets encoder values to zero
    void zeroDTEncoders();

    // Returns right drivetrain distance driven in meters
    units::meter_t getRightDist();

    // Returns left drivetrain distance driven in meters
    units::meter_t getLeftDist();

    // Toggles between highspeed, and low speed
    void toggleDriveMode();

    // Sets auto state to either true or false
    // True means the robot is preforming an autonomus function
    // This prevents controller inputs from interfearing with the robot.
    void setAutoState(bool state){
        m_AutoState = state; 
    }

    // Returns the auto state of the robot
    bool getAutoState(){
        return m_AutoState;
    }
  
    void Periodic() override;
  

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

    double m_controllerDriveSpeed;
    double m_controllerRotation;
    bool m_AutoState;
    bool m_DriveMode;
    double m_DriveSpeedMult = DT_CONSTANTS::CONTROLLER_DRIVE_MULT_FULL;
    double m_RotationSpeedMult = DT_CONSTANTS::CONTROLLER_TURN_MULT_FULL;

    frc::XboxController* mp_Controller;

    WPI_TalonFX m_RightLeader{DT_CONSTANTS::RIGHT_LEADER};
    WPI_TalonFX m_RightFollower{DT_CONSTANTS::RIGHT_FOLLOWER};
    WPI_TalonFX m_LeftLeader{DT_CONSTANTS::LEFT_LEADER};
    WPI_TalonFX m_LeftFollower{DT_CONSTANTS::LEFT_FOLLOWER};

    frc::MotorControllerGroup m_RightGroup{m_RightLeader, m_RightFollower};
    frc::MotorControllerGroup m_LeftGroup{m_LeftLeader, m_LeftFollower};

    frc::DifferentialDrive m_DifferentialDrive{m_LeftGroup, m_RightGroup};
};