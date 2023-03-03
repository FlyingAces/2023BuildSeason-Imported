#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/WaitUntilCommand.h>
#include <frc2/command/PrintCommand.h>

#include "commands/DriveCommands/DriveStraightPID.h"
#include "commands/LevelCommands/PIDLevel.h"


#include "subsystems/DriveTrainSubsystem.h"
#include "subsystems/GyroSubsystem.h"

// NEEDS TESTING
// Routine:
// Drive forward 1 meter
// Run PIDBalance Command
class MiddleAutoNoScore : public frc2::CommandHelper<frc2::SequentialCommandGroup, MiddleAutoNoScore>
{
public:
    MiddleAutoNoScore(DriveTrainSubsystem* p_DriveTrain, GyroSubsystem* p_Gyro);
private:
    DriveTrainSubsystem* mp_DriveTrain;
    GyroSubsystem* mp_Gyro;
};