#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveTrainSubsystem.h"
#include "subsystems/LimeLightSubsystem.h"

// Uses limelight camera to center robot on target
class VisionAim : public frc2::CommandHelper<frc2::CommandBase, VisionAim> {
 public:
    explicit VisionAim(DriveTrainSubsystem* p_DriveTrain, LimeLightSubsystem* p_LimeLight);
    void Initialize() override;
    void Execute() override;
    bool IsFinished() override;
    void End(bool interrupted);

 private:
 DriveTrainSubsystem* mp_Drivetrain;
 LimeLightSubsystem* mp_LimeLight;
 double leftSteer;
 double rightSteer;
 double steerAjust;
 double headingError;
 double CONSTP = 0.007;
 // 0.27 is min to move
 double minCommand = 0.24;
};