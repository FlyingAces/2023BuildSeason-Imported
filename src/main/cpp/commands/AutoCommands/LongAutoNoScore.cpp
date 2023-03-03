#include "commands/AutoCommands/LongAutoNoScore.h"

LongAutoNoScore::LongAutoNoScore(DriveTrainSubsystem* p_DriveTrain, GyroSubsystem* p_Gyro) : mp_DriveTrain{p_DriveTrain}, mp_Gyro{p_Gyro} {
    AddCommands(DriveStraightPID(mp_DriveTrain, 1_m),
    TurnToAnglePID(mp_DriveTrain, mp_Gyro, -90_deg),
    DriveStraightPID(mp_DriveTrain, 1_m),
    TurnToAnglePID(mp_DriveTrain, mp_Gyro, -90_deg),
    DriveStraightPID(mp_DriveTrain, 1_m),
    PIDLevel(mp_DriveTrain, mp_Gyro));
}