#include "commands/AimingCommands/SetLimelightPipeline.h"

SetLimelightPipeline::SetLimelightPipeline(LimeLightSubsystem* p_Limelight, int pipelineNum) : mp_Limelight{p_Limelight}, m_pipelineNum{pipelineNum} {
    SetName("DriveWithController");
}
void SetLimelightPipeline::Initialize() {

}
void SetLimelightPipeline::Execute() {
    mp_Limelight->setPipeline(m_pipelineNum);
}
bool SetLimelightPipeline::IsFinished() {
    return true;
}
void SetLimelightPipeline::End(bool interrupted) {
    
}