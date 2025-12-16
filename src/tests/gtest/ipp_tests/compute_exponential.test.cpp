//
// Created by userk on 6/10/25.
//


#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <chord/check_args/check_not_zero.hpp>
#include <complex>
#include <gtest/gtest.h>


TEST(DISABLED_IPP_ComputeExponential, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;
    std::vector<std::complex<float>> input =
        random_utils::generate_random_vector<std::complex<float>>(len);
    std::vector<std::complex<float>> result(len);
    std::vector<std::complex<float>> expected(len);

    math_std::compute_exponential<std::complex<float>>(input, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_exponential<std::complex<float>>(input, result, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, result, 1e-4);
}
