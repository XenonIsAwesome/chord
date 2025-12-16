//
// Created by userk on 5/14/25.
//

#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"

template<>
IppStatus ipp::wrappers::combine(std::span<const float> src1,
                                 std::span<const float> src2,
                                 std::span<float> dst,
                                 int len) {
    return ippsAdd_32f(src1.data(), src2.data(), dst.data(), len);
}


template<>
IppStatus ipp::wrappers::combine(std::span<const std::complex<float>> src1,
                                 std::span<const std::complex<float>> src2,
                                 std::span<std::complex<float>> dst,
                                 int len) {
    const Ipp32fc* p_src1 = types::cast_to_ipp(src1.data());
    const Ipp32fc* p_src2 = types::cast_to_ipp(src2.data());
    Ipp32fc* p_dst = types::cast_to_ipp(dst.data());

    // types::cast_to_ipp(src1, p_src1);
    // types::cast_to_ipp(src2, p_src2);
    // types::cast_to_ipp(dst, p_dst);

    return ippsAdd_32fc(p_src1, p_src2, p_dst, len);
}


template<>
IppStatus ipp::wrappers::combine_inplace(std::span<const float> src, std::span<float> src_dst, int len) {
    return ippsAdd_32f_I(src.data(), src_dst.data(), len);
}


template<>
IppStatus ipp::wrappers::combine_inplace(std::span<const std::complex<float>> src,
                                         std::span<std::complex<float>> src_dst,
                                         int len) {
    const Ipp32fc* p_src_dst = types::cast_to_ipp(src.data());
    Ipp32fc* p_src2 = types::cast_to_ipp(src_dst.data());

    return ippsAdd_32fc_I(p_src_dst, p_src2, len);
}


template<>
IppStatus ipp::wrappers::combine_with_scalar(std::span<const float> src,
                                             float scalar,
                                             std::span<float> dst,
                                             int len) {
    return ippsAddC_32f(src.data(), scalar, dst.data(), len);
}


template<>
IppStatus ipp::wrappers::combine_with_scalar(std::span<const std::complex<float>> src,
                                             std::complex<float> scalar,
                                             std::span<std::complex<float>> dst,
                                             int len) {
    const Ipp32fc* p_src = types::cast_to_ipp(src.data());
    Ipp32fc* p_dst = types::cast_to_ipp(dst.data());
    Ipp32fc scalar_conv = types::cast_to_ipp(scalar);

    return ippsAddC_32fc(p_src, scalar_conv, p_dst, len);
}


template<>
IppStatus
ipp::wrappers::combine_with_scalar_inplace(std::span<float> src_dst, float scalar, int len) {
    return ippsAddC_32f_I(scalar, src_dst.data(), len);
}


template<>
IppStatus ipp::wrappers::combine_with_scalar_inplace(std::span<std::complex<float>> src_dst,
                                                     std::complex<float> scalar,
                                                     int len) {
    Ipp32fc* p_src_dst = types::cast_to_ipp(src_dst.data());

    Ipp32fc scalar_ipp = types::cast_to_ipp(scalar);

    return ippsAddC_32fc_I(scalar_ipp, p_src_dst, len);
}
