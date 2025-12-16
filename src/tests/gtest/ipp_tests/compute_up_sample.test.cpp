//
// Created by mayak on 8/12/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(IPP_SampleUp, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr int len = 10;
    auto expected_phase = 0;
    auto actual_phase = 0;
    const auto factor = random_utils::generate_random_number<int>(0, 10);

    std::vector<float> input = random_utils::generate_random_vector<float>(len);

    int expected_len = len * factor;
    std::vector<float> actual(expected_len);

    std::vector<float> expected(expected_len);
    math_std::compute_up_sample<float>(input, expected, factor, &expected_phase);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_up_sample<float>(input, len, factor, &actual_phase, actual, &expected_len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, actual);
    ASSERT_EQ(expected_phase, actual_phase);
}


TEST(IPP_SampleUp, Double) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr int len = 10;
    auto expected_phase = 0;
    auto actual_phase = 0;
    const auto factor = random_utils::generate_random_number<int>(0, 10);

    std::vector<double> input = random_utils::generate_random_vector<double>(len);

    int expected_len = len * factor;
    std::vector<double> actual(expected_len);

    std::vector<double> expected(expected_len);
    math_std::compute_up_sample<double>(input, expected, factor, &expected_phase);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_up_sample<double>(input, len, factor, &actual_phase, actual, &expected_len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<double>(expected, actual);
    ASSERT_EQ(expected_phase, actual_phase);
}


TEST(IPP_SampleUp, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr int len = 10;
    auto expected_phase = 0;
    auto actual_phase = 0;
    const auto factor = random_utils::generate_random_number<int>(0, 10);

    std::vector<std::complex<float>> input = random_utils::generate_random_vector<std::complex<float>>(len);

    int expected_len = len * factor;
    std::vector<std::complex<float>> actual(expected_len);

    std::vector<std::complex<float>> expected(expected_len);
    math_std::compute_up_sample<std::complex<float>>(input, expected, factor, &expected_phase);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_up_sample<std::complex<float>>(input, len, factor, &actual_phase, actual, &expected_len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, actual);
    ASSERT_EQ(expected_phase, actual_phase);
}
