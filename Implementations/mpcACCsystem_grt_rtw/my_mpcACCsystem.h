/*
 * my_mpcACCsystem.h
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

#ifndef RTW_HEADER_my_mpcACCsystem_h_
#define RTW_HEADER_my_mpcACCsystem_h_

#include <map>
#include <cmath>
#include <cfloat>
#include <cstring>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "my_mpcACCsystem_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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

/* Block signals (default storage) */
struct B_my_mpcACCsystem_T {
  real_T TransferFcn;                  /* '<S2>/Transfer Fcn' */
  real_T Sum1;                         /* '<S2>/Sum1' */
  real_T e_v;                          /* '<S1>/Sum2' */
  real_T Product2;                     /* '<S1>/Product2' */
  real_T safe_distance;                /* '<S1>/Sum1' */
  real_T Integrator1;                  /* '<S3>/Integrator1' */
  real_T Sum;                          /* '<S3>/Sum' */
  real_T Integrator1_d;                /* '<S2>/Integrator1' */
  real_T Sum_g;                        /* '<S2>/Sum' */
  real_T d_rel;                        /* '<Root>/Sum' */
  real_T e_d;                          /* '<S1>/Sum3' */
  real_T ProportionalGain;             /* '<S45>/Proportional Gain' */
  real_T Integrator;                   /* '<S40>/Integrator' */
  real_T DerivativeGain;               /* '<S34>/Derivative Gain' */
  real_T Filter;                       /* '<S35>/Filter' */
  real_T SumD;                         /* '<S35>/SumD' */
  real_T FilterCoefficient;            /* '<S43>/Filter Coefficient' */
  real_T Sum_a;                        /* '<S49>/Sum' */
  real_T ZeroGain;                     /* '<S31>/ZeroGain' */
  real_T DeadZone;                     /* '<S33>/DeadZone' */
  real_T SignPreSat;                   /* '<S31>/SignPreSat' */
  real_T IntegralGain;                 /* '<S37>/Integral Gain' */
  real_T SignPreIntegrator;            /* '<S31>/SignPreIntegrator' */
  real_T Switch;                       /* '<S31>/Switch' */
  real_T Saturation;                   /* '<S47>/Saturation' */
  real_T ProportionalGain_p;           /* '<S95>/Proportional Gain' */
  real_T Integrator_c;                 /* '<S90>/Integrator' */
  real_T DerivativeGain_i;             /* '<S84>/Derivative Gain' */
  real_T Filter_p;                     /* '<S85>/Filter' */
  real_T SumD_f;                       /* '<S85>/SumD' */
  real_T FilterCoefficient_d;          /* '<S93>/Filter Coefficient' */
  real_T Sum_b;                        /* '<S99>/Sum' */
  real_T ZeroGain_j;                   /* '<S81>/ZeroGain' */
  real_T DeadZone_l;                   /* '<S83>/DeadZone' */
  real_T SignPreSat_o;                 /* '<S81>/SignPreSat' */
  real_T IntegralGain_j;               /* '<S87>/Integral Gain' */
  real_T SignPreIntegrator_l;          /* '<S81>/SignPreIntegrator' */
  real_T Switch_f;                     /* '<S81>/Switch' */
  real_T Saturation_e;                 /* '<S97>/Saturation' */
  real_T a_ego;                        /* '<S1>/Switch' */
  real_T Integrator_b;                 /* '<S2>/Integrator' */
  real_T Integrator_d;                 /* '<S3>/Integrator' */
  real_T TransferFcn_m;                /* '<S3>/Transfer Fcn' */
  real_T Sum1_a;                       /* '<S3>/Sum1' */
  real_T a_lead;                       /* '<Root>/Sine Wave' */
  real_T old_a_lead;
  boolean_T old_ddt;
  real_T y;                            /* '<S1>/Chart' */
  int8_T DataTypeConv1;                /* '<S31>/DataTypeConv1' */
  int8_T DataTypeConv2;                /* '<S31>/DataTypeConv2' */
  int8_T DataTypeConv1_b;              /* '<S81>/DataTypeConv1' */
  int8_T DataTypeConv2_l;              /* '<S81>/DataTypeConv2' */
  boolean_T NotEqual;                  /* '<S31>/NotEqual' */
  boolean_T Equal1;                    /* '<S31>/Equal1' */
  boolean_T AND3;                      /* '<S31>/AND3' */
  boolean_T Memory;                    /* '<S31>/Memory' */
  boolean_T NotEqual_o;                /* '<S81>/NotEqual' */
  boolean_T Equal1_l;                  /* '<S81>/Equal1' */
  boolean_T AND3_i;                    /* '<S81>/AND3' */
  boolean_T Memory_j;                  /* '<S81>/Memory' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_my_mpcACCsystem_T {
  real_T lastSin;                      /* '<Root>/Sine Wave' */
  real_T lastCos;                      /* '<Root>/Sine Wave' */
  int32_T systemEnable;                /* '<Root>/Sine Wave' */
  uint8_T is_active_c3_my_mpcACCsystem;/* '<S1>/Chart' */
  uint8_T is_c3_my_mpcACCsystem;       /* '<S1>/Chart' */
  boolean_T Memory_PreviousInput;      /* '<S31>/Memory' */
  boolean_T Memory_PreviousInput_d;    /* '<S81>/Memory' */
};

