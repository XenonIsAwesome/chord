//
// Created by mayak on 8/13/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(IPP_ApplySquare, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<float> input = random_utils::generate_random_vector<float>(len);

    std::vector<float> actual(len);

    std::vector<float> expected(len);
    math_std::apply_square<float>(input, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::apply_square<float>(input, actual, len);
    
    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, actual);
}


TEST(IPP_ApplySquare_Inplace, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<float> input = random_utils::generate_random_vector<float>(len);

    std::vector<float> actual = input;
    std::vector<float> expected = input;

    math_std::apply_square_inplace<float>(expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::apply_square_inplace<float>(actual, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, actual);
}
