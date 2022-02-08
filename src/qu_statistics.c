#include "qu_statistics.h"

float qu_sum(const float *data, size_t n)
{
    float sum = 0.0f;
    for (size_t i = 0; i < n; i++) sum += data[i];
    return sum;
}

float qu_mul_sum(const float *data0, const float *data1, size_t n)
{
    float sum = 0.0f;
    for (size_t i = 0; i < n; i++) sum += (data0[i] * data1[i]);
    return sum;
}

float qu_power_sum(const float *data, unsigned int power, size_t n)
{
    float sum = 0.0f;
    for (size_t i = 0; i < n; i++) sum += pow((double)data[i], (double)power);
    return sum;
}

float qu_linear_correlation(const float *data0, const float *data1, size_t n)
{
    float r = ((n * qu_mul_sum(data0, data1, n)) - (qu_sum(data0, n) * qu_sum(data1, n))) / 
              ((float)sqrt((float)(n * qu_power_sum(data0, 2, n) - pow((float)qu_sum(data0, n), (double)2))) * 
               (float)sqrt((float)(n * qu_power_sum(data1, 2, n) - pow((float)qu_sum(data1, n), (double)2))));
    return r;
}