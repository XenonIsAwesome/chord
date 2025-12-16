//
// Created by mayak on 8/6/25.
//

#include "builtin_math/math_std.hpp"

#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(IPP_ApplyAbsolute, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<float> input = random_utils::generate_random_vector<float>(len, 0, 5);
    std::vector<float> expected_res(len);
    std::vector<float> actual_res(len);

    math_std::apply_absolute<float>(input, expected_res);  // set expected

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::apply_absolute<float>(input, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected_res, actual_res, 1e-5);
}


TEST(IPP_ApplyAbsolute, Double) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;
    std::vector<double> input = random_utils::generate_random_vector<double>(len, 0, 5);
    std::vector<double> actual_res(len);

    std::vector<double> expected_res(len);
    math_std::apply_absolute<double>(input, expected_res);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::apply_absolute<double>(input, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<double>(expected_res, actual_res, 1e-5);
}


TEST(IPP_ApplyAbsolute_Inplace, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<float> input = random_utils::generate_random_vector<float>(len, 0, 5);
    std::vector<float> actual_res = input;

    std::vector<float> expected_res = input;
    math_std::apply_absolute_inplace<float>(expected_res);  // set expected

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::apply_absolute_inplace<float>(actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected_res, actual_res, 1e-5);
}


TEST(IPP_ApplyAbsolute_Inplace, Double) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<double> input = random_utils::generate_random_vector<double>(len, 0, 5);
    std::vector<double> actual_res = input;

    std::vector<double> expected_res = input;
    math_std::apply_absolute_inplace<double>(expected_res);  // set expected

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::apply_absolute_inplace<double>(actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<double>(expected_res, actual_res, 1e-5);
}


// INSTANTIATE_TEST_SUITE_P(ApplyAbsolute,
//                          FloatTestWrapperOneSrcOneDst,
//                          ::testing::Values(FloatParam{
//                              math_std::apply_absolute<float>,
//                              ipp::wrappers::apply_absolute<float>}));


// INSTANTIATE_TEST_SUITE_P(ApplyFlip,
//                          FloatTestWrapperOneSrcOneDst,
//                          ::testing::Values(FloatParam{math_std::apply_absolute<float>,
//                                                        ipp::wrappers::apply_absolute<float>}));
