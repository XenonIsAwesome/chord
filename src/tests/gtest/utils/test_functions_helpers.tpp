//
// Created by userk on 6/3/25.
//

#pragma once

#include <gtest/gtest.h>


template<NumericComplex T>
void gtest_utils::test::compare_complex(T expected, T actual) {
    ASSERT_EQ(expected.real(), actual.real());
    ASSERT_EQ(expected.imag(), actual.imag());
}


template<NumericComplex T>
void gtest_utils::test::compare_complex_with_threshold(T expected, T actual, float threshold) {
    ASSERT_TRUE(std::abs(expected.real() - actual.real()) < threshold);
    ASSERT_TRUE(std::abs(expected.imag() - actual.imag()) < threshold);
}


template<Numeric T>
void gtest_utils::test::compare_spans(std::span<T> expected, std::span<T> actual, float threshold) {
    ASSERT_EQ(expected.size(), actual.size()) << "Spans not in the same length. dude";

    constexpr size_t accepted_fails_count = 0;

    size_t actual_fails_count = 0;

    for (size_t i = 0; i < expected.size(); ++i) {
        if (std::abs(expected[i] - actual[i]) > threshold) {
            ++actual_fails_count;

            if constexpr (WITH_TEST_FAIL_LOGS) {
                ADD_FAILURE() << "Mismatch at index " << i << ": expected = " << expected[i]
                              << ", actual = " << actual[i];
            }
        }
    }

    ASSERT_EQ(accepted_fails_count, actual_fails_count);
}


template<NumericComplex T>
void gtest_utils::test::compare_spans(std::span<T> expected, std::span<T> actual, float threshold) {
    ASSERT_EQ(expected.size(), actual.size()) << "Spans not in the same length. dude";

    constexpr size_t accepted_fails_count = 0;
    size_t real_fail_count = 0;
    size_t imag_fail_count = 0;

    for (size_t i = 0; i < expected.size(); ++i) {
        if (std::abs(expected[i].real() - actual[i].real()) > threshold) {
            ++real_fail_count;

            if constexpr (WITH_TEST_FAIL_LOGS) {
                ADD_FAILURE() << "Mismatch at index " << i
                              << " for REAL value of complex: expected = " << expected[i].real()
                              << ", actual = " << actual[i].real();
            }
        }

        if (std::abs(expected[i].imag() - actual[i].imag()) > threshold) {
            ++imag_fail_count;

            if constexpr (WITH_TEST_FAIL_LOGS) {
                ADD_FAILURE() << "Mismatch at index " << i
                              << " for IMAGINARY value of complex: \nexpected = "
                              << expected[i].imag() << ", actual = " << actual[i].imag();
            }
        }
    }

    EXPECT_EQ(accepted_fails_count, real_fail_count);
    EXPECT_EQ(accepted_fails_count, imag_fail_count);
}
