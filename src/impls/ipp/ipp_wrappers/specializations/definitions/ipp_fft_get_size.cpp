//
// Created by userk on 6/11/25.
//


#include "ipp/ipp_wrappers/ipp_wrappers.hpp"


template<>
IppStatus ipp::wrappers::generate_FFT_sizes<std::complex<float>>(int order,
                                                                 int flag,
                                                                 chord::WorkBufferSizes& sizes_to_update) {
    return ippsFFTGetSize_C_32fc(order,
                                 flag,
                                 ippAlgHintNone,
                                 &sizes_to_update.size_spec,
                                 &sizes_to_update.size_init,
                                 &sizes_to_update.size_buffer);
}
