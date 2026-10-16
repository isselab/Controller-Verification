/*
 * satellite_attitude.h
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

#ifndef satellite_attitude_h_
#define satellite_attitude_h_
#include <cmath>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#include "satellite_attitude_types.h"
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
struct B_satellite_attitude_T {
  real_T desiredAttitude;              /* '<Root>/Step' */
  real_T actualAttitude;              /* '<Root>/Satellite structure (Plant)' */
  real_T FilterCoefficient;            /* '<S39>/Filter Coefficient' */
  real_T Sum;                          /* '<S45>/Sum' */
  real_T IntegralGain;                 /* '<S33>/Integral Gain' */
  real_T actuatorForce;                /* '<Root>/Actuator' */
  real_T amplifiedSignal;              /* '<Root>/Amplifier' */
};

/* Continuous states (default storage) */
struct X_satellite_attitude_T {
  real_T Satellite_structure[2];      /* '<Root>/Satellite structure (Plant)' */
  real_T Filter_CSTATE;                /* '<S31>/Filter' */
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
  real_T Actuator[2];                  /* '<Root>/Actuator' */
  real_T Amplifier;                    /* '<Root>/Amplifier' */
};

/* State derivatives (default storage) */
struct XDot_satellite_attitude_T {
  real_T Satellite_structure[2];      /* '<Root>/Satellite structure (Plant)' */
  real_T Filter_CSTATE;                /* '<S31>/Filter' */
  real_T Integrator_CSTATE;            /* '<S36>/Integrator' */
  real_T Actuator[2];                  /* '<Root>/Actuator' */
  real_T Amplifier;                    /* '<Root>/Amplifier' */
};

/* State disabled  */
struct XDis_satellite_attitude_T {
  boolean_T Satellite_structure[2];   /* '<Root>/Satellite structure (Plant)' */
  boolean_T Filter_CSTATE;             /* '<S31>/Filter' */
  boolean_T Integrator_CSTATE;         /* '<S36>/Integrator' */
  boolean_T Actuator[2];               /* '<Root>/Actuator' */
  boolean_T Amplifier;                 /* '<Root>/Amplifier' */
};

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
struct ODE3_IntgData {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
};

#endif

/* Real-time Model Data Structure */
struct tag_RTM_satellite_attitude_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_satellite_attitude_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_satellite_attitude_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[7];
  real_T odeF[3][7];
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

/* Class declaration for model satellite_attitude */
class satellite_attitude final
{
  /* public data and function members */
 public:
  /* Copy Constructor */
  satellite_attitude(satellite_attitude const&) = delete;

  /* Assignment Operator */
  satellite_attitude& operator= (satellite_attitude const&) & = delete;

  /* Move Constructor */
  satellite_attitude(satellite_attitude &&) = delete;

  /* Move Assignment Operator */
  satellite_attitude& operator= (satellite_attitude &&) = delete;

  /* Real-Time Model get method */
  RT_MODEL_satellite_attitude_T * getRTM();

  /* model start function */
  void start();

  /* Initial conditions function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  static void terminate();

  /* Constructor */
  satellite_attitude();

  /* Destructor */
  ~satellite_attitude();

  Observer ObserverFSM;
  
  /* private data and function members */
 private:
  /* Block signals */
  B_satellite_attitude_T satellite_attitude_B;

  /* Block continuous states */
  X_satellite_attitude_T satellite_attitude_X;

  /* Block Continuous state disabled vector */
  XDis_satellite_attitude_T satellite_attitude_XDis;

  /* Global mass matrix */

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void satellite_attitude_derivatives();

