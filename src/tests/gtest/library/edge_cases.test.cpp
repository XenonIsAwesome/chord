//
// Created by mayak on 8/17/25.
//

#include <gtest/gtest.h>
#include <lib.hpp>

/**
 * Checking that when two srcs of different lengths are given to function from library the function
 * returns Status InvalidParamter.
 */
TEST(LIB_Test, NotEqualSpans) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<float> input1(3);
    std::vector<float> input2(4);

    // CALL FUNCTION ----------------------------------------------------------------------------
    const auto res = chord::combine<float>(input1, input2);
    std::cout << res;

    // COMAPRE RESULTS --------------------------------------------------------------------------
    ASSERT_TRUE(res.get_status() == chord::Status::InvalidParamter);
}


/**
 * Checking that for division by zero function returns Status InvalidParamter.
 */
TEST(LIB_Test, DivisionByZero) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<float> input1 = {1.2, 2.3, 3.4};
    constexpr float scalar = 0.0;

    // CALL FUNCTION ----------------------------------------------------------------------------
    const auto res = chord::divide_by_scalar<float>(input1, scalar);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    ASSERT_TRUE(res.get_status() == chord::Status::InvalidParamter);
}


// TODO: add range tests for values recieved in std to actually return InvalidParameter.
// When fixed can uncomment.
TEST(LIB_Test, WrongToneParam) {
    // SET VALUES -------------------------------------------------------------------------------
    // constexpr size_t len = 5;
    // std::vector<std::complex<float>> tone(len);
    // float magn = 1;
    // float freq = 1;
    // float phase = 0;
    //
    // // CALL FUNCTION ----------------------------------------------------------------------------
    // const auto res = chord::generate_tone<std::complex<float>, float>(tone,
    //                                                                   magn,
    //                                                                   freq,
    //                                                                   phase,
    //                                                                   len,
    //                                                                   chord::AlgoChoice::Basic);
    //
    // // COMAPRE RESULTS --------------------------------------------------------------------------
    // ASSERT_TRUE(res.get_status() == chord::Status::InvalidParamter);
}
