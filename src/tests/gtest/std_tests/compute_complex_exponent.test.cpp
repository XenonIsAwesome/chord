//
// Created by mayak on 6/29/25.
//

#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <cmath>
#include <complex>
#include <gtest/gtest.h>


TEST(ComputeComplexExponent, FloatInput) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<float> src = {0.0,
                              static_cast<float>(M_PI / 4),
                              static_cast<float>(M_PI / 2),
                              static_cast<float>(M_PI),
                              static_cast<float>(3 * M_PI / 2)};
    std::vector<std::complex<float>> dst(5);

    std::vector<std::complex<float>> expected = {{1, 0},
                                                 {0.707107, 0.707107},
                                                 {6.12323e-17, 1},
                                                 {-1, 1.22465e-16},
                                                 {-1.83697e-16, -1}};


    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::compute_complex_exponent<float>(src, dst);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, dst, 1e-6);
}
