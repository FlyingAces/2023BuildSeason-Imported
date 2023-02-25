#include "commands/AimingCommands/VisionAimWithDistance.h"
#include <iostream>

VisionAimWithDistance::VisionAimWithDistance(DriveTrainSubsystem* p_DriveTrain, LimeLightSubsystem* p_LimeLight, LimeLightSubsystem::Pipeline pipeline, double  distance) : mp_Drivetrain{p_DriveTrain}, mp_LimeLight{p_LimeLight}, m_pipeline{pipeline} {
    SetName("VisionAimWithDistance");
    AddRequirements(p_DriveTrain);
}

void VisionAimWithDistance::Initialize(){
    mp_Drivetrain->setAutoState(true);
    mp_LimeLight->setPipeline(m_pipeline);

    if(m_pipeline == 0) {
        goalHightM = LIMELIGHT_CONSTANTS::coneReftape;
    } else if (m_pipeline == 1) {
        goalHightM = LIMELIGHT_CONSTANTS::cubeApril;
    }
}

void VisionAimWithDistance::Execute(){
    headingError = mp_LimeLight->getX();
    // first section gets angle to goal in degrees
    // second section converts to rad
    angleToGoalRad = (LIMELIGHT_CONSTANTS::MOUNT_ANGLE + mp_LimeLight->getY()) * (3.1415926 / 180);

    distanceFromGoalM = (goalHightM - LIMELIGHT_CONSTANTS::LENS_HEIGHT_M) / tan(angleToGoalRad);

    std::cout << "Distance from goal: " << distanceFromGoalM << std::endl;
}

bool VisionAimWithDistance::IsFinished(){
    return false;
}

void VisionAimWithDistance::End(bool interupted){
    leftSteer = 0;
    rightSteer = 0;

    mp_Drivetrain->tankDrive(0,0);
    mp_Drivetrain->setAutoState(false);
}