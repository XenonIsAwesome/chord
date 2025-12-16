//
// Created by userk on 6/9/25.
//

#include "ipp/ipp_wrappers/ipp_wrappers.hpp"


template<>
IppStatus
ipp::wrappers::compute_fractional_part(std::span<const float> src, std::span<float> dst, int len) {
    // TODO: check if deprecated and gtest
    // return ippsFrac_32f(src.data(), dst.data(), len);
    return ippStsErr;
}


template<>
IppStatus
ipp::wrappers::compute_fractional_part(std::span<const double> src, std::span<double> dst, int len) {
    // return ippsFrac_64f(src.data(), dst.data(), len);
    // TODO: check if deprecated and gtest
    return ippStsErr;
}

