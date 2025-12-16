//
// Created by userk on 6/8/25.
//


#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <complex>
#include <gtest/gtest.h>


TEST(DivideByScalar, WorksWithFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t input_len = 10;

    constexpr float scalar = 2.0f;
    std::vector<float> input = {10.f, -5.5f, 3.3333f, 0.0f, 7.7f, -2.2f, 8.8f, 1.1f, -9.9f, 4.4f};

    std::vector<float> output(input_len);

    std::vector<float> expected =
        {5.0f, -2.75f, 1.66665f, 0.0f, 3.85f, -1.1f, 4.4f, 0.55f, -4.95f, 2.2f};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::divide_by_scalar<float>(input, scalar, output);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, output);
}
