//
// Created by mayak on 7/2/25.
//

#include "ipp/ipp_wrappers/ipp_wrappers.hpp"

template<>
IppStatus ipp::wrappers::apply_absolute<float>(std::span<const float> src, std::span<float> dst, int len) {
    return ippsAbs_32f(src.data(), dst.data(), len);
}


template<>
IppStatus ipp::wrappers::apply_absolute<double>(std::span<const double> src, std::span<double> dst, int len) {
    return ippsAbs_64f(src.data(), dst.data(), len);
}


template<>
IppStatus ipp::wrappers::apply_absolute_inplace<float>(std::span<float> src_dst, int len) {
    return ippsAbs_32f_I(src_dst.data(), len);
}


template<>
IppStatus ipp::wrappers::apply_absolute_inplace<double>(std::span<double> src_dst, int len) {
    return ippsAbs_64f_I(src_dst.data(), len);
}
