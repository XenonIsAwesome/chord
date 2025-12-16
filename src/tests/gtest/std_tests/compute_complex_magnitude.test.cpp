//
// Created by mayak on 6/29/25.
//

#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <complex>
#include <gtest/gtest.h>


TEST(STD_ComputeComplexMagnitude, ComplexFloatInput) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<std::complex<float>> src = {{0, 1},
                                            {1.0, 2.0},
                                            {3.69, 1.48},
                                            {0.592, 2.99},
                                            {6.98, 1.95}};

    std::vector<float> dst(5);

    std::vector<float> expected = {1.0,
                                   2.23606797749979,
                                   3.9757389250301634,
                                   3.0480426506202307,
                                   7.247268450940672};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::compute_complex_magnitude<float>(src, dst);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, dst, 1e-6);
}


TEST(ComputeComplexMagnitudeRealImag, ComplexFloatInput) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<float> src_imag = {1, 2.0, 1.48, 2.99, 1.95};
    std::vector<float> src_real = {0, 1.0, 3.69, 0.592, 6.98};

    std::vector<float> dst(5);

    std::vector<float> expected = {1.0,
                                   2.23606797749979,
                                   3.9757389250301634,
                                   3.0480426506202307,
                                   7.247268450940672};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::compute_real_imag_magnitude<float>(src_real, src_imag, dst);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, dst, 1e-6);
}
