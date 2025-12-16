//
// Created by mayak on 7/16/25.
//

#pragma once

#include <chord/check_args/check_equal_sizes.hpp>
#include <chord/check_args/check_not_zero.hpp>
#include <chord/lib_impl.hpp>

namespace chord {

template<typename T>
StatusResult multiply_with_scalar(std::span<T> src_dst, T val) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src_dst);

    return impl::multiply_with_scalar_inplace(src_dst, val);
}


template<typename T>
StatusResult multiply_with_scalar(std::span<const T> src, T val, std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);

    return impl::multiply_with_scalar(src, val, dst);
}


template<typename T>
StatusResult compute_exponential(std::span<const T> src, std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);

    return impl::compute_exponential(src, dst);
}


template<typename T>
StatusResult
compute_up_sample(std::span<const T> src, std::span<T> dst, int factor, int* phase, int* dst_size) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);

    return impl::compute_up_sample(src, dst, factor, phase, dst_size);
}


template<typename T>
StatusResult
integer_fraction_split(std::span<const T> src, std::span<T> dst_int, std::span<T> dst_frac) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, dst_int, dst_frac);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst_int, dst_frac);

    return impl::integer_fraction_split(src, dst_int, dst_frac);
}


template<typename T>
StatusResult compute_fractional_part(std::span<const T> src, std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);

    return impl::compute_fractional_part(src, dst);
}


template<typename T>
StatusResult divide_by_scalar(std::span<const T> src, T divider, std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);

    return impl::divide_by_scalar(src, divider, dst);
}


template<typename T>
StatusResult divide_by_scalar(std::span<T> src_dst, T divider) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src_dst);

    return impl::divide_by_scalar_inplace(src_dst, divider);
}


template<typename T>
StatusResult divide_list_by_list(std::span<const T> src_divided,
                                 std::span<const T> src_divisors,
                                 std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src_divided, src_divisors);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src_divided, src_divisors);

    return impl::divide_list_by_list(src_divided, src_divisors, dst);
}


template<typename T>
StatusResult divide_list_by_list(std::span<const T> src_divided, std::span<T> src_divisors_dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src_divisors_dst, src_divided);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src_divisors_dst, src_divided);

    return impl::divide_list_by_list_inplace(src_divided, src_divisors_dst);
}


template<typename T>
StatusResult
subtract(std::span<const T> src_minuend, std::span<const T> src_subtrahend, std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src_minuend, src_subtrahend, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src_minuend, src_subtrahend, dst);

    return impl::subtract(src_minuend, src_subtrahend, dst);
}


template<typename T>
StatusResult subtract(std::span<T> src_dst_minuend, std::span<const T> src_subtrahend) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src_dst_minuend, src_subtrahend);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src_dst_minuend, src_subtrahend);

    return impl::subtract_inplace(src_dst_minuend, src_subtrahend);
}


template<typename T>
StatusResult apply_square(std::span<const T> src, std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);

    return impl::apply_square(src, dst);
}


template<typename T>
StatusResult apply_square(std::span<T> src_dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src_dst);

    return impl::apply_square_inplace(src_dst);
}


template<typename T>
StatusResult apply_flip(std::span<const T> src, std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);

    return impl::apply_flip(src, dst);
}


template<typename T>
StatusResult apply_flip(std::span<T> src_dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src_dst);

    return impl::apply_flip_inplace(src_dst);
}


template<typename T>
StatusResult apply_absolute(std::span<const T> src, std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);

    return impl::apply_absolute(src, dst);
}


template<typename T>
StatusResult apply_absolute(std::span<T> src_dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src_dst);

    return impl::apply_absolute_inplace(src_dst);
}


template<typename T>
StatusResult compute_complex_magnitude(std::span<const std::complex<T>> src, std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);

    return impl::compute_complex_magnitude(src, dst);
}


template<typename T>
StatusResult compute_real_imag_magnitude(std::span<const T> src_real,
                                         std::span<const T> src_img,
                                         std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src_img, src_real, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src_real, src_img, dst);

    return impl::compute_real_imag_magnitude(src_real, src_img, dst);
}


template<typename T>
StatusResult fill_slope(std::span<T> dst, T offset, T slope) {
    CHECK_NOT_EMPTY_RETURN_STATUS(dst);

    return impl::fill_slope(dst, offset, slope);
}


template<typename T>
StatusResult combine(std::span<const T> src1, std::span<const T> src2, std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src1, src2, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src1, src2, dst);

    return impl::combine(src1, src2, dst);
}


