//
// Created by mayak on 6/25/25.
//

#include "lib.hpp"
#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(STD_ApplyAbsolute, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<float> actual(len);

    std::vector<float> input = {10.f, -5.5f, 3.3333f, 0.0f, 7.7f, -2.2f, 8.8f, 1.1f, -9.9f, 4.4f};
    std::vector<float> expected = {10.f, 5.5f, 3.3333f, 0.0f, 7.7f, 2.2f, 8.8f, 1.1f, 9.9f, 4.4f};


    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::apply_absolute<float>(input, actual);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, actual);
}
