#include "qu_statistics.h"
#include "gtest/gtest.h"
    
static const size_t n = 10;
static const float data0[n] = {
    57.898f, 48.567f, 51.005f, 2.962f, 53.308f,
    16.061f, 49.976f ,87.259f, 51.015f, 3.652f
};

static const float data1[n] = {
    58.515f, 32.668f ,2.281f ,98.447f, 98.34f,
    79.376f, 75.732f, 6.183f, 50.946f, 35.831f
};

TEST(sum, qu_sum)
{
    ASSERT_FLOAT_EQ(qu_sum(data0, n), 421.703f);
    ASSERT_FLOAT_EQ(qu_sum(data1, n), 538.319f);
}

TEST(mul_sum, qu_mul_sum)
{
    ASSERT_FLOAT_EQ(qu_mul_sum(data0, data1, n), 18953.767f);
}

TEST(power_sum, qu_power_sum)
{
    ASSERT_FLOAT_EQ(qu_power_sum(data0, 2, n), 24148.514f);
    ASSERT_FLOAT_EQ(qu_power_sum(data1, 2, n), 39812.443f);
}

TEST(linear_correlation, qu_linear_correlation)
{
    EXPECT_NEAR(qu_linear_correlation(data0, data1, n), -0.451261f, 0.00001f);
}