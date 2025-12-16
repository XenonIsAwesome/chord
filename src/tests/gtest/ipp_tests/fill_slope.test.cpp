//
// Created by mayak on 8/10/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>

// TODO: check cause threshols is LOW for float and non needed for double!
TEST(IPP_FillSlope, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    const auto offset = random_utils::generate_random_number<float>();
    const auto slope = random_utils::generate_random_number<float>();

    std::vector<float> actual(len);
    std::vector<float> expected(len);
    math_std::fill_slope<float>(expected, offset, slope);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::fill_slope<float>(actual, offset, slope, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, actual, 1e-3);
}


TEST(IPP_FillSlope, Double) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    const auto offset = random_utils::generate_random_number<double>();
    const auto slope = random_utils::generate_random_number<double>();

    std::vector<double> actual(len);

    std::vector<double> expected(len);
    math_std::fill_slope<double>(expected, offset, slope);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::fill_slope<double>(actual, offset, slope, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<double>(expected, actual);
}
