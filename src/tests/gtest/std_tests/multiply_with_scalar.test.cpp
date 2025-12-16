//
// Created by userk on 6/5/25.
//

#include "builtin_math/math_std.hpp"

#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(MultiplyWithScalar, WorksForFloatType) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<float> src =
        {0, 2.392f, 3.690f, 1.510f, 7.84f, 5.78f, 0.59f, 2.99f, 6.98f, 1.95f, 4.1f};

    std::vector<float> expected =
        {0, 7.6544f, 11.8080f, 4.832f, 25.088f, 18.496f, 1.888f, 9.568f, 22.336f, 6.24f, 13.12f};

    constexpr float scalar = 3.2f;

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::multiply_with_scalar_inplace<float>(src, scalar);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected,
                                            src,
                                            1e-5);
}


TEST(MultiplyWithScalar, WorksForComplexFloatType) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<std::complex<float>> src = {{0, 2.392f},
                                            {3.690f, 1.510f},
                                            {7.84f, 5.78f},
                                            {0.59f, 2.99f},
                                            {6.98f, 1.95f}};

    std::vector<std::complex<float>> expected = {{-16.00248f, 7.6544f},
                                                  {1.7060999999f, 29.5181f},
                                                  {-13.5802f, 70.9456f},
                                                  {-18.1151f, 13.5151f},
                                                  {9.2905f, 52.9362}};

    constexpr std::complex<float> scalar = {3.2f, 6.69f};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::multiply_with_scalar_inplace<std::complex<float>>(src, scalar);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(
        expected,
        src,
        1e-5);
}
