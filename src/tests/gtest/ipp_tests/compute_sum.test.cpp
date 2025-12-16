//
// Created by mayak on 8/14/25.
//

#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "builtin_math/math_std.hpp"
#include "random_generate/random_utils.hpp"

#include <gtest/gtest.h>


TEST(IPP_ComputeSum, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<float> input = random_utils::generate_random_vector<float>(len);

    float actual = 0;

    float expected = 0;
    math_std::compute_sum<float>(input, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_sum<float>(input, actual, chord::AlgoChoice::Basic, len);
    
    // COMAPRE RESULTS --------------------------------------------------------------------------
    ASSERT_EQ(expected, actual);
}


TEST(IPP_ComputeSum, Int) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<int> input = random_utils::generate_random_vector<int>(len);

    int actual = 0;

    int expected = 0;
    math_std::compute_sum<int>(input, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_sum<int>(input, actual, chord::AlgoChoice::Basic, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    ASSERT_EQ(expected, actual);
}


TEST(IPP_ComputeSum, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<std::complex<float>> input = random_utils::generate_random_vector<std::complex<float>>(len);

    std::complex<float> actual = {0, 0};

    std::complex<float> expected = {0, 0};
    math_std::compute_sum<std::complex<float>>(input, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_sum<std::complex<float>>(input, actual, chord::AlgoChoice::Basic, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    ASSERT_EQ(expected, actual);
}
