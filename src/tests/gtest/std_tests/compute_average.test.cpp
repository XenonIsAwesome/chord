//
// Created by mayak on 6/29/25.
//

#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <complex>
#include <gtest/gtest.h>


TEST(STD_ComputeAverage, ComplexFloatType) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<std::complex<float>> input = {{0.1, 0.254},
                                              {0.78941, 9.254},
                                              {78.1654, 10451.22},
                                              {2.3, 124.2},
                                              {-78.4599, 3.669}};

    std::complex<float> expected_mean = {0.578983, 2117.7194};
    std::complex<float> actual_mean;

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::compute_average<std::complex<float>>(input, actual_mean);

    // COMAPRE RESULTS --------------------------------------------------------------------------

    std::cout << actual_mean << " " << expected_mean;
    gtest_utils::test::compare_complex_with_threshold(expected_mean, actual_mean, 1e-3);
}
