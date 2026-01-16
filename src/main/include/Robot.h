#pragma once

//local
#include "Robot_Control_ert_rtw\Robot_Control.h"
#include "DertLib/include/Component.h"
#include "include/HIDs.h"
#include "include/SimulinkNetworkTables1.h"

//frc
#include <frc/TimedRobot.h>
#include <frc/DriverStation.h>

//std
#include <iostream>

class Robot : public frc::TimedRobot {
 public:
  /** Runs once when robot turns on */
  void RobotInit()      override;
  /** The following code runs once when its mode is enabledd */
  void AutonomousInit() override;
  void TeleopInit()     override;
  void DisabledInit()   override;
  void TestInit()       override;
  void SimulationInit() override;

  /** Runs every 20ms regardless of what mode the robot is in */
  void RobotPeriodic()      override;
  void AutonomousPeriodic() override {};
  void TeleopPeriodic()     override {};
  void DisabledPeriodic()   override {};
  void TestPeriodic()       override {};
  void SimulationPeriodic() override {};

private:
  /** Transfer data from Odometry outputs to Robot_Control inputs */

  /** Puts all inputs from sensors and HIDs into Simulink */
  void PreStep() {for(auto component : dlib::Component::allCreatedComponents) component->PreStepCallback();}
  
  /** Takes outputs from simulink and pushes their commands to hardware */
  void PostStep() {for(auto component : dlib::Component::allCreatedComponents) component->PostStepCallback();}
  


  /*
   * Below are the instances of the components used by the robot
   * Everything here should be direct hardware control, only
   * functions that manipulate global variables declared by Simulink
   * are exceptions to this rule.
   */

  /** Monitor code execution time */
  frc::Tracer m_Tracer{};

  /** Component Object for Human Input Devices */
  HIDs m_HIDs;
  
    
  /** Component for all Tunable Parameters created by simulink */
  SimulinkNetworkTables1 m_SimulinkNetworkTables1;


};
