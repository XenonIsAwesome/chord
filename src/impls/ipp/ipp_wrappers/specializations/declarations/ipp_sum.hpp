//
// Created by userk on 5/14/25.
//

#pragma once


namespace ipp::wrappers {

/// float
template<>
IppStatus compute_sum<float>(std::span<const float> src, float& sum, chord::AlgoChoice algo, int len);

/// complex float
template<>
IppStatus compute_sum<std::complex<float>>(std::span<const std::complex<float>> src,
                                           std::complex<float>& sum,
                                           chord::AlgoChoice algo,
                                           int len);

/// int
template<>
IppStatus compute_sum<int>(std::span<const int> src, int& sum, chord::AlgoChoice algo, int len);

/// unsigned short
// template<>
// IppStatus compute_sum<u_short>(std::span<u_short> src, u_short& sum, chord::AlgoChoice algo, int
// len);

}  // namespace ipp::wrappers
