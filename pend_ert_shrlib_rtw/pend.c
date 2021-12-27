/*
 * File: pend.c
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

#include "pend.h"
#include "pend_private.h"

/* Exported block signals */
real_T theta;                          /* '<Root>/Integrator1' */
real_T theta_dot;                      /* '<Root>/Integrator2' */
real_T t_out;                          /* '<Root>/Digital Clock' */

/* Exported block parameters */
real_T B = 1.0;                        /* Variable: B
                                        * Referenced by: '<Root>/B'
                                        */
real_T g = 9.8;                        /* Variable: g
                                        * Referenced by: '<S1>/g_over_l'
                                        */
real_T k = 100.0;                      /* Variable: k
                                        * Referenced by: '<S1>/k_over_m'
                                        */
real_T l = 2.0;                        /* Variable: l
                                        * Referenced by: '<S1>/g_over_l'
                                        */
real_T m = 50.0;                       /* Variable: m
                                        * Referenced by: '<S1>/k_over_m'
                                        */
real_T u = 0.0;                        /* Variable: u
                                        * Referenced by: '<Root>/Constant'
                                        */
real_T x_ddot_0 = 0.1;                 /* Variable: x_ddot_0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
real_T x_dot_0 = 0.0;                  /* Variable: x_dot_0
                                        * Referenced by: '<Root>/Integrator1'
                                        */

/* Block signals (default storage) */
B_pend_T pend_B;

/* Continuous states */
X_pend_T pend_X;

/* External outputs (root outports fed by signals with default storage) */
ExtY_pend_T pend_Y;

/* Real-time model */
RT_MODEL_pend_T pend_M_;
RT_MODEL_pend_T *const pend_M = &pend_M_;

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  pend_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  pend_step();
  pend_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  pend_step();
  pend_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  pend_step();
  pend_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  pend_step();
  pend_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  pend_step();
  pend_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void pend_step(void)
{
  real_T A;
  real_T B_0;
  if (rtmIsMajorTimeStep(pend_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&pend_M->solverInfo,((pend_M->Timing.clockTick0+1)*
      pend_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(pend_M)) {
    pend_M->Timing.t[0] = rtsiGetT(&pend_M->solverInfo);
  }

  /* Integrator: '<Root>/Integrator1' */
  theta = pend_X.Integrator1_CSTATE;

  /* Outport: '<Root>/x1' */
  pend_Y.x1 = theta;

  /* Integrator: '<Root>/Integrator2' */
  theta_dot = pend_X.Integrator2_CSTATE;

  /* Outport: '<Root>/x2' */
  pend_Y.x2 = theta_dot;
  if (rtmIsMajorTimeStep(pend_M)) {
    /* Gain: '<Root>/B' incorporates:
     *  Constant: '<Root>/Constant'
     */
    pend_B.B_i = B * u;

    /* DigitalClock: '<Root>/Digital Clock' */
    t_out = ((pend_M->Timing.clockTick1) * 0.005);
  }

  /* Trigonometry: '<S1>/sinx1' */
  pend_B.sinx1 = sin(theta);

  /* Gain: '<S1>/g_over_l' */
  A = -g;
  B_0 = l;
  A /= B_0;
  pend_B.g_over_l = A * pend_B.sinx1;

  /* Gain: '<S1>/k_over_m' */
  A = -k;
  B_0 = m;
  A /= B_0;
  pend_B.k_over_m = A * theta_dot;

  /* Sum: '<S1>/Sum' */
  pend_B.Sum = (pend_B.g_over_l + pend_B.k_over_m) + pend_B.B_i;
  if (rtmIsMajorTimeStep(pend_M)) {
    rt_ertODEUpdateContinuousStates(&pend_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++pend_M->Timing.clockTick0;
    pend_M->Timing.t[0] = rtsiGetSolverStopTime(&pend_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      pend_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void pend_derivatives(void)
{
  XDot_pend_T *_rtXdot;
  _rtXdot = ((XDot_pend_T *) pend_M->derivs);

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = theta_dot;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = pend_B.Sum;
}

/* Model initialize function */
void pend_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)pend_M, 0,
                sizeof(RT_MODEL_pend_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&pend_M->solverInfo, &pend_M->Timing.simTimeStep);
    rtsiSetTPtr(&pend_M->solverInfo, &rtmGetTPtr(pend_M));
    rtsiSetStepSizePtr(&pend_M->solverInfo, &pend_M->Timing.stepSize0);
    rtsiSetdXPtr(&pend_M->solverInfo, &pend_M->derivs);
    rtsiSetContStatesPtr(&pend_M->solverInfo, (real_T **) &pend_M->contStates);
    rtsiSetNumContStatesPtr(&pend_M->solverInfo, &pend_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&pend_M->solverInfo,
      &pend_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&pend_M->solverInfo,
      &pend_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&pend_M->solverInfo,
      &pend_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&pend_M->solverInfo, (&rtmGetErrorStatus(pend_M)));
    rtsiSetRTModelPtr(&pend_M->solverInfo, pend_M);
  }

  rtsiSetSimTimeStep(&pend_M->solverInfo, MAJOR_TIME_STEP);
  pend_M->intgData.y = pend_M->odeY;
  pend_M->intgData.f[0] = pend_M->odeF[0];
  pend_M->intgData.f[1] = pend_M->odeF[1];
  pend_M->intgData.f[2] = pend_M->odeF[2];
  pend_M->intgData.f[3] = pend_M->odeF[3];
  pend_M->intgData.f[4] = pend_M->odeF[4];
  pend_M->intgData.f[5] = pend_M->odeF[5];
  pend_M->contStates = ((X_pend_T *) &pend_X);
  rtsiSetSolverData(&pend_M->solverInfo, (void *)&pend_M->intgData);
  rtsiSetSolverName(&pend_M->solverInfo,"ode5");
  rtmSetTPtr(pend_M, &pend_M->Timing.tArray[0]);
  pend_M->Timing.stepSize0 = 0.005;

  /* block I/O */
  (void) memset(((void *) &pend_B), 0,
                sizeof(B_pend_T));

  /* exported global signals */
  theta = 0.0;
  theta_dot = 0.0;
  t_out = 0.0;

  /* states (continuous) */
  {
    (void) memset((void *)&pend_X, 0,
                  sizeof(X_pend_T));
  }

  /* external outputs */
  (void) memset((void *)&pend_Y, 0,
                sizeof(ExtY_pend_T));

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  pend_X.Integrator1_CSTATE = x_dot_0;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  pend_X.Integrator2_CSTATE = x_ddot_0;
}

/* Model terminate function */
void pend_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
