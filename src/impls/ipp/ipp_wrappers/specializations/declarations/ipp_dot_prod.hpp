//
// Created by userk on 6/10/25.
//

#pragma once

namespace ipp::wrappers {

/// float
template<>
IppStatus compute_complex_dot_product<float>(std::span<float> src,
                                             std::span<std::complex<float>> src_complex,
                                             std::complex<float>& dst,
                                             int len);


/// float
template<>
IppStatus
compute_dot_product<float>(std::span<float> src1, std::span<float> src2, float& dst, int len);


}  // namespace ipp::wrappers
