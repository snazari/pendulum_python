/*
 * File: pend.h
 *
 * Code generated for Simulink model 'pend'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Sun Sep 26 20:57:57 2021
 *
 * Target selection: ert_shrlib.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_pend_h_
#define RTW_HEADER_pend_h_
#include <math.h>
#include <string.h>
#ifndef pend_COMMON_INCLUDES_
# define pend_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* pend_COMMON_INCLUDES_ */

#include "pend_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T B_i;                          /* '<Root>/B' */
  real_T sinx1;                        /* '<S1>/sinx1' */
  real_T g_over_l;                     /* '<S1>/g_over_l' */
  real_T k_over_m;                     /* '<S1>/k_over_m' */
  real_T Sum;                          /* '<S1>/Sum' */
} B_pend_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
} X_pend_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE;           /* '<Root>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
} XDot_pend_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE;        /* '<Root>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<Root>/Integrator2' */
} XDis_pend_T;

#ifndef ODE5_INTG
#define ODE5_INTG

/* ODE5 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[6];                        /* derivatives */
} ODE5_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T x1;                           /* '<Root>/x1' */
  real_T x2;                           /* '<Root>/x2' */
} ExtY_pend_T;

/* Real-time Model Data Structure */
struct tag_RTM_pend_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_pend_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[6][2];
  ODE5_IntgData intgData;

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
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_pend_T pend_B;

/* Continuous states (default storage) */
extern X_pend_T pend_X;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_pend_T pend_Y;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T theta;                   /* '<Root>/Integrator1' */
extern real_T theta_dot;               /* '<Root>/Integrator2' */
extern real_T t_out;                   /* '<Root>/Digital Clock' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T B;                       /* Variable: B
                                        * Referenced by: '<Root>/B'
                                        */
extern real_T g;                       /* Variable: g
                                        * Referenced by: '<S1>/g_over_l'
                                        */
extern real_T k;                       /* Variable: k
                                        * Referenced by: '<S1>/k_over_m'
                                        */
extern real_T l;                       /* Variable: l
                                        * Referenced by: '<S1>/g_over_l'
                                        */
extern real_T m;                       /* Variable: m
                                        * Referenced by: '<S1>/k_over_m'
                                        */
extern real_T u;                       /* Variable: u
                                        * Referenced by: '<Root>/Constant'
                                        */
extern real_T x_ddot_0;                /* Variable: x_ddot_0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
extern real_T x_dot_0;                 /* Variable: x_dot_0
                                        * Referenced by: '<Root>/Integrator1'
                                        */

/* Model entry point functions */
extern void pend_initialize(void);
extern void pend_step(void);
extern void pend_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pend_T *const pend_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
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
 * '<Root>' : 'pend'
 * '<S1>'   : 'pend/pendulum_dynamics'
 */
#endif                                 /* RTW_HEADER_pend_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
