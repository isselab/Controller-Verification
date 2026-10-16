/*
 * my_mpcACCsystem_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "my_mpcACCsystem".
 *
 * Model version              : 1.39
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C++ source code generated on : Mon Apr 26 19:25:48 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "my_mpcACCsystem.h"
#include "my_mpcACCsystem_private.h"

/* Block parameters (default storage) */
P_my_mpcACCsystem_T my_mpcACCsystemModelClass::my_mpcACCsystem_P = {
  /* Variable: A_acc_lead
   * Referenced by: '<Root>/Sine Wave'
   */
  0.6,

  /* Variable: D_default
   * Referenced by: '<S1>/Constant'
   */
  10.0,

  /* Variable: amax_ego
   * Referenced by:
   *   '<S47>/Saturation'
   *   '<S97>/Saturation'
   *   '<S33>/DeadZone'
   *   '<S83>/DeadZone'
   */
  1.0,

  /* Variable: amin_ego
   * Referenced by:
   *   '<S47>/Saturation'
   *   '<S97>/Saturation'
   *   '<S33>/DeadZone'
   *   '<S83>/DeadZone'
   */
  -1.0,

  /* Variable: t_gap
   * Referenced by: '<Root>/Time gap'
   */
  1.4,

  /* Variable: v0_ego
   * Referenced by: '<Root>/v0 host'
   */
  20.0,

  /* Variable: v0_lead
   * Referenced by: '<Root>/v0 lead'
   */
  10.0,

  /* Variable: v_set
   * Referenced by: '<Root>/Set velocity'
   */
  30.0,

  /* Variable: x0_ego
   * Referenced by: '<Root>/x0 host'
   */
  0.0,

  /* Variable: x0_lead
   * Referenced by: '<Root>/x0 lead'
   */
  70.0,

  /* Mask Parameter: PIDController_D
   * Referenced by: '<S34>/Derivative Gain'
   */
  1.5,

  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S84>/Derivative Gain'
   */
  -1.1,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S37>/Integral Gain'
   */
  2.0,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S87>/Integral Gain'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S35>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialCondition
   * Referenced by: '<S85>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_l
   * Referenced by: '<S40>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditi_k
   * Referenced by: '<S90>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S43>/Filter Coefficient'
   */
  40.0,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S93>/Filter Coefficient'
   */
  7.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S45>/Proportional Gain'
   */
  5.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S95>/Proportional Gain'
   */
  -1.5,

  /* Expression: 0
   * Referenced by: '<S31>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S81>/Constant1'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S2>/Transfer Fcn'
   */
  -2.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S2>/Transfer Fcn'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S31>/ZeroGain'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S81>/ZeroGain'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A_i
   * Referenced by: '<S3>/Transfer Fcn'
   */
  -2.0,

  /* Computed Parameter: TransferFcn_C_f
   * Referenced by: '<S3>/Transfer Fcn'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<Root>/Sine Wave'
   */
  0.2,

  /* Computed Parameter: SineWave_Hsin
   * Referenced by: '<Root>/Sine Wave'
   */
  0.019998666693333084,

  /* Computed Parameter: SineWave_HCos
   * Referenced by: '<Root>/Sine Wave'
   */
  0.99980000666657776,

  /* Computed Parameter: SineWave_PSin
   * Referenced by: '<Root>/Sine Wave'
   */
  -0.019998666693333084,

  /* Computed Parameter: SineWave_PCos
   * Referenced by: '<Root>/Sine Wave'
   */
  0.99980000666657776,

  /* Computed Parameter: Memory_InitialCondition
   * Referenced by: '<S31>/Memory'
   */
  0,

  /* Computed Parameter: Memory_InitialCondition_e
   * Referenced by: '<S81>/Memory'
   */
  0
};
