//local
#include "include/Robot.h"

void Robot::RobotInit()
{

  Robot_Control_initialize();
}
void Robot::DisabledInit()   {}
void Robot::AutonomousInit() {}
void Robot::TeleopInit()     {}
void Robot::TestInit()       {}
void Robot::SimulationInit() {}

void Robot::RobotPeriodic() 
{  

  PreStep();
  Robot_Control_step(); //Step the model
  PostStep();
}


#ifndef RUNNING_FRC_TESTS
int main() 
{
  return frc::StartRobot<Robot>();
}
#endif