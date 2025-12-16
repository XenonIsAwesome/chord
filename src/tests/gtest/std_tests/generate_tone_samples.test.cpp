//
// Created by mayak on 6/29/25.
//

#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(GeneratTone, FloatInput) {
    // SET VALUES -------------------------------------------------------------------------------
    float magn = 1.0f;
    float freq = 0.05f;
    float phase = 0.0f;

    std::vector<float> res(10);

    std::vector<float> expected = {1,
                                   0.951057,
                                   0.809017,
                                   0.587785,
                                   0.309017,
                                   6.12323e-17,
                                   -0.309017,
                                   -0.587785,
                                   -0.809017,
                                   -0.951057};
    float expected_phase = M_PI;


    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::generate_tone<float>(res, magn, freq, phase);


    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, res, 1e-6);  // check samples
    EXPECT_EQ(expected_phase, phase);  // check updated phase
}


TEST(GeneratComplexTone, ComplexFloatInput) {
    // SET VALUES -------------------------------------------------------------------------------
    float magn = 1.0f;
    float freq = 0.05f;
    float phase = 0.0f;

    std::vector<std::complex<float>> res(10);

    std::vector<std::complex<float>> expected = {{1, 0},
                                                 {0.951057, 0.309017},
                                                 {0.809017, 0.587785},
                                                 {0.587785, 0.809017},
                                                 {0.309017, 0.951057},
                                                 {0, 1},
                                                 {-0.309017, 0.951057},
                                                 {-0.587785, 0.809017},
                                                 {-0.809017, 0.587785},
                                                 {-0.951057, 0.309017}};
    float expected_phase = M_PI;

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::generate_tone_complex<float>(res, magn, freq, phase);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, res, 1e-6);  // check samples
    EXPECT_EQ(expected_phase, phase);  // check updated phase
}