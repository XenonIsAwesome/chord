//
// Created by userk on 6/10/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(DISABLED_IPP_Floor, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<float> input = random_utils::generate_random_vector<float>(len);

    std::vector<float> result(len);

    std::vector<float> expected(len);
    math_std::apply_floor<float>(input, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::apply_floor<float>(input, result, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, result);
}


TEST(DISABLED_IPP_Floor, Double) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<double> input = random_utils::generate_random_vector<double>(len);

    std::vector<double> result(len);

    std::vector<double> expected(len);
    math_std::apply_floor<double>(input, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::apply_floor<double>(input, result, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<double>(expected, result);
}
