#include "commands/ToggleCommands/ToggleDriveMode.h"

ToggleDriveMode::ToggleDriveMode(DriveTrainSubsystem* p_DriveTrain) : mp_DriveTrain{p_DriveTrain}{
    SetName("ToggleDriveMode");
    AddRequirements(mp_DriveTrain);
}
void ToggleDriveMode::Execute(){
    mp_DriveTrain->toggleDriveMode();
}
bool ToggleDriveMode::IsFinished(){
    return true;
}