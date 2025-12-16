//
// Created by userk on 6/9/25.
//

#pragma once

namespace ipp::wrappers {

/// float
template<>
IppStatus compute_complex_conjugates_inplace<float>(std::span<std::complex<float>> src, int len);


/// float
template<>
IppStatus compute_complex_conjugates(std::span<std::complex<float>> src,
                                     std::span<std::complex<float>> dst,
                                     int len);


/// double
template<>
IppStatus compute_complex_conjugates_inplace<double>(std::span<std::complex<double>> src, int len);


/// double
template<>
IppStatus compute_complex_conjugates<double>(std::span<std::complex<double>> src,
                                             std::span<std::complex<double>> dst,
                                             int len);

}  // namespace ipp::wrappers
