//
// Created by userk on 6/11/25.
//

#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"

namespace ipp::wrappers {
template<>
IppStatus generate_tone<std::complex<float>, float>(std::span<std::complex<float>> res,
                                                    float magn,
                                                    float freq,
                                                    float& phase,
                                                    int len,
                                                    chord::AlgoChoice algo) {
    Ipp32fc* p_res = types::cast_to_ipp(res.data());
    Ipp32f* p_phase = types::cast_to_ipp(&phase);

    return ippsTone_32fc(p_res,
                         len,
                         magn,
                         freq,
                         p_phase,
                         types::cast_to_ipp(algo));
}
}  // namespace ipp::wrappers
