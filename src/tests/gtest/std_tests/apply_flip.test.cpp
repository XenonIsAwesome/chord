//
// Created by mayak on 6/25/25.
//

#include "../../../../src/utils/builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(STD_ApplyFlipInplace, WorksWithInt) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> expected = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::apply_flip_inplace<int>(input);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<int>(expected, input);
}


TEST(STD_ApplyFlip, WorksWithInt) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> output(9);
    std::vector<int> expected = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::apply_flip<int>(input, output);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<int>(expected, output);
}
