/*
 * UAV_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "UAV".
 *
 * Model version              : 1.11
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C++ source code generated on : Mon Mar 31 17:31:06 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "UAV.h"

/* Block parameters (default storage) */
P_UAV_T UAV::UAV_P{
  /* Variable: Kd
   * Referenced by: '<S29>/Derivative Gain'
   */
  1.10844,

  /* Variable: Ki
   * Referenced by: '<S33>/Integral Gain'
   */
  2.48,

  /* Variable: Kp
   * Referenced by: '<S41>/Proportional Gain'
   */
  30.7142,

  /* Variable: angle_change_start_time
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Variable: final_angle
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Variable: initial_angle
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S31>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditio_h
   * Referenced by: '<S36>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S39>/Filter Coefficient'
   */
  100.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<Root>/Transfer Fcn'
   */
  { -6.9676, -12.941, -0.0 },

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<Root>/Transfer Fcn'
   */
  { 0.0, 11.7304, 22.578 }
};
