//
// Created by mayak on 8/13/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(IPP_ComputeRealIMagMagnitude, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;

    std::vector<float> input1 = random_utils::generate_random_vector<float>(len);
    std::vector<float> input2 = random_utils::generate_random_vector<float>(len);

    std::vector<float> actual(len);

    std::vector<float> expected(len);
    math_std::compute_real_imag_magnitude<float>(input1, input2, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_real_imag_magnitude<float>(input1, input2, actual, len);
    
    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, actual, 1e-4);
}


TEST(IPP_ComputeRealIMagMagnitude, Double) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;

    std::vector<double> input1 = random_utils::generate_random_vector<double>(len);
    std::vector<double> input2 = random_utils::generate_random_vector<double>(len);

    std::vector<double> actual(len);

    std::vector<double> expected(len);
    math_std::compute_real_imag_magnitude<double>(input1, input2, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_real_imag_magnitude<double>(input1, input2, actual, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<double>(expected, actual);
}
