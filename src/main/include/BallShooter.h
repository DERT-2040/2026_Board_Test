#pragma once

// Local
#include "DertLib/include/Component.h"
#include "Robot_Control_ert_rtw/Robot_Control.h"
#include "DertLib/include/SparkMaxMotorGroup.h"
#include "DertLib/include/TalonFXMotorGroup.h"
#include "include/Constants.h"

//FRC
#include <frc/Servo.h>

namespace nsHood = Constants::HoodServo;

class BallShooter : public Component
{
public:
	BallShooter();
	void HoodServoSetPulseWidth();
	void PreStepCallback() override;
	void PostStepCallback() override;
private:
	dlib::SparkMaxMotorGroup ballMotorGroup 
	{
		{
			Constants::BallShooter::ballMotor
		}
	};
	// dlib::TalonFXMotorGroup testMotorGroup
	// {
	// 	{
	// 		Constants::BallShooter::testMotor
	// 	}
	// };

	// Servos for hood linear actuator  
	frc::Servo HoodServo_Left{nsHood::Hood_Servo_PWM_Left_ID};
	frc::Servo HoodServo_Right{nsHood::Hood_Servo_PWM_Right_ID};
};
