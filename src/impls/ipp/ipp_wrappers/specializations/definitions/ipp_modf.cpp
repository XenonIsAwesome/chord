//
// Created by userk on 5/11/25.
//

#include "ipp/ipp_wrappers/ipp_wrappers.hpp"


template<>
IppStatus ipp::wrappers::integer_fraction_split<float>(std::span<const float> src,
                                                       std::span<float> dst_int,
                                                       std::span<float> dst_frac,
                                                       int len) {
    // return ippsModf_32f(src.data(), dst_int.data(), dst_frac.data(), len);
    // TODO: check if deprecated and gtest
    return ippStsErr;
}
