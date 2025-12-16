//
// Created by mayak on 8/7/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(DISABLED_IPP_ApplyPower, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<float> input1 = random_utils::generate_random_vector<float>(len, 0, 5);
    std::vector<float> input2 = random_utils::generate_random_vector<float>(len, 0, 5);
    std::vector<float> expected_res(len);
    std::vector<float> actual_res(len);

    math_std::apply_raise_power<float>(input1, input2, expected_res);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::apply_raise_power<float>(input1, input2, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected_res, actual_res);
}

// TODO: ALL DISABLED TESTS NEED TO BE PUT BACK ON when functions fixed
TEST(DISABLED_IPP_ApplyPowerWithScalar, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<float> input1 = random_utils::generate_random_vector<float>(len, 0, 5);
    const auto scalar = random_utils::generate_random_number<float>(0, 10);
    std::vector<float> expected_res(len);
    std::vector<float> actual_res(len);

    math_std::apply_raise_power_with_scalar<float>(input1, scalar, expected_res);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::apply_raise_power_with_scalar<float>(input1, scalar, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected_res, actual_res);
}
