//
// Created by mayak on 7/2/25.
//

#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(FillSlope, FloatType) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<float> result(10);
    float offset = 1.1;
    float slope = 2.64;

    std::vector<float> expected = {1.1,
                                   3.74,
                                   6.380000000000001,
                                   9.02,
                                   11.66,
                                   14.300000000000001,
                                   16.940000000000001,
                                   19.580000000000002,
                                   22.220000000000002,
                                   24.860000000000003};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::fill_slope<float>(result, offset, slope);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, result, 1e-5);
}