template<typename T>
StatusResult combine(std::span<const T> src, std::span<T> src_dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, src_dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, src_dst);

    return impl::combine_inplace(src, src_dst);
}


template<typename T>
StatusResult combine_with_scalar(std::span<const T> src, T scalar, std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);

    return impl::combine_with_scalar(src, scalar, dst);
}


template<typename T>
StatusResult combine_with_scalar(std::span<T> src_dst, T scalar) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src_dst);

    return impl::combine_with_scalar_inplace(src_dst, scalar);
}


template<typename T>
StatusResult apply_floor(std::span<const T> src, std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);

    return impl::apply_floor(src, dst);
}


template<typename T>
StatusResult compute_complex_conjugates(std::span<const std::complex<T>> src,
                                        std::span<std::complex<T>> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);

    return impl::compute_complex_conjugates(src, dst);
}


template<typename T>
StatusResult compute_complex_conjugates(std::span<std::complex<T>> src_dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src_dst);

    return impl::compute_complex_conjugates_inplace(src_dst);
}


template<typename T>
StatusResult find_minimum_and_index(std::span<const T> src, T& min, int& index) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src);

    return impl::find_minimum_and_index(src, min, index);
}


template<typename T>
StatusResult find_minimum(std::span<const T> src, T& min) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src);

    return impl::find_minimum(src, min);
}


template<typename T>
StatusResult find_maximum_and_index(std::span<const T> src, T& max, int& index) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src);

    return impl::find_maximum_and_index<T>(src, max, index);
}


template<typename T>
StatusResult find_maximum(std::span<const T> src, T& max) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src);

    return impl::find_maximum(src, max);
}


template<typename T>
StatusResult compute_dot_product(std::span<const T> src1, std::span<const T> src2, T& dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src1, src2);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src1, src2);

    return impl::compute_dot_product(src1, src2, dst);
}


template<typename T>
StatusResult compute_complex_dot_product(std::span<const T> src,
                                         std::span<const std::complex<T>> src_complex,
                                         std::complex<T>& dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, src_complex, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, src_complex, dst);

    return impl::compute_complex_dot_product(src, src_complex, dst);
}


template<typename T>
StatusResult compute_xor(std::span<const T> src1, std::span<const T> src2, std::span<T> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src1, src2, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src1, src2, dst);

    return impl::compute_xor(src1, src2, dst);
}


template<typename T>
StatusResult compute_xor(std::span<T> src1, std::span<const T> src2) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src1, src2);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src1, src2);

    return impl::compute_xor_inplace(src1, src2);
}


template<typename T>
StatusResult compute_mean_value(std::span<const T> src, T& mean, AlgoChoice algo) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src);

    return impl::compute_mean_value(src, mean, algo);
}


template<typename T, typename U>
StatusResult generate_tone(std::span<T> res, U magn, U freq, U& phase, int len, AlgoChoice algo) {
    return impl::generate_tone<T, U>(res, magn, freq, phase, len, algo);
}


template<typename T>
StatusResult generate_FFT_sizes(int order, int flag, WorkBufferSizes& sizes_to_update) {
    return impl::generate_FFT_sizes<T>(order, flag, sizes_to_update);
}


template<typename T>
StatusResult compute_sum(std::span<const T> src, T& sum, AlgoChoice algo) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src);

    return impl::compute_sum(src, sum, algo);
}


template<typename T>
StatusResult apply_raise_power_with_scalar(std::span<const T> bases, T scalar, std::span<T> res) {
    CHECK_NOT_EMPTY_RETURN_STATUS(bases);

    return impl::apply_raise_power_with_scalar(bases, scalar, res);
}


template<typename T>
StatusResult
apply_raise_power(std::span<const T> bases, std::span<const T> expos, std::span<T> res) {
    CHECK_NOT_EMPTY_RETURN_STATUS(bases, expos, res);

    CHECK_EQUAL_SIZE_RETURN_STATUS(bases, expos, res);

    return impl::apply_raise_power(bases, expos, res);
}


template<typename T>
StatusResult generate_DFT_sizes(int len, int flag, WorkBufferSizes& sizes_to_update) {
    return impl::generate_DFT_sizes<T>(len, flag, sizes_to_update);
}


template<typename T>
StatusResult compute_complex_exponent(std::span<const T> src, std::span<std::complex<T>> dst) {
    CHECK_NOT_EMPTY_RETURN_STATUS(src, dst);

    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);

    return impl::compute_complex_exponent(src, dst);
}

}  // namespace chord
