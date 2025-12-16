#ifndef CHORD_SRC_IMPL_IPP_IMPL_TPP
#define CHORD_SRC_IMPL_IPP_IMPL_TPP

#include "ipp_wrappers/ipp_wrappers.hpp"
#include "types/casts/cast.hpp"

#include <chord/chord_status.hpp>
#include <functional>
#include <iostream>

#ifdef INTEL_PRESENT
#    if __has_include(<ipp/ippversion.h>)
#        include <ipp/ipp.h>
#    elif __has_include(<ippversion.h>)
#        include <ipp.h>
#    else
#        error "IPP Version not supported"
#    endif
#endif

#include <lib.hpp>
#include <mutex>

#define IPP_CALL(func_call)       \
    IppStatus status = func_call; \
    return (chord::StatusResult(status, __func__, __FILE__, __LINE__));


/// flag for init once logic in AUTO_INIT(isn't used elsewhere)
static std::once_flag chord_once_flag;

/**
 * @brief Wraps the safe_cast::cast() function.
 *
 * This function can throw std::out_of_range if casting fails, so macro calls the function and
 * catches error if is thrown and returns a StatusResult that casting failed.
 *
 * @param func_call receives safe_cast::cast({params}) function call with the params.
 */
#define SAFE_CAST_CALL(func_call)                                                                 \
    try {                                                                                         \
        func_call;                                                                                \
    } catch (std::out_of_range & err) {                                                           \
        return chord::StatusResult(Status::OutOfRange, err.what(), __func__, __FILE__, __LINE__); \
    }


/**
 * Functions in namespace call IPP wrappers.
 *
 * Before functions are called a safe cast happens.
 * The safe cast takes place because size is retrieved from the span object using the .size(), the
 * return type is size_t, but the IPP functions recieve the size as int.
 */
namespace chord::impl {

inline void init() {
    // init implementation calling init
    ippInit();
}


template<typename T>
StatusResult multiply_with_scalar(std::span<const T> src, T val, std::span<T> dst) {
    AUTO_INIT();

    int src_size;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_size));

    IPP_CALL(ipp::wrappers::multiply_with_scalar(src, val, dst, src_size));
}


template<typename T>
StatusResult multiply_with_scalar_inplace(std::span<T> src_dst, T val) {
    AUTO_INIT();

    int src_dst_size;
    SAFE_CAST_CALL(safe_cast::cast(src_dst.size(), src_dst_size));

    IPP_CALL(ipp::wrappers::multiply_with_scalar_inplace(src_dst, val, src_dst_size));
}


template<typename T>
StatusResult compute_exponential(std::span<const T> src, std::span<T> dst) {
    AUTO_INIT();

    int src_size, dst_size;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_size));
    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_size));

    IPP_CALL(ipp::wrappers::compute_exponential(src, dst, src_size));
}


template<typename T>
StatusResult
compute_up_sample(std::span<const T> src, std::span<T> dst, int factor, int* phase, int* dst_size) {
    AUTO_INIT();

    int src_size;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_size));

    IPP_CALL(ipp::wrappers::compute_up_sample(src, src_size, factor, phase, dst, dst_size));
}


template<typename T>
StatusResult
integer_fraction_split(std::span<const T> src, std::span<T> dst_int, std::span<T> dst_frac) {
    AUTO_INIT();

    int src_size;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_size));

    IPP_CALL(ipp::wrappers::integer_fraction_split(src, dst_int, dst_frac, src_size));
}


template<typename T>
StatusResult compute_fractional_part(std::span<const T> src, std::span<T> dst) {
    AUTO_INIT();

    int src_len, dst_len;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_len));

    IPP_CALL(ipp::wrappers::compute_fractional_part(src, dst, src_len));
}


template<typename T>
StatusResult divide_by_scalar(std::span<const T> src, T divider, std::span<T> dst) {
    AUTO_INIT();

    int src_len, dst_len;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_len));

    IPP_CALL(ipp::wrappers::divide_by_scalar(src, divider, dst, src_len));
}


