//
// Created by mayak on 8/10/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(IPP_SubstractByList, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    const size_t len = 10;
    std::vector<float> input1 = random_utils::generate_random_vector<float>(len, 3);
    std::vector<float> input2 = random_utils::generate_random_vector<float>(len);

    std::vector<float> actual(len);

    std::vector<float> expected(len);
    math_std::compute_substraction<float>(input1, input2, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::substract_by_list<float>(input1, input2, actual, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, actual);
}


TEST(IPP_SubstractByList, Double) {
    // SET VALUES -------------------------------------------------------------------------------
    const size_t len = 10;
    std::vector<double> input1 = random_utils::generate_random_vector<double>(len, 3);
    std::vector<double> input2 = random_utils::generate_random_vector<double>(len);

    std::vector<double> actual(len);

    std::vector<double> expected(len);
    math_std::compute_substraction<double>(input1, input2, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::substract_by_list<double>(input1, input2, actual, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<double>(expected, actual);
}


TEST(IPP_SubstractByList, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    const size_t len = 10;
    std::vector<std::complex<float>> input1 =
        random_utils::generate_random_vector<std::complex<float>>(len, 3);
    std::vector<std::complex<float>> input2 =
        random_utils::generate_random_vector<std::complex<float>>(len);

    std::vector<std::complex<float>> actual(len);

    std::vector<std::complex<float>> expected(len);
    math_std::compute_substraction<std::complex<float>>(input1, input2, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::substract_by_list<std::complex<float>>(input1, input2, actual, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, actual);
}


TEST(IPP_SubstractByList, ComplexDouble) {
    // SET VALUES -------------------------------------------------------------------------------
    const size_t len = 10;
    std::vector<std::complex<double>> input1 =
        random_utils::generate_random_vector<std::complex<double>>(len, 3);
    std::vector<std::complex<double>> input2 =
        random_utils::generate_random_vector<std::complex<double>>(len);

    std::vector<std::complex<double>> actual(len);

    std::vector<std::complex<double>> expected(len);
    math_std::compute_substraction<std::complex<double>>(input1, input2, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::substract_by_list<std::complex<double>>(input1, input2, actual, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<double>>(expected, actual);
}


TEST(IPP_SubstractByList_Inplace, Float) {
    // SET VALUES -------------------------------------------------------------------------------
    const size_t len = 10;
    std::vector<float> input1_dst_expected = random_utils::generate_random_vector<float>(len, 3);
    std::vector<float> input2 = random_utils::generate_random_vector<float>(len);

    std::vector<float> input1_dst_actual = input1_dst_expected;

    math_std::compute_substraction_inplace<float>(input1_dst_expected, input2);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::substract_by_list_inplace<float>(input1_dst_actual, input2, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(input1_dst_expected, input1_dst_actual);
}


TEST(IPP_SubstractByList_Inplace, Double) {
    // SET VALUES -------------------------------------------------------------------------------
    const size_t len = 10;
    std::vector<double> input1_dst_expected = random_utils::generate_random_vector<double>(len, 3);
    std::vector<double> input2 = random_utils::generate_random_vector<double>(len);

    std::vector<double> input1_dst_actual = input1_dst_expected;

    math_std::compute_substraction_inplace<double>(input1_dst_expected, input2);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::substract_by_list_inplace<double>(input1_dst_actual, input2, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<double>(input1_dst_expected, input1_dst_actual);
}


TEST(IPP_SubstractByList_Inplace, ComplexFloat) {
    // SET VALUES -------------------------------------------------------------------------------
    const size_t len = 10;
    std::vector<std::complex<float>> input1_dst_expected =
        random_utils::generate_random_vector<std::complex<float>>(len, 3);
    std::vector<std::complex<float>> input2 =
        random_utils::generate_random_vector<std::complex<float>>(len);

    std::vector<std::complex<float>> input1_dst_actual = input1_dst_expected;

    math_std::compute_substraction_inplace<std::complex<float>>(input1_dst_expected, input2);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::substract_by_list_inplace<std::complex<float>>(input1_dst_actual, input2, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(input1_dst_expected, input1_dst_actual);
}


TEST(IPP_SubstractByList_Inplace, ComplexDouble) {
    // SET VALUES -------------------------------------------------------------------------------
    const size_t len = 10;
    std::vector<std::complex<double>> input1_dst_expected =
        random_utils::generate_random_vector<std::complex<double>>(len, 3);
    std::vector<std::complex<double>> input2 =
        random_utils::generate_random_vector<std::complex<double>>(len);

    std::vector<std::complex<double>> input1_dst_actual = input1_dst_expected;

    math_std::compute_substraction_inplace<std::complex<double>>(input1_dst_expected, input2);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::substract_by_list_inplace<std::complex<double>>(input1_dst_actual, input2, len);

    // COMPARE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<double>>(input1_dst_expected, input1_dst_actual);
}
