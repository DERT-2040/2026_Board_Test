/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Robot_Control.h
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

#ifndef RTW_HEADER_Robot_Control_h_
#define RTW_HEADER_Robot_Control_h_
#ifndef Robot_Control_COMMON_INCLUDES_
#define Robot_Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Robot_Control_COMMON_INCLUDES_ */

#include "Robot_Control_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S3>/Unit Delay' */
} DW_Robot_Control_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T ballMotor_Speed;              /* '<Root>/ballMotor_Speed' */
  real_T Gamepad_B3_X;                 /* '<Root>/Gamepad_B3_X' */
} ExtU_Robot_Control_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T ballMotor_Duty_Cycle;         /* '<Root>/ballMotor_Duty_Cycle' */
  real_T HoodServo_Left_Position;      /* '<Root>/HoodServo_Left_Position' */
  real_T HoodServo_Right_Position;     /* '<Root>/HoodServo_Right_Position' */
} ExtY_Robot_Control_T;

/* Real-time Model Data Structure */
struct tag_RTM_Robot_Control_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Robot_Control_T Robot_Control_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Robot_Control_T Robot_Control_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Robot_Control_T Robot_Control_Y;

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T Ballmotor_speed_Kff;     /* Variable: Ballmotor_speed_Kff
                                        * Referenced by: '<S3>/Gain'
                                        */
extern real_T Ballmotor_speed_Ki;      /* Variable: Ballmotor_speed_Ki
                                        * Referenced by: '<S3>/Gain2'
                                        */
extern real_T Ballmotor_speed_Kp;      /* Variable: Ballmotor_speed_Kp
                                        * Referenced by: '<S3>/Gain1'
                                        */
extern real_T HoodServo_Position;      /* Variable: HoodServo_Position
                                        * Referenced by: '<S1>/Constant2'
                                        */
extern real_T ballMotor_Set_Desiredspeed;/* Variable: ballMotor_Set_Desiredspeed
                                          * Referenced by: '<S1>/Constant1'
                                          */

/* Model entry point functions */
extern void Robot_Control_initialize(void);
extern void Robot_Control_step(void);
extern void Robot_Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Robot_Control_T *const Robot_Control_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Robot_Control'
 * '<S1>'   : 'Robot_Control/Control_System'
 * '<S2>'   : 'Robot_Control/Control_System/Compare To Zero'
 * '<S3>'   : 'Robot_Control/Control_System/Feed Forward plus PI and Integral Enable'
 * '<S4>'   : 'Robot_Control/Control_System/Feed Forward plus PI and Integral Enable/Saturation Dynamic'
 */
#endif                                 /* RTW_HEADER_Robot_Control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
