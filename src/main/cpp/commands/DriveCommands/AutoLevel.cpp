#include "commands/DriveCommands/AutoLevel.h"
#include <iostream>

AutoLevel::AutoLevel(DriveTrainSubsystem* p_DriveTrain, GyroSubsystem* p_Gyro) : mp_DriveTrain{p_DriveTrain}, mp_Gyro{p_Gyro} {
    SetName("AutoLevel");
    AddRequirements(p_DriveTrain);
    AddRequirements(p_Gyro);
}

void AutoLevel::Initialize() {
    mp_DriveTrain->setAutoState(true);
}

void AutoLevel::Execute() {
    std::cout << "Pitch: " << mp_Gyro->getPitch() << std::endl;

    balanceError = mp_Gyro->getPitch();

    if (balanceError > 1.0) {
        balanceSpeed = -CONSTP*balanceError - minCommand;
    } else if (balanceError < -1.0) {
        balanceSpeed = -CONSTP*balanceError + minCommand;
    } else {
        balanceSpeed = 0;
    }

    mp_DriveTrain->arcadeDrive(balanceSpeed,0);
}   

bool AutoLevel::IsFinished() {
    return false;
}

void AutoLevel::End(bool interrupted) {
    mp_DriveTrain->setAutoState(false);
}