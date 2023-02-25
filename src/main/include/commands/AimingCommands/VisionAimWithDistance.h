#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveTrainSubsystem.h"
#include "subsystems/LimeLightSubsystem.h"

// Uses limelight camera to center robot on target
class VisionAimWithDistance : public frc2::CommandHelper<frc2::CommandBase, VisionAimWithDistance> {
 public:
    explicit VisionAimWithDistance(DriveTrainSubsystem* p_DriveTrain, LimeLightSubsystem* p_LimeLight, LimeLightSubsystem::Pipeline pipeline, double distance);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted);

 private:
 DriveTrainSubsystem* mp_Drivetrain;
 LimeLightSubsystem* mp_LimeLight;
 LimeLightSubsystem::Pipeline m_pipeline;
 double leftSteer;
 double rightSteer;
 double steerAjust;
 double headingError;
 double distanceError;
 double distanceFromGoalM;
 double goalHightM;
 double angleToGoalRad;

 double CONST_P_AIM = 0.007;
 double CONST_P_Distance = 0.007;
 // 0.27 is min to move
 double minAimCommand = 0.24;
};