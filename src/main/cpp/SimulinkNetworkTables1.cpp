// This file has been auto generated from a Matlab script
// Do not manually edit since changes will be lost
// Janelyn <3
#include "include/SimulinkNetworkTables1.h"
 
SimulinkNetworkTables1::SimulinkNetworkTables1()
{
    nt::NetworkTableInstance NTinst = nt::NetworkTableInstance::GetDefault();
    auto NTtable_Tune = NTinst.GetTable("Simulink Tunable Params");
    auto NTtable_Inport = NTinst.GetTable("Simulink Top Level Ports");
    auto NTtable_Outport = NTinst.GetTable("Simulink Top Level Ports");
    auto NTtable_TPoint = NTinst.GetTable("Simulink Test Points");
 
    P__Ballmotor_speed_Kff__Entry = NTtable_Tune->GetEntry("Ballmotor_speed_Kff");
    NTinst.AddListener(P__Ballmotor_speed_Kff__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Ballmotor_speed_Kff = event.GetValueEventData()->value.GetDouble();});
    P__Ballmotor_speed_Kff__Entry.SetDouble(0.00018519);
 
    P__Ballmotor_speed_Ki__Entry = NTtable_Tune->GetEntry("Ballmotor_speed_Ki");
    NTinst.AddListener(P__Ballmotor_speed_Ki__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Ballmotor_speed_Ki = event.GetValueEventData()->value.GetDouble();});
    P__Ballmotor_speed_Ki__Entry.SetDouble(8e-07);
 
    P__Ballmotor_speed_Kp__Entry = NTtable_Tune->GetEntry("Ballmotor_speed_Kp");
    NTinst.AddListener(P__Ballmotor_speed_Kp__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Ballmotor_speed_Kp = event.GetValueEventData()->value.GetDouble();});
    P__Ballmotor_speed_Kp__Entry.SetDouble(4e-05);
 
    P__ballMotor_Set_Desiredspeed__Entry = NTtable_Tune->GetEntry("ballMotor_Set_Desiredspeed");
    NTinst.AddListener(P__ballMotor_Set_Desiredspeed__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {ballMotor_Set_Desiredspeed = event.GetValueEventData()->value.GetDouble();});
    P__ballMotor_Set_Desiredspeed__Entry.SetDouble(2500);
 
// Inports
    I__Gamepad_B3_X__Entry = NTtable_Inport->GetEntry("Gamepad_B3_X");
    I__ballMotor_Speed__Entry = NTtable_Inport->GetEntry("ballMotor_Speed");
 
// Outports
    O__ballMotor_Duty_Cycle__Entry = NTtable_Outport->GetEntry("ballMotor_Duty_Cycle");
 
// Test Points
}
 
void SimulinkNetworkTables1::PreStepCallback() {}
 
void SimulinkNetworkTables1::PostStepCallback()
{
    // Tunable Parameters
    P__Ballmotor_speed_Kff__Entry.SetDouble(Ballmotor_speed_Kff);
    P__Ballmotor_speed_Ki__Entry.SetDouble(Ballmotor_speed_Ki);
    P__Ballmotor_speed_Kp__Entry.SetDouble(Ballmotor_speed_Kp);
    P__ballMotor_Set_Desiredspeed__Entry.SetDouble(ballMotor_Set_Desiredspeed);
    // Inports
    I__Gamepad_B3_X__Entry.SetDouble(Robot_Control_U.Gamepad_B3_X);
    I__ballMotor_Speed__Entry.SetDouble(Robot_Control_U.ballMotor_Speed);
    // Outports
    O__ballMotor_Duty_Cycle__Entry.SetDouble(Robot_Control_Y.ballMotor_Duty_Cycle);
    // Test Points
}
// Why are you reading to the bottom of an autogen file?
// Get a life...