template<typename T>
StatusResult divide_by_scalar_inplace(std::span<T> src_dst, T divider) {
    AUTO_INIT();

    int src_dst_len;
    SAFE_CAST_CALL(safe_cast::cast(src_dst.size(), src_dst_len));

    IPP_CALL(ipp::wrappers::divide_by_scalar_inplace(src_dst, divider, src_dst_len));
}


template<typename T>
StatusResult subtract_inplace(std::span<T> src_dst_minuend, std::span<const T> src_subtrahend) {
    AUTO_INIT();

    int src_dst_minuend_size, src_subtrahend_size;
    SAFE_CAST_CALL(safe_cast::cast(src_dst_minuend.size(), src_dst_minuend_size));
    SAFE_CAST_CALL(safe_cast::cast(src_subtrahend.size(), src_subtrahend_size));

    IPP_CALL(ipp::wrappers::substract_by_list_inplace(src_dst_minuend,
                                                      src_subtrahend,
                                                      src_dst_minuend_size));
}


template<typename T>
StatusResult
subtract(std::span<const T> src_minuend, std::span<const T> src_subtrahend, std::span<T> dst) {
    AUTO_INIT();

    int src_minuend_size, src_subtrahend_size, dst_size;
    SAFE_CAST_CALL(safe_cast::cast(src_minuend.size(), src_minuend_size));
    SAFE_CAST_CALL(safe_cast::cast(src_subtrahend.size(), src_subtrahend_size));
    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_size));

    IPP_CALL(ipp::wrappers::substract_by_list(src_minuend, src_subtrahend, dst, src_minuend_size));
}


template<typename T>
StatusResult apply_square(std::span<const T> src, std::span<T> dst) {
    AUTO_INIT();

    int src_size, dst_size;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_size));
    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_size));

    IPP_CALL(ipp::wrappers::apply_square(src, dst, src_size));
}


template<typename T>
StatusResult apply_square_inplace(std::span<T> src_dst) {
    AUTO_INIT();

    int src_dst_size;
    SAFE_CAST_CALL(safe_cast::cast(src_dst.size(), src_dst_size));

    IPP_CALL(ipp::wrappers::apply_square_inplace(src_dst, src_dst_size));
}


template<typename T>
StatusResult apply_flip(std::span<const T> src, std::span<T> dst) {
    AUTO_INIT();

    int src_size, dst_size;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_size));
    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_size));

    IPP_CALL(ipp::wrappers::apply_flip(src, dst, src_size));
}


template<typename T>
StatusResult apply_flip_inplace(std::span<T> src_dst) {
    AUTO_INIT();

    int src_dst_size;
    SAFE_CAST_CALL(safe_cast::cast(src_dst.size(), src_dst_size));

    IPP_CALL(ipp::wrappers::apply_flip_inplace(src_dst, src_dst_size));
}


template<typename T>
StatusResult apply_absolute(std::span<const T> src, std::span<T> dst) {
    AUTO_INIT();

    int src_size, dst_size;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_size));
    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_size));

    IPP_CALL(ipp::wrappers::apply_absolute(src, dst, src_size));
}


template<typename T>
StatusResult apply_absolute_inplace(std::span<T> src_dst) {
    AUTO_INIT();

    int src_dst_size;
    SAFE_CAST_CALL(safe_cast::cast(src_dst.size(), src_dst_size));

    IPP_CALL(ipp::wrappers::apply_absolute_inplace(src_dst, src_dst_size));
}


template<typename T>
StatusResult compute_complex_magnitude(std::span<const std::complex<T>> src, std::span<T> dst) {
    AUTO_INIT();

    int src_len;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));

    IPP_CALL(ipp::wrappers::compute_complex_magnitude(src, dst, src_len));
}


template<typename T>
StatusResult divide_list_by_list(std::span<const T> src_divided,
                                 std::span<const T> src_divisors,
                                 std::span<T> dst) {
    AUTO_INIT();

    int src_divided_len, src_divisors_len;
    SAFE_CAST_CALL(safe_cast::cast(src_divided.size(), src_divided_len));
    SAFE_CAST_CALL(safe_cast::cast(src_divisors.size(), src_divisors_len));

    IPP_CALL(ipp::wrappers::divide_list_by_list(src_divided, src_divisors, dst, src_divided_len));
}


