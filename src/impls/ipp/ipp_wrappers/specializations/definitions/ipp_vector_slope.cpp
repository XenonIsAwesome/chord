//
// Created by userk on 5/19/25.
//

#include "ipp/ipp_wrappers/ipp_wrappers.hpp"

template<>
IppStatus
ipp::wrappers::fill_slope<double>(std::span<double> dst, double offset, double slope, int len) {
    return ippsVectorSlope_64f(dst.data(), len, offset, slope);
}


template<>
IppStatus
ipp::wrappers::fill_slope<float>(std::span<float> dst, float offset, float slope, int len) {
    return ippsVectorSlope_32f(dst.data(), len, offset, slope);
}
