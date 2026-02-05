/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.435
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Wed Feb  4 20:15:40 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Robot_Control.h"
#include "rtwtypes.h"

/* Exported block parameters */
real_T Ballmotor_speed_Kff = 0.00018519;/* Variable: Ballmotor_speed_Kff
                                         * Referenced by: '<S3>/Gain'
                                         */
real_T Ballmotor_speed_Ki = 8.0E-7;    /* Variable: Ballmotor_speed_Ki
                                        * Referenced by: '<S3>/Gain2'
                                        */
real_T Ballmotor_speed_Kp = 4.0E-5;    /* Variable: Ballmotor_speed_Kp
                                        * Referenced by: '<S3>/Gain1'
                                        */
real_T HoodServo_Position = 0.5;       /* Variable: HoodServo_Position
                                        * Referenced by: '<S1>/Constant2'
                                        */
real_T ballMotor_Set_Desiredspeed = 2500.0;/* Variable: ballMotor_Set_Desiredspeed
                                            * Referenced by: '<S1>/Constant1'
                                            */

/* Block states (default storage) */
DW_Robot_Control_T Robot_Control_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Robot_Control_T Robot_Control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Robot_Control_T Robot_Control_Y;

/* Real-time model */
static RT_MODEL_Robot_Control_T Robot_Control_M_;
RT_MODEL_Robot_Control_T *const Robot_Control_M = &Robot_Control_M_;

/* Model step function */
void Robot_Control_step(void)
{
  real_T rtb_Add;
  real_T rtb_Error;
  real_T rtb_Switch2;

  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Inport: '<Root>/ballMotor_Speed'
   */
  rtb_Error = ballMotor_Set_Desiredspeed - Robot_Control_U.ballMotor_Speed;

  /* Sum: '<S3>/Add' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Gain: '<S3>/Gain'
   *  Gain: '<S3>/Gain1'
   */
  rtb_Add = (Ballmotor_speed_Kff * ballMotor_Set_Desiredspeed) +
    (Ballmotor_speed_Kp * rtb_Error);

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S3>/Constant2'
   *  Inport: '<Root>/Gamepad_B3_X'
   *  RelationalOperator: '<S2>/Compare'
   *  Switch: '<S1>/Switch'
   */
  if (Robot_Control_U.Gamepad_B3_X != 0.0) {
    /* Sum: '<S3>/Sum2' incorporates:
     *  Gain: '<S3>/Gain2'
     *  UnitDelay: '<S3>/Unit Delay'
     */
    rtb_Error = (Ballmotor_speed_Ki * rtb_Error) +
      Robot_Control_DW.UnitDelay_DSTATE;

    /* Sum: '<S3>/Subtract' incorporates:
     *  Constant: '<S3>/Constant'
     */
    rtb_Switch2 = 1.0 - rtb_Add;

    /* Switch: '<S4>/Switch2' incorporates:
     *  Constant: '<S3>/Constant'
     *  RelationalOperator: '<S4>/LowerRelop1'
     *  Sum: '<S3>/Subtract'
     */
    if (!(rtb_Error > (1.0 - rtb_Add))) {
      /* Sum: '<S3>/Subtract1' incorporates:
       *  Constant: '<S3>/Constant1'
       */
      rtb_Switch2 = 0.0 - rtb_Add;

      /* Switch: '<S4>/Switch' incorporates:
       *  Constant: '<S3>/Constant1'
       *  RelationalOperator: '<S4>/UpperRelop'
       *  Sum: '<S3>/Subtract1'
       */
      if (!(rtb_Error < (0.0 - rtb_Add))) {
        rtb_Switch2 = rtb_Error;
      }

      /* End of Switch: '<S4>/Switch' */
    }

    /* End of Switch: '<S4>/Switch2' */

    /* Saturate: '<S3>/Saturation1' */
    if (rtb_Switch2 > 0.1) {
      rtb_Error = 0.1;
    } else if (rtb_Switch2 < -0.1) {
      rtb_Error = -0.1;
    } else {
      rtb_Error = rtb_Switch2;
    }

    /* End of Saturate: '<S3>/Saturation1' */

    /* Sum: '<S3>/Add1' */
    rtb_Add += rtb_Error;

    /* Saturate: '<S3>/Saturation2' */
    if (rtb_Add > 1.0) {
      /* Outport: '<Root>/ballMotor_Duty_Cycle' */
      Robot_Control_Y.ballMotor_Duty_Cycle = 1.0;
    } else if (rtb_Add < 0.0) {
      /* Outport: '<Root>/ballMotor_Duty_Cycle' */
      Robot_Control_Y.ballMotor_Duty_Cycle = 0.0;
    } else {
      /* Outport: '<Root>/ballMotor_Duty_Cycle' */
      Robot_Control_Y.ballMotor_Duty_Cycle = rtb_Add;
    }

    /* End of Saturate: '<S3>/Saturation2' */
  } else {
    rtb_Error = 0.0;

    /* Outport: '<Root>/ballMotor_Duty_Cycle' incorporates:
     *  Constant: '<S1>/Constant'
     *  Constant: '<S3>/Constant2'
     */
    Robot_Control_Y.ballMotor_Duty_Cycle = 0.0;
  }

  /* End of Switch: '<S3>/Switch' */

  /* Outport: '<Root>/HoodServo_Left_Position' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  Robot_Control_Y.HoodServo_Left_Position = HoodServo_Position;

  /* Outport: '<Root>/HoodServo_Right_Position' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  Robot_Control_Y.HoodServo_Right_Position = HoodServo_Position;

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  Robot_Control_DW.UnitDelay_DSTATE = rtb_Error;
}

/* Model initialize function */
void Robot_Control_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Robot_Control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
