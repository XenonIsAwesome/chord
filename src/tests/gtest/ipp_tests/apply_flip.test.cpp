//
// Created by mayak on 8/7/25.
//


#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(IPP_ApplyFlip, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<float> input = random_utils::generate_random_vector<float>(len, 0, 5);
    std::vector<float> expected_res(len);
    std::vector<float> actual_res(len);

    math_std::apply_flip<float>(input, expected_res);  // set expected

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::apply_flip<float>(input, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected_res, actual_res, 1e-5);
}


TEST(IPP_ApplyFlip_Inplace, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<float> input = random_utils::generate_random_vector<float>(len, 0, 5);
    std::vector<float> expected_res = input;
    std::vector<float> actual_res = input;

    math_std::apply_flip_inplace<float>(expected_res);  // set expected

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::apply_flip_inplace<float>(actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected_res, actual_res);
}
