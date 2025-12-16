//
// Created by mayak on 8/11/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(DISABLED_IPP_IntegerFractionSplit, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<float> input = random_utils::generate_random_vector<float>(len);

    std::vector<float> actual_int(len), actual_frac(len);

    std::vector<float> expected_int(len), expected_frac(len);
    math_std::integer_fraction_split<float>(input, expected_int, expected_frac);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::integer_fraction_split<float>(input, actual_int, actual_frac, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected_int, actual_int);
    gtest_utils::test::compare_spans<float>(expected_frac, actual_frac);
}
