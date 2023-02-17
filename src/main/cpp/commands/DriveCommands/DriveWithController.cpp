#include "commands/DriveCommands/DriveWithController.h"

DriveWithController::DriveWithController(DriveTrainSubsystem* p_DriveTrain) : mp_DriveTrain{p_DriveTrain} {
    SetName("DriveWithController");
    AddRequirements(mp_DriveTrain);
}
void DriveWithController::Initialize() {

}
void DriveWithController::Execute() {
    if(!mp_DriveTrain->getAutoState()) {
        mp_DriveTrain->driveWithController();
    }
}
bool DriveWithController::IsFinished() {
    return false;
}
void DriveWithController::End(bool interrupted) {
    
}