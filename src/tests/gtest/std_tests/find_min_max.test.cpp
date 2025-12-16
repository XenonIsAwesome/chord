//
// Created by mayak on 6/29/25.
//

#include "builtin_math/math_std.hpp"
#include "utils/test_runner.hpp"

#include <complex>
#include <gtest/gtest.h>


TEST(FindMax, ComplexFloatInput) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<std::complex<float>> input = {{4.0f, 0.0f},
                                              {-4.0f, 0.0f},
                                              {0.0f, 4.0f},
                                              {3.0f, 4.0f},
                                              {-3.0f, 4.0f},
                                              {0.0f, 0.0f},
                                              {1.0f, 1.0f},
                                              {0.01f, -0.01f},
                                              {-0.25f, 0.5f},
                                              {0.75f, 0.75f}};

    std::complex<float> expected_max = {3, 4};
    std::complex<float> actual_max;

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::find_maximum<std::complex<float>>(input, actual_max);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    EXPECT_EQ(expected_max, actual_max);
}


TEST(FindMaxIndex, ComplexFloatInput) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<std::complex<float>> input = {{4.0f, 0.0f},
                                              {-4.0f, 0.0f},
                                              {0.0f, 4.0f},
                                              {3.0f, 4.0f},
                                              {-3.0f, 4.0f},
                                              {0.0f, 0.0f},
                                              {1.0f, 1.0f},
                                              {0.01f, -0.01f},
                                              {-0.25f, 0.5f},
                                              {0.75f, 0.75f}};

    std::complex<float> expected_max = {3, 4};
    std::complex<float> actual_max;

    int expected_index = 3;
    int actual_index;

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::find_maximum_and_index<std::complex<float>>(input, actual_max, actual_index);


    // COMAPRE RESULTS --------------------------------------------------------------------------
    EXPECT_EQ(expected_max, actual_max);
    EXPECT_EQ(expected_index, actual_index);
}


TEST(FindMin, ComplexFloatInput) {
    // SET VALUES -------------------------------------------------------------------------------
    const std::vector<std::complex<float>> input = {{4.0f, 0.0f},
                                              {-4.0f, 0.0f},
                                              {0.0f, 4.0f},
                                              {3.0f, 4.0f},
                                              {-3.0f, 4.0f},
                                              {0.0f, 0.0f},
                                              {1.0f, 1.0f},
                                              {0.01f, -0.01f},
                                              {-0.25f, 0.5f},
                                              {0.75f, 0.75f}};

    std::complex<float> expected_min = {0, 0};
    std::complex<float> actual_min;

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::find_minimum<std::complex<float>>(input, actual_min);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    EXPECT_EQ(expected_min, actual_min);
}


TEST(FindMinIndex, ComplexFloatInput) {
    // SET VALUES -------------------------------------------------------------------------------
    const std::vector<std::complex<float>> input = {{4.0f, 0.0f},
                                              {-4.0f, 0.0f},
                                              {0.0f, 4.0f},
                                              {3.0f, 4.0f},
                                              {-3.0f, 4.0f},
                                              {0.0f, 0.0f},
                                              {1.0f, 1.0f},
                                              {0.01f, -0.01f},
                                              {-0.25f, 0.5f},
                                              {0.75f, 0.75f}};

    std::complex<float> expected_min = {0, 0};
    std::complex<float> actual_min;

    int expected_index = 5;
    int actual_index;

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::find_minimum_and_index<std::complex<float>>(input, actual_min, actual_index);


    // COMAPRE RESULTS --------------------------------------------------------------------------
    EXPECT_EQ(expected_min, actual_min);
    EXPECT_EQ(expected_index, actual_index);
}
