//local
#include "include/Robot.h"

void Robot::RobotInit()
{
  Robot_Control_initialize();

  AddPeriodic([&](){
    static size_t HighFrequencyCount = 0;

    if(HighFrequencyCount == 2)
    {
      for (auto group : dlib::TalonFXMotorGroup::allTalonFXMotorGroups)
      {
        group->UpdateMotorCANConnectionAlerts();
      }

      for (auto group : dlib::SparkMaxMotorGroup::allSparkMaxMotorGroups)
      {
        group->UpdateMotorCANConnectionAlerts();
      }
    }
    if(HighFrequencyCount == 4)
      HighFrequencyCount = 0;
    else
      HighFrequencyCount++;
  },
  4_ms,
  0_ms);
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