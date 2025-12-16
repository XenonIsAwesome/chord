//
// Created by userk on 6/11/25.
//

#pragma once


namespace ipp::wrappers {

/// complex float
template<>
IppStatus
generate_FFT_sizes<std::complex<float>>(int order, int flag, chord::WorkBufferSizes& sizes_to_update);

}  // namespace ipp::wrappers
