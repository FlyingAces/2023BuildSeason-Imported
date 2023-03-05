#include "commands/AutoCommands/AutoDock.h"

AutoDock::AutoDock(DriveTrainSubsystem* p_DriveTrain, GyroSubsystem* p_Gyro) : mp_DriveTrain{p_DriveTrain}, mp_Gyro{p_Gyro} {
    AddCommands(DriveStraightPID(mp_DriveTrain, 1_m), PIDLevel(mp_DriveTrain, mp_Gyro));
}