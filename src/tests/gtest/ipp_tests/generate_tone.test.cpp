//
// Created by mayak on 8/14/25.
//

#include "builtin_math/math_std.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "random_generate/random_utils.hpp"
#include "utils/test_functions_helpers.hpp"

#include <any>
#include <gtest/gtest.h>


TEST(IPP_GenerateTone, ComplexFloat_Float) {
    // SET VALUES -------------------------------------------------------------------------------
    constexpr size_t len = 10;

    const auto magn = random_utils::generate_random_number<float>(0.1, 10);
    const auto freq = random_utils::generate_random_number<float>(0.0, 1.0);

    std::vector<std::complex<float>> actual(len);
    float actual_phase = 0;

    std::vector<std::complex<float>> expected(len);
    float expected_phase = 0;
    math_std::generate_tone_complex<float>(expected, magn, freq, expected_phase);


    // CALL FUNCTION ----------------------------------------------------------------------------
    ipp::wrappers::generate_tone<std::complex<float>, float>(actual,
                                                             magn,
                                                             freq,
                                                             actual_phase,
                                                             len,
                                                             chord::AlgoChoice::Basic);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, actual, 1e-5);
    ASSERT_EQ(expected_phase, actual_phase);
}
