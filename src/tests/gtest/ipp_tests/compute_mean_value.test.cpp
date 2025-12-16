//
// Created by mayak on 8/7/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <complex>
#include <gtest/gtest.h>


TEST(IPP_ComputeAverage, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;
    const std::vector<float> input = random_utils::generate_random_vector<float>(len, 0, 5);

    float actual_mean;

    float expected_mean;
    math_std::compute_average<float>(input, expected_mean);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_mean_value<float>(input, actual_mean, chord::AlgoChoice::Basic, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    ASSERT_NEAR(actual_mean, expected_mean, 1e-6);
}
