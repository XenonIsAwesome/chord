//
// Created by userk on 6/11/25.
//

#pragma once

namespace ipp::wrappers {

/// float 24a
template<>
IppStatus
compute_complex_exponent<float>(std::span<const float> src, std::span<std::complex<float>> dst, int len);

}
