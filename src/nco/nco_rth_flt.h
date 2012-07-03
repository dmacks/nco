/* $Header: /data/zender/nco_20150216/nco/src/nco/nco_rth_flt.h,v 1.37 2012-07-03 19:44:30 zender Exp $ */

/* Purpose: Float-precision arithmetic */

/* Copyright (C) 1995--2012 Charlie Zender
   License: GNU General Public License (GPL) Version 3
   See http://www.gnu.org/copyleft/gpl.html for full license text */

/* Usage:
   #include "nco_rth_flt.h" *//* Float-precision arithmetic */

#ifndef NCO_RTH_FLT_H
#define NCO_RTH_FLT_H

#ifdef HAVE_CONFIG_H
# include <config.h> /* Autotools tokens */
#endif /* !HAVE_CONFIG_H */

/* Standard header files */
#include <math.h> /* sin cos cos sin 3.14159 */

/* fxm stdio only needed for TODO ncap57 */
#include <stdio.h> /* stderr, FILE, NULL, etc. */
#include <stdlib.h> /* atof, atoi, malloc, getopt */
#ifdef _MSC_VER
# include <time.h> /* time() seed for rand() */
#endif 

/* 3rd party vendors */
#include <netcdf.h> /* netCDF definitions and C library */
#include "nco_netcdf.h" /* NCO wrappers for netCDF C library */

/* Personal headers */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

  /* MSVC does not define lround(), lroundf(), lroundl(), llround(), llroundf(), llroundl(): Round to nearest integer */
#ifdef _MSC_VER
  long long llround(double x);
  long long llroundf(float x);
  long lround(double x);
  long lroundf(float x);
#endif /* !_MSC_VER */ 

#if !defined(HPUX) && !defined(__INTEL_COMPILER)
  /* Math float prototypes required by AIX, Solaris, but not by Linux, IRIX
     20040708: HP-UX does not like these 
     20090223: Intel compilers version 11.x complains about these */

  /* Basic math: acos, asin, atan, atan2, cos, exp, fabs, log, log10, pow, sin, sqrt, tan */
  float acosf(float);
  float asinf(float);
  float atanf(float);
  float atan2f(float,float);
  float cosf(float);
  float expf(float);
  float fabsf(float);
  float logf(float);
  float log10f(float);
  float powf(float,float);
  float sinf(float);
  float sqrtf(float);
  float tanf(float);

  /* Advanced math: erf, erfc, gamma, rnd_nbr */
  float erff(float);
  float erfcf(float);
  float gammaf(float);
  float rnd_nbrf(float);

  /* Hyperbolic trigonometric: acosh, asinh, atanh, cosh, sinh, tanh */
  float acoshf(float);
  float asinhf(float);
  float atanhf(float);
  float coshf(float);
  float sinhf(float);
  float tanhf(float);

  /* Basic Rounding: ceil, floor */
  float ceilf(float);
  float floorf(float);

  /* Advanced Rounding: nearbyint, rint, round, trunc */
  float nearbyintf(float);
  float rintf(float);
  float roundf(float);
  float truncf(float);

#endif /* HPUX */

double /* O [frc] Random fraction in [0,1] */
rnd_nbr /* [fnc] Generate random fraction in [0,1] */
(double x); /* I [frc] Immaterial */

#ifdef __cplusplus
} /* end extern "C" */
#endif /* __cplusplus */

#endif /* NCO_RTH_FLT_H */