template<typename T>
StatusResult divide_list_by_list_inplace(std::span<const T> src_divided,
                                         std::span<T> src_divisors_dst) {
    AUTO_INIT();

    int src_divided_len, src_divisors_len;
    SAFE_CAST_CALL(safe_cast::cast(src_divided.size(), src_divided_len));
    SAFE_CAST_CALL(safe_cast::cast(src_divisors_dst.size(), src_divisors_len));

    IPP_CALL(
        ipp::wrappers::divide_list_by_list_inplace(src_divided, src_divisors_dst, src_divided_len));
}


template<typename T>
StatusResult compute_real_imag_magnitude(std::span<const T> src_real,
                                         std::span<const T> src_img,
                                         std::span<T> dst) {
    AUTO_INIT();

    int src_real_len, src_img_len;
    SAFE_CAST_CALL(safe_cast::cast(src_real.size(), src_real_len));
    SAFE_CAST_CALL(safe_cast::cast(src_img.size(), src_img_len));


    IPP_CALL(ipp::wrappers::compute_real_imag_magnitude(src_real, src_img, dst, src_real_len));
}


template<typename T>
StatusResult fill_slope(std::span<T> dst, T offset, T slope) {
    AUTO_INIT();

    int dst_len;
    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_len));

    IPP_CALL(ipp::wrappers::fill_slope(dst, offset, slope, dst_len));
}


template<typename T>
StatusResult combine(std::span<const T> src1, std::span<const T> src2, std::span<T> dst) {
    AUTO_INIT();

    int src1_len, src2_len, dst_len;
    SAFE_CAST_CALL(safe_cast::cast(src1.size(), src1_len));
    SAFE_CAST_CALL(safe_cast::cast(src2.size(), src2_len));
    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_len));

    IPP_CALL(ipp::wrappers::combine(src1, src2, dst, src1_len));
}


template<typename T>
StatusResult combine_inplace(std::span<const T> src1, std::span<T> src2) {
    AUTO_INIT();

    int src1_len, src2_len;
    SAFE_CAST_CALL(safe_cast::cast(src1.size(), src1_len));
    SAFE_CAST_CALL(safe_cast::cast(src2.size(), src2_len));
    // ipp::wrappers::combine_inplace()

    IPP_CALL(ipp::wrappers::combine_inplace(src1, src2, src1_len));
}


template<typename T>
StatusResult combine_with_scalar(std::span<const T> src, T scalar, std::span<T> dst) {
    AUTO_INIT();

    int src_size, dst_size;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_size));
    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_size));

    IPP_CALL(ipp::wrappers::combine_with_scalar(src, scalar, dst, src_size));
}


template<typename T>
StatusResult combine_with_scalar_inplace(std::span<T> src_dst, T scalar) {
    AUTO_INIT();

    int src_dst_size;
    SAFE_CAST_CALL(safe_cast::cast(src_dst.size(), src_dst_size));

    IPP_CALL(ipp::wrappers::combine_with_scalar_inplace(src_dst, scalar, src_dst_size));
}


template<typename T>
StatusResult apply_floor(std::span<const T> src, std::span<T> dst) {
    AUTO_INIT();

    int src_size, dst_size;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_size));
    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_size));

    // ipp::wrappers::apply_floor(src, dst, src_size);

    IPP_CALL(ipp::wrappers::apply_floor(src, dst, src_size));
}


template<typename T>
StatusResult compute_complex_conjugates(std::span<const std::complex<T>> src,
                                        std::span<std::complex<T>> dst) {
    AUTO_INIT();

    int src_size, dst_size;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_size));
    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_size));

    IPP_CALL(ipp::wrappers::compute_complex_conjugates(src, dst, src_size));
}


template<typename T>
StatusResult compute_complex_conjugates_inplace(std::span<std::complex<T>> src_dst) {
    AUTO_INIT();

    int src_dst_len;
    SAFE_CAST_CALL(safe_cast::cast(src_dst.size(), src_dst_len));

    IPP_CALL(ipp::wrappers::compute_complex_conjugates_inplace(src_dst, src_dst_len));
}


