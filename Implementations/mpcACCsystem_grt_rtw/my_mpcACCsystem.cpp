/*
 * my_mpcACCsystem.cpp
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

#include <iostream>
#include <dios.h>
#include <sys/divm.h>

/* Named constants for Chart: '<S1>/Chart' */
const uint8_T my_mpcACCsyst_IN_Safety_control = 1U;
const uint8_T my_mpcACCsyste_IN_Speed_control = 2U;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void my_mpcACCsystemModelClass::rt_ertODEUpdateContinuousStates(RTWSolverInfo
  *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 10;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  my_mpcACCsystem_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  my_mpcACCsystem_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  this->step();
  my_mpcACCsystem_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void my_mpcACCsystemModelClass::step()
{ 
  if (rtmIsMajorTimeStep((&my_mpcACCsystem_M))) {
    /* set solver stop time */
    if (!((&my_mpcACCsystem_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&my_mpcACCsystem_M)->solverInfo,
                            (((&my_mpcACCsystem_M)->Timing.clockTickH0 + 1) *
        (&my_mpcACCsystem_M)->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&my_mpcACCsystem_M)->solverInfo,
                            (((&my_mpcACCsystem_M)->Timing.clockTick0 + 1) *
        (&my_mpcACCsystem_M)->Timing.stepSize0 + (&my_mpcACCsystem_M)
        ->Timing.clockTickH0 * (&my_mpcACCsystem_M)->Timing.stepSize0 *
        4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&my_mpcACCsystem_M))) {
    (&my_mpcACCsystem_M)->Timing.t[0] = rtsiGetT(&(&my_mpcACCsystem_M)
      ->solverInfo);
  }

  {
    real_T u;
    real_T u1;
    real_T u2;

    /* TransferFcn: '<S2>/Transfer Fcn' */
    my_mpcACCsystem_B.TransferFcn = 0.0;
    my_mpcACCsystem_B.TransferFcn += my_mpcACCsystem_P.TransferFcn_C *
      my_mpcACCsystem_X.TransferFcn_CSTATE;

    /* Sum: '<S2>/Sum1' incorporates:
     *  Constant: '<Root>/v0 host'
     */
    my_mpcACCsystem_B.Sum1 = my_mpcACCsystem_B.TransferFcn +
      my_mpcACCsystem_P.v0_ego;

    /* Sum: '<S1>/Sum2' incorporates:
     *  Constant: '<Root>/Set velocity'
     */
    my_mpcACCsystem_B.e_v = my_mpcACCsystem_P.v_set - my_mpcACCsystem_B.Sum1; // !!! Calc error velocity

    /* Product: '<S1>/Product2' incorporates:
     *  Constant: '<Root>/Time gap'
     */
    my_mpcACCsystem_B.Product2 = my_mpcACCsystem_B.Sum1 *
      my_mpcACCsystem_P.t_gap;

    /* Sum: '<S1>/Sum1' incorporates:
     *  Constant: '<S1>/Constant'
     */
    my_mpcACCsystem_B.safe_distance = my_mpcACCsystem_B.Product2 +
      my_mpcACCsystem_P.D_default;

    /* Integrator: '<S3>/Integrator1' */
    my_mpcACCsystem_B.Integrator1 = my_mpcACCsystem_X.Integrator1_CSTATE;

    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<Root>/x0 lead'
     */
    my_mpcACCsystem_B.Sum = my_mpcACCsystem_P.x0_lead +
      my_mpcACCsystem_B.Integrator1;

    /* Integrator: '<S2>/Integrator1' */
    my_mpcACCsystem_B.Integrator1_d = my_mpcACCsystem_X.Integrator1_CSTATE_d;

    /* Sum: '<S2>/Sum' incorporates:
     *  Constant: '<Root>/x0 host'
     */
    my_mpcACCsystem_B.Sum_g = my_mpcACCsystem_P.x0_ego +
      my_mpcACCsystem_B.Integrator1_d;

    /* Sum: '<Root>/Sum' */
    my_mpcACCsystem_B.d_rel = my_mpcACCsystem_B.Sum - my_mpcACCsystem_B.Sum_g;

    /* Sum: '<S1>/Sum3' */
    my_mpcACCsystem_B.e_d = my_mpcACCsystem_B.safe_distance -
      my_mpcACCsystem_B.d_rel; // !!! Calc error distance


    /*Time for the Observer*/
    time_T timing = rtsiGetT(&(&my_mpcACCsystem_M)->solverInfo);

    /* Observer for Distance Control*/

    DistanceObserver.setExternalInput(my_mpcACCsystem_B.safe_distance, my_mpcACCsystem_B.e_d, my_mpcACCsystem_B.d_rel, timing);
    DistanceObserver.transition();
  
    // AP[safe] = (my_mpcACCsystem_B.d_rel - my_mpcACCsystem_B.safe_distance) > 0.05 * my_mpcACCsystem_B.safe_distance;

    if (rtmIsMajorTimeStep((&my_mpcACCsystem_M))) {
      /* Chart: '<S1>/Chart' */
      if (my_mpcACCsystem_DW.is_active_c3_my_mpcACCsystem == 0U) {
        my_mpcACCsystem_DW.is_active_c3_my_mpcACCsystem = 1U;
        my_mpcACCsystem_DW.is_c3_my_mpcACCsystem =
          my_mpcACCsyste_IN_Speed_control;
        /* :  y=1; */
        my_mpcACCsystem_B.y = 1.0;
      } else if (my_mpcACCsystem_DW.is_c3_my_mpcACCsystem == 1) {
        /* :  sf_internal_predicateOutput = (e_v<0); */
        if (my_mpcACCsystem_B.e_v < 0.0) {
          my_mpcACCsystem_DW.is_c3_my_mpcACCsystem =
            my_mpcACCsyste_IN_Speed_control;

          /* :  y=1; */
          my_mpcACCsystem_B.y = 1.0;
        } else {
          /* :  y=-1; */
          my_mpcACCsystem_B.y = -1.0;
        }

        /* case IN_Speed_control: */
        /* :  sf_internal_predicateOutput = (e_d > 0); */
      } else if (my_mpcACCsystem_B.e_d > 0.0) {
        my_mpcACCsystem_DW.is_c3_my_mpcACCsystem =
          my_mpcACCsyst_IN_Safety_control;
        /* :  y=-1; */
        my_mpcACCsystem_B.y = -1.0;
      } else {
        /* :  y=1; */
        my_mpcACCsystem_B.y = 1.0;
      }

      /* End of Chart: '<S1>/Chart' */
    }

    /* Gain: '<S45>/Proportional Gain' */
    my_mpcACCsystem_B.ProportionalGain = my_mpcACCsystem_P.PIDController_P *
      my_mpcACCsystem_B.e_v;

    /* Integrator: '<S40>/Integrator' */
    my_mpcACCsystem_B.Integrator = my_mpcACCsystem_X.Integrator_CSTATE;

    /* Gain: '<S34>/Derivative Gain' */
    my_mpcACCsystem_B.DerivativeGain = my_mpcACCsystem_P.PIDController_D *
      my_mpcACCsystem_B.e_v;

    /* Integrator: '<S35>/Filter' */
    my_mpcACCsystem_B.Filter = my_mpcACCsystem_X.Filter_CSTATE;

    /* Sum: '<S35>/SumD' */
    my_mpcACCsystem_B.SumD = my_mpcACCsystem_B.DerivativeGain -
      my_mpcACCsystem_B.Filter;

    /* Gain: '<S43>/Filter Coefficient' */
    my_mpcACCsystem_B.FilterCoefficient = my_mpcACCsystem_P.PIDController_N *
      my_mpcACCsystem_B.SumD;

    /* Sum: '<S49>/Sum' */
    my_mpcACCsystem_B.Sum_a = (my_mpcACCsystem_B.ProportionalGain +
      my_mpcACCsystem_B.Integrator) + my_mpcACCsystem_B.FilterCoefficient;

    /* Gain: '<S31>/ZeroGain' */
    my_mpcACCsystem_B.ZeroGain = my_mpcACCsystem_P.ZeroGain_Gain *
      my_mpcACCsystem_B.Sum_a;

    /* DeadZone: '<S33>/DeadZone' */
    if (my_mpcACCsystem_B.Sum_a > my_mpcACCsystem_P.amax_ego) {
      /* DeadZone: '<S33>/DeadZone' */
      my_mpcACCsystem_B.DeadZone = my_mpcACCsystem_B.Sum_a -
        my_mpcACCsystem_P.amax_ego;
    } else if (my_mpcACCsystem_B.Sum_a >= my_mpcACCsystem_P.amin_ego) {
      /* DeadZone: '<S33>/DeadZone' */
      my_mpcACCsystem_B.DeadZone = 0.0;
    } else {
      /* DeadZone: '<S33>/DeadZone' */
      my_mpcACCsystem_B.DeadZone = my_mpcACCsystem_B.Sum_a -
        my_mpcACCsystem_P.amin_ego;
    }

    /* End of DeadZone: '<S33>/DeadZone' */

    /* RelationalOperator: '<S31>/NotEqual' */
    my_mpcACCsystem_B.NotEqual = (my_mpcACCsystem_B.ZeroGain !=
      my_mpcACCsystem_B.DeadZone);

    /* Signum: '<S31>/SignPreSat' */
    u = my_mpcACCsystem_B.DeadZone;
    if (u < 0.0) {
      /* Signum: '<S31>/SignPreSat' */
      my_mpcACCsystem_B.SignPreSat = -1.0;
    } else if (u > 0.0) {
      /* Signum: '<S31>/SignPreSat' */
      my_mpcACCsystem_B.SignPreSat = 1.0;
    } else if (u == 0.0) {
      /* Signum: '<S31>/SignPreSat' */
      my_mpcACCsystem_B.SignPreSat = 0.0;
    } else {
      /* Signum: '<S31>/SignPreSat' */
      my_mpcACCsystem_B.SignPreSat = (rtNaN);
    }

    /* End of Signum: '<S31>/SignPreSat' */

    /* DataTypeConversion: '<S31>/DataTypeConv1' */
    u = std::floor(my_mpcACCsystem_B.SignPreSat);
    if (rtIsNaN(u) || rtIsInf(u)) {
      u = 0.0;
    } else {
      u = std::fmod(u, 256.0);
    }

    /* DataTypeConversion: '<S31>/DataTypeConv1' */
    my_mpcACCsystem_B.DataTypeConv1 = static_cast<int8_T>(u < 0.0 ?
      static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
      (static_cast<uint8_T>(-u)))) : static_cast<int32_T>(static_cast<int8_T>(
      static_cast<uint8_T>(u))));

    /* Gain: '<S37>/Integral Gain' */
    my_mpcACCsystem_B.IntegralGain = my_mpcACCsystem_P.PIDController_I *
      my_mpcACCsystem_B.e_v;

    /* Signum: '<S31>/SignPreIntegrator' */
    u = my_mpcACCsystem_B.IntegralGain;
    if (u < 0.0) {
      /* Signum: '<S31>/SignPreIntegrator' */
      my_mpcACCsystem_B.SignPreIntegrator = -1.0;
    } else if (u > 0.0) {
      /* Signum: '<S31>/SignPreIntegrator' */
      my_mpcACCsystem_B.SignPreIntegrator = 1.0;
    } else if (u == 0.0) {
      /* Signum: '<S31>/SignPreIntegrator' */
      my_mpcACCsystem_B.SignPreIntegrator = 0.0;
    } else {
      /* Signum: '<S31>/SignPreIntegrator' */
      my_mpcACCsystem_B.SignPreIntegrator = (rtNaN);
    }

    /* End of Signum: '<S31>/SignPreIntegrator' */

    /* DataTypeConversion: '<S31>/DataTypeConv2' */
    u = std::floor(my_mpcACCsystem_B.SignPreIntegrator);
    if (rtIsNaN(u) || rtIsInf(u)) {
      u = 0.0;
    } else {
      u = std::fmod(u, 256.0);
    }

    /* DataTypeConversion: '<S31>/DataTypeConv2' */
    my_mpcACCsystem_B.DataTypeConv2 = static_cast<int8_T>(u < 0.0 ?
      static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
      (static_cast<uint8_T>(-u)))) : static_cast<int32_T>(static_cast<int8_T>(
      static_cast<uint8_T>(u))));

    /* RelationalOperator: '<S31>/Equal1' */
    my_mpcACCsystem_B.Equal1 = (my_mpcACCsystem_B.DataTypeConv1 ==
      my_mpcACCsystem_B.DataTypeConv2);

    /* Logic: '<S31>/AND3' */
    my_mpcACCsystem_B.AND3 = (my_mpcACCsystem_B.NotEqual &&
      my_mpcACCsystem_B.Equal1);
    if (rtmIsMajorTimeStep((&my_mpcACCsystem_M))) {
      /* Memory: '<S31>/Memory' */
      my_mpcACCsystem_B.Memory = my_mpcACCsystem_DW.Memory_PreviousInput;
    }

    /* Switch: '<S31>/Switch' */
    if (my_mpcACCsystem_B.Memory) {
      /* Switch: '<S31>/Switch' incorporates:
       *  Constant: '<S31>/Constant1'
       */
      my_mpcACCsystem_B.Switch = my_mpcACCsystem_P.Constant1_Value;
    } else {
      /* Switch: '<S31>/Switch' */
      my_mpcACCsystem_B.Switch = my_mpcACCsystem_B.IntegralGain;
    }

    /* End of Switch: '<S31>/Switch' */

    /* Saturate: '<S47>/Saturation' */
    u = my_mpcACCsystem_B.Sum_a;
    u1 = my_mpcACCsystem_P.amin_ego;
    u2 = my_mpcACCsystem_P.amax_ego;
    if (u > u2) {
      /* Saturate: '<S47>/Saturation' */
      my_mpcACCsystem_B.Saturation = u2;
    } else if (u < u1) {
      /* Saturate: '<S47>/Saturation' */
      my_mpcACCsystem_B.Saturation = u1;
    } else {
      /* Saturate: '<S47>/Saturation' */
      my_mpcACCsystem_B.Saturation = u;
    }

    /* End of Saturate: '<S47>/Saturation' */

    /* Gain: '<S95>/Proportional Gain' */
    my_mpcACCsystem_B.ProportionalGain_p = my_mpcACCsystem_P.PIDController1_P *
      my_mpcACCsystem_B.e_d;

    /* Integrator: '<S90>/Integrator' */
    my_mpcACCsystem_B.Integrator_c = my_mpcACCsystem_X.Integrator_CSTATE_j;

    /* Gain: '<S84>/Derivative Gain' */
    my_mpcACCsystem_B.DerivativeGain_i = my_mpcACCsystem_P.PIDController1_D *
      my_mpcACCsystem_B.e_d;

    /* Integrator: '<S85>/Filter' */
    my_mpcACCsystem_B.Filter_p = my_mpcACCsystem_X.Filter_CSTATE_j;

    /* Sum: '<S85>/SumD' */
    my_mpcACCsystem_B.SumD_f = my_mpcACCsystem_B.DerivativeGain_i -
      my_mpcACCsystem_B.Filter_p;

    /* Gain: '<S93>/Filter Coefficient' */
    my_mpcACCsystem_B.FilterCoefficient_d = my_mpcACCsystem_P.PIDController1_N *
      my_mpcACCsystem_B.SumD_f;

    /* Sum: '<S99>/Sum' */
    my_mpcACCsystem_B.Sum_b = (my_mpcACCsystem_B.ProportionalGain_p +
      my_mpcACCsystem_B.Integrator_c) + my_mpcACCsystem_B.FilterCoefficient_d;

    /* Gain: '<S81>/ZeroGain' */
    my_mpcACCsystem_B.ZeroGain_j = my_mpcACCsystem_P.ZeroGain_Gain_i *
      my_mpcACCsystem_B.Sum_b;

    /* DeadZone: '<S83>/DeadZone' */
    if (my_mpcACCsystem_B.Sum_b > my_mpcACCsystem_P.amax_ego) {
      /* DeadZone: '<S83>/DeadZone' */
      my_mpcACCsystem_B.DeadZone_l = my_mpcACCsystem_B.Sum_b -
        my_mpcACCsystem_P.amax_ego;
    } else if (my_mpcACCsystem_B.Sum_b >= my_mpcACCsystem_P.amin_ego) {
      /* DeadZone: '<S83>/DeadZone' */
      my_mpcACCsystem_B.DeadZone_l = 0.0;
    } else {
      /* DeadZone: '<S83>/DeadZone' */
      my_mpcACCsystem_B.DeadZone_l = my_mpcACCsystem_B.Sum_b -
        my_mpcACCsystem_P.amin_ego;
    }

    /* End of DeadZone: '<S83>/DeadZone' */

    /* RelationalOperator: '<S81>/NotEqual' */
    my_mpcACCsystem_B.NotEqual_o = (my_mpcACCsystem_B.ZeroGain_j !=
      my_mpcACCsystem_B.DeadZone_l);

    /* Signum: '<S81>/SignPreSat' */
    u = my_mpcACCsystem_B.DeadZone_l;
    if (u < 0.0) {
      /* Signum: '<S81>/SignPreSat' */
      my_mpcACCsystem_B.SignPreSat_o = -1.0;
    } else if (u > 0.0) {
      /* Signum: '<S81>/SignPreSat' */
      my_mpcACCsystem_B.SignPreSat_o = 1.0;
    } else if (u == 0.0) {
      /* Signum: '<S81>/SignPreSat' */
      my_mpcACCsystem_B.SignPreSat_o = 0.0;
    } else {
      /* Signum: '<S81>/SignPreSat' */
      my_mpcACCsystem_B.SignPreSat_o = (rtNaN);
    }

    /* End of Signum: '<S81>/SignPreSat' */

    /* DataTypeConversion: '<S81>/DataTypeConv1' */
    u = std::floor(my_mpcACCsystem_B.SignPreSat_o);
    if (rtIsNaN(u) || rtIsInf(u)) {
      u = 0.0;
    } else {
      u = std::fmod(u, 256.0);
    }

    /* DataTypeConversion: '<S81>/DataTypeConv1' */
    my_mpcACCsystem_B.DataTypeConv1_b = static_cast<int8_T>(u < 0.0 ?
      static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
      (static_cast<uint8_T>(-u)))) : static_cast<int32_T>(static_cast<int8_T>(
      static_cast<uint8_T>(u))));

    /* Gain: '<S87>/Integral Gain' */
    my_mpcACCsystem_B.IntegralGain_j = my_mpcACCsystem_P.PIDController1_I *
      my_mpcACCsystem_B.e_d;

    /* Signum: '<S81>/SignPreIntegrator' */
    u = my_mpcACCsystem_B.IntegralGain_j;
    if (u < 0.0) {
      /* Signum: '<S81>/SignPreIntegrator' */
      my_mpcACCsystem_B.SignPreIntegrator_l = -1.0;
    } else if (u > 0.0) {
      /* Signum: '<S81>/SignPreIntegrator' */
      my_mpcACCsystem_B.SignPreIntegrator_l = 1.0;
    } else if (u == 0.0) {
      /* Signum: '<S81>/SignPreIntegrator' */
      my_mpcACCsystem_B.SignPreIntegrator_l = 0.0;
    } else {
      /* Signum: '<S81>/SignPreIntegrator' */
      my_mpcACCsystem_B.SignPreIntegrator_l = (rtNaN);
    }

    /* End of Signum: '<S81>/SignPreIntegrator' */

    /* DataTypeConversion: '<S81>/DataTypeConv2' */
    u = std::floor(my_mpcACCsystem_B.SignPreIntegrator_l);
    if (rtIsNaN(u) || rtIsInf(u)) {
      u = 0.0;
    } else {
      u = std::fmod(u, 256.0);
    }

    /* DataTypeConversion: '<S81>/DataTypeConv2' */
    my_mpcACCsystem_B.DataTypeConv2_l = static_cast<int8_T>(u < 0.0 ?
      static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
      (static_cast<uint8_T>(-u)))) : static_cast<int32_T>(static_cast<int8_T>(
      static_cast<uint8_T>(u))));

    /* RelationalOperator: '<S81>/Equal1' */
    my_mpcACCsystem_B.Equal1_l = (my_mpcACCsystem_B.DataTypeConv1_b ==
      my_mpcACCsystem_B.DataTypeConv2_l);

    /* Logic: '<S81>/AND3' */
    my_mpcACCsystem_B.AND3_i = (my_mpcACCsystem_B.NotEqual_o &&
      my_mpcACCsystem_B.Equal1_l);
    if (rtmIsMajorTimeStep((&my_mpcACCsystem_M))) {
      /* Memory: '<S81>/Memory' */
      my_mpcACCsystem_B.Memory_j = my_mpcACCsystem_DW.Memory_PreviousInput_d;
    }

    /* Switch: '<S81>/Switch' */
    if (my_mpcACCsystem_B.Memory_j) {
      /* Switch: '<S81>/Switch' incorporates:
       *  Constant: '<S81>/Constant1'
       */
      my_mpcACCsystem_B.Switch_f = my_mpcACCsystem_P.Constant1_Value_k;
    } else {
      /* Switch: '<S81>/Switch' */
      my_mpcACCsystem_B.Switch_f = my_mpcACCsystem_B.IntegralGain_j;
    }

    /* End of Switch: '<S81>/Switch' */

    /* Saturate: '<S97>/Saturation' */
    u = my_mpcACCsystem_B.Sum_b;
    u1 = my_mpcACCsystem_P.amin_ego;
    u2 = my_mpcACCsystem_P.amax_ego;
    if (u > u2) {
      /* Saturate: '<S97>/Saturation' */
      my_mpcACCsystem_B.Saturation_e = u2;
    } else if (u < u1) {
      /* Saturate: '<S97>/Saturation' */
      my_mpcACCsystem_B.Saturation_e = u1;
    } else {
      /* Saturate: '<S97>/Saturation' */
      my_mpcACCsystem_B.Saturation_e = u;
    }

    /* End of Saturate: '<S97>/Saturation' */

    /* Switch: '<S1>/Switch' */
    if (my_mpcACCsystem_B.y > my_mpcACCsystem_P.Switch_Threshold) {
      /* Switch: '<S1>/Switch' */
      my_mpcACCsystem_B.a_ego = my_mpcACCsystem_B.Saturation;
    } else {
      /* Switch: '<S1>/Switch' */
      my_mpcACCsystem_B.a_ego = my_mpcACCsystem_B.Saturation_e;
    }

    /* End of Switch: '<S1>/Switch' */

    /* Integrator: '<S2>/Integrator' */
    my_mpcACCsystem_B.Integrator_b = my_mpcACCsystem_X.Integrator_CSTATE_a;

    /* Integrator: '<S3>/Integrator' */
    my_mpcACCsystem_B.Integrator_d = my_mpcACCsystem_X.Integrator_CSTATE_i;

    /* TransferFcn: '<S3>/Transfer Fcn' */
    my_mpcACCsystem_B.TransferFcn_m = 0.0;
    my_mpcACCsystem_B.TransferFcn_m += my_mpcACCsystem_P.TransferFcn_C_f *
      my_mpcACCsystem_X.TransferFcn_CSTATE_a;

    /* Sum: '<S3>/Sum1' incorporates:
     *  Constant: '<Root>/v0 lead'
     */
    my_mpcACCsystem_B.Sum1_a = my_mpcACCsystem_B.TransferFcn_m +
      my_mpcACCsystem_P.v0_lead;
    if (rtmIsMajorTimeStep((&my_mpcACCsystem_M))) {
      /* Sin: '<Root>/Sine Wave' */
      if (my_mpcACCsystem_DW.systemEnable != 0) {
        my_mpcACCsystem_DW.lastSin = std::sin(my_mpcACCsystem_P.SineWave_Freq *
          ((((&my_mpcACCsystem_M)->Timing.clockTick1+(&my_mpcACCsystem_M)
             ->Timing.clockTickH1* 4294967296.0)) * 0.1));
        my_mpcACCsystem_DW.lastCos = std::cos(my_mpcACCsystem_P.SineWave_Freq *
          ((((&my_mpcACCsystem_M)->Timing.clockTick1+(&my_mpcACCsystem_M)
             ->Timing.clockTickH1* 4294967296.0)) * 0.1));
        my_mpcACCsystem_DW.systemEnable = 0;
      } 

      /* Sin: '<Root>/Sine Wave' */
      my_mpcACCsystem_B.a_lead = ((my_mpcACCsystem_DW.lastSin *
        my_mpcACCsystem_P.SineWave_PCos + my_mpcACCsystem_DW.lastCos *
        my_mpcACCsystem_P.SineWave_PSin) * my_mpcACCsystem_P.SineWave_HCos +
        (my_mpcACCsystem_DW.lastCos * my_mpcACCsystem_P.SineWave_PCos -
         my_mpcACCsystem_DW.lastSin * my_mpcACCsystem_P.SineWave_PSin) *
        my_mpcACCsystem_P.SineWave_Hsin) * my_mpcACCsystem_P.A_acc_lead +
        my_mpcACCsystem_P.SineWave_Bias;
    }


  }

  if (rtmIsMajorTimeStep((&my_mpcACCsystem_M))) {
    /* Matfile logging */
    rt_UpdateTXYLogVars((&my_mpcACCsystem_M)->rtwLogInfo, ((&my_mpcACCsystem_M
      )->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep((&my_mpcACCsystem_M))) {
    real_T HoldCosine;
    real_T HoldSine;
    if (rtmIsMajorTimeStep((&my_mpcACCsystem_M))) {
      /* Update for Memory: '<S31>/Memory' */
      my_mpcACCsystem_DW.Memory_PreviousInput = my_mpcACCsystem_B.AND3;

      /* Update for Memory: '<S81>/Memory' */
      my_mpcACCsystem_DW.Memory_PreviousInput_d = my_mpcACCsystem_B.AND3_i;

      /* Update for Sin: '<Root>/Sine Wave' */
      HoldSine = my_mpcACCsystem_DW.lastSin;
      HoldCosine = my_mpcACCsystem_DW.lastCos;
      my_mpcACCsystem_DW.lastSin = HoldSine * my_mpcACCsystem_P.SineWave_HCos +
        HoldCosine * my_mpcACCsystem_P.SineWave_Hsin;
      my_mpcACCsystem_DW.lastCos = HoldCosine * my_mpcACCsystem_P.SineWave_HCos
        - HoldSine * my_mpcACCsystem_P.SineWave_Hsin;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep((&my_mpcACCsystem_M))) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal((&my_mpcACCsystem_M))!=-1) &&
          !((rtmGetTFinal((&my_mpcACCsystem_M))-((((&my_mpcACCsystem_M)
               ->Timing.clockTick1+(&my_mpcACCsystem_M)->Timing.clockTickH1*
               4294967296.0)) * 0.1)) > ((((&my_mpcACCsystem_M)
              ->Timing.clockTick1+(&my_mpcACCsystem_M)->Timing.clockTickH1*
              4294967296.0)) * 0.1) * (DBL_EPSILON))) {
        rtmSetErrorStatus((&my_mpcACCsystem_M), "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&(&my_mpcACCsystem_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&my_mpcACCsystem_M)->Timing.clockTick0)) {
      ++(&my_mpcACCsystem_M)->Timing.clockTickH0;
    }

    (&my_mpcACCsystem_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&my_mpcACCsystem_M)->solverInfo);

    {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      (&my_mpcACCsystem_M)->Timing.clockTick1++;
      if (!(&my_mpcACCsystem_M)->Timing.clockTick1) {
        (&my_mpcACCsystem_M)->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void my_mpcACCsystemModelClass::my_mpcACCsystem_derivatives()
{
  XDot_my_mpcACCsystem_T *_rtXdot;
  _rtXdot = ((XDot_my_mpcACCsystem_T *) (&my_mpcACCsystem_M)->derivs);

  /* Derivatives for TransferFcn: '<S2>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += my_mpcACCsystem_P.TransferFcn_A *
    my_mpcACCsystem_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += my_mpcACCsystem_B.Integrator_b;

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = my_mpcACCsystem_B.Sum1_a;

  /* Derivatives for Integrator: '<S2>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_d = my_mpcACCsystem_B.Sum1;

  /* Derivatives for Integrator: '<S40>/Integrator' */
  _rtXdot->Integrator_CSTATE = my_mpcACCsystem_B.Switch;

  /* Derivatives for Integrator: '<S35>/Filter' */
  _rtXdot->Filter_CSTATE = my_mpcACCsystem_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S90>/Integrator' */
  _rtXdot->Integrator_CSTATE_j = my_mpcACCsystem_B.Switch_f;

  /* Derivatives for Integrator: '<S85>/Filter' */
  _rtXdot->Filter_CSTATE_j = my_mpcACCsystem_B.FilterCoefficient_d;

  /* Derivatives for Integrator: '<S2>/Integrator' */
  _rtXdot->Integrator_CSTATE_a = my_mpcACCsystem_B.a_ego;

  /* Derivatives for Integrator: '<S3>/Integrator' */
  _rtXdot->Integrator_CSTATE_i = my_mpcACCsystem_B.a_lead;

  /* Derivatives for TransferFcn: '<S3>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_a = 0.0;
  _rtXdot->TransferFcn_CSTATE_a += my_mpcACCsystem_P.TransferFcn_A_i *
    my_mpcACCsystem_X.TransferFcn_CSTATE_a;
  _rtXdot->TransferFcn_CSTATE_a += my_mpcACCsystem_B.Integrator_d;
}

/* Model initialize function */
void my_mpcACCsystemModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&my_mpcACCsystem_M)->solverInfo,
                          &(&my_mpcACCsystem_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&my_mpcACCsystem_M)->solverInfo, &rtmGetTPtr
                ((&my_mpcACCsystem_M)));
    rtsiSetStepSizePtr(&(&my_mpcACCsystem_M)->solverInfo, &(&my_mpcACCsystem_M
                       )->Timing.stepSize0);
    rtsiSetdXPtr(&(&my_mpcACCsystem_M)->solverInfo, &(&my_mpcACCsystem_M)
                 ->derivs);
    rtsiSetContStatesPtr(&(&my_mpcACCsystem_M)->solverInfo, (real_T **)
                         &(&my_mpcACCsystem_M)->contStates);
    rtsiSetNumContStatesPtr(&(&my_mpcACCsystem_M)->solverInfo,
      &(&my_mpcACCsystem_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&my_mpcACCsystem_M)->solverInfo,
      &(&my_mpcACCsystem_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&my_mpcACCsystem_M)->solverInfo,
      &(&my_mpcACCsystem_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&my_mpcACCsystem_M)->solverInfo,
      &(&my_mpcACCsystem_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&my_mpcACCsystem_M)->solverInfo, (&rtmGetErrorStatus
      ((&my_mpcACCsystem_M))));
    rtsiSetRTModelPtr(&(&my_mpcACCsystem_M)->solverInfo, (&my_mpcACCsystem_M));
  }

  rtsiSetSimTimeStep(&(&my_mpcACCsystem_M)->solverInfo, MAJOR_TIME_STEP);
  (&my_mpcACCsystem_M)->intgData.y = (&my_mpcACCsystem_M)->odeY;
  (&my_mpcACCsystem_M)->intgData.f[0] = (&my_mpcACCsystem_M)->odeF[0];
  (&my_mpcACCsystem_M)->intgData.f[1] = (&my_mpcACCsystem_M)->odeF[1];
  (&my_mpcACCsystem_M)->intgData.f[2] = (&my_mpcACCsystem_M)->odeF[2];
  (&my_mpcACCsystem_M)->contStates = ((X_my_mpcACCsystem_T *) &my_mpcACCsystem_X);
  rtsiSetSolverData(&(&my_mpcACCsystem_M)->solverInfo, static_cast<void *>
                    (&(&my_mpcACCsystem_M)->intgData));
  rtsiSetSolverName(&(&my_mpcACCsystem_M)->solverInfo,"ode3");
  rtmSetTPtr((&my_mpcACCsystem_M), &(&my_mpcACCsystem_M)->Timing.tArray[0]);
  rtmSetTFinal((&my_mpcACCsystem_M), 35.0);
  (&my_mpcACCsystem_M)->Timing.stepSize0 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    (&my_mpcACCsystem_M)->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo((&my_mpcACCsystem_M)->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs((&my_mpcACCsystem_M)->rtwLogInfo, (NULL));
    rtliSetLogT((&my_mpcACCsystem_M)->rtwLogInfo, "tout");
    rtliSetLogX((&my_mpcACCsystem_M)->rtwLogInfo, "");
    rtliSetLogXFinal((&my_mpcACCsystem_M)->rtwLogInfo, "");
    rtliSetLogVarNameModifier((&my_mpcACCsystem_M)->rtwLogInfo, "rt_");
    rtliSetLogFormat((&my_mpcACCsystem_M)->rtwLogInfo, 4);
    rtliSetLogMaxRows((&my_mpcACCsystem_M)->rtwLogInfo, 0);
    rtliSetLogDecimation((&my_mpcACCsystem_M)->rtwLogInfo, 1);
    rtliSetLogY((&my_mpcACCsystem_M)->rtwLogInfo, "");
    rtliSetLogYSignalInfo((&my_mpcACCsystem_M)->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs((&my_mpcACCsystem_M)->rtwLogInfo, (NULL));
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime((&my_mpcACCsystem_M)->rtwLogInfo, 0.0,
    rtmGetTFinal((&my_mpcACCsystem_M)), (&my_mpcACCsystem_M)->Timing.stepSize0,
    (&rtmGetErrorStatus((&my_mpcACCsystem_M))));

  /* InitializeConditions for TransferFcn: '<S2>/Transfer Fcn' */
  my_mpcACCsystem_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S3>/Integrator1' */
  my_mpcACCsystem_X.Integrator1_CSTATE = my_mpcACCsystem_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S2>/Integrator1' */
  my_mpcACCsystem_X.Integrator1_CSTATE_d = my_mpcACCsystem_P.Integrator1_IC_j;

  /* InitializeConditions for Integrator: '<S40>/Integrator' */
  my_mpcACCsystem_X.Integrator_CSTATE =
    my_mpcACCsystem_P.PIDController_InitialConditio_l;

  /* InitializeConditions for Integrator: '<S35>/Filter' */
  my_mpcACCsystem_X.Filter_CSTATE =
    my_mpcACCsystem_P.PIDController_InitialConditionF;

  /* InitializeConditions for Memory: '<S31>/Memory' */
  my_mpcACCsystem_DW.Memory_PreviousInput =
    my_mpcACCsystem_P.Memory_InitialCondition;

  /* InitializeConditions for Integrator: '<S90>/Integrator' */
  my_mpcACCsystem_X.Integrator_CSTATE_j =
    my_mpcACCsystem_P.PIDController1_InitialConditi_k;

  /* InitializeConditions for Integrator: '<S85>/Filter' */
  my_mpcACCsystem_X.Filter_CSTATE_j =
    my_mpcACCsystem_P.PIDController1_InitialCondition;

  /* InitializeConditions for Memory: '<S81>/Memory' */
  my_mpcACCsystem_DW.Memory_PreviousInput_d =
    my_mpcACCsystem_P.Memory_InitialCondition_e;

  /* InitializeConditions for Integrator: '<S2>/Integrator' */
  my_mpcACCsystem_X.Integrator_CSTATE_a = my_mpcACCsystem_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S3>/Integrator' */
  my_mpcACCsystem_X.Integrator_CSTATE_i = my_mpcACCsystem_P.Integrator_IC_o;

  /* InitializeConditions for TransferFcn: '<S3>/Transfer Fcn' */
  my_mpcACCsystem_X.TransferFcn_CSTATE_a = 0.0;

  /* Enable for Sin: '<Root>/Sine Wave' */
  my_mpcACCsystem_DW.systemEnable = 1;
}

/* Model terminate function */
void my_mpcACCsystemModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
my_mpcACCsystemModelClass::my_mpcACCsystemModelClass() :
  my_mpcACCsystem_B(),
  my_mpcACCsystem_DW(),
  my_mpcACCsystem_X(),
  my_mpcACCsystem_M(),
  DistanceObserver()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
my_mpcACCsystemModelClass::~my_mpcACCsystemModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_my_mpcACCsystem_T * my_mpcACCsystemModelClass::getRTM()
{
  return (&my_mpcACCsystem_M);
}