/* Continuous states (default storage) */
struct X_my_mpcACCsystem_T {
  real_T TransferFcn_CSTATE;           /* '<S2>/Transfer Fcn' */
  real_T Integrator1_CSTATE;           /* '<S3>/Integrator1' */
  real_T Integrator1_CSTATE_d;         /* '<S2>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S40>/Integrator' */
  real_T Filter_CSTATE;                /* '<S35>/Filter' */
  real_T Integrator_CSTATE_j;          /* '<S90>/Integrator' */
  real_T Filter_CSTATE_j;              /* '<S85>/Filter' */
  real_T Integrator_CSTATE_a;          /* '<S2>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S3>/Integrator' */
  real_T TransferFcn_CSTATE_a;         /* '<S3>/Transfer Fcn' */
};

/* State derivatives (default storage) */
struct XDot_my_mpcACCsystem_T {
  real_T TransferFcn_CSTATE;           /* '<S2>/Transfer Fcn' */
  real_T Integrator1_CSTATE;           /* '<S3>/Integrator1' */
  real_T Integrator1_CSTATE_d;         /* '<S2>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S40>/Integrator' */
  real_T Filter_CSTATE;                /* '<S35>/Filter' */
  real_T Integrator_CSTATE_j;          /* '<S90>/Integrator' */
  real_T Filter_CSTATE_j;              /* '<S85>/Filter' */
  real_T Integrator_CSTATE_a;          /* '<S2>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S3>/Integrator' */
  real_T TransferFcn_CSTATE_a;         /* '<S3>/Transfer Fcn' */
};

