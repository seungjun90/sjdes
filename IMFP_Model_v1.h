/*
 * File: IMFP_Model_v1.h
 *
 * Code generated for Simulink model 'IMFP_Model_v1'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 8.9 (R2015b) 13-Aug-2015
 * C/C++ source code generated on : Fri Sep 28 11:06:04 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_IMFP_Model_v1_h_
#define RTW_HEADER_IMFP_Model_v1_h_
#include <math.h>
#ifndef IMFP_Model_v1_COMMON_INCLUDES_
# define IMFP_Model_v1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* IMFP_Model_v1_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T AirSpeedknot;                 /* '<Root>/Air Speed (knot)' */ //HLR_1 Airspeed Input Signal Processing
  real_T Altitudeft;                   /* '<Root>/Altitude (ft)' */ //HLR_2 Altitude Input Signal Processing
  real_T TemperatureCelsius;           /* '<Root>/Temperature (Celsius)' */ //HLR_3 Temperature Input Signal Processing
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T DynamicPressureVolt;          /* '<Root>/Dynamic Pressure Volt' */ //HLR_4 Dynamic Pressure Output Signal Processing
  real_T AltitudeVolt;                 /* '<Root>/Altitude Volt' */ //HLR_5 Static Pressure Output Signal Processing
  real_T TemperatureFahrenheit;        /* '<Root>/Temperature (Fahrenheit)' */ //HLR_6 Temperature Output Signal Processing
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void IMFP_Model_v1_initialize(void);
extern void IMFP_Model_v1_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * '<Root>' : 'IMFP_Model_v1'
 * '<S1>'   : 'IMFP_Model_v1/IMFP Model'
 * '<S2>'   : 'IMFP_Model_v1/IMFP Model/Airspeed-to-Dynamic Pressure Converter'
 * '<S3>'   : 'IMFP_Model_v1/IMFP Model/Altitude-to-Static Pressure Converter'
 * '<S4>'   : 'IMFP_Model_v1/IMFP Model/Temeperature Converter'
 */
#endif                                 /* RTW_HEADER_IMFP_Model_v1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
