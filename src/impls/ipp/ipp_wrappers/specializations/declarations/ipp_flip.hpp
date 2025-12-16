//
// Created by userk on 5/14/25.
//

#pragma once


namespace ipp::wrappers {

/// float
template<>
IppStatus apply_flip(std::span<const float> src, std::span<float> dst, int len);


/// complex float
template<>
IppStatus
apply_flip(std::span<const std::complex<float>> src, std::span<std::complex<float>> dst, int len);


/// float
template<>
IppStatus apply_flip_inplace(std::span<float> src, int len);


/// complex float
template<>
IppStatus apply_flip_inplace(std::span<std::complex<float>> src, int len);

}

