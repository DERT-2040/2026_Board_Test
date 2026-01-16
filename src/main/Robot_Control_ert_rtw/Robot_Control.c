/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.c
 *
 * Code generated for Simulink model 'Robot_Control'.
 *
 * Model version                  : 2.434
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jan 15 20:21:29 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Robot_Control.h"
#include "rtwtypes.h"

/* Exported block parameters */
real_T ballMotor_Set_Duty_Cycle = 0.0; /* Variable: ballMotor_Set_Duty_Cycle
                                        * Referenced by: '<S1>/Constant1'
                                        */

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
  /* Switch: '<S1>/Switch' incorporates:
   *  Inport: '<Root>/Gamepad_B3_X'
   */
  if (Robot_Control_U.Gamepad_B3_X > 0.0) {
    /* Outport: '<Root>/ballMotor_Duty_Cycle' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    Robot_Control_Y.ballMotor_Duty_Cycle = ballMotor_Set_Duty_Cycle;
  } else {
    /* Outport: '<Root>/ballMotor_Duty_Cycle' incorporates:
     *  Constant: '<S1>/Constant'
     */
    Robot_Control_Y.ballMotor_Duty_Cycle = 0.0;
  }

  /* End of Switch: '<S1>/Switch' */
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
