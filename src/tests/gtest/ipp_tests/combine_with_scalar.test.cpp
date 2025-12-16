//
// Created by mayak on 8/7/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <complex>
#include <gtest/gtest.h>


TEST(IPP_CombineWithScalar, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    const auto scalar = random_utils::generate_random_number<std::complex<float>>(-10, 100);
    std::vector<std::complex<float>> input =
        random_utils::generate_random_vector<std::complex<float>>(len);

    std::vector<std::complex<float>> expected_res(len);
    std::vector<std::complex<float>> actual_res(len);

    math_std::combine_with_scalar<std::complex<float>>(input,
                                                       scalar,
                                                       expected_res);  // set expected

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::combine_with_scalar<std::complex<float>>(input, scalar, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected_res, actual_res);
}


TEST(IPP_CombineWithScalar, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    const auto scalar = random_utils::generate_random_number<float>(-10, 100);
    std::vector<float> input = random_utils::generate_random_vector<float>(len);

    std::vector<float> expected_res(len);
    std::vector<float> actual_res(len);

    math_std::combine_with_scalar<float>(input, scalar,
                                         expected_res);  // set expected

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::combine_with_scalar<float>(input, scalar, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected_res, actual_res);
}


TEST(IPP_CombineWithScalar_Inplace, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    const auto scalar = random_utils::generate_random_number<float>(-10, 100);
    const std::vector<float> input =
        random_utils::generate_random_vector<float>(len);

    std::vector<float> expected_res = input;
    std::vector<float> actual_res = input;

    math_std::combine_with_scalar_inplace<float>(expected_res,
                                                               scalar);  // set expected


    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::combine_with_scalar_inplace<float>(actual_res, scalar, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected_res, actual_res);
}


TEST(IPP_CombineWithScalar_Inplace, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    const auto scalar = random_utils::generate_random_number<std::complex<float>>(-10, 100);
    const std::vector<std::complex<float>> input =
        random_utils::generate_random_vector<std::complex<float>>(len);

    std::vector<std::complex<float>> expected_res = input;
    std::vector<std::complex<float>> actual_res = input;

    math_std::combine_with_scalar_inplace<std::complex<float>>(expected_res,
                                                               scalar);  // set expected


    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::combine_with_scalar_inplace<std::complex<float>>(actual_res, scalar, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected_res, actual_res);
}
