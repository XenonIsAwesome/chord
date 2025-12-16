//
// Created by userk on 6/10/25.
//

#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"

template<>
IppStatus ipp::wrappers::compute_dot_product<float>(std::span<float> src1,
                                                    std::span<float> src2,
                                                    float& dst,
                                                    int len) {
    auto p_dst = types::cast_to_ipp(&dst);
    return ippsDotProd_32f(src1.data(), src2.data(), len, p_dst);
}



template<>
IppStatus
ipp::wrappers::compute_complex_dot_product<float>(std::span<float> src,
                                                  std::span<std::complex<float>> src_complex,
                                                  std::complex<float>& dst,
                                                  int len) {
    Ipp32fc* p_dst = types::cast_to_ipp(&dst);
    Ipp32fc* p_src_complex = types::cast_to_ipp(src_complex.data());

    return ippsDotProd_32f32fc(src.data(), p_src_complex, len, p_dst);
}
