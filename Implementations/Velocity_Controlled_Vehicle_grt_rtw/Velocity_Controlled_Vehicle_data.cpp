/*
 * Velocity_Controlled_Vehicle_data.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Velocity_Controlled_Vehicle".
 *
 * Model version              : 1.0
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C++ source code generated on : Tue Jun 27 17:10:21 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objective: Debugging
 * Validation result: Not run
 */

#include "Velocity_Controlled_Vehicle.h"
#include "Velocity_Controlled_Vehicle_private.h"

/* Block parameters (default storage) */
P_Velocity_Controlled_Vehicle_T Velocity_Controlled_VehicleModelClass::
  Velocity_Controlled_Vehicle_P{
  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 30
   * Referenced by: '<Root>/Sine Wave'
   */
  30.0,

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

  /* Computed Parameter: car_transfer_fcn_A
   * Referenced by: '<S2>/car_transfer_fcn'
   */
  { -2.0, -0.0 },

  /* Computed Parameter: car_transfer_fcn_C
   * Referenced by: '<S2>/car_transfer_fcn'
   */
  { 0.0, 2.0 },

  /* Expression: 5
   * Referenced by: '<S1>/Kp'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S1>/Integrator'
   */
  0.0,

  /* Expression: 1.5
   * Referenced by: '<S1>/Ki'
   */
  1.5
};
