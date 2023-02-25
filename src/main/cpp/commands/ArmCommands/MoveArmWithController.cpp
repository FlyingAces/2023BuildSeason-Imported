#include "commands/ArmCommands/MoveArmWithController.h"

MoveArmWithController::MoveArmWithController(ArmSubsystem* p_Arm) : mp_Arm{p_Arm} {
    SetName("MoveArmWithController");
    AddRequirements(mp_Arm);
}
void MoveArmWithController::Initialize() {

}
void MoveArmWithController::Execute() {
   mp_Arm->moveArmWithController();
}
bool MoveArmWithController::IsFinished() {
    return false;
}
void MoveArmWithController::End(bool interrupted) {
    
}