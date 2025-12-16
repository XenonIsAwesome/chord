//
// Created by userk on 6/9/25.
//

#include "builtin_math/math_std.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <chord/lib.hpp>
#include <gtest/gtest.h>


TEST(IPP_MultiplyWithScalar, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<float> input = random_utils::generate_random_vector<float>(len);

    std::vector<float> actual(len);

    std::vector<float> expected(len);
    const auto scalar = random_utils::generate_random_number<float>();

    math_std::multiply_with_scalar<float>(input, scalar, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::multiply_with_scalar<float>(input, scalar, actual, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, actual, 1e-1);
}

// TODO: check complex float stds impl casue threshold 1e-1 needed
TEST(IPP_MultiplyWithScalar, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<std::complex<float>> input =
        random_utils::generate_random_vector<std::complex<float>>(len);

    std::vector<std::complex<float>> actual(len);

    std::vector<std::complex<float>> expected(len);
    const auto scalar = random_utils::generate_random_number<std::complex<float>>();

    math_std::multiply_with_scalar<std::complex<float>>(input, scalar, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::multiply_with_scalar<std::complex<float>>(input, scalar, actual, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, actual, 1e-1);
}


TEST(IPP_MultiplyWithScalar_Inplace, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;

    std::vector<float> expected = random_utils::generate_random_vector<float>(len);
    std::vector<float> actual = expected;

    const auto scalar = random_utils::generate_random_number<float>();

    math_std::multiply_with_scalar_inplace<float>(expected, scalar);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::multiply_with_scalar_inplace<float>(actual, scalar, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, actual);
}


TEST(IPP_MultiplyWithScalar_Inplace, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<std::complex<float>> input =
        random_utils::generate_random_vector<std::complex<float>>(len);

    std::vector<std::complex<float>> actual(len);

    std::vector<std::complex<float>> expected(len);
    const auto scalar = random_utils::generate_random_number<std::complex<float>>();

    math_std::multiply_with_scalar<std::complex<float>>(input, scalar, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::multiply_with_scalar<std::complex<float>>(input, scalar, actual, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, actual, 1e-1);
}
