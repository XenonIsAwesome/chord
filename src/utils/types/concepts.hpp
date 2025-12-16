//
// Created by mayak on 8/5/25.
//

#pragma once
#include "template_specialization.hpp"

#include <complex>

template<typename T>
concept RealDecimal = std::is_floating_point_v<T>;

template<typename T>
concept RealIntegral = std::is_integral_v<T> and not
        (std::is_same_v<T, bool> or std::is_same_v<T, const bool>);

template<typename T>
concept RealArithmetic = std::is_arithmetic_v<T> and not
        (std::is_same_v<T, bool> or std::is_same_v<T, const bool>);

template<typename T>
concept ComplexDecimal = std::is_same_v<T, std::complex<float>> or std::is_same_v<T, std::complex<double>>;

template <typename T>
concept ComplexArithmetic = is_specialization<T, std::complex>::value and not
        (std::is_same_v<T, std::complex<bool>> or std::is_same_v<T, std::complex<const bool>>);

template <typename T>
concept AnyDecimal = RealDecimal<T> or ComplexDecimal<T>;

template <typename T>
concept AnyArithmetic = RealArithmetic<T> or ComplexArithmetic<T>;