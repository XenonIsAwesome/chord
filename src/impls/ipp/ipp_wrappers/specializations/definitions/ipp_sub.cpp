//
// Created by userk on 5/12/25.
//

#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"
// src_minuend
template<>
IppStatus ipp::wrappers::substract_by_list<float>(std::span<float> src_minuend,
                                                  std::span<float> src_subtrahend,
                                                  std::span<float> dst,
                                                  int len) {
    return ippsSub_32f(src_subtrahend.data(), src_minuend.data(), dst.data(), len);
}


template<>
IppStatus ipp::wrappers::substract_by_list<double>(std::span<double> src_minuend,
                                                   std::span<double> src_subtrahend,
                                                   std::span<double> dst,
                                                   int len) {
    return ippsSub_64f(src_subtrahend.data(), src_minuend.data(), dst.data(), len);
}


template<>
IppStatus
ipp::wrappers::substract_by_list<std::complex<float>>(std::span<std::complex<float>> src_minuend,
                                                      std::span<std::complex<float>> src_subtrahend,
                                                      std::span<std::complex<float>> dst,
                                                      int len) {
    Ipp32fc* p_src_minuend = types::cast_to_ipp(src_minuend.data());
    Ipp32fc* p_src_subtrahend = types::cast_to_ipp(src_subtrahend.data());
    Ipp32fc* p_dst = types::cast_to_ipp(dst.data());

    return ippsSub_32fc(p_src_subtrahend, p_src_minuend, p_dst, len);
}


template<>
IppStatus ipp::wrappers::substract_by_list<std::complex<double>>(
    std::span<std::complex<double>> src_minuend,
    std::span<std::complex<double>> src_subtrahend,
    std::span<std::complex<double>> dst,
    int len) {
    Ipp64fc* p_src_minuend = types::cast_to_ipp(src_minuend.data());
    Ipp64fc* p_src_subtrahend = types::cast_to_ipp(src_subtrahend.data());
    Ipp64fc* p_dst = types::cast_to_ipp(dst.data());

    return ippsSub_64fc(p_src_subtrahend, p_src_minuend, p_dst, len);
}


template<>
IppStatus ipp::wrappers::substract_by_list_inplace<float>(std::span<float> src_minuend_dst,
                                                          std::span<const float> src_subtrahend,
                                                          int len) {
    return ippsSub_32f_I(src_subtrahend.data(), src_minuend_dst.data(), len);
}


template<>
IppStatus ipp::wrappers::substract_by_list_inplace<double>(std::span<double> src_minuend_dst,
                                                           std::span<const double> src_subtrahend,
                                                           int len) {

    return ippsSub_64f_I(src_subtrahend.data(), src_minuend_dst.data(), len);
}


template<>
IppStatus ipp::wrappers::substract_by_list_inplace<std::complex<float>>(
std::span<std::complex<float>> src_minuend_dst,
                                std::span<const std::complex<float>> src_subtrahend,
                                int len) {
    Ipp32fc* p_src_minuend = types::cast_to_ipp(src_minuend_dst.data());
    const Ipp32fc* p_src_subtrahend = types::cast_to_ipp(src_subtrahend.data());

    return ippsSub_32fc_I(p_src_subtrahend, p_src_minuend, len);
}


template<>
IppStatus ipp::wrappers::substract_by_list_inplace<std::complex<double>>(
    std::span<std::complex<double>> src_minuend_dst,
    std::span<const std::complex<double>> src_subtrahend,
    int len) {
    Ipp64fc* p_src_minuend = types::cast_to_ipp(src_minuend_dst.data());
    const Ipp64fc* p_src_subtrahend = types::cast_to_ipp(src_subtrahend.data());

    return ippsSub_64fc_I(p_src_subtrahend, p_src_minuend, len);
}
