//
// Created by mayak on 8/7/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(DISABLED_IPP_ComputeComplexMagnitude, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<std::complex<float>> input =
        random_utils::generate_random_vector<std::complex<float>>(len, 0, 5);
    std::vector<float> expected_res(len);
    std::vector<float> actual_res(len);

    math_std::compute_complex_magnitude<float>(input, expected_res);  // set expected

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_complex_magnitude<float>(input, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected_res, actual_res, 1e-6);
}


TEST(IPP_ComputeComplexMagnitude, ComplexDouble) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<std::complex<double>> input =
        random_utils::generate_random_vector<std::complex<double>>(len, 0, 5);
    std::vector<double> expected_res(len);
    std::vector<double> actual_res(len);

    math_std::compute_complex_magnitude<double>(input, expected_res);  // set expected

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_complex_magnitude<double>(input, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<double>(expected_res, actual_res, 1e-6);
}
