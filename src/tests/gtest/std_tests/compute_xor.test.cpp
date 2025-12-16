//
// Created by mayak on 7/2/25.
//

#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(ComputeXor, UnsignedShortType) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<unsigned short> src1 = {0xFFFF, 0x0F0F, 0x1234, 0x0000};
    std::vector<unsigned short> src2 = {0xAAAA, 0XF0F0, 0XFFFF, 0X1234};

    std::vector<unsigned short> result(4);

    std::vector<unsigned short> expected = {0x5555, 0xFFFF, 0xEDCB, 0x1234};
    
    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::compute_xor<unsigned short>(src1, src2, result);
    
    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<unsigned short>(expected, result);
}
