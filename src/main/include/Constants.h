#pragma once
//std
#include <string>


//local
#include "DertLib/include/SparkMaxMotor.h"
#include "DertLib/include/TalonFXMotor.h"
#include "DertLib/include/CANBus.h"
#include "Robot_Control_ert_rtw/Robot_Control.h"

using namespace dlib;

namespace Constants
{
    namespace CANBuses
    {
        static dlib::CANBus CANivoreBus("Uno");
        static dlib::CANBus RoboRioBus("Rio");
    };

    namespace BallShooter
    {
            static SparkMaxMotorCreateInfo defaultBallCreateInfo = SparkMaxMotorCreateInfo::getDefaultCreateInfo();

            static const SparkMaxMotorCreateInfo ballMotor = defaultBallCreateInfo
                .SetCanID(1)
                .SetIsReversed(false)
                .SetSmartCurrentLimit(80)
                .SetSecondaryCurrentLimit(80)
                .SetDutyCycleCallback(&Robot_Control_Y.ballMotor_Duty_Cycle)
                .SetVelocityCallback(&Robot_Control_U.ballMotor_Speed)
                .SetDisplayName("Ball Shooter Motor");

            // static const TalonFXMotorCreateInfo testMotor = TalonFXMotorCreateInfo::getDefaultCreateInfo()
            //     .SetCanID(2)
            //     .SetCanbus(Constants::CANBuses::RoboRioBus)
            //     .SetIsReversed(false)
            //     .SetOpenLoopRampPeriod(0)
            //     .SetEnableFOC(true)
            //     .SetDisplayName("TestMotor");

    };
    
    namespace HID
    {
        static constexpr int k_Gamepad_Port = 0;
        static constexpr int k_Left_Joystick_Port = 1;
        static constexpr int k_Right_Joystick_Port = 2;
    };


};