template<typename T>
StatusResult find_minimum_and_index(std::span<const T> src, T& min, int& index) {
    AUTO_INIT();

    int src_size;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_size));

    IPP_CALL(ipp::wrappers::find_minimum_index(src, min, index, src_size));
}


template<typename T>
StatusResult find_minimum(std::span<const T> src, T& min) {
    int src_size;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_size));

    IPP_CALL(ipp::wrappers::find_minimum(src, min, src_size));
}


template<typename T>
StatusResult find_maximum_and_index(std::span<const T> src, T& max, int& index) {
    AUTO_INIT();

    int src_size;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_size));

    IPP_CALL(ipp::wrappers::find_maximum_index<T>(src, max, index, src_size));
}


template<typename T>
StatusResult find_maximum(std::span<const T> src, T& max) {
    AUTO_INIT();

    int src_size;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_size));

    IPP_CALL(ipp::wrappers::find_minimum(src, max, src_size));
}


template<typename T>
StatusResult compute_dot_product(std::span<const T> src1, std::span<const T> src2, T& dst) {
    AUTO_INIT();

    int src1_len, src2_len;
    SAFE_CAST_CALL(safe_cast::cast(src1.size(), src1_len));
    SAFE_CAST_CALL(safe_cast::cast(src2.size(), src2_len));

    IPP_CALL(ipp::wrappers::compute_dot_product(src1, src2, dst));
}


template<typename T>
StatusResult compute_xor(std::span<const T> src1, std::span<const T> src2, std::span<T> dst) {
    AUTO_INIT();

    int src1_len, src2_len;
    SAFE_CAST_CALL(safe_cast::cast(src1.size(), src1_len));
    SAFE_CAST_CALL(safe_cast::cast(src2.size(), src2_len));

    IPP_CALL(ipp::wrappers::compute_xor(src1, src2, dst, src1_len));
}


template<typename T>
StatusResult compute_xor_inplace(std::span<T> src1, std::span<const T> src2) {
    AUTO_INIT();

    int src1_len, src2_len;
    SAFE_CAST_CALL(safe_cast::cast(src1.size(), src1_len));
    SAFE_CAST_CALL(safe_cast::cast(src2.size(), src2_len));

    IPP_CALL(ipp::wrappers::compute_xor_inplace(src1, src2));
}


template<typename T>
StatusResult compute_mean_value(std::span<const T> src, T& mean, AlgoChoice algo) {
    AUTO_INIT();

    int src_len;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));

    IPP_CALL(ipp::wrappers::compute_mean_value(src, mean, algo, src_len));
}


template<typename T, typename U>
StatusResult generate_tone(std::span<T> res, U magn, U freq, U& phase, int len, AlgoChoice algo) {
    AUTO_INIT();

    int res_len;
    SAFE_CAST_CALL(safe_cast::cast(res.size(), res_len));

    if (res_len < len) {
        return StatusResult(
            Status::OutOfRange,
            "Number of elements for operation bigger than allocated size avaliable.",
            __func__,
            __FILE__,
            __LINE__);
    }

    IPP_CALL(ipp::wrappers::generate_tone(res, magn, freq, phase, len, algo))
}


template<typename T>
StatusResult generate_FFT_sizes(int order, int flag, WorkBufferSizes& sizes_to_update);


template<typename T>
StatusResult compute_sum(std::span<const T> src, T& sum, AlgoChoice algo) {
    AUTO_INIT();

    int src_len;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));

    IPP_CALL(ipp::wrappers::compute_sum(src, sum, algo, src_len));
}


template<typename T>
StatusResult apply_raise_power_with_scalar(std::span<const T> bases, T scalar, std::span<T> res) {
    AUTO_INIT();

    int bases_len;
    SAFE_CAST_CALL(safe_cast::cast(bases.size(), bases_len));

    IPP_CALL(ipp::wrappers::apply_raise_power_with_scalar(bases, scalar, res, bases_len));
}


template<typename T>
StatusResult
apply_raise_power(std::span<const T> bases, std::span<const T> expos, std::span<T> res) {
    AUTO_INIT();

    int bases_len, expos_len;
    SAFE_CAST_CALL(safe_cast::cast(bases.size(), bases_len));
    SAFE_CAST_CALL(safe_cast::cast(expos.size(), expos_len));

    IPP_CALL(ipp::wrappers::apply_raise_power(bases, expos, res));
}


