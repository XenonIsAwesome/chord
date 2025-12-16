//
// Created by mayak on 9/3/25.
//

#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(STD_ComputeMeanValue, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    const std::vector<float> input = {4.58, 6.72, 8.91, 3.25, 1.83, 7.61, 5.47, 9.99, 2.14, 4.3};
    float expected_mean = 5.48, actual_mean = 0;
    
    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::compute_mean_value<float>(input, actual_mean);
    
    // COMAPRE RESULTS --------------------------------------------------------------------------
    EXPECT_EQ(expected_mean, actual_mean);
}
