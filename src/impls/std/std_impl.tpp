#ifndef CHORD_SRC_STD_IMPL_TPP
#define CHORD_SRC_STD_IMPL_TPP

#include "builtin_math/math_std.hpp"

#include <chord_status.hpp>
#include <chord_structs.hpp>
#include <iostream>
#include <mutex>
#include <span>

/// flag for init once logic in AUTO_INIT(isn't used elsewhere)
static std::once_flag chord_once_flag;


#define FUNC_CALL_TO_STATUS(FUNC_CALL)                                                             \
    return ([&]() -> chord::StatusResult {                                                         \
        try {                                                                                      \
            FUNC_CALL;                                                                             \
            return chord::StatusResult(__func__, __FILE__, __LINE__);                              \
        } catch (std::bad_alloc & err) {                                                           \
            return chord::StatusResult(chord::Status::MemoryError,                                 \
                                       err.what(),                                                 \
                                       __func__,                                                   \
                                       __FILE__,                                                   \
                                       __LINE__);                                                  \
        } catch (std::logic_error & err) {                                                         \
            return chord::StatusResult(chord::Status::InvalidParamter,                             \
                                       err.what(),                                                 \
                                       __func__,                                                   \
                                       __FILE__,                                                   \
                                       __LINE__);                                                  \
        } catch (std::exception & err) {                                                           \
            return chord::StatusResult(Status::Unknown, err.what(), __func__, __FILE__, __LINE__); \
        }                                                                                          \
    })()


