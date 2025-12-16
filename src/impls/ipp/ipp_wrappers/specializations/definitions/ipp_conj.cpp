//
// Created by userk on 6/9/25.
//


#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"

template<>
IppStatus ipp::wrappers::compute_complex_conjugates<double>(std::span<std::complex<double>> src,
                                                            std::span<std::complex<double>> dst,
                                                            int len) {
    Ipp64fc* p_src = types::cast_to_ipp(src.data());
    Ipp64fc* p_dst = types::cast_to_ipp(dst.data());

    // types::cast_to_ipp(src, p_src);
    // types::cast_to_ipp(dst, p_dst);

    return ippsConj_64fc(p_src, p_dst, len);
}


template<>
IppStatus ipp::wrappers::compute_complex_conjugates<float>(std::span<std::complex<float>> src,
                                                           std::span<std::complex<float>> dst,
                                                           int len) {
    Ipp32fc* p_src = types::cast_to_ipp(src.data());
    Ipp32fc* p_dst = types::cast_to_ipp(dst.data());

    // types::cast_to_ipp(src, p_src);
    // types::cast_to_ipp(dst, p_dst);

    return ippsConj_32fc(p_src, p_dst, len);
}


template<>
IppStatus
ipp::wrappers::compute_complex_conjugates_inplace<double>(std::span<std::complex<double>> src,
                                                          int len) {
    Ipp64fc* p_src = types::cast_to_ipp(src.data());

    return ippsConj_64fc_I(p_src, len);
}


template<>
IppStatus
ipp::wrappers::compute_complex_conjugates_inplace<float>(std::span<std::complex<float>> src,
                                                         int len) {
    Ipp32fc* p_src = types::cast_to_ipp(src.data());


    return ippsConj_32fc_I(p_src, len);
}
