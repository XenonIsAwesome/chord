//
// Created by mayak on 8/10/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"

#include <gtest/gtest.h>


TEST(IPP_FindMax, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<float> input = random_utils::generate_random_vector<float>(len);

    float actual_max, expected_max;
    math_std::find_maximum<float>(input, expected_max);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::find_maximum<float>(input, actual_max, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    ASSERT_EQ(expected_max, actual_max);
}


TEST(IPP_FindMax, Double) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<double> input = random_utils::generate_random_vector<double>(len);

    double actual_max, expected_max;
    math_std::find_maximum<double>(input, expected_max);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::find_maximum<double>(input, actual_max, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    ASSERT_EQ(expected_max, actual_max);
}


TEST(IPP_FindMaxIndex, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<float> input = random_utils::generate_random_vector<float>(len, 5);

    float actual_max, expected_max;
    int actual_max_index, expected_max_index;
    math_std::find_maximum_and_index<float>(input, expected_max, expected_max_index);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::find_maximum_index<float>(input, actual_max, actual_max_index, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    ASSERT_EQ(expected_max, actual_max);
    ASSERT_EQ(expected_max_index, actual_max_index);
}

/////////////////////////////////////
TEST(IPP_FindMin, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    const std::vector<float> input = random_utils::generate_random_vector<float>(len);

    float actual_max, expected_max;
    math_std::find_minimum<float>(input, expected_max);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::find_minimum<float>(input, actual_max, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    ASSERT_EQ(expected_max, actual_max);
}


TEST(IPP_FindMin, Double) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    const std::vector<double> input = random_utils::generate_random_vector<double>(len);

    double actual_max, expected_max;
    math_std::find_minimum<double>(input, expected_max);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::find_minimum<double>(input, actual_max, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    ASSERT_EQ(expected_max, actual_max);
}


TEST(IPP_FindMinIndex, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    const std::vector<float> input = random_utils::generate_random_vector<float>(len, 5);

    float actual_min, expected_min;
    int actual_min_index, expected_min_index;
    math_std::find_minimum_and_index<float>(input, expected_min, expected_min_index);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::find_minimum_index<float>(input, actual_min, actual_min_index, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    ASSERT_EQ(expected_min, actual_min);
    ASSERT_EQ(expected_min_index, actual_min_index);
}
