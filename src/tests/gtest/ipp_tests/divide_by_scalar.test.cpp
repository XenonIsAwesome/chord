//
// Created by userk on 6/10/25.
//

#include "../src/impls/ipp/ipp_impl.tpp"
#include "builtin_math/math_std.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <complex>
#include <gtest/gtest.h>


TEST(IPP_DivideByScalar_Inplace, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<float> expected = random_utils::generate_random_vector<float>(len);

    const auto scalar = random_utils::generate_random_number<float>();

    std::vector<float> actual = expected;
    math_std::divide_by_scalar_inplace<float>(expected, scalar);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::divide_by_scalar_inplace<float>(actual, scalar, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, actual, 1e-6);
}


TEST(IPP_DivideByScalar_Inplace, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<std::complex<float>> expected =
        random_utils::generate_random_vector<std::complex<float>>(len);

    const auto scalar = random_utils::generate_random_number<std::complex<float>>();

    std::vector<std::complex<float>> actual = expected;
    math_std::divide_by_scalar_inplace<std::complex<float>>(expected, scalar);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::divide_by_scalar_inplace<std::complex<float>>(actual, scalar, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, actual, 1e-6);
}


TEST(IPP_DivideByScalar, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<std::complex<float>> input =
        random_utils::generate_random_vector<std::complex<float>>(len);

    const auto scalar = random_utils::generate_random_number<std::complex<float>>();

    std::vector<std::complex<float>> actual(len);

    std::vector<std::complex<float>> expected(len);
    math_std::divide_by_scalar<std::complex<float>>(input, scalar, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::divide_by_scalar<std::complex<float>>(input, scalar, actual, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, actual, 1e-6);
}


TEST(IPP_DivideByScalar, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<float> input = random_utils::generate_random_vector<float>(len);

    const auto scalar = random_utils::generate_random_number<float>();

    std::vector<float> actual(len);

    std::vector<float> expected(len);
    math_std::divide_by_scalar<float>(input, scalar, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::divide_by_scalar<float>(input, scalar, actual, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, actual, 1e-6);
}
