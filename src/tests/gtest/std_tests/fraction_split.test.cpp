//
// Created by userk on 6/8/25.
//


#include "builtin_math/math_std.hpp"

#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(IntegerFractionSplit, WorksWithFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t input_len = 10;
    std::vector<float> input = {3.14f, -2.75f, 0, 1.999f, -0.001f, 5.5f, -7.3f, 4, -0.5f, 8.125f};

    std::vector<float> output_int(input_len);
    std::vector<float> output_frac(input_len);

    std::vector<float> expected_int = {3.0, -2.0, 0, 1, 0, 5, -7, 4, 0, 8};
    std::vector<float> expected_frac = {0.14f, -0.75, 0, 0.999f, -0.001f, 0.5f, -0.3f, 0, -0.5f, 0.125f};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::integer_fraction_split<float>(input, output_int, output_frac);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected_int,
                                            output_int,
                                            1e-5);

    gtest_utils::test::compare_spans<float>(expected_frac,
                                            output_frac,
                                            1e-5);
}