  /* Real-Time Model */
  RT_MODEL_satellite_attitude_T satellite_attitude_M;
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
 * '<Root>' : 'satellite_attitude'
 * '<S1>'   : 'satellite_attitude/PID Controller'
 * '<S2>'   : 'satellite_attitude/PID Controller/Anti-windup'
 * '<S3>'   : 'satellite_attitude/PID Controller/D Gain'
 * '<S4>'   : 'satellite_attitude/PID Controller/External Derivative'
 * '<S5>'   : 'satellite_attitude/PID Controller/Filter'
 * '<S6>'   : 'satellite_attitude/PID Controller/Filter ICs'
 * '<S7>'   : 'satellite_attitude/PID Controller/I Gain'
 * '<S8>'   : 'satellite_attitude/PID Controller/Ideal P Gain'
 * '<S9>'   : 'satellite_attitude/PID Controller/Ideal P Gain Fdbk'
 * '<S10>'  : 'satellite_attitude/PID Controller/Integrator'
 * '<S11>'  : 'satellite_attitude/PID Controller/Integrator ICs'
 * '<S12>'  : 'satellite_attitude/PID Controller/N Copy'
 * '<S13>'  : 'satellite_attitude/PID Controller/N Gain'
 * '<S14>'  : 'satellite_attitude/PID Controller/P Copy'
 * '<S15>'  : 'satellite_attitude/PID Controller/Parallel P Gain'
 * '<S16>'  : 'satellite_attitude/PID Controller/Reset Signal'
 * '<S17>'  : 'satellite_attitude/PID Controller/Saturation'
 * '<S18>'  : 'satellite_attitude/PID Controller/Saturation Fdbk'
 * '<S19>'  : 'satellite_attitude/PID Controller/Sum'
 * '<S20>'  : 'satellite_attitude/PID Controller/Sum Fdbk'
 * '<S21>'  : 'satellite_attitude/PID Controller/Tracking Mode'
 * '<S22>'  : 'satellite_attitude/PID Controller/Tracking Mode Sum'
 * '<S23>'  : 'satellite_attitude/PID Controller/Tsamp - Integral'
 * '<S24>'  : 'satellite_attitude/PID Controller/Tsamp - Ngain'
 * '<S25>'  : 'satellite_attitude/PID Controller/postSat Signal'
 * '<S26>'  : 'satellite_attitude/PID Controller/preInt Signal'
 * '<S27>'  : 'satellite_attitude/PID Controller/preSat Signal'
 * '<S28>'  : 'satellite_attitude/PID Controller/Anti-windup/Passthrough'
 * '<S29>'  : 'satellite_attitude/PID Controller/D Gain/Internal Parameters'
 * '<S30>'  : 'satellite_attitude/PID Controller/External Derivative/Error'
 * '<S31>'  : 'satellite_attitude/PID Controller/Filter/Cont. Filter'
 * '<S32>'  : 'satellite_attitude/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S33>'  : 'satellite_attitude/PID Controller/I Gain/Internal Parameters'
 * '<S34>'  : 'satellite_attitude/PID Controller/Ideal P Gain/Passthrough'
 * '<S35>'  : 'satellite_attitude/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S36>'  : 'satellite_attitude/PID Controller/Integrator/Continuous'
 * '<S37>'  : 'satellite_attitude/PID Controller/Integrator ICs/Internal IC'
 * '<S38>'  : 'satellite_attitude/PID Controller/N Copy/Disabled'
 * '<S39>'  : 'satellite_attitude/PID Controller/N Gain/Internal Parameters'
 * '<S40>'  : 'satellite_attitude/PID Controller/P Copy/Disabled'
 * '<S41>'  : 'satellite_attitude/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S42>'  : 'satellite_attitude/PID Controller/Reset Signal/Disabled'
 * '<S43>'  : 'satellite_attitude/PID Controller/Saturation/Passthrough'
 * '<S44>'  : 'satellite_attitude/PID Controller/Saturation Fdbk/Disabled'
 * '<S45>'  : 'satellite_attitude/PID Controller/Sum/Sum_PID'
 * '<S46>'  : 'satellite_attitude/PID Controller/Sum Fdbk/Disabled'
 * '<S47>'  : 'satellite_attitude/PID Controller/Tracking Mode/Disabled'
 * '<S48>'  : 'satellite_attitude/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S49>'  : 'satellite_attitude/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S50>'  : 'satellite_attitude/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S51>'  : 'satellite_attitude/PID Controller/postSat Signal/Forward_Path'
 * '<S52>'  : 'satellite_attitude/PID Controller/preInt Signal/Internal PreInt'
 * '<S53>'  : 'satellite_attitude/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* satellite_attitude_h_ */
