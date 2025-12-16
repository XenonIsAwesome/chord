//
// Created by userk on 5/12/25.
//


#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"


template<>
IppStatus ipp::wrappers::divide_by_scalar<float>(std::span<const float> src,
                                                 float divider,
                                                 std::span<float> dst,
                                                 int len) {
    return ippsDivC_32f(src.data(), divider, dst.data(), len);
}


template<>
IppStatus
ipp::wrappers::divide_by_scalar<std::complex<float>>(std::span<const std::complex<float>> src,
                                                     std::complex<float> divider,
                                                     std::span<std::complex<float>> dst,
                                                     int len) {
    Ipp32fc p_divider = types::cast_to_ipp(divider);

    const Ipp32fc* p_src = types::cast_to_ipp(src.data());
    Ipp32fc* p_dst = types::cast_to_ipp(dst.data());

    return ippsDivC_32fc(p_src, p_divider, p_dst, len);
}


template<>
IppStatus
ipp::wrappers::divide_by_scalar_inplace<float>(std::span<float> src_dst, float divider, int len) {
    return ippsDivC_32f_I(divider, src_dst.data(), len);
}


template<>
IppStatus
ipp::wrappers::divide_by_scalar_inplace<std::complex<float>>(std::span<std::complex<float>> src_dst,
                                                             std::complex<float> divider,
                                                             int len) {
    Ipp32fc p_divider = types::cast_to_ipp(divider);
    Ipp32fc* p_src = types::cast_to_ipp(src_dst.data());

    // types::cast_to_ipp(src_dst, p_src);

    return ippsDivC_32fc_I(p_divider, p_src, len);
}


template<>
IppStatus ipp::wrappers::divide_list_by_list_inplace<std::complex<float>>(
    std::span<const std::complex<float>> src1,
    std::span<std::complex<float>> src2,
    int len) {
    const Ipp32fc* p_src1 = types::cast_to_ipp(src1.data());
    Ipp32fc* p_src2 = types::cast_to_ipp(src2.data());

    return ippsDiv_32fc_I(p_src1, p_src2, len);
}


template<>
IppStatus ipp::wrappers::divide_list_by_list_inplace<float>(std::span<const float> src1,
                                                            std::span<float> src2,
                                                            int len) {
    const Ipp32f* p_src1 = ipp::types::cast_to_ipp(src1.data());
    Ipp32f* p_src2 = ipp::types::cast_to_ipp(src2.data());

    return ippsDiv_32f_I(p_src1, p_src2, len);
}


template<>
IppStatus ipp::wrappers::divide_list_by_list(std::span<const std::complex<float>> src1,
                                             std::span<const std::complex<float>> src2,
                                             std::span<std::complex<float>> dst,
                                             int len) {
    const Ipp32fc* p_src1 = types::cast_to_ipp(src1.data());
    const Ipp32fc* p_src2 = types::cast_to_ipp(src2.data());
    Ipp32fc* p_dst = types::cast_to_ipp(dst.data());

    return ippsDiv_32fc(p_src1, p_src2, p_dst, len);
}