/* State disabled  */
struct XDis_my_mpcACCsystem_T {
  boolean_T TransferFcn_CSTATE;        /* '<S2>/Transfer Fcn' */
  boolean_T Integrator1_CSTATE;        /* '<S3>/Integrator1' */
  boolean_T Integrator1_CSTATE_d;      /* '<S2>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<S40>/Integrator' */
  boolean_T Filter_CSTATE;             /* '<S35>/Filter' */
  boolean_T Integrator_CSTATE_j;       /* '<S90>/Integrator' */
  boolean_T Filter_CSTATE_j;           /* '<S85>/Filter' */
  boolean_T Integrator_CSTATE_a;       /* '<S2>/Integrator' */
  boolean_T Integrator_CSTATE_i;       /* '<S3>/Integrator' */
  boolean_T TransferFcn_CSTATE_a;      /* '<S3>/Transfer Fcn' */
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
struct P_my_mpcACCsystem_T_ {
  real_T A_acc_lead;                   /* Variable: A_acc_lead
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T D_default;                    /* Variable: D_default
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T amax_ego;                     /* Variable: amax_ego
                                        * Referenced by:
                                        *   '<S47>/Saturation'
                                        *   '<S97>/Saturation'
                                        *   '<S33>/DeadZone'
                                        *   '<S83>/DeadZone'
                                        */
  real_T amin_ego;                     /* Variable: amin_ego
                                        * Referenced by:
                                        *   '<S47>/Saturation'
                                        *   '<S97>/Saturation'
                                        *   '<S33>/DeadZone'
                                        *   '<S83>/DeadZone'
                                        */
  real_T t_gap;                        /* Variable: t_gap
                                        * Referenced by: '<Root>/Time gap'
                                        */
  real_T v0_ego;                       /* Variable: v0_ego
                                        * Referenced by: '<Root>/v0 host'
                                        */
  real_T v0_lead;                      /* Variable: v0_lead
                                        * Referenced by: '<Root>/v0 lead'
                                        */
  real_T v_set;                        /* Variable: v_set
                                        * Referenced by: '<Root>/Set velocity'
                                        */
  real_T x0_ego;                       /* Variable: x0_ego
                                        * Referenced by: '<Root>/x0 host'
                                        */
  real_T x0_lead;                      /* Variable: x0_lead
                                        * Referenced by: '<Root>/x0 lead'
                                        */
  real_T PIDController_D;              /* Mask Parameter: PIDController_D
                                        * Referenced by: '<S34>/Derivative Gain'
                                        */
  real_T PIDController1_D;             /* Mask Parameter: PIDController1_D
                                        * Referenced by: '<S84>/Derivative Gain'
                                        */
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S37>/Integral Gain'
                                        */
  real_T PIDController1_I;             /* Mask Parameter: PIDController1_I
                                        * Referenced by: '<S87>/Integral Gain'
                                        */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S35>/Filter'
                               */
  real_T PIDController1_InitialCondition;
                              /* Mask Parameter: PIDController1_InitialCondition
                               * Referenced by: '<S85>/Filter'
                               */
  real_T PIDController_InitialConditio_l;
                              /* Mask Parameter: PIDController_InitialConditio_l
                               * Referenced by: '<S40>/Integrator'
                               */
  real_T PIDController1_InitialConditi_k;
                              /* Mask Parameter: PIDController1_InitialConditi_k
                               * Referenced by: '<S90>/Integrator'
                               */
  real_T PIDController_N;              /* Mask Parameter: PIDController_N
                                        * Referenced by: '<S43>/Filter Coefficient'
                                        */
  real_T PIDController1_N;             /* Mask Parameter: PIDController1_N
                                        * Referenced by: '<S93>/Filter Coefficient'
                                        */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S45>/Proportional Gain'
                                        */
  real_T PIDController1_P;             /* Mask Parameter: PIDController1_P
                                        * Referenced by: '<S95>/Proportional Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S31>/Constant1'
                                        */
  real_T Constant1_Value_k;            /* Expression: 0
                                        * Referenced by: '<S81>/Constant1'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S2>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S2>/Transfer Fcn'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  real_T Integrator1_IC_j;             /* Expression: 0
                                        * Referenced by: '<S2>/Integrator1'
                                        */
  real_T ZeroGain_Gain;                /* Expression: 0
                                        * Referenced by: '<S31>/ZeroGain'
                                        */
  real_T ZeroGain_Gain_i;              /* Expression: 0
                                        * Referenced by: '<S81>/ZeroGain'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S2>/Integrator'
                                        */
  real_T Integrator_IC_o;              /* Expression: 0
                                        * Referenced by: '<S3>/Integrator'
                                        */
  real_T TransferFcn_A_i;              /* Computed Parameter: TransferFcn_A_i
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_f;              /* Computed Parameter: TransferFcn_C_f
                                        * Referenced by: '<S3>/Transfer Fcn'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 0.2
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  boolean_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<S31>/Memory'
                                   */
  boolean_T Memory_InitialCondition_e;
                                /* Computed Parameter: Memory_InitialCondition_e
                                 * Referenced by: '<S81>/Memory'
                                 */
};

/* Real-time Model Data Structure */
struct tag_RTM_my_mpcACCsystem_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_my_mpcACCsystem_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[10];
  real_T odeF[3][10];
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
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Class declaration for model my_mpcACCsystem */
class my_mpcACCsystemModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  my_mpcACCsystemModelClass();

