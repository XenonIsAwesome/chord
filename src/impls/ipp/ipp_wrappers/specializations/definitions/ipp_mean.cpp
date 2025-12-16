//
// Created by userk on 6/10/25.
//


#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"


template<>
IppStatus ipp::wrappers::compute_mean_value<float>(std::span<const float> src,
                                                   float& mean,
                                                   chord::AlgoChoice algo,
                                                   int len) {
    Ipp32f* p_mean = types::cast_to_ipp(&mean);

    return ippsMean_32f(src.data(), len, p_mean, types::cast_to_ipp(algo));
}
