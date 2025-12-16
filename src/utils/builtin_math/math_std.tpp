//
// Created by userk on 5/5/25.
//

#pragma once


#include <algorithm>
#include <chord_types.hpp>
#include <cmath>
#include <complex>
#include <iostream>
#include <numeric>


namespace math_std {

template<typename T>
void multiply_with_scalar_inplace(std::span<T> elems, T val) {
    std::transform(elems.begin(), elems.end(), elems.begin(), [val](T& elem) {
        return elem * val;
    });
}


template<typename T>
void multiply_with_scalar(std::span<const T> src, T val, std::span<T> dst) {
    for (size_t i = 0; i < src.size(); ++i) {
        dst[i] = src[i] * val;
    }
}


template<typename T>
void compute_exponential(std::span<const T> src, std::span<T> dst) {
    for (size_t i = 0; i < src.size(); ++i) {
        dst[i] = std::exp(src[i]);
    }
}


template<typename T>
void compute_up_sample(std::span<T> input, std::span<T> output, int factor, int* pphase) {
    int input_size = input.size();
    int phase = *pphase;

    for (int i = 0; i < input_size; ++i) {
        int output_index = (i * factor + phase) % (input_size * factor);
        output[output_index] = input[i];

        for (int j = 1; j < factor; ++j) {
            int phase_adjusted_index = (i * factor + phase + j) % (input_size * factor);
            output[phase_adjusted_index] = T{};
        }
    }
    *pphase = phase;
}


template<std::floating_point T>
void apply_floor(std::span<const T> src, std::span<T> dst) {
    for (size_t i = 0; i < src.size(); ++i) {
        dst[i] = std::floor(src[i]);
    }
}


template<std::floating_point T>
void integer_fraction_split(std::span<const T> src, std::span<T> dst_int, std::span<T> dst_frac) {
    for (size_t i = 0; i < src.size(); ++i) {
        dst_frac[i] = std::modf(src[i], &dst_int[i]);
    }
}


template<typename T>
void divide_by_scalar(std::span<const T> src, T scalar, std::span<T> dst) {
    if (scalar == T(0)) {
        throw std::logic_error("Division by zero");
    }
    for (size_t i = 0; i < src.size(); ++i) {
        dst[i] = src[i] / scalar;
    }
}


template<typename T>
void divide_by_scalar_inplace(std::span<T> src, T scalar) {
    if (scalar == T(0)) {
        throw std::logic_error("Division by zero");
    }
    std::transform(src.begin(), src.end(), src.begin(), [scalar](auto val) {
        return (val / scalar);
    });
}


template<typename T>
void divide_list_by_list(std::span<T> src_divided, std::span<T> src_divisors, std::span<T> dst) {
    for (size_t i = 0; i < src_divided.size(); ++i) {
        if (src_divisors[i] == T(0)) {
            throw std::logic_error("Division by zero");
        }
        dst[i] = src_divided[i] / src_divisors[i];
    }
}


template<typename T>
void divide_list_by_list_inplace(std::span<const T> src_divided, std::span<T> src_divisors_dst) {
    for (size_t i = 0; i < src_divided.size(); ++i) {
        if (src_divisors_dst[i] == T(0)) {
            throw std::logic_error("Division by zero");
        }
        src_divisors_dst[i] = src_divided[i] / src_divisors_dst[i];
    }
}


template<typename T>
void compute_substraction(std::span<T> src_minuend, std::span<T> src_subtrahend, std::span<T> dst) {
    for (size_t i = 0; i < src_minuend.size(); i++) {
        dst[i] = src_minuend[i] - src_subtrahend[i];
    }
}


template<typename T>
void compute_substraction_inplace(std::span<T> src_minuend, std::span<const T> src_subtrahend) {
    std::transform(src_minuend.begin(),
                   src_minuend.end(),
                   src_subtrahend.begin(),
                   src_minuend.begin(),
                   [](T& elem_minu, const T& elem_sub) { return elem_minu - elem_sub; });
}


template<typename T>
void apply_square(std::span<const T> src, std::span<T> dst) {
    for (size_t i = 0; i < src.size(); i++) {
        dst[i] = std::pow(src[i], 2);
    }
}


template<typename T>
void apply_square_inplace(std::span<T> src) {
    std::transform(src.begin(), src.end(), src.begin(), [](T& elem) { return std::pow(elem, 2); });
}


template<typename T>
void apply_flip(std::span<const T> src, std::span<T> dst) {
    int len = src.size();
    for (int i = 0; i < len; i++) {
        dst[i] = src[len - i - 1];
    }
}


template<typename T>
void apply_flip_inplace(std::span<T> src) {
    int len = src.size();
    for (int i = 0; i < len / 2; i++) {
        std::swap(src[i], src[len - 1 - i]);
    }
}


template<typename T>
void apply_absolute(std::span<const T> src, std::span<T> dst) {
    for (size_t i = 0; i < src.size(); ++i) {
        dst[i] = std::abs(src[i]);
    }
}


template<typename T>
void apply_absolute_inplace(std::span<T> src) {
    std::transform(src.begin(), src.end(), src.begin(), [](T& elem) { return std::abs(elem); });
}


template<typename T>
void combine(std::span<const T> src1, std::span<const T> src2, std::span<T> dst) {
    for (size_t i = 0; i < src1.size(); ++i) {
        dst[i] = src1[i] + src2[i];
    }
}


template<typename T>
void combine_inplace(std::span<T> src_dst, std::span<const T> src2) {
    for (size_t i = 0; i < src_dst.size(); ++i) {
        src_dst[i] += src2[i];
    }
}


template<typename T>
void combine_with_scalar(std::span<const T> src, T scalar, std::span<T> dst) {
    for (size_t i = 0; i < src.size(); ++i) {
        dst[i] = src[i] + scalar;
    }
}


template<typename T>
void combine_with_scalar_inplace(std::span<T> src_dst, T scalar) {
    std::transform(src_dst.begin(), src_dst.end(), src_dst.begin(), [scalar](T val) {
        return val + scalar;
    });
}


template<typename T>
bool is_smaller(T a, T b) {
    if constexpr (is_numeric_complex_v<T>) {
        return (std::abs(a) < std::abs(b));
    }
    if constexpr (std::is_arithmetic_v<T>) {
        return a < b;
    }
    return false;
}


template<typename T>
bool is_bigger(T a, T b) {
    if constexpr (is_numeric_complex_v<T>) {
        return (std::abs(a) > std::abs(b));
    }
    if constexpr (std::is_arithmetic_v<T>) {
        return a > b;
    }
    return false;
}


template<typename T>
void find_minimum(std::span<const T> src, T& min) {
    min = src[0];
    for (size_t i = 1; i < src.size(); ++i) {
        if (is_smaller(src[i], min)) {
            min = src[i];
        }
    }
}


template<typename T>
void find_minimum_and_index(std::span<const T> src, T& min, int& index) {
    min = src[0];
    for (size_t i = 1; i < src.size(); ++i) {
        if (is_smaller(src[i], min)) {
            min = src[i];
            index = i;
        }
    }
    // auto min_it = std::min_element(src.begin(), src.end(), [](const T& a, const T& b) {
    //     return is_smaller(a, b);
    // });
    // index = std::distance(src.begin(), min_it);
    // min = *min_it;
}


template<typename T>
void find_maximum(std::span<const T> src, T& max) {
    max = src[0];
    for (size_t i = 1; i < src.size(); ++i) {
        if (is_bigger(src[i], max)) {
            max = src[i];
        }
    }
}


template<typename T>
void find_maximum_and_index(std::span<const T> src, T& max, int& index) {
    max = src[0];
    for (size_t i = 1; i < src.size(); ++i) {
        if (is_bigger(src[i], max)) {
            max = src[i];
            index = i;
        }
    }
}


template<typename T>
void compute_average(std::span<const T> src, T& mean) {
    T sum = 0;
    for (size_t i = 0; i < src.size(); ++i) {
        sum += src[i];
    }

    mean = sum / (static_cast<float>(src.size()));
}


template<typename T>
void apply_raise_power_with_scalar(std::span<const T> bases, T scalar, std::span<T> res) {
    for (size_t i = 0; i < bases.size(); ++i) {
        res[i] = std::pow(bases[i], scalar);
    }
}


template<typename T>
void apply_raise_power(std::span<T> bases, std::span<T> expos, std::span<T> res) {
    for (size_t i = 0; i < bases.size(); ++i) {
        res[i] = std::pow(bases[i], expos[i]);
    }
}


template<typename T>
void compute_real_imag_magnitude(std::span<const T> src_real,
                                 std::span<const T> src_img,
                                 std::span<T> dst) {
    for (size_t i = 0; i < src_real.size(); ++i) {
        dst[i] = sqrt(pow(src_real[i], 2) + pow(src_img[i], 2));
    }
}


template<typename T>
void compute_complex_magnitude(std::span<const std::complex<T>> src, std::span<T> dst) {
    for (size_t i = 0; i < src.size(); ++i) {
        dst[i] = abs(src[i]);
    }
}


template<typename T>
void compute_complex_conjugates(std::span<std::complex<T>> src, std::span<std::complex<T>> dst) {
    for (size_t i = 0; i < src.size(); ++i) {
        dst[i] = std::conj(src[i]);
    }
}


template<typename T>
void compute_complex_conjugates_inplace(std::span<std::complex<T>> src) {
    std::transform(src.begin(), src.end(), src.begin(), [](std::complex<T> val) {
        return std::conj(val);
    });
}


template<typename T, typename U>
void generate_tone(std::span<T> res, U magn, U freq, U& phase) {
    if constexpr (is_numeric_complex_v<T>) {
        std::cout << "STD: {generate_tone} for type complex not implemented" << std::endl;
        return;
    }
    for (size_t i = 0; i < res.size(); ++i) {
        res[i] = magn * std::cos(2 * M_PI * i * freq + phase);
        // TODO: check if supposed to be sin cause in ipp docs says cos
    }

    phase += 2.0f * M_PI * freq * res.size();
    phase = std::fmod(phase, 2.0f * M_PI);
}


template<typename T, typename U>
void generate_tone_complex(std::span<std::complex<T>> res, U magn, U freq, U& phase) {
    for (size_t i = 0; i < res.size(); ++i) {
        float angle = 2.0f * M_PI * freq * i + phase;
        res[i] = std::polar(magn, angle);
    }

    phase += 2.0f * M_PI * freq * res.size();
    phase = std::fmod(phase, 2.0f * M_PI);
}


template<typename T>
void compute_complex_exponent(std::span<const T> src, std::span<std::complex<T>> dst) {
    for (size_t i = 0; i < src.size(); ++i) {
        float angle = src[i];
        dst[i] = std::complex<T>(std::cos(angle), std::sin(angle));
    }
}


template<typename T>
void compute_fractional_part(std::span<const T> src, std::span<T> dst) {
    for (size_t i = 0; i < src.size(); i++) {
        dst[i] = src[i] - trunc(src[i]);
    }
}


template<typename T>
void fill_slope(std::span<T> dst, T offset, T slope) {
    for (size_t i = 0; i < dst.size(); ++i) {
        dst[i] = slope * i + offset;
    }
}


template<typename T>
void compute_xor(std::span<T> src1, std::span<T> src2, std::span<T> dst) {
    for (size_t i = 0; i < src1.size(); ++i) {
        dst[i] = src1[i] ^ src2[i];
    }
}


template<typename T>
void compute_xor_inplace(std::span<T> src1, std::span<T> src2) {
    for (size_t i = 0; i < src1.size(); ++i) {
        src1[i] = src1[i] ^ src2[i];
    }
}


template<typename T>
void compute_complex_dot_product(std::span<T> src,
                                 std::span<std::complex<T>> src_complex,
                                 std::complex<T>& dst) {
    for (size_t i = 0; i < src.size(); ++i) {
        dst += src[i] * src_complex[i];
    }
}


template<typename T>
void compute_dot_product(std::span<const T> src1, std::span<const T> src2, T& dst) {
    for (size_t i = 0; i < src1.size(); ++i) {
        dst += src1[i] * src2[i];
    }
}


template<typename T>
void compute_sum(std::span<const T> src, T& sum) {
    for (size_t i = 0; i < src.size(); ++i) {
        sum += src[i];
    }
}


template<typename T>
void compute_mean_value(std::span<const T> src, T& mean) {
    for (size_t i = 0; i < src.size(); ++i) {
        mean += src[i];
    }

    mean /= src.size();
}


// template<typename T>
// void math_std::generate_FFT_sizes(const int order,
//                                   FFTFlag flag,
//                                   chord::WorkBufferSizes& sizes_to_update) {
//     const int n = 1 << order;
//     int float_size = sizeof(T)
//     int twiddle_table_size = (n / 2) * sizeof(float) * 2;
//     int bit_rev_table_size = n * sizeof(int);
//     constexpr int flags_size = 64;
//
//     if (flag == FFTFlag::FFT_FLAG_FAST_HINT) {
//         twiddle_table_size /= 2;
//         bit_rev_table_size /= 2;
//     } else if (flag == FFTFlag::FFT_FLAG_HIGH_PRECISION) {
//         twiddle_table_size += 256;
//         bit_rev_table_size += 256;
//     }
//
//     sizes_to_update.size_spec = twiddle_table_size + bit_rev_table_size + flags_size;
//     sizes_to_update.size_init = sizes_to_update.size_spec / 2;
//     sizes_to_update.size_buffer = n * sizeof(float) * 2;
// }


}  // namespace math_std
