//
// Created by userk on 6/5/25.
//

#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <complex>

#include <gtest/gtest.h>


TEST(ComputeExponential, WorksForComplexFloatType) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;
    const std::vector<std::complex<float>> input = {{0, 0},
                                              {1.0f, 2.0f},
                                              {3.69f, 1.51f},
                                              {0.59f, 2.99f},
                                              {6.98f, 1.95f}};
    std::vector<std::complex<float>> result(len);

    std::vector<std::complex<float>> expected = {{1.000000000000f, 0.000000000000f},
                                                 {-1.131204383757f, 2.471726672005f},
                                                 {2.433080099726f, 39.970863001202f},
                                                 {-1.783299953025f, 0.272425183182f},
                                                 {-397.91421508789062, 998.5557861328125}};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::compute_exponential<std::complex<float>>(input, result);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(
        expected,
        result, 1e-5);
}
