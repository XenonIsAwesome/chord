//
// Created by mayak on 6/25/25.
//

#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <complex>
#include <gtest/gtest.h>


TEST(STD_ApplySqaure_Inplace, ComplexFloat) {
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

    std::vector<std::complex<float>> expected = {{16.0000000, 0.0000000},
                                                 {16.0000000, -0.0000000},
                                                 {-16.0000000, 0.0000000},
                                                 {-7.0000000, 24.0000000},
                                                 {-7.0000000, -24.0000000},
                                                 {0.0000000, 0.0000000},
                                                 {0.0000000, 2.0000000},
                                                 {0.0000000, -0.0002000},
                                                 {-0.1875000, -0.2500000},
                                                 {0.0000000, 1.1250000}};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::apply_square_inplace<std::complex<float>>(input);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, input, 1e-6);
}
