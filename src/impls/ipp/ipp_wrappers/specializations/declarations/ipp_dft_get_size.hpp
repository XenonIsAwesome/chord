//
// Created by userk on 6/11/25.
//

#pragma once


namespace ipp::wrappers {

/// float
template<>
IppStatus generate_DFT_sizes<std::complex<float>>(int len, int flag, chord::WorkBufferSizes& sizes_to_update);

}
