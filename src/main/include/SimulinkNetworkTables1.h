// This file has been auto generated from a Matlab script
// Do not manually edit since changes will be lost
// Janelyn <3
#pragma once
#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTable.h>
#include <networktables/RawTopic.h>
#include <networktables/NetworkTableInstance.h>
#include "Robot_Control_ert_rtw\Robot_Control.h"
#include "DertLib/include/Component.h"
 
class SimulinkNetworkTables1 : public dlib::Component
{
public:
    SimulinkNetworkTables1();
    void PreStepCallback() override ;
    void PostStepCallback() override;
private:
        // Parameters
        nt::NetworkTableEntry P__Ballmotor_speed_Kff__Entry;
        nt::NetworkTableEntry P__Ballmotor_speed_Ki__Entry;
        nt::NetworkTableEntry P__Ballmotor_speed_Kp__Entry;
        nt::NetworkTableEntry P__ballMotor_Set_Desiredspeed__Entry;
 
        // Inports
        nt::NetworkTableEntry I__Gamepad_B3_X__Entry;
        nt::NetworkTableEntry I__ballMotor_Speed__Entry;
        // Outports
        nt::NetworkTableEntry O__ballMotor_Duty_Cycle__Entry;
 
        // Test Points
};
