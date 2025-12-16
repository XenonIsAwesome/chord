//
// Created by userk on 6/10/25.
//

#include "ipp/ipp_wrappers/ipp_wrappers.hpp"

template<>
IppStatus ipp::wrappers::compute_xor(std::span<const u_short> src1,
                                     std::span<const u_short> src2,
                                     std::span<u_short> dst,
                                     int len) {
    return ippsXor_16u(src1.data(), src2.data(), dst.data(), len);
}


template<>
IppStatus
ipp::wrappers::compute_xor_inplace(std::span<u_short> src1, std::span<u_short> src2, int len) {
    return ippsXor_16u_I(src1.data(), src2.data(), len);
}
