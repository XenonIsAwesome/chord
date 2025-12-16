//
// Created by userk on 5/4/25.
//

#pragma once

#include <complex>

#define IS_SAME(T1, T2)           std::same_as<T1, T2>

/// Concepts
template<typename T>
concept IsFloat = IS_SAME(T, float);

template<typename T>
concept IsDouble = IS_SAME(T, double);

template<typename T>
concept IsComplexFloat = IS_SAME(T, std::complex<float>);

template<typename T>
concept FloatOrComplexFloat = IsFloat<T> || IsComplexFloat<T>;

template<typename T>
concept FloatOrDoubleOrComplexFloat = IsFloat<T> || IsDouble<T> || IsComplexFloat<T>;

template<typename T>
struct is_numeric_complex : std::false_type {};

template<typename T>
struct is_numeric_complex<std::complex<T>> : std::bool_constant<std::is_arithmetic_v<T>> {};

template<typename T>
constexpr bool is_numeric_complex_v = is_numeric_complex<T>::value;

template<typename T>
concept NumericComplex = is_numeric_complex<std::remove_const_t<T>>::value;

template<typename T>
concept Numeric = std::is_arithmetic_v<T>;
