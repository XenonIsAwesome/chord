//
// Created by mayak on 8/13/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(DISABLED_IPP_ComputeFractionalPart, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<float> input = random_utils::generate_random_vector<float>(len);

    std::vector<float> actual(len);

    std::vector<float> expected(len);
    math_std::compute_fractional_part<float>(input, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_fractional_part<float>(input, actual, len);;
    
    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, actual);
}


TEST(DISABLED_IPP_ComputeFractionalPart, Double) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<double> input = random_utils::generate_random_vector<double>(len);

    std::vector<double> actual(len);

    std::vector<double> expected(len);
    math_std::compute_fractional_part<double>(input, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_fractional_part<double>(input, actual, len);;

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<double>(expected, actual);
}
