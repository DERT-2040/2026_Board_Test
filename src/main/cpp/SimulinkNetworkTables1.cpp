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
 
    P__ballMotor_Set_Duty_Cycle__Entry = NTtable_Tune->GetEntry("ballMotor_Set_Duty_Cycle");
    NTinst.AddListener(P__ballMotor_Set_Duty_Cycle__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {ballMotor_Set_Duty_Cycle = event.GetValueEventData()->value.GetDouble();});
    P__ballMotor_Set_Duty_Cycle__Entry.SetDouble(0);
 
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
    P__ballMotor_Set_Duty_Cycle__Entry.SetDouble(ballMotor_Set_Duty_Cycle);
    // Inports
    I__Gamepad_B3_X__Entry.SetDouble(Robot_Control_U.Gamepad_B3_X);
    I__ballMotor_Speed__Entry.SetDouble(Robot_Control_U.ballMotor_Speed);
    // Outports
    O__ballMotor_Duty_Cycle__Entry.SetDouble(Robot_Control_Y.ballMotor_Duty_Cycle);
    // Test Points
}
// Why are you reading to the bottom of an autogen file?
// Get a life...
