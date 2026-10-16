/*
 * UAV.h
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

#ifndef UAV_h_
#define UAV_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "UAV_types.h"
#include <cfloat>
#include <cstring>

/* Include Observer */
#include "Observer.h"
#include "ObserverState.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* Block signals (default storage) */
struct B_UAV_T {
  real_T Ys;                           /* '<Root>/Transfer Fcn' */
  real_T IntegralGain;                 /* '<S33>/Integral Gain' */
  real_T FilterCoefficient;            /* '<S39>/Filter Coefficient' */
  real_T Sum;                          /* '<S45>/Sum' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_UAV_T {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
};

/* Continuous states (default storage) */
struct X_UAV_T {
  real_T TransferFcn_CSTATE[3];        /* '<Root>/Transfer Fcn' */
  real_T Filter_CSTATE;                /* '<S31>/Filter' */
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
};

/* State derivatives (default storage) */
struct XDot_UAV_T {
  real_T TransferFcn_CSTATE[3];        /* '<Root>/Transfer Fcn' */
  real_T Filter_CSTATE;                /* '<S31>/Filter' */
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
};

/* State disabled  */
struct XDis_UAV_T {
  boolean_T TransferFcn_CSTATE[3];     /* '<Root>/Transfer Fcn' */
  boolean_T Filter_CSTATE;             /* '<S31>/Filter' */
  boolean_T Integrator_CSTATE;         /* '<S36>/Integrator' */
};

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
struct ODE3_IntgData {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
};

#endif

/* Parameters (default storage) */
struct P_UAV_T_ {
  real_T Kd;                           /* Variable: Kd
                                        * Referenced by: '<S29>/Derivative Gain'
                                        */
  real_T Ki;                           /* Variable: Ki
                                        * Referenced by: '<S33>/Integral Gain'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by: '<S41>/Proportional Gain'
                                        */
  real_T angle_change_start_time;      /* Variable: angle_change_start_time
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T final_angle;                  /* Variable: final_angle
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T initial_angle;                /* Variable: initial_angle
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S31>/Filter'
                               */
  real_T PIDController_InitialConditio_h;
                              /* Mask Parameter: PIDController_InitialConditio_h
                               * Referenced by: '<S36>/Integrator'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S39>/Filter Coefficient'
                                        */
  real_T TransferFcn_A[3];             /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  real_T TransferFcn_C[3];             /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_UAV_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_UAV_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_UAV_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[5];
  real_T odeF[3][5];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tStart;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Class declaration for model UAV */
class UAV final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  UAV(UAV const&) = delete;

  /* Assignment Operator */
  UAV& operator= (UAV const&) & = delete;

  /* Move Constructor */
  UAV(UAV &&) = delete;

  /* Move Assignment Operator */
  UAV& operator= (UAV &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_UAV_T * getRTM();

  Observer ObserverFSM;

  /* model start function */
  void start();

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  UAV();

  /* Destructor */
  ~UAV();

  /* private data and function members */
 private:
  /* Block signals */
  B_UAV_T UAV_B;

  /* Block states */
  DW_UAV_T UAV_DW;

  /* Tunable parameters */
  static P_UAV_T UAV_P;

  /* Block continuous states */
  X_UAV_T UAV_X;

  /* Block Continuous state disabled vector */
  XDis_UAV_T UAV_XDis;

  /* Global mass matrix */

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void UAV_derivatives();

  /* Real-Time Model */
  RT_MODEL_UAV_T UAV_M;
};

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
 * '<Root>' : 'UAV'
 * '<S1>'   : 'UAV/PID Controller'
 * '<S2>'   : 'UAV/PID Controller/Anti-windup'
 * '<S3>'   : 'UAV/PID Controller/D Gain'
 * '<S4>'   : 'UAV/PID Controller/External Derivative'
 * '<S5>'   : 'UAV/PID Controller/Filter'
 * '<S6>'   : 'UAV/PID Controller/Filter ICs'
 * '<S7>'   : 'UAV/PID Controller/I Gain'
 * '<S8>'   : 'UAV/PID Controller/Ideal P Gain'
 * '<S9>'   : 'UAV/PID Controller/Ideal P Gain Fdbk'
 * '<S10>'  : 'UAV/PID Controller/Integrator'
 * '<S11>'  : 'UAV/PID Controller/Integrator ICs'
 * '<S12>'  : 'UAV/PID Controller/N Copy'
 * '<S13>'  : 'UAV/PID Controller/N Gain'
 * '<S14>'  : 'UAV/PID Controller/P Copy'
 * '<S15>'  : 'UAV/PID Controller/Parallel P Gain'
 * '<S16>'  : 'UAV/PID Controller/Reset Signal'
 * '<S17>'  : 'UAV/PID Controller/Saturation'
 * '<S18>'  : 'UAV/PID Controller/Saturation Fdbk'
 * '<S19>'  : 'UAV/PID Controller/Sum'
 * '<S20>'  : 'UAV/PID Controller/Sum Fdbk'
 * '<S21>'  : 'UAV/PID Controller/Tracking Mode'
 * '<S22>'  : 'UAV/PID Controller/Tracking Mode Sum'
 * '<S23>'  : 'UAV/PID Controller/Tsamp - Integral'
 * '<S24>'  : 'UAV/PID Controller/Tsamp - Ngain'
 * '<S25>'  : 'UAV/PID Controller/postSat Signal'
 * '<S26>'  : 'UAV/PID Controller/preInt Signal'
 * '<S27>'  : 'UAV/PID Controller/preSat Signal'
 * '<S28>'  : 'UAV/PID Controller/Anti-windup/Passthrough'
 * '<S29>'  : 'UAV/PID Controller/D Gain/Internal Parameters'
 * '<S30>'  : 'UAV/PID Controller/External Derivative/Error'
 * '<S31>'  : 'UAV/PID Controller/Filter/Cont. Filter'
 * '<S32>'  : 'UAV/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S33>'  : 'UAV/PID Controller/I Gain/Internal Parameters'
 * '<S34>'  : 'UAV/PID Controller/Ideal P Gain/Passthrough'
 * '<S35>'  : 'UAV/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S36>'  : 'UAV/PID Controller/Integrator/Continuous'
 * '<S37>'  : 'UAV/PID Controller/Integrator ICs/Internal IC'
 * '<S38>'  : 'UAV/PID Controller/N Copy/Disabled'
 * '<S39>'  : 'UAV/PID Controller/N Gain/Internal Parameters'
 * '<S40>'  : 'UAV/PID Controller/P Copy/Disabled'
 * '<S41>'  : 'UAV/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S42>'  : 'UAV/PID Controller/Reset Signal/Disabled'
 * '<S43>'  : 'UAV/PID Controller/Saturation/Passthrough'
 * '<S44>'  : 'UAV/PID Controller/Saturation Fdbk/Disabled'
 * '<S45>'  : 'UAV/PID Controller/Sum/Sum_PID'
 * '<S46>'  : 'UAV/PID Controller/Sum Fdbk/Disabled'
 * '<S47>'  : 'UAV/PID Controller/Tracking Mode/Disabled'
 * '<S48>'  : 'UAV/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S49>'  : 'UAV/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S50>'  : 'UAV/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S51>'  : 'UAV/PID Controller/postSat Signal/Forward_Path'
 * '<S52>'  : 'UAV/PID Controller/preInt Signal/Internal PreInt'
 * '<S53>'  : 'UAV/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* UAV_h_ */
