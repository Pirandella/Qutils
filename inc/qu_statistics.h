#ifndef _QUTILS_STATISTICS_H_
#define _QUTILS_STATISTICS_H_

#include <stdio.h>
#include <math.h>


float qu_sum(const float *data, size_t n);
float qu_mul_sum(const float *data0, const float *data1, size_t n);
float qu_power_sum(const float *data, unsigned int power, size_t n);

float qu_linear_correlation(const float *data0, const float *data1, size_t n);

#endif /* _QUTILS_STATISTICS_H_ */