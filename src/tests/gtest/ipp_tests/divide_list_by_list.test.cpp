//
// Created by mayak on 8/6/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(IPP_DivideListByList, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<std::complex<float>> input1 =
        random_utils::generate_random_vector<std::complex<float>>(len);
    std::vector<std::complex<float>> input2 =
        random_utils::generate_random_vector<std::complex<float>>(len);

    std::vector<std::complex<float>> actual(len);

    std::vector<std::complex<float>> expected(len);
    math_std::divide_list_by_list<std::complex<float>>(input1, input2, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::divide_list_by_list<std::complex<float>>(input1, input2, actual, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, actual, 1e-6);
}


TEST(DISABLED_IPP_DivideListByList_Inplace, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;
    std::vector<std::complex<float>> input1 =
        random_utils::generate_random_vector<std::complex<float>>(len);
    std::vector<std::complex<float>> input2 =
        random_utils::generate_random_vector<std::complex<float>>(len);

    std::vector<std::complex<float>> actual = input1;

    std::vector<std::complex<float>> expected = input1;
    math_std::divide_list_by_list_inplace<std::complex<float>>(expected, input2);

    // CALL FUNCTION ----------------------------------------------------------------------------
    // TODO: UPDATE TO REPLACE SRC AND DST LOCATIONS
    ipp::wrappers::divide_list_by_list_inplace<std::complex<float>>(input2, actual, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, actual, 1e-6);
}


// INSTANTIATE_TEST_SUITE_P(DivideListByList,
//                          ComplexFloatTestWrapperTwoSrcOneDst,
//                          ::testing::Values(ComplexFloatParam{
//                              math_std::divide_list_by_list<std::complex<float>>,
//                              ipp::wrappers::divide_list_by_list<std::complex<float>>}));
