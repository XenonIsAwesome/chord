//
// Created by userk on 5/8/25.
//


#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"

namespace ipp::wrappers {

template<>
IppStatus multiply_with_scalar_inplace<float>(std::span<float> src_dst, float val, int src_size) {
    return ippsMulC_32f_I(val, src_dst.data(), src_size);
}


template<>
IppStatus multiply_with_scalar_inplace<std::complex<float>>(std::span<std::complex<float>> src_dst,
                                                            std::complex<float> val,
                                                            int src_size) {
    Ipp32fc* p_src_dst = types::cast_to_ipp(src_dst.data());

    Ipp32fc complex_val = types::cast_to_ipp(val);

    return ippsMulC_32fc_I(complex_val, p_src_dst, src_size);
}


template<>
IppStatus
multiply_with_scalar<float>(std::span<const float> src, float val, std::span<float> dst, int size) {
    return ippsMulC_32f(src.data(), val, dst.data(), size);
}


template<>
IppStatus multiply_with_scalar<std::complex<float>>(std::span<const std::complex<float>> src,
                                                    std::complex<float> val,
                                                    std::span<std::complex<float>> dst,
                                                    int size) {
    const Ipp32fc* p_src = types::cast_to_ipp(src.data());
    Ipp32fc* p_dst = types::cast_to_ipp(dst.data());

    // Ipp32fc complex_val = types::cast_to_ipp(val);
    const Ipp32fc* complex_val = types::cast_to_ipp(&val);

    return ippsMulC_32fc(p_src, *complex_val, p_dst, size);
}

}  // namespace ipp::wrappers
