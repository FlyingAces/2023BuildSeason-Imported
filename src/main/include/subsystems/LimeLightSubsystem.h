#pragma once

#include <frc2/command/SubsystemBase.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

namespace LIMELIGHT_CONSTANTS {
    // Degrees rotated back from perfectly vertical
    const double MOUNT_ANGLE = 0;

    // Distance from center of limelight lens to floor in meters
    const double LENS_HEIGHT_M = 0;

    // Distance from botom of cube april tag to floor in meters
    const double cubeApril = 0.36;

    // Distance from botom of low level reflective tape on cone node to floor in meters
    const double coneReftape = 0.56;
}

class LimeLightSubsystem : public frc2::SubsystemBase {
    public:
    LimeLightSubsystem();

    // Camera LED Modes
    enum LEDMode{
        noMode, off, blink, on
    };

    // Camera Operation Modes
    enum CamMode{
        vision, driveCam
    };

    enum Pipeline{
        refTape, aprilTag
    };

    // Returns horizontal offset from crosshair to target [-27, 27] degrees
    double getX();

    // Returns vertical offset from crosshair to target [-20.5, 20.5] degrees
    double getY();

    // Returns TRUE if the limelight has a target
    bool hasTarget();

    // Returns target area [0, 100] percent of image
    double getArea();

    // Sets limelight's LED state
    void setLED(LEDMode mode);

    // Sets limelight camera mode
    // 0 vision procesing
    // 1 driver camera (disables vision processing)
    void setMode(CamMode mode);

    // Sets limelight pipelime mode
    // 0 is reflective tape
    // 1 is april tags
    void setPipeline(Pipeline mode);

    void Periodic() override;

    private:
    std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
};