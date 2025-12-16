//
// Created by mayak on 8/7/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <chord/lib.hpp>
#include <gtest/gtest.h>


TEST(IPP_ComputeComplexConjugate, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    chord::divide_by_scalar<float>(std::span<float>(), 0, std::span<float>());
    chord::subtract<float>(std::span<float>(), std::span<float>());

    std::vector<std::complex<float>> input =
        random_utils::generate_random_vector<std::complex<float>>(len, 0, 5);
    std::vector<std::complex<float>> expected_res(len);
    std::vector<std::complex<float>> actual_res(len);

    math_std::compute_complex_conjugates<float>(input, expected_res);  // set expected

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_complex_conjugates<float>(input, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected_res, actual_res);
}


TEST(IPP_ComputeComplexConjugate, ComplexDouble) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<std::complex<double>> input =
        random_utils::generate_random_vector<std::complex<double>>(len, 0, 5);
    std::vector<std::complex<double>> expected_res(len);
    std::vector<std::complex<double>> actual_res(len);

    math_std::compute_complex_conjugates<double>(input, expected_res);  // set expected

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_complex_conjugates<double>(input, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<double>>(expected_res, actual_res);
}


TEST(IPP_ComputeComplexConjugate_Inplace, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<std::complex<float>> input =
        random_utils::generate_random_vector<std::complex<float>>(len, 0, 5);

    std::vector<std::complex<float>> src_dst_expected = input;
    std::vector<std::complex<float>> src_dst_actual = input;

    math_std::compute_complex_conjugates_inplace<float>(src_dst_expected);  // set expected

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_complex_conjugates_inplace<float>(src_dst_actual, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(src_dst_expected, src_dst_actual);
}


TEST(IPP_ComputeComplexConjugate_Inplace, ComplexDouble) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<std::complex<double>> input =
        random_utils::generate_random_vector<std::complex<double>>(len, 0, 5);

    std::vector<std::complex<double>> src_dst_expected = input;
    std::vector<std::complex<double>> src_dst_actual = input;

    math_std::compute_complex_conjugates_inplace<double>(src_dst_expected);  // set expected

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_complex_conjugates_inplace<double>(src_dst_actual, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<double>>(src_dst_expected, src_dst_actual);
}
