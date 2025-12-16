//
// Created by userk on 5/14/25.
//

#include "ipp/ipp_wrappers/ipp_wrappers.hpp"


template<>
IppStatus
ipp::wrappers::apply_square<float>(std::span<const float> src, std::span<float> dst, int len) {

    return ippsSqr_32f(src.data(), dst.data(), len);
}


template<>
IppStatus ipp::wrappers::apply_square_inplace<float>(std::span<float> src, int len) {
    return ippsSqr_32f_I(src.data(), len);
}
