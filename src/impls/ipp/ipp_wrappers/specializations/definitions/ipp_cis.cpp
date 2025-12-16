//
// Created by userk on 6/11/25.
//


#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"


template<>
IppStatus ipp::wrappers::compute_complex_exponent<float>(std::span<const float> src,
                                                         std::span<std::complex<float>> dst,
                                                         int len) {
    // Ipp32fc* p_dst = types::cast_to_ipp(dst.data());

    // return ippsCIS_32fc_A24(src.data(), p_dst, len);
    // TODO: check if deprecated and gtest
    return ippStsErr;
}
