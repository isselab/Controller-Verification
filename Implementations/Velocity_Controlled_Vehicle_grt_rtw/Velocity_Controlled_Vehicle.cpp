/*
 * Velocity_Controlled_Vehicle.cpp
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

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
void Velocity_Controlled_VehicleModelClass::rt_ertODEUpdateContinuousStates
  (RTWSolverInfo *si )
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
  int_T nXc { 3 };

  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  Velocity_Controlled_Vehicle_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  this->step();
  Velocity_Controlled_Vehicle_derivatives();

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
  Velocity_Controlled_Vehicle_derivatives();

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
void Velocity_Controlled_VehicleModelClass::step()
{
  if (rtmIsMajorTimeStep((&Velocity_Controlled_Vehicle_M))) {
    /* set solver stop time */
    if (!((&Velocity_Controlled_Vehicle_M)->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&(&Velocity_Controlled_Vehicle_M)->solverInfo,
                            (((&Velocity_Controlled_Vehicle_M)
        ->Timing.clockTickH0 + 1) * (&Velocity_Controlled_Vehicle_M)
        ->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&(&Velocity_Controlled_Vehicle_M)->solverInfo,
                            (((&Velocity_Controlled_Vehicle_M)
        ->Timing.clockTick0 + 1) * (&Velocity_Controlled_Vehicle_M)
        ->Timing.stepSize0 + (&Velocity_Controlled_Vehicle_M)
        ->Timing.clockTickH0 * (&Velocity_Controlled_Vehicle_M)
        ->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep((&Velocity_Controlled_Vehicle_M))) {
    (&Velocity_Controlled_Vehicle_M)->Timing.t[0] = rtsiGetT
      (&(&Velocity_Controlled_Vehicle_M)->solverInfo);
  }

  {
    real_T rtb_e;
    if (rtmIsMajorTimeStep((&Velocity_Controlled_Vehicle_M))) {
      /* Sin: '<Root>/Sine Wave' */
      if (Velocity_Controlled_Vehicle_DW.systemEnable != 0) {
        rtb_e = Velocity_Controlled_Vehicle_P.SineWave_Freq *
          ((((&Velocity_Controlled_Vehicle_M)->Timing.clockTick1+
             (&Velocity_Controlled_Vehicle_M)->Timing.clockTickH1* 4294967296.0))
           * 0.1);
        Velocity_Controlled_Vehicle_DW.lastSin = std::sin(rtb_e);
        Velocity_Controlled_Vehicle_DW.lastCos = std::cos(rtb_e);
        Velocity_Controlled_Vehicle_DW.systemEnable = 0;
      }

      /* Sin: '<Root>/Sine Wave' */
      Velocity_Controlled_Vehicle_B.ref =
        ((Velocity_Controlled_Vehicle_DW.lastSin *
          Velocity_Controlled_Vehicle_P.SineWave_PCos +
          Velocity_Controlled_Vehicle_DW.lastCos *
          Velocity_Controlled_Vehicle_P.SineWave_PSin) *
         Velocity_Controlled_Vehicle_P.SineWave_HCos +
         (Velocity_Controlled_Vehicle_DW.lastCos *
          Velocity_Controlled_Vehicle_P.SineWave_PCos -
          Velocity_Controlled_Vehicle_DW.lastSin *
          Velocity_Controlled_Vehicle_P.SineWave_PSin) *
         Velocity_Controlled_Vehicle_P.SineWave_Hsin) *
        Velocity_Controlled_Vehicle_P.SineWave_Amp +
        Velocity_Controlled_Vehicle_P.SineWave_Bias;
    }

    /* Sum: '<Root>/Sum2' incorporates:
     *  TransferFcn: '<S2>/car_transfer_fcn'
     */
    rtb_e = Velocity_Controlled_Vehicle_B.ref -
      (Velocity_Controlled_Vehicle_P.car_transfer_fcn_C[0] *
       Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[0] +
       Velocity_Controlled_Vehicle_P.car_transfer_fcn_C[1] *
       Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[1]);

    /* Sum: '<S1>/Add' incorporates:
     *  Gain: '<S1>/Kp'
     *  Integrator: '<S1>/Integrator'
     */
    Velocity_Controlled_Vehicle_B.acc = Velocity_Controlled_Vehicle_P.Kp_Gain *
      rtb_e + Velocity_Controlled_Vehicle_X.Integrator_CSTATE;

    /* Gain: '<S1>/Ki' */
    Velocity_Controlled_Vehicle_B.Ki = Velocity_Controlled_Vehicle_P.Ki_Gain *
      rtb_e;

    /* Is this the time information? If so jackpott 
    * Could be passed to the Observer and can serve as guards */
    time_T timing = rtsiGetT(&(&Velocity_Controlled_Vehicle_M)->solverInfo);
    
    /* 
    *
    * Pass values to the Observer
    * The error of the system is captured by the variable:        rtb_e
    * The reference is captrued by the variable:                  Velocity_Controlled_Vehicle_B.ref
    * The output of the system is captured by the variable:       (Velocity_Controlled_Vehicle_P.car_transfer_fcn_C[0] * Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[0] + Velocity_Controlled_Vehicle_P.car_transfer_fcn_C[1] * Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[1])
    * 
    */

    ObserverFSM.setExternalInput(Velocity_Controlled_Vehicle_B.ref, rtb_e, (Velocity_Controlled_Vehicle_P.car_transfer_fcn_C[0] * Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[0] + Velocity_Controlled_Vehicle_P.car_transfer_fcn_C[1] * Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[1]), timing);
    ObserverFSM.transition();
  }



  if (rtmIsMajorTimeStep((&Velocity_Controlled_Vehicle_M))) {
    /* Matfile logging */
    rt_UpdateTXYLogVars((&Velocity_Controlled_Vehicle_M)->rtwLogInfo,
                        ((&Velocity_Controlled_Vehicle_M)->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep((&Velocity_Controlled_Vehicle_M))) {
    real_T HoldSine;
    if (rtmIsMajorTimeStep((&Velocity_Controlled_Vehicle_M))) {
      /* Update for Sin: '<Root>/Sine Wave' */
      HoldSine = Velocity_Controlled_Vehicle_DW.lastSin;
      Velocity_Controlled_Vehicle_DW.lastSin =
        Velocity_Controlled_Vehicle_DW.lastSin *
        Velocity_Controlled_Vehicle_P.SineWave_HCos +
        Velocity_Controlled_Vehicle_DW.lastCos *
        Velocity_Controlled_Vehicle_P.SineWave_Hsin;
      Velocity_Controlled_Vehicle_DW.lastCos =
        Velocity_Controlled_Vehicle_DW.lastCos *
        Velocity_Controlled_Vehicle_P.SineWave_HCos - HoldSine *
        Velocity_Controlled_Vehicle_P.SineWave_Hsin;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep((&Velocity_Controlled_Vehicle_M))) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal((&Velocity_Controlled_Vehicle_M))!=-1) &&
          !((rtmGetTFinal((&Velocity_Controlled_Vehicle_M))-
             ((((&Velocity_Controlled_Vehicle_M)->Timing.clockTick1+
                (&Velocity_Controlled_Vehicle_M)->Timing.clockTickH1*
                4294967296.0)) * 0.1)) > ((((&Velocity_Controlled_Vehicle_M)
              ->Timing.clockTick1+(&Velocity_Controlled_Vehicle_M)
              ->Timing.clockTickH1* 4294967296.0)) * 0.1) * (DBL_EPSILON))) {
        rtmSetErrorStatus((&Velocity_Controlled_Vehicle_M),
                          "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&(&Velocity_Controlled_Vehicle_M)
      ->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++(&Velocity_Controlled_Vehicle_M)->Timing.clockTick0)) {
      ++(&Velocity_Controlled_Vehicle_M)->Timing.clockTickH0;
    }

    (&Velocity_Controlled_Vehicle_M)->Timing.t[0] = rtsiGetSolverStopTime
      (&(&Velocity_Controlled_Vehicle_M)->solverInfo);

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
      (&Velocity_Controlled_Vehicle_M)->Timing.clockTick1++;
      if (!(&Velocity_Controlled_Vehicle_M)->Timing.clockTick1) {
        (&Velocity_Controlled_Vehicle_M)->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Velocity_Controlled_VehicleModelClass::
  Velocity_Controlled_Vehicle_derivatives()
{
  XDot_Velocity_Controlled_Vehi_T *_rtXdot;
  _rtXdot = ((XDot_Velocity_Controlled_Vehi_T *) (&Velocity_Controlled_Vehicle_M)
             ->derivs);

  /* Derivatives for TransferFcn: '<S2>/car_transfer_fcn' */
  _rtXdot->car_transfer_fcn_CSTATE[0] = 0.0;
  _rtXdot->car_transfer_fcn_CSTATE[0] +=
    Velocity_Controlled_Vehicle_P.car_transfer_fcn_A[0] *
    Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[0];
  _rtXdot->car_transfer_fcn_CSTATE[1] = 0.0;
  _rtXdot->car_transfer_fcn_CSTATE[0] +=
    Velocity_Controlled_Vehicle_P.car_transfer_fcn_A[1] *
    Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[1];
  _rtXdot->car_transfer_fcn_CSTATE[1] +=
    Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[0];
  _rtXdot->car_transfer_fcn_CSTATE[0] += Velocity_Controlled_Vehicle_B.acc;

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = Velocity_Controlled_Vehicle_B.Ki;
}

/* Model initialize function */
void Velocity_Controlled_VehicleModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&(&Velocity_Controlled_Vehicle_M)->solverInfo,
                          &(&Velocity_Controlled_Vehicle_M)->Timing.simTimeStep);
    rtsiSetTPtr(&(&Velocity_Controlled_Vehicle_M)->solverInfo, &rtmGetTPtr
                ((&Velocity_Controlled_Vehicle_M)));
    rtsiSetStepSizePtr(&(&Velocity_Controlled_Vehicle_M)->solverInfo,
                       &(&Velocity_Controlled_Vehicle_M)->Timing.stepSize0);
    rtsiSetdXPtr(&(&Velocity_Controlled_Vehicle_M)->solverInfo,
                 &(&Velocity_Controlled_Vehicle_M)->derivs);
    rtsiSetContStatesPtr(&(&Velocity_Controlled_Vehicle_M)->solverInfo, (real_T **)
                         &(&Velocity_Controlled_Vehicle_M)->contStates);
    rtsiSetNumContStatesPtr(&(&Velocity_Controlled_Vehicle_M)->solverInfo,
      &(&Velocity_Controlled_Vehicle_M)->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&(&Velocity_Controlled_Vehicle_M)
      ->solverInfo, &(&Velocity_Controlled_Vehicle_M)
      ->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&(&Velocity_Controlled_Vehicle_M)
      ->solverInfo, &(&Velocity_Controlled_Vehicle_M)->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&(&Velocity_Controlled_Vehicle_M)
      ->solverInfo, &(&Velocity_Controlled_Vehicle_M)->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&(&Velocity_Controlled_Vehicle_M)->solverInfo,
                          (&rtmGetErrorStatus((&Velocity_Controlled_Vehicle_M))));
    rtsiSetRTModelPtr(&(&Velocity_Controlled_Vehicle_M)->solverInfo,
                      (&Velocity_Controlled_Vehicle_M));
  }

  rtsiSetSimTimeStep(&(&Velocity_Controlled_Vehicle_M)->solverInfo,
                     MAJOR_TIME_STEP);
  (&Velocity_Controlled_Vehicle_M)->intgData.y = (&Velocity_Controlled_Vehicle_M)
    ->odeY;
  (&Velocity_Controlled_Vehicle_M)->intgData.f[0] =
    (&Velocity_Controlled_Vehicle_M)->odeF[0];
  (&Velocity_Controlled_Vehicle_M)->intgData.f[1] =
    (&Velocity_Controlled_Vehicle_M)->odeF[1];
  (&Velocity_Controlled_Vehicle_M)->intgData.f[2] =
    (&Velocity_Controlled_Vehicle_M)->odeF[2];
  (&Velocity_Controlled_Vehicle_M)->contStates =
    ((X_Velocity_Controlled_Vehicle_T *) &Velocity_Controlled_Vehicle_X);
  rtsiSetSolverData(&(&Velocity_Controlled_Vehicle_M)->solverInfo, static_cast<
                    void *>(&(&Velocity_Controlled_Vehicle_M)->intgData));
  rtsiSetSolverName(&(&Velocity_Controlled_Vehicle_M)->solverInfo,"ode3");
  rtmSetTPtr((&Velocity_Controlled_Vehicle_M), &(&Velocity_Controlled_Vehicle_M
             )->Timing.tArray[0]);
  rtmSetTFinal((&Velocity_Controlled_Vehicle_M), 30.0);
  (&Velocity_Controlled_Vehicle_M)->Timing.stepSize0 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (nullptr);
    (&Velocity_Controlled_Vehicle_M)->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo((&Velocity_Controlled_Vehicle_M)->rtwLogInfo, (nullptr));
    rtliSetLogXSignalPtrs((&Velocity_Controlled_Vehicle_M)->rtwLogInfo, (nullptr));
    rtliSetLogT((&Velocity_Controlled_Vehicle_M)->rtwLogInfo, "tout");
    rtliSetLogX((&Velocity_Controlled_Vehicle_M)->rtwLogInfo, "");
    rtliSetLogXFinal((&Velocity_Controlled_Vehicle_M)->rtwLogInfo, "");
    rtliSetLogVarNameModifier((&Velocity_Controlled_Vehicle_M)->rtwLogInfo,
      "rt_");
    rtliSetLogFormat((&Velocity_Controlled_Vehicle_M)->rtwLogInfo, 4);
    rtliSetLogMaxRows((&Velocity_Controlled_Vehicle_M)->rtwLogInfo, 0);
    rtliSetLogDecimation((&Velocity_Controlled_Vehicle_M)->rtwLogInfo, 1);
    rtliSetLogY((&Velocity_Controlled_Vehicle_M)->rtwLogInfo, "");
    rtliSetLogYSignalInfo((&Velocity_Controlled_Vehicle_M)->rtwLogInfo, (nullptr));
    rtliSetLogYSignalPtrs((&Velocity_Controlled_Vehicle_M)->rtwLogInfo, (nullptr));
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime((&Velocity_Controlled_Vehicle_M)->rtwLogInfo,
    0.0, rtmGetTFinal((&Velocity_Controlled_Vehicle_M)),
    (&Velocity_Controlled_Vehicle_M)->Timing.stepSize0, (&rtmGetErrorStatus
    ((&Velocity_Controlled_Vehicle_M))));

  /* InitializeConditions for TransferFcn: '<S2>/car_transfer_fcn' */
  Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[0] = 0.0;
  Velocity_Controlled_Vehicle_X.car_transfer_fcn_CSTATE[1] = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  Velocity_Controlled_Vehicle_X.Integrator_CSTATE =
    Velocity_Controlled_Vehicle_P.Integrator_IC;

  /* Enable for Sin: '<Root>/Sine Wave' */
  Velocity_Controlled_Vehicle_DW.systemEnable = 1;
}

/* Model terminate function */
void Velocity_Controlled_VehicleModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
Velocity_Controlled_VehicleModelClass::Velocity_Controlled_VehicleModelClass() :
  Velocity_Controlled_Vehicle_B(),
  Velocity_Controlled_Vehicle_DW(),
  Velocity_Controlled_Vehicle_X(),
  Velocity_Controlled_Vehicle_M(),
  ObserverFSM()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
Velocity_Controlled_VehicleModelClass::~Velocity_Controlled_VehicleModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_Velocity_Controlled__T * Velocity_Controlled_VehicleModelClass::getRTM()
{
  return (&Velocity_Controlled_Vehicle_M);
}
