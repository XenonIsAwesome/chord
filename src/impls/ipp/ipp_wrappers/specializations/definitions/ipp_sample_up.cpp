//
// Created by userk on 5/11/25.
//

#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"

template<>
IppStatus ipp::wrappers::compute_up_sample<float>(std::span<const float> src,
                                                  int src_size,
                                                  int factor,
                                                  int* phase,
                                                  std::span<float> dst,
                                                  int* dst_size) {
    return ippsSampleUp_32f(src.data(), src_size, dst.data(), dst_size, factor, phase);
}


template<>
IppStatus
ipp::wrappers::compute_up_sample<std::complex<float>>(std::span<const std::complex<float>> src,
                                                      int src_size,
                                                      int factor,
                                                      int* phase,
                                                      std::span<std::complex<float>> dst,
                                                      int* dst_size) {
    const Ipp32fc* p_src = types::cast_to_ipp(src.data());
    Ipp32fc* p_dst = types::cast_to_ipp(dst.data());

    // types::cast_to_ipp(src, p_src);
    // types::cast_to_ipp(dst, p_dst);

    return ippsSampleUp_32fc(p_src, src_size, p_dst, dst_size, factor, phase);
}


template<>
IppStatus ipp::wrappers::compute_up_sample<double>(std::span<const double> src,
                                                   int src_size,
                                                   int factor,
                                                   int* phase,
                                                   std::span<double> dst,
                                                   int* dst_size) {
    return ippsSampleUp_64f(src.data(), src_size, dst.data(), dst_size, factor, phase);
}
