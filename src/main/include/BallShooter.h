#pragma once

// Local
#include "DertLib/include/Component.h"
#include "Robot_Control_ert_rtw/Robot_Control.h"
#include "DertLib/include/SparkMaxMotorGroup.h"
#include "DertLib/include/TalonFXMotorGroup.h"
#include "include/Constants.h"

class BallShooter : public Component
{
public:
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
};
