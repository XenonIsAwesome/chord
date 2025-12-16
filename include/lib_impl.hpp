//
// Created by mayak on 7/16/25.
//

#pragma once


/**
 * Assumes spans given are of same lengths and allocated("not empty").
 */
namespace chord::impl {


/**
 * For full function docs check function with same name in lib.hpp
 *
 * Assumes spans given are of same lengths and allocated("not empty").
 *
 * @note Implementation differs depending on processor.
 */
template<typename T>
StatusResult multiply_with_scalar(std::span<const T> src, T val, std::span<T> dst);


template<typename T>
StatusResult multiply_with_scalar_inplace(std::span<T> src_dst, T val);


template<typename T>
StatusResult compute_exponential(std::span<const T> src, std::span<T> dst);


template<typename T>
StatusResult
compute_up_sample(std::span<const T> src, std::span<T> dst, int factor, int* phase, int* dst_size);


template<typename T>
StatusResult
integer_fraction_split(std::span<const T> src, std::span<T> dst_int, std::span<T> dst_frac);


template<typename T>
StatusResult compute_fractional_part(std::span<const T> src, std::span<T> dst);


template<typename T>
StatusResult divide_by_scalar(std::span<const T> src, T divider, std::span<T> dst);


template<typename T>
StatusResult divide_by_scalar_inplace(std::span<T> src_dst, T divider);


template<typename T>
StatusResult divide_list_by_list(std::span<const T> src_divided,
                                 std::span<const T> src_divisors,
                                 std::span<T> dst);


template<typename T>
StatusResult divide_list_by_list_inplace(std::span<const T> src_divided,
                                         std::span<T> src_divisors_dst);


template<typename T>
StatusResult subtract_inplace(std::span<T> src_dst_minuend, std::span<const T> src_subtrahend);


template<typename T>
StatusResult
subtract(std::span<const T> src_minuend, std::span<const T> src_subtrahend, std::span<T> dst);


template<typename T>
StatusResult apply_square(std::span<const T> src, std::span<T> dst);


template<typename T>
StatusResult apply_square_inplace(std::span<T> src_dst);


template<typename T>
StatusResult apply_flip(std::span<const T> src, std::span<T> dst);


template<typename T>
StatusResult apply_flip_inplace(std::span<T> src_dst);


template<typename T>
StatusResult apply_absolute(std::span<const T> src, std::span<T> dst);


template<typename T>
StatusResult apply_absolute_inplace(std::span<T> src_dst);


template<typename T>
StatusResult compute_complex_magnitude(std::span<const std::complex<T>> src, std::span<T> dst);


template<typename T>
StatusResult compute_real_imag_magnitude(std::span<const T> src_real,
                                         std::span<const T> src_img,
                                         std::span<T> dst);

template<typename T>
StatusResult fill_slope(std::span<T> dst, T offset, T slope);


template<typename T>
StatusResult combine(std::span<const T> src1, std::span<const T> src2, std::span<T> dst);


template<typename T>
StatusResult combine_inplace(std::span<const T> src, std::span<T> src_dst);


template<typename T>
StatusResult combine_with_scalar(std::span<const T> src, T scalar, std::span<T> dst);


template<typename T>
StatusResult combine_with_scalar_inplace(std::span<T> src_dst, T scalar);


template<typename T>
StatusResult apply_floor(std::span<const T> src, std::span<T> dst);


template<typename T>
StatusResult compute_complex_conjugates(std::span<const std::complex<T>> src,
                                        std::span<std::complex<T>> dst);


template<typename T>
StatusResult compute_complex_conjugates_inplace(std::span<std::complex<T>> src_dst);


template<typename T>
StatusResult find_minimum(std::span<const T> src, T& min);


template<typename T>
StatusResult find_minimum_and_index(std::span<const T> src, T& min, int& index);


template<typename T>
StatusResult find_maximum_and_index(std::span<const T> src, T& max, int& index);


template<typename T>
StatusResult find_maximum(std::span<const T> src, T& max);


template<typename T>
StatusResult
compute_dot_product(std::span<const T> src1, std::span<const T> src2, T& dst);


template<typename T>
StatusResult compute_complex_dot_product(std::span<const T> src,
                                         std::span<const std::complex<T>> src_complex,
                                         std::complex<T>& dst);


template<typename T>
StatusResult compute_xor(std::span<const T> src1, std::span<const T> src2, std::span<T> dst);


template<typename T>
StatusResult compute_xor_inplace(std::span<T> src1, std::span<const T> src2);


template<typename T>
StatusResult
compute_mean_value(std::span<const T> src, T& mean, AlgoChoice algo = AlgoChoice::Basic);


template<typename T, typename U>
StatusResult generate_tone(std::span<T> res,
                           U magn,
                           U freq,
                           U& phase,
                           int len,
                           AlgoChoice algo = AlgoChoice::Basic);


template<typename T>
StatusResult generate_FFT_sizes(int order, int flag, WorkBufferSizes& sizes_to_update);


template<typename T>
StatusResult compute_sum(std::span<const T> src, T& sum, AlgoChoice algo = AlgoChoice::Basic);


template<typename T>
StatusResult apply_raise_power_with_scalar(std::span<const T> bases, T scalar, std::span<T> res);


template<typename T>
StatusResult
apply_raise_power(std::span<const T> bases, std::span<const T> expos, std::span<T> res);


template<typename T>
StatusResult generate_DFT_sizes(int len, int flag, WorkBufferSizes& sizes_to_update);


template<typename T>
StatusResult compute_complex_exponent(std::span<const T> src, std::span<std::complex<T>> dst);

}  // namespace chord::impl


#ifdef INTEL_PRESENT

#    include "../src/impls/ipp/ipp_impl.tpp"
#elif defined(OVERRIDE_USE_STD)
#    include "../src/impls/std/std_impl.tpp"
#endif
