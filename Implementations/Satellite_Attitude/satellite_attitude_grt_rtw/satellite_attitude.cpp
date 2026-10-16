/*
 * satellite_attitude.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "satellite_attitude".
 *
 * Model version              : 1.18
 * Simulink Coder version : 24.2 (R2024b) 21-Jun-2024
 * C++ source code generated on : Thu May 15 17:20:05 2025
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "satellite_attitude.h"
#include "rtwtypes.h"
#include "satellite_attitude_private.h"

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void satellite_attitude::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3]{
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3]{
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t { rtsiGetT(si) };

  time_T tnew { rtsiGetSolverStopTime(si) };

  time_T h { rtsiGetStepSize(si) };

  real_T *x { rtsiGetContStates(si) };

  ODE3_IntgData *id { static_cast<ODE3_IntgData *>(rtsiGetSolverData(si)) };

  real_T *y { id->y };

  real_T *f0 { id->f[0] };

  real_T *f1 { id->f[1] };

  real_T *f2 { id->f[2] };

  real_T hB[3];
  int_T i;
  int_T nXc { 7 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  satellite_attitude_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  satellite_attitude_derivatives();

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
  satellite_attitude_derivatives();

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
void satellite_attitude::step()
{
  real_T rtb_errorDesiredActualAttitude;
  if (rtmIsMajorTimeStep((&satellite_attitude_M))) {
    /* set solver stop time */
    if (!((&satellite_attitude_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&satellite_attitude_M)->solverInfo,
                            (((&satellite_attitude_M)->Timing.clockTickH0 + 1) *
        (&satellite_attitude_M)->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&satellite_attitude_M)->solverInfo,
                            (((&satellite_attitude_M)->Timing.clockTick0 + 1) *
        (&satellite_attitude_M)->Timing.stepSize0 + (&satellite_attitude_M)
        ->Timing.clockTickH0 * (&satellite_attitude_M)->Timing.stepSize0 *
        4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&satellite_attitude_M))) {
    (&satellite_attitude_M)->Timing.t[0] = rtsiGetT(&(&satellite_attitude_M)
      ->solverInfo);
  }

  /* Step: '<Root>/Step' */
  satellite_attitude_B.desiredAttitude = !((&satellite_attitude_M)->Timing.t[0] <
    1.0);

  /* TransferFcn: '<Root>/Satellite structure (Plant)' */
  satellite_attitude_B.actualAttitude = 0.0;
  satellite_attitude_B.actualAttitude += 0.0 *
    satellite_attitude_X.Satellite_structure[0];
  satellite_attitude_B.actualAttitude += 1.25 *
    satellite_attitude_X.Satellite_structure[1];
  if (rtmIsMajorTimeStep((&satellite_attitude_M))) {
  }

  /* Sum: '<Root>/Sum' */
  rtb_errorDesiredActualAttitude = satellite_attitude_B.desiredAttitude -
    satellite_attitude_B.actualAttitude;

  /* Gain: '<S39>/Filter Coefficient' incorporates:
   *  Gain: '<S29>/Derivative Gain'
   *  Integrator: '<S31>/Filter'
   *  Sum: '<S31>/SumD'
   */
  satellite_attitude_B.FilterCoefficient = (1.98 *
    rtb_errorDesiredActualAttitude - satellite_attitude_X.Filter_CSTATE) * 100.0;

  /* Sum: '<S45>/Sum' incorporates:
   *  Gain: '<S41>/Proportional Gain'
   *  Integrator: '<S36>/Integrator'
   */
  satellite_attitude_B.Sum = (20.55 * rtb_errorDesiredActualAttitude +
    satellite_attitude_X.Integrator_CSTATE) +
    satellite_attitude_B.FilterCoefficient;

  /* Gain: '<S33>/Integral Gain' */
  satellite_attitude_B.IntegralGain = 0.0564 * rtb_errorDesiredActualAttitude;

  /* TransferFcn: '<Root>/Actuator' */
  satellite_attitude_B.actuatorForce = 78.3 * satellite_attitude_X.Actuator[0];
  satellite_attitude_B.actuatorForce += 0.0 * satellite_attitude_X.Actuator[1];

  /* TransferFcn: '<Root>/Amplifier' */
  satellite_attitude_B.amplifiedSignal = 2400.0 * satellite_attitude_X.Amplifier;
  if (rtmIsMajorTimeStep((&satellite_attitude_M))) {
    /* Matfile logging */
    rt_UpdateTXYLogVars((&satellite_attitude_M)->rtwLogInfo,
                        ((&satellite_attitude_M)->Timing.t));
  }                                    /* end MajorTimeStep */

  /* 
    *
    * Pass values to the Observer
    * The error of the system is captured by the variable:        rtb_e
    * The reference is captrued by the variable:                  Velocity_Controlled_Vehicle_B.ref
    * The output of the system is captured by the variable:       (Velocity_Controlled_Vehicle_P.car_transfer_fcn_C[0] * Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[0] + Velocity_Controlled_Vehicle_P.car_transfer_fcn_C[1] * Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[1])
    * 
    */

    ObserverFSM.setExternalInput(satellite_attitude_B.desiredAttitude, rtb_errorDesiredActualAttitude, satellite_attitude_B.actualAttitude, (&satellite_attitude_M)->Timing.t[0]);
    ObserverFSM.transition();

  if (rtmIsMajorTimeStep((&satellite_attitude_M))) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal((&satellite_attitude_M))!=-1) &&
          !((rtmGetTFinal((&satellite_attitude_M))-((((&satellite_attitude_M)
               ->Timing.clockTick1+(&satellite_attitude_M)->Timing.clockTickH1*
               4294967296.0)) * 0.001)) > ((((&satellite_attitude_M)
              ->Timing.clockTick1+(&satellite_attitude_M)->Timing.clockTickH1*
              4294967296.0)) * 0.001) * (DBL_EPSILON))) {
        rtmSetErrorStatus((&satellite_attitude_M), "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&(&satellite_attitude_M)->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&satellite_attitude_M)->Timing.clockTick0)) {
      ++(&satellite_attitude_M)->Timing.clockTickH0;
    }

    (&satellite_attitude_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&satellite_attitude_M)->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      (&satellite_attitude_M)->Timing.clockTick1++;
      if (!(&satellite_attitude_M)->Timing.clockTick1) {
        (&satellite_attitude_M)->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void satellite_attitude::satellite_attitude_derivatives()
{
  XDot_satellite_attitude_T *_rtXdot;
  _rtXdot = ((XDot_satellite_attitude_T *) (&satellite_attitude_M)->derivs);

  /* Derivatives for Integrator: '<S31>/Filter' */
  _rtXdot->Filter_CSTATE = satellite_attitude_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S36>/Integrator' */
  _rtXdot->Integrator_CSTATE = satellite_attitude_B.IntegralGain;

  /* Derivatives for TransferFcn: '<Root>/Satellite structure (Plant)' */
  _rtXdot->Satellite_structure[0] = -0.0 *
    satellite_attitude_X.Satellite_structure[0];

  /* Derivatives for TransferFcn: '<Root>/Actuator' */
  _rtXdot->Actuator[0] = -1815.4 * satellite_attitude_X.Actuator[0];

  /* Derivatives for TransferFcn: '<Root>/Satellite structure (Plant)' */
  _rtXdot->Satellite_structure[0] += -0.0 *
    satellite_attitude_X.Satellite_structure[1];

  /* Derivatives for TransferFcn: '<Root>/Actuator' */
  _rtXdot->Actuator[0] += -24466.0 * satellite_attitude_X.Actuator[1];

  /* Derivatives for TransferFcn: '<Root>/Satellite structure (Plant)' */
  _rtXdot->Satellite_structure[1] = satellite_attitude_X.Satellite_structure[0];
  _rtXdot->Satellite_structure[0] += satellite_attitude_B.actuatorForce;

  /* Derivatives for TransferFcn: '<Root>/Actuator' */
  _rtXdot->Actuator[1] = satellite_attitude_X.Actuator[0];
  _rtXdot->Actuator[0] += satellite_attitude_B.amplifiedSignal;

  /* Derivatives for TransferFcn: '<Root>/Amplifier' */
  _rtXdot->Amplifier = -10.0 * satellite_attitude_X.Amplifier;
  _rtXdot->Amplifier += satellite_attitude_B.Sum;
}

/* Model initialize function */
void satellite_attitude::initialize()
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&satellite_attitude_M)->solverInfo,
                          &(&satellite_attitude_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&satellite_attitude_M)->solverInfo, &rtmGetTPtr
                ((&satellite_attitude_M)));
    rtsiSetStepSizePtr(&(&satellite_attitude_M)->solverInfo,
                       &(&satellite_attitude_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&satellite_attitude_M)->solverInfo, &(&satellite_attitude_M
                 )->derivs);
    rtsiSetContStatesPtr(&(&satellite_attitude_M)->solverInfo, (real_T **)
                         &(&satellite_attitude_M)->contStates);
    rtsiSetNumContStatesPtr(&(&satellite_attitude_M)->solverInfo,
      &(&satellite_attitude_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&satellite_attitude_M)->solverInfo,
      &(&satellite_attitude_M)->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&satellite_attitude_M)->solverInfo,
      &(&satellite_attitude_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&satellite_attitude_M)->solverInfo,
      &(&satellite_attitude_M)->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&(&satellite_attitude_M)->solverInfo, (boolean_T**)
      &(&satellite_attitude_M)->contStateDisabled);
    rtsiSetErrorStatusPtr(&(&satellite_attitude_M)->solverInfo,
                          (&rtmGetErrorStatus((&satellite_attitude_M))));
    rtsiSetRTModelPtr(&(&satellite_attitude_M)->solverInfo,
                      (&satellite_attitude_M));
  }

  rtsiSetSimTimeStep(&(&satellite_attitude_M)->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&(&satellite_attitude_M)->solverInfo,
    false);
  rtsiSetIsContModeFrozen(&(&satellite_attitude_M)->solverInfo, false);
  (&satellite_attitude_M)->intgData.y = (&satellite_attitude_M)->odeY;
  (&satellite_attitude_M)->intgData.f[0] = (&satellite_attitude_M)->odeF[0];
  (&satellite_attitude_M)->intgData.f[1] = (&satellite_attitude_M)->odeF[1];
  (&satellite_attitude_M)->intgData.f[2] = (&satellite_attitude_M)->odeF[2];
  (&satellite_attitude_M)->contStates = ((X_satellite_attitude_T *)
    &satellite_attitude_X);
  (&satellite_attitude_M)->contStateDisabled = ((XDis_satellite_attitude_T *)
    &satellite_attitude_XDis);
  (&satellite_attitude_M)->Timing.tStart = (0.0);
  rtsiSetSolverData(&(&satellite_attitude_M)->solverInfo, static_cast<void *>(&(
    &satellite_attitude_M)->intgData));
  rtsiSetSolverName(&(&satellite_attitude_M)->solverInfo,"ode3");
  rtmSetTPtr((&satellite_attitude_M), &(&satellite_attitude_M)->Timing.tArray[0]);
  rtmSetTFinal((&satellite_attitude_M), 15.0);
  (&satellite_attitude_M)->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (nullptr);
    (&satellite_attitude_M)->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo((&satellite_attitude_M)->rtwLogInfo, (nullptr));
    rtliSetLogXSignalPtrs((&satellite_attitude_M)->rtwLogInfo, (nullptr));
    rtliSetLogT((&satellite_attitude_M)->rtwLogInfo, "tout");
    rtliSetLogX((&satellite_attitude_M)->rtwLogInfo, "");
    rtliSetLogXFinal((&satellite_attitude_M)->rtwLogInfo, "");
    rtliSetLogVarNameModifier((&satellite_attitude_M)->rtwLogInfo, "rt_");
    rtliSetLogFormat((&satellite_attitude_M)->rtwLogInfo, 0);
    rtliSetLogMaxRows((&satellite_attitude_M)->rtwLogInfo, 0);
    rtliSetLogDecimation((&satellite_attitude_M)->rtwLogInfo, 1);
    rtliSetLogY((&satellite_attitude_M)->rtwLogInfo, "");
    rtliSetLogYSignalInfo((&satellite_attitude_M)->rtwLogInfo, (nullptr));
    rtliSetLogYSignalPtrs((&satellite_attitude_M)->rtwLogInfo, (nullptr));
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime((&satellite_attitude_M)->rtwLogInfo, 0.0,
    rtmGetTFinal((&satellite_attitude_M)), (&satellite_attitude_M)
    ->Timing.stepSize0, (&rtmGetErrorStatus((&satellite_attitude_M))));

  /* InitializeConditions for Integrator: '<S31>/Filter' */
  satellite_attitude_X.Filter_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S36>/Integrator' */
  satellite_attitude_X.Integrator_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Satellite structure (Plant)' */
  satellite_attitude_X.Satellite_structure[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Actuator' */
  satellite_attitude_X.Actuator[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Satellite structure (Plant)' */
  satellite_attitude_X.Satellite_structure[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Actuator' */
  satellite_attitude_X.Actuator[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Amplifier' */
  satellite_attitude_X.Amplifier = 0.0;
}

/* Model terminate function */
void satellite_attitude::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
satellite_attitude::satellite_attitude() :
  satellite_attitude_B(),
  satellite_attitude_X(),
  satellite_attitude_XDis(),
  satellite_attitude_M(),
  ObserverFSM()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
/* Currently there is no destructor body generated.*/
satellite_attitude::~satellite_attitude() = default;

/* Real-Time Model get method */
RT_MODEL_satellite_attitude_T * satellite_attitude::getRTM()
{
  return (&satellite_attitude_M);
}