template<typename T>
StatusResult generate_DFT_sizes(int len, int flag, WorkBufferSizes& sizes_to_update);


template<typename T>
StatusResult compute_complex_exponent(std::span<const T> src, std::span<std::complex<T>> dst) {
    AUTO_INIT();

    int src_len;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));

    IPP_CALL(ipp::wrappers::compute_complex_exponent(src, dst, src_len));
}

// template<typename T>
// StatusResult divide_by_scalar(std::span<T> src, T divider, std::optional<std::span<T>> dst) {
//     AUTO_INIT();
//
//     CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src);
//
//     int src_len;
//     SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
//
//     if (dst.has_value()) {
//         CHECK_SIZE_NOT_ZERO_RETURN_STATUS(dst.value());
//
//         int dst_len;
//         SAFE_CAST_CALL(safe_cast::cast(dst.value().size(), dst_len));
//
//         SIZES_EQUAL_CHECK(src_len, dst_len);
//
//         IPP_CALL(ipp::wrappers::divide_by_scalar(src, divider, dst.value(), src_len));
//     }
//     IPP_CALL(ipp::wrappers::divide_by_scalar_inplace(src, divider, src_len));
// }
//
//
// template<typename T>
// StatusResult divide_list_by_list(std::span<T> src_divided,
//                                  std::span<T> src_divisors,
//                                  std::optional<std::span<T>> dst) {
//     AUTO_INIT();
//
//     CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src_divided, src_divisors);
//
//     int src_divided_len, src_divisors_len;
//     SAFE_CAST_CALL(safe_cast::cast(src_divided.size(), src_divided_len));
//     SAFE_CAST_CALL(safe_cast::cast(src_divisors.size(), src_divisors_len));
//
//     SIZES_EQUAL_CHECK(src_divided_len, src_divisors_len);
//
//     if (dst.has_value()) {
//         CHECK_SIZE_NOT_ZERO_RETURN_STATUS(dst.value());
//
//         int dst_len;
//         SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_len));
//
//         SIZES_EQUAL_CHECK(dst_len, src_divided_len);  // check dst len equal
//
//         IPP_CALL(
//             ipp::wrappers::divide_list_by_list(src_divided, src_divisors, dst, src_divided_len));
//     }
//
//     IPP_CALL(
//         ipp::wrappers::divide_list_by_list_inplace(src_divided, src_divisors, src_divided_len));
// }
//
//
// template<typename T>
// StatusResult compute_substraction(std::span<T> src_minuend,
//                                   std::span<T> src_subtrahend,
//                                   std::optional<std::span<T>> dst) {
//     AUTO_INIT();
//
//     CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src_minuend, src_subtrahend);
//
//     int src_minuend_len, src_subtrahend_len;
//     SAFE_CAST_CALL(safe_cast::cast(src_minuend.size(), src_minuend_len));
//     SAFE_CAST_CALL(safe_cast::cast(src_subtrahend.size(), src_subtrahend_len));
//
//     SIZES_EQUAL_CHECK(src_minuend_len, src_subtrahend_len);
//
//     if (dst.has_value()) {
//         CHECK_SIZE_NOT_ZERO_RETURN_STATUS(dst.value());
//
//         int dst_len;
//         SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_len));
//
//         SIZES_EQUAL_CHECK(dst_len, src_minuend_len);  // check dst len equal
//
//         IPP_CALL(ipp::wrappers::substract_by_list(src_minuend,
//                                                   src_subtrahend,
//                                                   dst.value(),
//                                                   src_minuend_len));
//     }
//     IPP_CALL(
//         ipp::wrappers::substract_by_list_inplace(src_minuend, src_subtrahend, src_minuend_len));
// }
//
//
// template<typename T>
// StatusResult apply_square(std::span<T> src, std::optional<std::span<T>> dst) {
//     AUTO_INIT();
//
//     CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src);
//
//     int src_len;
//     SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
//
//     if (dst.has_value()) {
//         CHECK_SIZE_NOT_ZERO_RETURN_STATUS(dst.value());
//
//         int dst_len;
//         SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_len));
//
//         SIZES_EQUAL_CHECK(dst_len, src_len);
//
//         IPP_CALL(ipp::wrappers::apply_square(src, dst.value(), src_len));
//     }
//     IPP_CALL(ipp::wrappers::apply_square_inplace(src, src_len));
// }
//
//
// template<typename T>
// StatusResult apply_flip(std::span<T> src, std::optional<std::span<T>> dst) {
//     AUTO_INIT();
//
//     CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src);
//
//     int src_len;
//     SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
//
//     if (dst.has_value()) {
//         CHECK_EQUAL_SIZE_RETURN_STATUS(dst.value());
//
//         int dst_len;
//         SAFE_CAST_CALL(safe_cast::cast(dst.value().size(), dst_len));
//
//         SIZES_EQUAL_CHECK(dst_len, src_len);
//
//         IPP_CALL(ipp::wrappers::apply_flip(src, dst.value(), src_len));
//     }
//     IPP_CALL(ipp::wrappers::apply_flip_inplace(src));
// }
//
//
// template<typename T>
// StatusResult apply_absolute(std::span<T> src, std::optional<std::span<T>> dst) {
//     AUTO_INIT();
//
//     CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src);
//
//     int src_len;
//     SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
//
//     if (dst.has_value()) {
//         CHECK_EQUAL_SIZE_RETURN_STATUS(dst.value());
//
//         int dst_len;
//         SAFE_CAST_CALL(safe_cast::cast(dst.value().size(), dst_len));
//
//         SIZES_EQUAL_CHECK(dst_len, src_len);
//
//         IPP_CALL(ipp::wrappers::apply_absolute(src, dst.value(), src_len));
//     }
//
//     IPP_CALL(ipp::wrappers::apply_absolute_inplace(src, src_len));
// }
//

