#include "commands/AutoCommands/MiddleAutoNoScore.h"

MiddleAutoNoScore::MiddleAutoNoScore(DriveTrainSubsystem* p_DriveTrain, GyroSubsystem* p_Gyro) : mp_DriveTrain{p_DriveTrain}, mp_Gyro{p_Gyro} {
    AddCommands(DriveStraightPID(mp_DriveTrain, 3_m));
}