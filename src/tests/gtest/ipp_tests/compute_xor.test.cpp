//
// Created by mayak on 8/10/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(IPP_ComputeXor, UnsignedShortType) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr int len = 4;
    std::vector<uint16_t> src1 = {0xFFFF, 0x0F0F, 0x1234, 0x0000};
    std::vector<uint16_t> src2 = {0xAAAA, 0XF0F0, 0XFFFF, 0X1234};

    std::vector<uint16_t> actual(len);

    std::vector<uint16_t> expected(len);
    math_std::compute_xor<uint16_t>(src1, src2, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_xor<uint16_t>(src1, src2, actual, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<uint16_t>(expected, actual);
}


TEST(IPP_ComputeXor_Inplace, UnsignedShortType) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr int len = 4;
    std::vector<uint16_t> src1 = {0xFFFF, 0x0F0F, 0x1234, 0x0000};
    std::vector<uint16_t> src2 = {0xAAAA, 0XF0F0, 0XFFFF, 0X1234};

    std::vector<uint16_t> actual = src1;
    std::vector<uint16_t> expected = src1;

    math_std::compute_xor_inplace<uint16_t>(src1, expected);

    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::compute_xor_inplace<uint16_t>(src1, actual, len);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<uint16_t>(expected, actual);
}
