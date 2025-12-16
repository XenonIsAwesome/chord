//
// Created by userk on 6/8/25.
//


#include "builtin_math/math_std.hpp"

#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(SampleUp, WorksWithFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    int phase = 0;
    constexpr size_t input_len = 4;
    const int factor = 3;
    constexpr size_t expected_len = input_len * factor;
    std::vector<float> input = {1.0f, 2.0f, 3.0f, 4.0f};
    std::vector<float> expected =
        {1.0f, 0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 4.0f, 0.0f, 0.0f};

    std::vector<float> output(expected_len);

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::compute_up_sample<float>(input, output, factor, &phase);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, output);
}


TEST(SampleUp, WorksWithComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    int phase = 0;
    constexpr size_t input_len = 4;
    constexpr int factor = 3;
    std::vector<std::complex<float>> input = {{1.0f, 1.0f},
                                              {2.0f, -1.0f},
                                              {3.0f, 0.5f},
                                              {4.0f, -0.5f}};


    std::vector<std::complex<float>> expected = {{1.0f, 1.0f},
                                                 {0, 0},
                                                 {0, 0},
                                                 {2.0f, -1.0f},
                                                 {0, 0},
                                                 {0, 0},
                                                 {3.0f, 0.5f},
                                                 {0, 0},
                                                 {0, 0},
                                                 {4.0f, -0.5f},
                                                 {0, 0},
                                                 {0, 0}};

    constexpr size_t expected_len = input_len * factor;
    std::vector<std::complex<float>> output(expected_len);

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::compute_up_sample<std::complex<float>>(input, output, factor, &phase);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, output);
}
