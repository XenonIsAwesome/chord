//
// Created by userk on 6/3/25.
//

#pragma once

#include "chord_types.hpp"

#include <span>


namespace gtest_utils::test {

template<Numeric T>
void compare_spans(std::span<T> expected, std::span<T> actual, float threshold = 0);

template<NumericComplex T>
void compare_spans(std::span<T> expected, std::span<T> actual, float threshold = 0);

template<NumericComplex T>
void compare_complex(T expected, T actual);

template<NumericComplex T>
void compare_complex_with_threshold(T expected, T actual, float threshold = 0);


}  // namespace gtest_utils::test


#include "test_functions_helpers.tpp"
