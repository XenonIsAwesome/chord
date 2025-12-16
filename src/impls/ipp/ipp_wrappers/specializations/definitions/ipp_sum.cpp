//
// Created by userk on 5/14/25.
//


#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"


template<>
IppStatus
ipp::wrappers::compute_sum<float>(std::span<const float> src, float& sum, chord::AlgoChoice algo, int len) {
    return ippsSum_32f(src.data(), len, &sum, types::cast_to_ipp(algo));
}


template<>
IppStatus ipp::wrappers::compute_sum<std::complex<float>>(std::span<const std::complex<float>> src,
                                                          std::complex<float>& sum,
                                                          chord::AlgoChoice algo,
                                                          int len) {
    const Ipp32fc* p_src = types::cast_to_ipp(src.data());
    Ipp32fc* p_sum = types::cast_to_ipp(&sum);

    return ippsSum_32fc(p_src, len, p_sum, types::cast_to_ipp(algo));
}


template<>
IppStatus ipp::wrappers::compute_sum<int>(std::span<const int> src, int& sum, chord::AlgoChoice algo, int len) {
    // TODO: check the last param in function = scaling
    return ippsSum_32s_Sfs(src.data(), len, &sum, 0);
}

