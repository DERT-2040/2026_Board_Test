// Local
#include "include/BallShooter.h"

void BallShooter::PreStepCallback()
{
	ballMotorGroup.SendSensorDataToSL();
}

void BallShooter::PostStepCallback()
{
	ballMotorGroup.FetchMotorCommandsFromSL();
}
