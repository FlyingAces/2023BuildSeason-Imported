#include "commands/AutoCommands/MainAuto.h"

MainAuto::MainAuto(DriveTrainSubsystem* p_DriveTrain, GyroSubsystem* p_Gyro) : mp_DriveTrain{p_DriveTrain}, mp_Gyro{p_Gyro} {
    // List commands to be run here
    AddCommands(DriveStraightPID(mp_DriveTrain, 1_m));
}