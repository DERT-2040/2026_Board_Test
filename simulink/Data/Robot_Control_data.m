% Parameters to exclude from being tunable.
% This is used in the 'Build_Extern.m' file
Not_Tunable_List = {'t_sample'...
};

% sample time model
t_sample = 0.020;

% Duty Cycle for Testing
ballMotor_Set_Desiredspeed = 2500;

Ballmotor_speed_Kff = 1.0/5400;
Ballmotor_speed_Kp = 0.02/500;
Ballmotor_speed_Ki = 0.02/500*t_sample

HoodServo_Position = 0.5;