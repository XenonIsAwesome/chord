//
// Created by userk on 5/7/25.
//

#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"


template<>
IppStatus ipp::wrappers::compute_exponential<std::complex<float>>(std::span<const std::complex<float>> src,
                                       std::span<std::complex<float>> dst, int size) {
    // const Ipp32fc* pSrc = types::cast_to_ipp(src.data());
    // Ipp32fc* pDst = types::cast_to_ipp(dst.data());

    // types::cast_to_ipp(src, pSrc);
    // types::cast_to_ipp(dst, pDst);

    // return ippsExp_32fc_A24(pSrc, pDst, size);
    // TODO: check if deprecated and gtest
    return ippStsErr;
}


template<>
IppStatus ipp::wrappers::compute_exponential<float>(std::span<const float> src,
                                       std::span<float> dst, int size) {
    // return ippsExp_32f_A24(src.data(), dst.data(), size);
    // TODO: check if deprecated and gtest
    return ippStsErr;
}