  /* Destructor */
  ~my_mpcACCsystemModelClass();

  /* Real-Time Model get method */
  RT_MODEL_my_mpcACCsystem_T * getRTM();

  /*
  * Adds the Observer to the vehicle model class
  * Hopefully inits the Observer just once and can then be updated any time
  * To acces the observer something like "modelName".ObserverFSM.returnStates...
  */

  Observer DistanceObserver;

  /* private data and function members */
 private:
  /* Tunable parameters */
  static P_my_mpcACCsystem_T my_mpcACCsystem_P;

  /* Block signals */
  B_my_mpcACCsystem_T my_mpcACCsystem_B;

  /* Block states */
  DW_my_mpcACCsystem_T my_mpcACCsystem_DW;
  X_my_mpcACCsystem_T my_mpcACCsystem_X;/* Block continuous states */

  /* Real-Time Model */
  RT_MODEL_my_mpcACCsystem_T my_mpcACCsystem_M;

  /* Continuous states update member function*/
  void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );

  /* Derivatives member function */
  void my_mpcACCsystem_derivatives();
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
 * '<Root>' : 'my_mpcACCsystem'
 * '<S1>'   : 'my_mpcACCsystem/Controller'
 * '<S2>'   : 'my_mpcACCsystem/Ego Car'
 * '<S3>'   : 'my_mpcACCsystem/Lead Car'
 * '<S4>'   : 'my_mpcACCsystem/Controller/Chart'
 * '<S5>'   : 'my_mpcACCsystem/Controller/PID Controller'
 * '<S6>'   : 'my_mpcACCsystem/Controller/PID Controller1'
 * '<S7>'   : 'my_mpcACCsystem/Controller/PID Controller/Anti-windup'
 * '<S8>'   : 'my_mpcACCsystem/Controller/PID Controller/D Gain'
 * '<S9>'   : 'my_mpcACCsystem/Controller/PID Controller/Filter'
 * '<S10>'  : 'my_mpcACCsystem/Controller/PID Controller/Filter ICs'
 * '<S11>'  : 'my_mpcACCsystem/Controller/PID Controller/I Gain'
 * '<S12>'  : 'my_mpcACCsystem/Controller/PID Controller/Ideal P Gain'
 * '<S13>'  : 'my_mpcACCsystem/Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S14>'  : 'my_mpcACCsystem/Controller/PID Controller/Integrator'
 * '<S15>'  : 'my_mpcACCsystem/Controller/PID Controller/Integrator ICs'
 * '<S16>'  : 'my_mpcACCsystem/Controller/PID Controller/N Copy'
 * '<S17>'  : 'my_mpcACCsystem/Controller/PID Controller/N Gain'
 * '<S18>'  : 'my_mpcACCsystem/Controller/PID Controller/P Copy'
 * '<S19>'  : 'my_mpcACCsystem/Controller/PID Controller/Parallel P Gain'
 * '<S20>'  : 'my_mpcACCsystem/Controller/PID Controller/Reset Signal'
 * '<S21>'  : 'my_mpcACCsystem/Controller/PID Controller/Saturation'
 * '<S22>'  : 'my_mpcACCsystem/Controller/PID Controller/Saturation Fdbk'
 * '<S23>'  : 'my_mpcACCsystem/Controller/PID Controller/Sum'
 * '<S24>'  : 'my_mpcACCsystem/Controller/PID Controller/Sum Fdbk'
 * '<S25>'  : 'my_mpcACCsystem/Controller/PID Controller/Tracking Mode'
 * '<S26>'  : 'my_mpcACCsystem/Controller/PID Controller/Tracking Mode Sum'
 * '<S27>'  : 'my_mpcACCsystem/Controller/PID Controller/Tsamp - Integral'
 * '<S28>'  : 'my_mpcACCsystem/Controller/PID Controller/Tsamp - Ngain'
 * '<S29>'  : 'my_mpcACCsystem/Controller/PID Controller/postSat Signal'
 * '<S30>'  : 'my_mpcACCsystem/Controller/PID Controller/preSat Signal'
 * '<S31>'  : 'my_mpcACCsystem/Controller/PID Controller/Anti-windup/Cont. Clamping Parallel'
 * '<S32>'  : 'my_mpcACCsystem/Controller/PID Controller/Anti-windup/Cont. Clamping Parallel/Dead Zone'
 * '<S33>'  : 'my_mpcACCsystem/Controller/PID Controller/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
 * '<S34>'  : 'my_mpcACCsystem/Controller/PID Controller/D Gain/Internal Parameters'
 * '<S35>'  : 'my_mpcACCsystem/Controller/PID Controller/Filter/Cont. Filter'
 * '<S36>'  : 'my_mpcACCsystem/Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S37>'  : 'my_mpcACCsystem/Controller/PID Controller/I Gain/Internal Parameters'
 * '<S38>'  : 'my_mpcACCsystem/Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S39>'  : 'my_mpcACCsystem/Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S40>'  : 'my_mpcACCsystem/Controller/PID Controller/Integrator/Continuous'
 * '<S41>'  : 'my_mpcACCsystem/Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S42>'  : 'my_mpcACCsystem/Controller/PID Controller/N Copy/Disabled'
 * '<S43>'  : 'my_mpcACCsystem/Controller/PID Controller/N Gain/Internal Parameters'
 * '<S44>'  : 'my_mpcACCsystem/Controller/PID Controller/P Copy/Disabled'
 * '<S45>'  : 'my_mpcACCsystem/Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S46>'  : 'my_mpcACCsystem/Controller/PID Controller/Reset Signal/Disabled'
 * '<S47>'  : 'my_mpcACCsystem/Controller/PID Controller/Saturation/Enabled'
 * '<S48>'  : 'my_mpcACCsystem/Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S49>'  : 'my_mpcACCsystem/Controller/PID Controller/Sum/Sum_PID'
 * '<S50>'  : 'my_mpcACCsystem/Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S51>'  : 'my_mpcACCsystem/Controller/PID Controller/Tracking Mode/Disabled'
 * '<S52>'  : 'my_mpcACCsystem/Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S53>'  : 'my_mpcACCsystem/Controller/PID Controller/Tsamp - Integral/Passthrough'
 * '<S54>'  : 'my_mpcACCsystem/Controller/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S55>'  : 'my_mpcACCsystem/Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S56>'  : 'my_mpcACCsystem/Controller/PID Controller/preSat Signal/Forward_Path'
 * '<S57>'  : 'my_mpcACCsystem/Controller/PID Controller1/Anti-windup'
 * '<S58>'  : 'my_mpcACCsystem/Controller/PID Controller1/D Gain'
 * '<S59>'  : 'my_mpcACCsystem/Controller/PID Controller1/Filter'
 * '<S60>'  : 'my_mpcACCsystem/Controller/PID Controller1/Filter ICs'
 * '<S61>'  : 'my_mpcACCsystem/Controller/PID Controller1/I Gain'
 * '<S62>'  : 'my_mpcACCsystem/Controller/PID Controller1/Ideal P Gain'
 * '<S63>'  : 'my_mpcACCsystem/Controller/PID Controller1/Ideal P Gain Fdbk'
 * '<S64>'  : 'my_mpcACCsystem/Controller/PID Controller1/Integrator'
 * '<S65>'  : 'my_mpcACCsystem/Controller/PID Controller1/Integrator ICs'
 * '<S66>'  : 'my_mpcACCsystem/Controller/PID Controller1/N Copy'
 * '<S67>'  : 'my_mpcACCsystem/Controller/PID Controller1/N Gain'
 * '<S68>'  : 'my_mpcACCsystem/Controller/PID Controller1/P Copy'
 * '<S69>'  : 'my_mpcACCsystem/Controller/PID Controller1/Parallel P Gain'
 * '<S70>'  : 'my_mpcACCsystem/Controller/PID Controller1/Reset Signal'
 * '<S71>'  : 'my_mpcACCsystem/Controller/PID Controller1/Saturation'
 * '<S72>'  : 'my_mpcACCsystem/Controller/PID Controller1/Saturation Fdbk'
 * '<S73>'  : 'my_mpcACCsystem/Controller/PID Controller1/Sum'
 * '<S74>'  : 'my_mpcACCsystem/Controller/PID Controller1/Sum Fdbk'
 * '<S75>'  : 'my_mpcACCsystem/Controller/PID Controller1/Tracking Mode'
 * '<S76>'  : 'my_mpcACCsystem/Controller/PID Controller1/Tracking Mode Sum'
 * '<S77>'  : 'my_mpcACCsystem/Controller/PID Controller1/Tsamp - Integral'
 * '<S78>'  : 'my_mpcACCsystem/Controller/PID Controller1/Tsamp - Ngain'
 * '<S79>'  : 'my_mpcACCsystem/Controller/PID Controller1/postSat Signal'
 * '<S80>'  : 'my_mpcACCsystem/Controller/PID Controller1/preSat Signal'
 * '<S81>'  : 'my_mpcACCsystem/Controller/PID Controller1/Anti-windup/Cont. Clamping Parallel'
 * '<S82>'  : 'my_mpcACCsystem/Controller/PID Controller1/Anti-windup/Cont. Clamping Parallel/Dead Zone'
 * '<S83>'  : 'my_mpcACCsystem/Controller/PID Controller1/Anti-windup/Cont. Clamping Parallel/Dead Zone/Enabled'
 * '<S84>'  : 'my_mpcACCsystem/Controller/PID Controller1/D Gain/Internal Parameters'
 * '<S85>'  : 'my_mpcACCsystem/Controller/PID Controller1/Filter/Cont. Filter'
 * '<S86>'  : 'my_mpcACCsystem/Controller/PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S87>'  : 'my_mpcACCsystem/Controller/PID Controller1/I Gain/Internal Parameters'
 * '<S88>'  : 'my_mpcACCsystem/Controller/PID Controller1/Ideal P Gain/Passthrough'
 * '<S89>'  : 'my_mpcACCsystem/Controller/PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S90>'  : 'my_mpcACCsystem/Controller/PID Controller1/Integrator/Continuous'
 * '<S91>'  : 'my_mpcACCsystem/Controller/PID Controller1/Integrator ICs/Internal IC'
 * '<S92>'  : 'my_mpcACCsystem/Controller/PID Controller1/N Copy/Disabled'
 * '<S93>'  : 'my_mpcACCsystem/Controller/PID Controller1/N Gain/Internal Parameters'
 * '<S94>'  : 'my_mpcACCsystem/Controller/PID Controller1/P Copy/Disabled'
 * '<S95>'  : 'my_mpcACCsystem/Controller/PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S96>'  : 'my_mpcACCsystem/Controller/PID Controller1/Reset Signal/Disabled'
 * '<S97>'  : 'my_mpcACCsystem/Controller/PID Controller1/Saturation/Enabled'
 * '<S98>'  : 'my_mpcACCsystem/Controller/PID Controller1/Saturation Fdbk/Disabled'
 * '<S99>'  : 'my_mpcACCsystem/Controller/PID Controller1/Sum/Sum_PID'
 * '<S100>' : 'my_mpcACCsystem/Controller/PID Controller1/Sum Fdbk/Disabled'
 * '<S101>' : 'my_mpcACCsystem/Controller/PID Controller1/Tracking Mode/Disabled'
 * '<S102>' : 'my_mpcACCsystem/Controller/PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S103>' : 'my_mpcACCsystem/Controller/PID Controller1/Tsamp - Integral/Passthrough'
 * '<S104>' : 'my_mpcACCsystem/Controller/PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S105>' : 'my_mpcACCsystem/Controller/PID Controller1/postSat Signal/Forward_Path'
 * '<S106>' : 'my_mpcACCsystem/Controller/PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_my_mpcACCsystem_h_ */
