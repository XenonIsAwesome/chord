//
// Created by mayak on 8/13/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(DISABLED_IPP_ComputeComplexDotProduct, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<float> input1 = random_utils::generate_random_vector<float>(len);
    std::vector<std::complex<float>> input2 =
        random_utils::generate_random_vector<std::complex<float>>(len);

    std::complex<float> actual = {0, 0};
    std::complex<float> expected = {0, 0};

    math_std::compute_complex_dot_product<float>(input1, input2, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_complex_dot_product<float>(input1, input2, actual, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_complex(expected, actual);
}


TEST(IPP_ComputeDotProduct, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<float> input1 = random_utils::generate_random_vector<float>(len);
    std::vector<float> input2 =
        random_utils::generate_random_vector<float>(len);

    float actual = 0;
    float expected = 0;

    math_std::compute_dot_product<float>(input1, input2, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_dot_product<float>(input1, input2, actual, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    ASSERT_EQ(actual, expected);
    ASSERT_NE(actual, 0);
}
