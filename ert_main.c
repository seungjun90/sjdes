/*
* File: ert_main.c
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

#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "IMFP_Model_v1.h"             /* Model's header file */
#include "rtwtypes.h"

/*
* Associating rt_OneStep with a real-time clock or interrupt service routine
* is what makes the generated code "real-time".  The function rt_OneStep is
* always associated with the base rate of the model.  Subrates are managed
* by the base rate from inside the generated code.  Enabling/disabling
* interrupts and floating point context switches are target specific.  This
* example code indicates where these should take place relative to executing
* the generated code step function.  Overrun behavior should be tailored to
* your application needs.  This example simply sets an error status in the
* real-time model and returns from rt_OneStep.
*/

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

void rt_OneStep(void);
void IMFP_Model_v1_step(void);
void IMFP_Model_v1_initialize(void);

/* Model step function */
void IMFP_Model_v1_step(void)
{
  real_T rtb_MathFunction_e;

  /* Gain: '<S1>/knot-to-km//h Converter' incorporates:
  *  Inport: '<Root>/Air Speed (knot)'
  */
  rtb_MathFunction_e = 1.852 * rtU.AirSpeedknot; //HLR_7 knot-to-km//h Convertere

  // HLR_8 Airspeed-to-Dynamic Pressure Converter //
  /* Saturate: '<S2>/Saturation' */
  if (rtb_MathFunction_e > 1000.0) {
    rtb_MathFunction_e = 1000.0;
  }
  else {
    if (rtb_MathFunction_e < 0.0) {
      rtb_MathFunction_e = 0.0;
    }
  }

  /* Gain: '<S2>/Gain' incorporates:
  *  Saturate: '<S2>/Saturation'
  */
  rtb_MathFunction_e *= 0.27777777777777779;

  /* Outport: '<Root>/Dynamic Pressure Volt' incorporates:
  *  Gain: '<S2>/Gain1'
  *  Gain: '<S2>/Gain2'
  *  Gain: '<S2>/rho_0'
  *  Math: '<S2>/Math Function'
  *
  * About '<S2>/Math Function':
  *  Operator: magnitude^2
  */
  rtY.DynamicPressureVolt = rtb_MathFunction_e * rtb_MathFunction_e * 1.25 * 0.5
    * 0.00010309278350515464;

  //----------------------------------------------------------//


  // HLR_9 Altitude-to-Static Pressure Converter //

  /* Saturate: '<S3>/Saturation' incorporates:
  *  Inport: '<Root>/Altitude (ft)'
  */
  if (rtU.Altitudeft > 48000.0) {
    rtb_MathFunction_e = 48000.0;
  }
  else if (rtU.Altitudeft < 0.0) {
    rtb_MathFunction_e = 0.0;
  }
  else {
    rtb_MathFunction_e = rtU.Altitudeft;
  }

  /* Outport: '<Root>/Altitude Volt' incorporates:
  *  Constant: '<S3>/Constant'
  *  Gain: '<S3>/Gain1'
  *  Gain: '<S3>/k1'
  *  Math: '<S3>/Math Function'
  *  Saturate: '<S3>/Saturation'
  *  Sum: '<S3>/Sum'
  */
  rtY.AltitudeVolt = pow(1.0 - 6.87558E-6 * rtb_MathFunction_e, 5.2559) * 5.0;

  //----------------------------------------------------------//


  // HLR_10 Temeperature Converter //

  /* Outport: '<Root>/Temperature (Fahrenheit)' incorporates:
  *  Constant: '<S4>/Constant'
  *  Gain: '<S4>/k1'
  *  Inport: '<Root>/Temperature (Celsius)'
  *  Sum: '<S4>/Sum'
  */
  rtY.TemperatureFahrenheit = 1.8 * rtU.TemperatureCelsius + 32.0;

  //----------------------------------------------------------//
}

/* Model initialize function */
void IMFP_Model_v1_initialize(void)
{
  /* (no initialization code required) */
}

/*
* File trailer for generated code.
*
* [EOF]
*/

void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(rtM, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  IMFP_Model_v1_step();

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
* The example "main" function illustrates what is required by your
* application code to initialize, execute, and terminate the generated code.
* Attaching rt_OneStep to a real-time clock is target specific.  This example
* illustates how you do this relative to initializing the model.
*/
int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  rtU.AirSpeedknot = 1000;
  rtU.Altitudeft = 1000;
  rtU.TemperatureCelsius = 1000;


  /* Initialize model */
  IMFP_Model_v1_initialize();

  /* Attach rt_OneStep to a timer or interrupt service routine with
  * period 0.2 seconds (the model's base sample time) here.  The
  * call syntax for rt_OneStep is
  *
  *  rt_OneStep();
  */
  printf("Warning: The simulation will run forever. "
    "Generated ERT main won't simulate model step behavior. "
    "To change this behavior selecvt the 'MAT-file logging' option.\n");
  fflush((NULL));
  while (rtmGetErrorStatus(rtM) == (NULL)) {
    rt_OneStep();
    printf("%d", rtY.DynamicPressureVolt);
    printf("\n");
    printf("%d", rtY.AltitudeVolt);
    printf("\n");
    printf("%d", rtY.TemperatureFahrenheit);


    /*  Perform other application tasks here */
  }

  /* Disable rt_OneStep() here */
  return 0;
}

/*
* File trailer for generated code.
*
* [EOF]
*/
