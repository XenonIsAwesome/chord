//
// Created by userk on 5/11/25.
//

#include "ipp/ipp_wrappers/ipp_wrappers.hpp"


template<>
IppStatus ipp::wrappers::apply_floor<float>(std::span<const float> src, std::span<float> dst, int len) {
    // return ippsFloor_32f(src.data(), dst.data(), len);
    // TODO: check if deprecated and gtest
    return ippStsErr;
}


template<>
IppStatus
ipp::wrappers::apply_floor<double>(std::span<const double> src, std::span<double> dst, int len) {
    // return ippsFloor_64f(src.data(), dst.data(), len);
    // TODO: check if deprecated and gtest
    return ippStsErr;
}
