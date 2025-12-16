//
// Created by mayak on 6/29/25.
//

#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(STD_CombineWithScalar, FloatInputInplace) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<float> input =
        {0.1, 0.254, 0.78941, 9.254, 78.1654, 10451.22, 2.3, 124.2, -78.4599, 3.669};

    float scalar = 9.9;
    std::vector<float> expected = {
        10.00000000000000,
        10.15400000000000,
        10.68941000000000,
        19.15400000000000,
        88.06540000000001,
        10461.11999999999898,
        12.20000000000000,
        134.09999084472656,
        -68.55990000000000,
        13.56900000000000,
    };

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::combine_with_scalar_inplace<float>(input, scalar);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, input, 1e-6);
}


TEST(STD_CombineWithScalar, FloatInput) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<float> input =
        {0.1, 0.254, 0.78941, 9.254, 78.1654, 10451.22, 2.3, 124.2, -78.4599, 3.669};
    std::vector<float> output(10);

    float scalar = 9.9;
    std::vector<float> expected = {
        10.00000000000000,
        10.15400000000000,
        10.68941000000000,
        19.15400000000000,
        88.06540000000001,
        10461.11999999999898,
        12.20000000000000,
        134.09999084472656,
        -68.55990000000000,
        13.56900000000000,
    };

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::combine_with_scalar<float>(input, scalar, output);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, output, 1e-6);
}
