#pragma once

#include <frc2/command/SubsystemBase.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"
#include "span.h"

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

    // Sets limelight pipeline
    // 0 vision procesing
    // 1 driver camera (disables vision processing)
    void setMode(CamMode mode);

    void Periodic() override;

    private:
    std::shared_ptr<nt::NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
};