namespace chord::impl {

inline void init() {}


template<typename T>
StatusResult multiply_with_scalar(std::span<const T> src, T val, std::span<T> dst) {
    FUNC_CALL_TO_STATUS(math_std::multiply_with_scalar(src, val, dst));
}


template<typename T>
StatusResult multiply_with_scalar_inplace(std::span<T> src_dst, T val) {
    FUNC_CALL_TO_STATUS(math_std::multiply_with_scalar_inplace(src_dst, val));
}


template<typename T>
StatusResult compute_exponential(std::span<const T> src, std::span<T> dst) {
    FUNC_CALL_TO_STATUS(math_std::compute_exponential(src, dst));
}


template<typename T>
StatusResult
compute_up_sample(std::span<const T> src, std::span<T> dst, int factor, int* phase, int* dst_size) {
    // TODO: check impl cause dst_size unused

    FUNC_CALL_TO_STATUS(math_std::compute_up_sample(src, dst, factor, phase));
}


template<typename T>
StatusResult
integer_fraction_split(std::span<const T> src, std::span<T> dst_int, std::span<T> dst_frac) {
    FUNC_CALL_TO_STATUS(math_std::integer_fraction_split(src, dst_int, dst_frac));
}


template<typename T>
StatusResult compute_fractional_part(std::span<const T> src, std::span<T> dst) {
    FUNC_CALL_TO_STATUS(math_std::compute_fractional_part(src, dst));
}


template<typename T>
StatusResult divide_by_scalar(std::span<const T> src, T divider, std::span<T> dst) {
    math_std::divide_by_scalar(src, divider, dst);
    FUNC_CALL_TO_STATUS(math_std::divide_by_scalar(src, divider, dst));
}


template<typename T>
StatusResult divide_by_scalar_inplace(std::span<T> src_dst, T divider) {
    FUNC_CALL_TO_STATUS(math_std::divide_by_scalar_inplace(src_dst, divider));
}


template<typename T>
StatusResult subtract_inplace(std::span<T> src_dst_minuend, std::span<const T> src_subtrahend) {
    FUNC_CALL_TO_STATUS(math_std::compute_substraction_inplace(src_dst_minuend, src_subtrahend));
}


template<typename T>
StatusResult
subtract(std::span<const T> src_minuend, std::span<const T> src_subtrahend, std::span<T> dst) {
    FUNC_CALL_TO_STATUS(math_std::compute_substraction(src_minuend, src_subtrahend, dst));
}


template<typename T>
StatusResult apply_square(std::span<const T> src, std::span<T> dst) {
    FUNC_CALL_TO_STATUS(math_std::apply_square(src, dst));
}


template<typename T>
StatusResult apply_square_inplace(std::span<T> src_dst) {
    FUNC_CALL_TO_STATUS(math_std::apply_square_inplace(src_dst));
}


template<typename T>
StatusResult apply_flip(std::span<const T> src, std::span<T> dst) {
    FUNC_CALL_TO_STATUS(math_std::apply_flip(src, dst));
}


template<typename T>
StatusResult apply_flip_inplace(std::span<T> src_dst) {
    FUNC_CALL_TO_STATUS(math_std::apply_flip_inplace(src_dst));
}


template<typename T>
StatusResult apply_absolute(std::span<const T> src, std::span<T> dst) {
    FUNC_CALL_TO_STATUS(math_std::apply_absolute(src, dst));
}


template<typename T>
StatusResult apply_absolute_inplace(std::span<T> src_dst) {
    FUNC_CALL_TO_STATUS(math_std::apply_absolute_inplace(src_dst));
}


template<typename T>
StatusResult compute_complex_magnitude(std::span<const std::complex<T>> src, std::span<T> dst) {
    FUNC_CALL_TO_STATUS(math_std::compute_complex_magnitude(src, dst));
}


template<typename T>
StatusResult compute_real_imag_magnitude(std::span<const T> src_real,
                                         std::span<const T> src_img,
                                         std::span<T> dst) {
    FUNC_CALL_TO_STATUS(math_std::compute_real_imag_magnitude(src_real, src_img, dst));
}


template<typename T>
StatusResult fill_slope(std::span<T> dst, T offset, T slope) {
    FUNC_CALL_TO_STATUS(math_std::fill_slope(dst, offset, slope));
}


template<typename T>
StatusResult combine(std::span<const T> src1, std::span<const T> src2, std::span<T> dst) {
    FUNC_CALL_TO_STATUS(math_std::combine(src1, src2, dst));
}


template<typename T>
StatusResult combine_inplace(std::span<const T> src1, std::span<T> src2) {
    FUNC_CALL_TO_STATUS(math_std::combine_inplace(src2, src1));
}


template<typename T>
StatusResult combine_with_scalar(std::span<const T> src, T scalar, std::span<T> dst) {
    FUNC_CALL_TO_STATUS(math_std::combine_with_scalar(src, scalar, dst));
}


template<typename T>
StatusResult combine_with_scalar_inplace(std::span<T> src_dst, T scalar) {
    FUNC_CALL_TO_STATUS(math_std::combine_with_scalar_inplace(src_dst, scalar));
}


template<typename T>
StatusResult apply_floor(std::span<const T> src, std::span<T> dst) {
    FUNC_CALL_TO_STATUS(math_std::apply_floor(src, dst));
}


template<typename T>
StatusResult compute_complex_conjugates(std::span<const std::complex<T>> src,
                                        std::span<std::complex<T>> dst) {
    FUNC_CALL_TO_STATUS(math_std::compute_complex_conjugates(src, dst));
}


template<typename T>
StatusResult compute_complex_conjugates_inplace(std::span<std::complex<T>> src_dst) {
    FUNC_CALL_TO_STATUS(math_std::compute_complex_conjugates_inplace(src_dst));
}


template<typename T>
StatusResult find_minimum_and_index(std::span<const T> src, T& min, int& index) {
    FUNC_CALL_TO_STATUS(math_std::find_minimum_and_index(src, min, index));
}


template<typename T>
StatusResult find_minimum(std::span<const T> src, T& min) {
    FUNC_CALL_TO_STATUS(math_std::find_minimum(src, min));
}


template<typename T>
StatusResult find_maximum_and_index(std::span<const T> src, T& max, int& index) {
    FUNC_CALL_TO_STATUS(math_std::find_maximum_and_index(src, max, index));
}


template<typename T>
StatusResult find_maximum(std::span<const T> src, T& max) {
    FUNC_CALL_TO_STATUS(math_std::find_maximum(src, max));
}


template<typename T>
StatusResult
compute_dot_product(std::span<const T> src1, std::span<const T> src2, std::span<T> dst) {
    // FUNC_CALL_TO_STATUS(math_std::)
    // TODO: emmm checkimpl
    return StatusResult();
}


template<typename T>
StatusResult compute_complex_dot_product(std::span<const T> src,
                                         std::span<const std::complex<T>> src_complex,
                                         std::complex<T>& dst) {
    // math_std::compute_com
    // TODO: emmm checkimpl
    return StatusResult();
}


template<typename T>
StatusResult compute_xor(std::span<const T> src1, std::span<const T> src2, std::span<T> dst) {
    FUNC_CALL_TO_STATUS(math_std::compute_xor(src1, src2, dst));
}


template<typename T>
StatusResult compute_xor_inplace(std::span<T> src1, std::span<const T> src2) {
    FUNC_CALL_TO_STATUS(math_std::compute_xor_inplace(src1, src2));
}


template<typename T>
StatusResult compute_mean_value(std::span<const T> src, T& mean, AlgoChoice algo) {
    FUNC_CALL_TO_STATUS(math_std::compute_mean_value(src, mean));
}


template<typename T, typename U>
StatusResult generate_tone(std::span<T> res, U magn, U freq, U& phase, int len, AlgoChoice algo) {
    FUNC_CALL_TO_STATUS(math_std::generate_tone(res, magn, freq, phase));
}


template<typename T>
StatusResult generate_FFT_sizes(int order, int flag, WorkBufferSizes& sizes_to_update) {
    // FUNC_CALL_TO_STATUS(math_std::ge)
    // TODO: emmm checkimpl
    return StatusResult();
}


template<typename T>
StatusResult compute_sum(std::span<const T> src, T& sum, AlgoChoice algo) {
    // FUNC_CALL_TO_STATUS(math_std::compute_)
    // TODO: emmm checkimpl
    return StatusResult();
}


template<typename T>
StatusResult apply_raise_power_with_scalar(std::span<const T> bases, T scalar, std::span<T> res) {
    FUNC_CALL_TO_STATUS(math_std::apply_raise_power_with_scalar(bases, scalar, res));
}


template<typename T>
StatusResult
apply_raise_power(std::span<const T> bases, std::span<const T> expos, std::span<T> res) {
    FUNC_CALL_TO_STATUS(math_std::apply_raise_power(bases, expos, res));
}


template<typename T>
StatusResult generate_DFT_sizes(int len, int flag, WorkBufferSizes& sizes_to_update) {
    // FUNC_CALL_TO_STATUS(math_std::genera)
    // TODO: emmm checkimpl
    return StatusResult();
}


template<typename T>
StatusResult compute_complex_exponent(std::span<const T> src, std::span<std::complex<T>> dst) {
    FUNC_CALL_TO_STATUS(math_std::compute_complex_exponent(src, dst));
}


template<typename T>
StatusResult divide_list_by_list_inplace(std::span<const T> src_divided,
                                         std::span<T> src_divisors_dst) {
    FUNC_CALL_TO_STATUS(math_std::divide_list_by_list_inplace(src_divided, src_divisors_dst));
}



// template<typename T>
// StatusResult divide_by_scalar(std::span<T> src, T divider, std::optional<std::span<T>> dst) {
//     AUTO_INIT();
//
//     CHECK_NULLPTRS_RETURN_STATUS(src.data());
//
//     if (dst.has_value()) {
//         CHECK_NULLPTRS_RETURN_STATUS(dst.value().data());
//         CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst.value());
//
//         FUNC_CALL_TO_STATUS(math_std::divide_by_scalar(src, divider, dst.value()));
//     }
//
//     FUNC_CALL_TO_STATUS(math_std::divide_by_scalar_inplace(src, divider));
// }
//
//

//
//

//
//
// template<typename T>
// StatusResult divide_list_by_list(std::span<T> src_divided,
//                                 std::span<T> src_divisors,
//                                 std::optional<std::span<T>> dst) {
//    AUTO_INIT();
//
//    CHECK_NULLPTRS_RETURN_STATUS(src_divided.data(), src_divisors);
//
//    if (dst.has_value()) {
//        CHECK_EQUAL_SIZE_RETURN_STATUS(src_divided, dst.value());
//
//        FUNC_CALL_TO_STATUS(math_std::divide_list_by_list(src_divided, src_divisors, dst));
//    }
//
//    FUNC_CALL_TO_STATUS(math_std::divide_list_by_list(src_divided, src_divisors));
//}
//
//

//
//
// template<typename T>
// StatusResult apply_square(std::span<T> src, std::optional<std::span<T>> dst) {
//    AUTO_INIT();
//
//    if (dst.has_value()) {
//        CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst.value());
//
//        FUNC_CALL_TO_STATUS(math_std::apply_square(src, dst.value()));
//    }
//    FUNC_CALL_TO_STATUS(math_std::apply_square_inplace(src));
//}
//
//
// template<typename T>
// StatusResult apply_flip(std::span<T> src, std::optional<std::span<T>> dst) {
//    AUTO_INIT();
//
//    if (dst.has_value()) {
//        CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst.value());
//
//        FUNC_CALL_TO_STATUS(math_std::apply_flip(src, dst.value()));
//    }
//
//    FUNC_CALL_TO_STATUS(math_std::apply_flip_inplace(src));
//}
//
//
// template<typename T>
// StatusResult apply_absolute(std::span<T> src, std::optional<std::span<T>> dst) {
//    AUTO_INIT();
//
//    if (dst.has_value()) {
//        CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst.value());
//
//        FUNC_CALL_TO_STATUS(math_std::apply_absolute(src, dst.value()));
//    }
//
//    FUNC_CALL_TO_STATUS(math_std::apply_absolute_inplace(src));
//}
//
//
// template<typename T>
// StatusResult compute_complex_magnitude(std::span<const std::complex<T>> src, std::span<T> dst) {
//    AUTO_INIT();
//
//    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);
//
//    FUNC_CALL_TO_STATUS(math_std::compute_complex_magnitude(src, dst));
//}
//
//
// template<typename T>
// StatusResult compute_real_imag_magnitude(std::span<const T> src_real,
//                                         std::span<const T> src_img,
//                                         std::span<T> dst) {
//    AUTO_INIT();
//
//    CHECK_EQUAL_SIZE_RETURN_STATUS(src_img, src_real, dst);
//
//    FUNC_CALL_TO_STATUS(math_std::compute_real_imag_magnitude(src_real, src_img, dst));
//}
//
//
// template<typename T>
// StatusResult combine(std::span<T> src1, std::span<T> src2, std::optional<std::span<T>> dst) {
//    AUTO_INIT();
//
//    CHECK_EQUAL_SIZE_RETURN_STATUS(src1, src2);
//
//    if (dst.has_value()) {
//        CHECK_EQUAL_SIZE_RETURN_STATUS(src1, dst.value());
//
//        FUNC_CALL_TO_STATUS(math_std::combine(src1, src2, dst.value()));
//    }
//
//    FUNC_CALL_TO_STATUS(math_std::combine_inplace(src1, src2));
//}
//
//
// template<typename T>
// StatusResult combine_with_scalar(std::span<T> src, T scalar, std::optional<std::span<T>> dst) {
//    AUTO_INIT();
//
//    if (dst.has_value()) {
//        CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst.value());
//
//        FUNC_CALL_TO_STATUS(math_std::combine_with_scalar(src, scalar, dst.value()));
//    }
//
//    FUNC_CALL_TO_STATUS(math_std::combine_with_scalar_inplace(src, scalar));
//}
//
//
// template<typename T>
// StatusResult fill_slope(std::span<T> dst, T offset, T slope) {
//    AUTO_INIT();
//
//    FUNC_CALL_TO_STATUS(math_std::fill_slope(dst, offset, slope));
//}
//
//
//// template<typename T>
//// StatusResult compute_fractional_part(std::span<const T> src, std::span<T> dst) {
////     AUTO_INIT();
////     // TODO: check impl
////
////     // FUNC_CALL_TO_STATUS(math_std::compute_)
//// }
//
//
// template<typename T>
// StatusResult apply_floor(std::span<T> src, std::span<T> dst) {
//    AUTO_INIT();
//
//    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);
//
//    FUNC_CALL_TO_STATUS(math_std::apply_floor(src, dst));
//}
//
//
// template<typename T>
// StatusResult compute_complex_conjugates(std::span<std::complex<T>> src,
//                                        std::optional<std::span<std::complex<T>>> dst) {
//    AUTO_INIT();
//
//    if (dst.has_value()) {
//        CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst.value());
//
//        FUNC_CALL_TO_STATUS(math_std::compute_complex_conjugates(src, dst.value()));
//    }
//
//    FUNC_CALL_TO_STATUS(math_std::compute_complex_conjugates_inplace(src));
//}
//
//
// template<typename T>
// StatusResult
// find_minimum_and_index(std::span<T> src, T& min, std::optional<std::reference_wrapper<int>>
// index) {
//    AUTO_INIT();
//
//    if (index.has_value()) {
//        FUNC_CALL_TO_STATUS(math_std::find_minimum_and_index(src, min, index.value()));
//    }
//
//    FUNC_CALL_TO_STATUS(math_std::find_minimum(src, min));
//}
//
//
// template<typename T>
// StatusResult
// find_maximum_and_index(std::span<T> src, T& max, std::optional<std::reference_wrapper<int>>
// index) {
//    AUTO_INIT();
//
//    if (index.has_value()) {
//        FUNC_CALL_TO_STATUS(math_std::find_maximum_and_index(src, max, index.value()));
//    }
//
//    FUNC_CALL_TO_STATUS(math_std::find_maximum(src, max));
//}
//
//
//// template<typename T>
//// StatusResult compute_complex_dot_product(std::span<T> src,
////                                          std::span<std::complex<T>> src_complex,
////                                          std::span<std::complex<T>> dst) {
////     AUTO_INIT();
////     // TODO: check impl
////     // FUNC_CALL_TO_STATUS(math_std::compute_comple)
//// }
//
//
//// template<typename T>
//// StatusResult compute_dot_product(std::span<T> src1, std::span<T> src2, std::span<T> dst) {
////     AUTO_INIT();
////
////     // math_std::compute_s// TODO: check impl
//// }
//
//
// template<typename T>
// StatusResult compute_xor(std::span<T> src1, std::span<T> src2, std::optional<std::span<T>> dst) {
//    AUTO_INIT();
//
//    CHECK_EQUAL_SIZE_RETURN_STATUS(src1, src2);
//
//    if (dst.has_value()) {
//        CHECK_EQUAL_SIZE_RETURN_STATUS(src1, dst.value());
//
//        FUNC_CALL_TO_STATUS(math_std::compute_xor(src1, src2, dst.value()));
//    }
//
//    FUNC_CALL_TO_STATUS(math_std::compute_xor_inplace(src1, src2));
//}
//
//
// template<typename T>
// StatusResult compute_mean_value(std::span<T> src, T& mean, AlgoChoice algo) {
//    AUTO_INIT();
//
//    FUNC_CALL_TO_STATUS(math_std::compute_average(src, mean));
//}
//
//
// template<typename T, typename U>
// StatusResult generate_tone(std::span<T> res, U magn, U freq, U& phase, int len, AlgoChoice algo)
// {
//    AUTO_INIT();
//
//    FUNC_CALL_TO_STATUS(math_std::generate_tone(res, magn, freq, phase));
//}
//
//
//// template<typename T>
//// StatusResult generate_FFT_sizes(int order, int flag, WorkBufferSizes& sizes_to_update) {
////     AUTO_INIT();
////
////     // FUNC_CALL_TO_STATUS(math_std::)
////     // TODO: check impl
//// }
//
//
//// template<typename T>
//// StatusResult compute_sum(std::span<T> src, T& sum, AlgoChoice algo) {
////     AUTO_INIT();
////
////     // FUNC_CALL_TO_STATUS(math_std::)
////     // TODO: check impl
//// }
//
//
// template<typename T>
// StatusResult apply_raise_power_with_scalar(std::span<T> bases, T scalar, std::span<T> res) {
//    AUTO_INIT();
//
//    CHECK_EQUAL_SIZE_RETURN_STATUS(bases, res);
//
//    FUNC_CALL_TO_STATUS(math_std::apply_raise_power_with_scalar(bases, scalar, res));
//}
//
//
// template<typename T>
// StatusResult apply_raise_power(std::span<T> bases, std::span<T> expos, std::span<T> res) {
//    AUTO_INIT();
//
//    CHECK_EQUAL_SIZE_RETURN_STATUS(bases, expos, res);
//
//    FUNC_CALL_TO_STATUS(math_std::apply_raise_power(bases, expos, res));
//}
//
//
//// template<typename T>
//// StatusResult generate_DFT_sizes(int len, int flag, WorkBufferSizes& sizes_to_update) {
////     AUTO_INIT();
////     // TODO: check impl
//// }
//
//
// template<typename T>
// StatusResult compute_complex_exponent(std::span<T> src, std::span<std::complex<T>> dst) {
//    AUTO_INIT();
//
//    CHECK_EQUAL_SIZE_RETURN_STATUS(src, dst);
//
//    FUNC_CALL_TO_STATUS(math_std::compute_complex_exponent(src, dst));
//}


}  // namespace chord::impl


#endif  // CHORD_SRC_STD_IMPL_TPP