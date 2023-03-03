#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/LimelightSubsystem.h"

// Uses inputs from controller to control the drivetrain
class SetLimelightPipeline
    : public frc2::CommandHelper<frc2::CommandBase, SetLimelightPipeline> {
 public:
  explicit SetLimelightPipeline(LimeLightSubsystem* p_Limelight, int pipelineNum);
  
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;
 private:
  LimeLightSubsystem* mp_Limelight;
  int m_pipelineNum;
};