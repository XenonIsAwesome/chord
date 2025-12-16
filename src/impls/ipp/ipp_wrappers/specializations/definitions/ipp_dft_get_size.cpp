//
// Created by userk on 6/11/25.
//


#include "ipp/ipp_wrappers/ipp_wrappers.hpp"

template<>
IppStatus
ipp::wrappers::generate_DFT_sizes<std::complex<float>>(int len,
                                                       int flag,
                                                       chord::WorkBufferSizes& sizes_to_update) {
    return ippsDFTGetSize_C_32fc(len,
                                 flag,
                                 ippAlgHintNone,
                                 &sizes_to_update.size_spec,
                                 &sizes_to_update.size_init,
                                 &sizes_to_update.size_buffer);
}
