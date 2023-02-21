#pragma once

#include <frc/controller/PIDController.h>

#include <frc2/command/CommandHelper.h>
#include <frc2/command/PIDCommand.h>

#include "subsystems/DriveTrainSubsystem.h"
#include "subsystems/GyroSubsystem.h"

#include <iostream>

// Automatically levels the robot on charging station while ran
class AutoLevel : public frc2::CommandHelper<frc2::CommandBase, AutoLevel> {
    public:
    explicit AutoLevel(DriveTrainSubsystem* p_DriveTrain, GyroSubsystem* p_Gyro);

    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted);

    private:
    DriveTrainSubsystem* mp_DriveTrain;
    GyroSubsystem* mp_Gyro;
    double balanceError;
    double balanceSpeed;
    double CONSTP = 0.01;
    double minCommand = 0.06;
};