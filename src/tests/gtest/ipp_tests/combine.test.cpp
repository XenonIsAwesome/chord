//
// Created by mayak on 8/5/25.
//


#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "builtin_math/math_std.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(IPP_CombineListWithList, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<float> input1 = random_utils::generate_random_vector<float>(len, 0, 5);
    std::vector<float> input2 = random_utils::generate_random_vector<float>(len, 0, 5);
    std::vector<float> expected_res(len);
    std::vector<float> actual_res(len);

    math_std::combine<float>(input1, input2, expected_res);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::combine<float>(input1, input2, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected_res, actual_res);
}


TEST(IPP_CombineListWithList, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<std::complex<float>> input1 =
        random_utils::generate_random_vector<std::complex<float>>(len, 0, 5);
    std::vector<std::complex<float>> input2 =
        random_utils::generate_random_vector<std::complex<float>>(len, 0, 5);
    std::vector<std::complex<float>> expected_res(len);
    std::vector<std::complex<float>> actual_res(len);

    math_std::combine<std::complex<float>>(input1, input2, expected_res);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::combine<std::complex<float>>(input1, input2, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected_res, actual_res);
}


TEST(IPP_CombineListWithList_Inplace, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<float> input1 = random_utils::generate_random_vector<float>(len);
    std::vector<float> input2 = random_utils::generate_random_vector<float>(len);
    std::vector<float> expected_res = input1;
    std::vector<float> actual_res = input1;

    math_std::combine_inplace<float>(expected_res, input2);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::combine_inplace<float>(input2, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected_res, actual_res);
}


TEST(IPP_CombineListWithList_Inplace, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 5;

    std::vector<std::complex<float>> input1 =
        random_utils::generate_random_vector<std::complex<float>>(len);
    std::vector<std::complex<float>> input2 =
        random_utils::generate_random_vector<std::complex<float>>(len);
    std::vector<std::complex<float>> expected_res = input1;
    std::vector<std::complex<float>> actual_res = input1;

    math_std::combine_inplace<std::complex<float>>(expected_res, input2);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::combine_inplace<std::complex<float>>(input2, actual_res, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected_res, actual_res);
}


// INSTANTIATE_TEST_SUITE_P(Combine,
//                          TwoSrcAndScalarTestComplexFloat,
//                          ::testing::Values(
//                                            FloatParam{math_std::multiply_with_scalar<float>,
//                                                       ipp::wrappers::multiply_with_scalar<float>}));

// INSTANTIATE_TEST_SUITE_P(Combine,
//                          TwoSrcAndScalarTestComplexFloat,
//                          ::testing::Values(FloatParam{math_std::combine_with_scalar<float>,
//                                                        ipp::wrappers::combine_with_scalar<float>},
//                                            FloatParam{math_std::multiply_with_scalar<float>,
//                                                        ipp::wrappers::multiply_with_scalar<float>}));
//
//
// INSTANTIATE_TEST_SUITE_P(Combine,
//                          ComplexFloatTestWrapperTwoSpansAndScalar,
//                          ::testing::Values(ComplexFloatParam{math_std::combine_with_scalar<std::complex<float>>,
//                                                        ipp::wrappers::combine_with_scalar<std::complex<float>>},
//                                            ComplexFloatParam{math_std::multiply_with_scalar<std::complex<float>>,
//                                                        ipp::wrappers::multiply_with_scalar<std::complex<float>>}));


// INSTANTIATE_TEST_SUITE_P(Combine,
//                          TwoSrcAndScalarTestComplexFloat,
//                          ::testing::Values(FloatParam{math_std::combine_with_scalar<float>,
//                                                        ipp::wrappers::combine_with_scalar<float>}));


// INSTANTIATE_TEST_SUITE_P(Combine,
//                          TwoSrcAndScalarTestComplexFloat,
//                          ::testing::Values(FloatParam{math_std::multiply_with_scalar<float>,
//                                                        ipp::wrappers::multiply_with_scalar<float>}));


//
//
// INSTANTIATE_TEST_SUITE_P(Combine,
//                          ComplexFloatTestWrapperTwoSpansAndScalar,
//                          ::testing::Values(ComplexFloatParam{math_std::combine_with_scalar<std::complex<float>>,
//                                                        ipp::wrappers::combine_with_scalar<std::complex<float>>},
//                                            ComplexFloatParam{math_std::multiply_with_scalar<std::complex<float>>,
//                                                        ipp::wrappers::multiply_with_scalar<std::complex<float>>}));
