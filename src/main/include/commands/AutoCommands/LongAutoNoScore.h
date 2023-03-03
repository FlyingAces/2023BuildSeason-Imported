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
#include "commands/TurnCommands/TurnToAnglePID.h"

// NEEDS MEASUREMENTS AND TESTING
// Routine
// Drive forward X meter
// Turn -90 degrees
// Drive forward X meters
// Turn -90 degrees
// Drive forward X meters
// Run PIDBalance Command
class LongAutoNoScore : public frc2::CommandHelper<frc2::SequentialCommandGroup, LongAutoNoScore> {
    public:
    LongAutoNoScore(DriveTrainSubsystem* p_DriveTrain, GyroSubsystem* p_Gyro);

    private:
    DriveTrainSubsystem* mp_DriveTrain;
    GyroSubsystem* mp_Gyro;
};