// Local
#include "include/BallShooter.h"
#include <units/time.h>

BallShooter::BallShooter()
{
    HoodServoSetPulseWidth();   
}

void BallShooter::PreStepCallback()
{
	ballMotorGroup.SendSensorDataToSL();
}

void BallShooter::PostStepCallback()
{
	ballMotorGroup.FetchMotorCommandsFromSL();
	HoodServo_Left.Set(Robot_Control_Y.HoodServo_Left_Position);
    HoodServo_Right.Set(Robot_Control_Y.HoodServo_Right_Position);
}

void BallShooter::HoodServoSetPulseWidth()
{
	// Set servo pulse widths in microseconds
	HoodServo_Left.SetBounds(
    units::time::microsecond_t(2000), // full forward (extend)
    units::time::microsecond_t(1550), // deadband max
    units::time::microsecond_t(1500), // center
    units::time::microsecond_t(1450), // deadband min
    units::time::microsecond_t(1000)  // full reverse (retract)
	);

	// Set servo pulse widths in microseconds
	HoodServo_Right.SetBounds(
    units::time::microsecond_t(2000), // full forward (extend)
    units::time::microsecond_t(1550), // deadband max
    units::time::microsecond_t(1500), // center
    units::time::microsecond_t(1450), // deadband min
    units::time::microsecond_t(1000)  // full reverse (retract)
	);
}
