//
// Created by userk on 5/14/25.
//


#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
#include "ipp/cast_to_ipp/cast_to_ipp.hpp"

template<>
IppStatus ipp::wrappers::apply_flip<float>(std::span<const float> src, std::span<float> dst, int len) {
    return ippsFlip_32f(src.data(), dst.data(), len);
}


template<>
IppStatus ipp::wrappers::apply_flip<std::complex<float>>(std::span<const std::complex<float>> src,
                                                         std::span<std::complex<float>> dst,
                                                         int len) {
    const Ipp32fc* p_src = types::cast_to_ipp(src.data());
    Ipp32fc* p_dst = types::cast_to_ipp(dst.data());

    // types::cast_to_ipp(src, p_src);
    // types::cast_to_ipp(dst, p_dst);

    return ippsFlip_32fc(p_src, p_dst, len);
}


template<>
IppStatus ipp::wrappers::apply_flip_inplace<float>(std::span<float> src, int len) {
    return ippsFlip_32f_I(src.data(), len);
}


template<>
IppStatus ipp::wrappers::apply_flip_inplace<std::complex<float>>(std::span<std::complex<float>> src,
                                                                int len) {
    Ipp32fc* p_src = types::cast_to_ipp(src.data());

    // types::cast_to_ipp(src, p_src);

    return ippsFlip_32fc_I(p_src, len);
}
