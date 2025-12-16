//
// Created by userk on 5/14/25.
//

#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"


template<>
IppStatus ipp::wrappers::compute_complex_magnitude<float>(std::span<const std::complex<float>> src,
                                                          std::span<float> dst,
                                                          int len) {
    const Ipp32fc* p_src = types::cast_to_ipp(src.data());
    // types::cast_to_ipp(src, p_src);

    return ippsMagnitude_32fc(p_src, dst.data(), len);
}


/// double
template<>
IppStatus
ipp::wrappers::compute_complex_magnitude<double>(std::span<const std::complex<double>> src,
                                                 std::span<double> dst,
                                                 int len) {
    const Ipp64fc* p_src = types::cast_to_ipp(src.data());
    // types::cast_to_ipp(src, p_src);

    return ippsMagnitude_64fc(p_src, dst.data(), len);
}


/// float
template<>
IppStatus ipp::wrappers::compute_real_imag_magnitude<float>(std::span<const float> src_real,
                                                            std::span<const float> src_img,
                                                            std::span<float> dst,
                                                            int len) {
    return ippsMagnitude_32f(src_real.data(), src_img.data(), dst.data(), len);
}


/// double
template<>
IppStatus ipp::wrappers::compute_real_imag_magnitude<double>(std::span<const double> src_real,
                                                             std::span<const double> src_img,
                                                             std::span<double> dst,
                                                             int len) {
    return ippsMagnitude_64f(src_real.data(), src_img.data(), dst.data(), len);
}
