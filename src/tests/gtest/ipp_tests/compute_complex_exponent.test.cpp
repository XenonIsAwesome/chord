//
// Created by mayak on 8/7/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(DISABLED_IPP_ComputeComplexExponent, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<float> input = random_utils::generate_random_vector<float>(len);
    std::vector<std::complex<float>> expected_res(len);
    std::vector<std::complex<float>> actual_res(len);

    math_std::compute_complex_exponent<float>(input, expected_res);  // set expected

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_complex_exponent<float>(input, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected_res, actual_res, 1e-5);
}
