#include "commands/AimingCommands/VisionAim.h"
#include <iostream>

VisionAim::VisionAim(DriveTrainSubsystem* p_DriveTrain, LimeLightSubsystem* p_LimeLight) : mp_Drivetrain{p_DriveTrain}, mp_LimeLight{p_LimeLight} {
    SetName("VisionAimV1");
    AddRequirements(p_DriveTrain);
}

void VisionAim::Initialize(){
    mp_Drivetrain->setAutoState(true);
}

void VisionAim::Execute(){
    headingError = mp_LimeLight->getX();

    if (headingError > 1.0) {
        steerAjust = CONSTP*headingError + minCommand;
    }
    else if (headingError < -1.0){
        steerAjust = CONSTP*headingError - minCommand;
    }
    else {
        steerAjust = 0;
    }

    leftSteer=steerAjust;
    rightSteer=-steerAjust;

    std::cout <<std::endl << "tx: " << headingError << "StAj: " << steerAjust << "lsteer:" << leftSteer << "rsteer" << rightSteer << std::endl;
    mp_Drivetrain->tankDrive(leftSteer, rightSteer);
}

bool VisionAim::IsFinished(){
    return false;
}

void VisionAim::End(bool interupted){
    leftSteer = 0;
    rightSteer = 0;

    mp_Drivetrain->tankDrive(0,0);
    mp_Drivetrain->setAutoState(false);
}