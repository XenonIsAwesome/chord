//
// Created by mayak on 6/25/25.
//

#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(ComputeSubstraction, WorksForFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<float> input1 = {10.f, -5.5f, 3.3333f, 0.0f, 7.7f, -2.2f, 8.8f, 1.1f, -9.9f, 4.4f};
    const std::vector<float> input2 =
        {5.f, -5.43215f, 3.123f, 0.0f, -7.32f, -4.2f, 7.8f, 123.1f, -0.9f, 4.4f};

    std::vector<float> expected =
        {5.f, -0.06785f, 0.2103f, 0.0f, 15.02f, 2.0f, 1.0f, -122, -9.0f, 0.0f};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::compute_substraction_inplace<float>(input1, input2);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, input1, 1e-6);
}
