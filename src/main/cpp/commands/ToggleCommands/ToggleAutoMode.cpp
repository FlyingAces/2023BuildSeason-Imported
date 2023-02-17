#include "commands/ToggleCommands/ToggleAutoMode.h"

ToggleAutoMode::ToggleAutoMode(DriveTrainSubsystem* p_DriveTrain) : mp_DriveTrain{p_DriveTrain}{
    SetName("ToggleAutoMode");
    AddRequirements(mp_DriveTrain);
}

void ToggleAutoMode::Execute() {
    if(mp_DriveTrain->getAutoState()){
        mp_DriveTrain->setAutoState(false);
    }
    else {
        mp_DriveTrain->setAutoState(true);
    }
}

bool ToggleAutoMode::IsFinished() {
    return true;
}