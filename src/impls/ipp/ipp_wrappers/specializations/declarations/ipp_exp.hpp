//
// Created by userk on 5/7/25.
//

#pragma once


namespace ipp::wrappers {

/// complex float
template<>
IppStatus compute_exponential<std::complex<float>>(std::span<const std::complex<float>> src,
                                       std::span<std::complex<float>> dst, int size);


/// float
template<>
IppStatus compute_exponential<float>(std::span<const float> src,
                                       std::span<float> dst, int size);

}