//
// template<typename T>
// StatusResult compute_complex_magnitude(std::span<const std::complex<T>> src, std::span<T> dst) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src, dst);
//
//    int src_len;
//    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
//
//    IPP_CALL(ipp::wrappers::compute_complex_magnitude(src, dst, src_len));
//}
//
//
// template<typename T>
// StatusResult compute_real_imag_magnitude(std::span<const T> src_real,
//                                         std::span<const T> src_img,
//                                         std::span<T> dst) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src_real, src_img, dst);
//
//    int src_real_len, src_img_len;
//    SAFE_CAST_CALL(safe_cast::cast(src_real.size(), src_real_len));
//    SAFE_CAST_CALL(safe_cast::cast(src_img.size(), src_img_len));
//
//    SIZES_EQUAL_CHECK(src_real_len, src_real_len);
//
//    IPP_CALL(ipp::wrappers::compute_real_imag_magnitude(src_real, src_img, dst, src_real_len));
//}
//
//
// template<typename T>
// StatusResult combine(std::span<T> src1, std::span<T> src2, std::optional<std::span<T>> dst) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src1, src2);
//
//    int src1_len, src2_len;
//    SAFE_CAST_CALL(safe_cast::cast(src1.size(), src1_len));
//    SAFE_CAST_CALL(safe_cast::cast(src2.size(), src2_len));
//
//    if (dst.has_value()) {
//        CHECK_SIZE_NOT_ZERO_RETURN_STATUS(dst.value());
//
//        int dst_len;
//        SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_len));
//
//        IPP_CALL(ipp::wrappers::combine(src1, src2, dst.value()));
//    }
//    IPP_CALL(ipp::wrappers::combine_inplace(src1, src2));
//}
//
//
// template<typename T>
// StatusResult combine_with_scalar(std::span<T> src, T scalar, std::optional<std::span<T>> dst) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src);
//
//    if (dst.has_value()) {
//        CHECK_SIZE_NOT_ZERO_RETURN_STATUS(dst.value());
//
//        IPP_CALL(ipp::wrappers::combine_with_scalar(src, scalar, dst.value()));
//    }
//    IPP_CALL(ipp::wrappers::combine_with_scalar_inplace(src, scalar));
//}
//
//
// template<typename T>
// StatusResult fill_slope(std::span<T> dst, T offset, T slope) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(dst);
//
//    int dst_len;
//    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_len));
//
//    IPP_CALL(ipp::wrappers::fill_slope(dst, offset, slope, dst_len));
//}
//
//
//
//
// template<typename T>
// StatusResult apply_floor(std::span<T> src, std::span<T> dst) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src, dst);
//
//    int src_len, dst_len;
//    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
//    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_len));
//
//    SIZES_EQUAL_CHECK(src_len, dst_len);
//
//    IPP_CALL(ipp::wrappers::apply_floor(src, dst, src_len));
//}
//
//
// template<typename T>
// StatusResult compute_complex_conjugates(std::span<std::complex<T>> src,
//                                        std::optional<std::span<std::complex<T>>> dst) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src);
//
//    int src_len;
//    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
//
//    if (dst.has_value()) {
//        CHECK_SIZE_NOT_ZERO_RETURN_STATUS(dst.value());
//
//        int dst_len;
//        SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_len));
//
//        SIZES_EQUAL_CHECK(dst_len, src_len);
//
//        IPP_CALL(ipp::wrappers::compute_complex_conjugates(src, dst.value(), src_len));
//    }
//
//    IPP_CALL(ipp::wrappers::compute_complex_conjugates_inplace(src, src_len));
//}
//
//
// template<typename T>
// StatusResult
// find_minimum_and_index(std::span<T> src, T& min, std::optional<std::reference_wrapper<int>>
// index) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src);
//
//    int src_len;
//    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
//
//    if (index.has_value()) {
//        IPP_CALL(ipp::wrappers::find_minimum_index(src, src_len, min, index));
//    }
//    IPP_CALL(ipp::wrappers::find_minimum(src, min, src_len));
//}
//
//
// template<typename T>
// StatusResult
// find_maximum_and_index(std::span<T> src, T& max, std::optional<std::reference_wrapper<int>>
// index) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src);
//
//    int src_len;
//    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
//
//    if (index.has_value()) {
//        IPP_CALL(ipp::wrappers::find_maximum_index(src, src_len, max, index));
//    }
//    IPP_CALL(ipp::wrappers::find_maximum(src, max, src_len));
//}
//
//

