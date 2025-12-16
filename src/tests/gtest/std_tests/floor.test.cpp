//
// Created by userk on 6/8/25.
//

#include "builtin_math/math_std.hpp"

#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(Floor, WorksForFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<float> src = {3.7, -2.1f, 0, 1.999f, -0.999f};
    std::vector<float> expected =
        {3.0f, -3.0f, 0, 1, -1};

    std::vector<float> dst(5);

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::apply_floor<float>(src, dst);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected,
                                           dst,
                                           1e-5);
}


TEST(Floor, WorksForDouble) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<double> src = {3.7, -2.1, 0, 1.999, -0.999};
    std::vector<double> expected =
        {3.0f, -3.0f, 0, 1, -1};

    std::vector<double> dst(5);

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::apply_floor<double>(src, dst);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<double>(expected,
                                           dst,
                                           1e-5);
}
