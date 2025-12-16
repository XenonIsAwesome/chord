//
// Created by mayak on 6/29/25.
//

#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <complex>
#include <gtest/gtest.h>


TEST(ComputeComplexConjugate, ComplexFloatInput) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<std::complex<float>> src = {{0, 1},
                                            {1.0, 2.0},
                                            {3.69, 1.48},
                                            {0.592, 2.99},
                                            {6.98, 1.95}};

    std::vector<std::complex<float>> dst(5);

    std::vector<std::complex<float>> expected = {{0.0, -1.},
                                                 {1.0, -2.0},
                                                 {3.69, -1.48},
                                                 {0.592, -2.99},
                                                 {6.98, -1.95}};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::compute_complex_conjugates<float>(src, dst);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, dst);
}


TEST(ComputeComplexConjugateInplace, ComplexFloatInput) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<std::complex<float>> src = {{0, 1},
                                            {1.0, 2.0},
                                            {3.69, 1.48},
                                            {0.592, 2.99},
                                            {6.98, 1.95}};

    std::vector<std::complex<float>> expected = {{0.0, -1.},
                                                 {1.0, -2.0},
                                                 {3.69, -1.48},
                                                 {0.592, -2.99},
                                                 {6.98, -1.95}};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::compute_complex_conjugates_inplace<float>(src);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, src);
}