template<typename T>
StatusResult compute_complex_dot_product(std::span<T> src,
                                         std::span<std::complex<T>> src_complex,
                                         std::complex<T>& dst) {
    AUTO_INIT();

    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src, src_complex, dst);

    int src_len, src_complex_len;
    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
    SAFE_CAST_CALL(safe_cast::cast(src_complex.size(), src_complex_len));

    IPP_CALL(ipp::wrappers::compute_complex_dot_product(src, src, dst, src_len));
}

//
//
// template<typename T>
// StatusResult compute_dot_product(std::span<T> src1, std::span<T> src2, std::span<T> dst) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src1, src2, dst);
//
//    int src1_len, src2_len, dst_len;
//    SAFE_CAST_CALL(safe_cast::cast(src1.size(), src1_len));
//    SAFE_CAST_CALL(safe_cast::cast(src2.size(), src2_len));
//    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_len));
//
//    SIZES_EQUAL_CHECK(src1_len, src2_len);
//    SIZES_EQUAL_CHECK(src1_len, dst_len);
//
//    IPP_CALL(ipp::wrappers::compute_dot_product(src1, src2, dst, src1_len));
//}
//
//
// template<typename T>
// StatusResult compute_xor(std::span<T> src1, std::span<T> src2, std::optional<std::span<T>> dst) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src1, src2);
//
//    int src1_len, src2_len;
//    SAFE_CAST_CALL(safe_cast::cast(src1.size(), src1_len));
//    SAFE_CAST_CALL(safe_cast::cast(src2.size(), src2_len));
//
//    SIZES_EQUAL_CHECK(src1_len, src2_len);
//
//    if (dst.has_value()) {
//        CHECK_SIZE_NOT_ZERO_RETURN_STATUS(dst.value());
//
//        int dst_len;
//        SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_len));
//
//        SIZES_EQUAL_CHECK(src1_len, dst_len);
//
//        IPP_CALL(ipp::wrappers::compute_xor(src1, src2, dst.value(), src1_len));
//    }
//
//    IPP_CALL(ipp::wrappers::compute_xor_inplace(src1, src2, src1_len));
//}
//
//
// template<typename T>
// StatusResult compute_mean_value(std::span<T> src, T& mean, AlgoChoice algo) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src);
//
//    int src_len;
//    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
//
//    IPP_CALL(ipp::wrappers::compute_mean_value(src, mean, algo, src_len));
//}
//
//
// template<typename T, typename U>
// StatusResult generate_tone(std::span<T> res, U magn, U freq, U& phase, int len, AlgoChoice algo)
// {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(res);
//
//    int res_len;
//    SAFE_CAST_CALL(safe_cast::cast(res.size(), res_len));
//
//    if (res_len < len) {
//        return StatusResult(
//            Status::OutOfRange,
//            "Number of elements for operation bigger than allocated size avaliable.",
//            __func__,
//            __FILE__,
//            __LINE__);
//    }
//
//    IPP_CALL(ipp::wrappers::generate_tone(res, magn, freq, phase, len, algo));
//}
//
//
// template<typename T>
// StatusResult generate_FFT_sizes(int order, int flag, WorkBufferSizes& sizes_to_update) {
//    AUTO_INIT();
//
//    IPP_CALL(ipp::wrappers::generate_FFT_sizes<T>(order, flag, sizes_to_update));
//}
//
//
// template<typename T>
// StatusResult compute_sum(std::span<T> src, T& sum, AlgoChoice algo) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src);
//
//    int src_len;
//    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
//
//    IPP_CALL(ipp::wrappers::compute_sum(src, sum, algo, src_len));
//}
//
//
// template<typename T>
// StatusResult apply_raise_power_with_scalar(std::span<T> bases, T scalar, std::span<T> res) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(bases, res);
//
//    int bases_len;
//    SAFE_CAST_CALL(safe_cast::cast(bases.size(), bases_len));
//
//    IPP_CALL(ipp::wrappers::apply_raise_power_with_scalar(bases, scalar, res, bases_len));
//}
//
//
// template<typename T>
// StatusResult apply_raise_power(std::span<T> bases, std::span<T> expos, std::span<T> res) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(bases, expos, res);
//
//    int bases_len;
//    SAFE_CAST_CALL(safe_cast::cast(bases.size(), bases_len));
//
//    CHECK_EQUAL_SIZE_RETURN_STATUS(bases, expos, res);
//
//    IPP_CALL(ipp::wrappers::apply_raise_power(bases, expos, res, bases_len));
//}
//
//
// template<typename T>
// StatusResult generate_DFT_sizes(int len, int flag, WorkBufferSizes& sizes_to_update) {
//    AUTO_INIT();
//
//    IPP_CALL(ipp::wrappers::generate_DFT_sizes<T>(len, flag, sizes_to_update));
//}
//
//
// template<typename T>
// StatusResult compute_complex_exponent(std::span<T> src, std::span<std::complex<T>> dst) {
//    AUTO_INIT();
//
//    CHECK_SIZE_NOT_ZERO_RETURN_STATUS(src, dst);
//
//    int src_len, dst_len;
//    SAFE_CAST_CALL(safe_cast::cast(src.size(), src_len));
//    SAFE_CAST_CALL(safe_cast::cast(dst.size(), dst_len));
//
//    SIZES_EQUAL_CHECK(src_len, dst_len);
//
//    IPP_CALL(ipp::wrappers::compute_complex_exponent(src, dst, src_len));
//}
//
//
// template<typename T>
// StatusResult malloc(int len, T& buffer) {
//    AUTO_INIT();
//
//    if (len == 0) {
//        return chord::StatusResult(Status::MemoryError,
//                                   "Size wanted for allocation is zero",
//                                   __func__,
//                                   __FILE__,
//                                   __LINE__);
//    }
//
//    IPP_CALL(ipp::wrappers::malloc(len, buffer));
//}


}  // namespace chord::impl


#endif  // CHORD_SRC_IMPL_IPP_IMPL_TPP