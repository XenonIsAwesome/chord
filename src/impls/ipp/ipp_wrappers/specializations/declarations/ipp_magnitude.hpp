//
// Created by userk on 5/14/25.
//

#pragma once


namespace ipp::wrappers {

template<>
IppStatus compute_complex_magnitude<float>(std::span<const std::complex<float>> src,
                                           std::span<float> dst,
                                           int len);


/// double
template<>
IppStatus compute_complex_magnitude<double>(std::span<const std::complex<double>> src,
                                            std::span<double> dst,
                                            int len);


/// float
template<>
IppStatus compute_real_imag_magnitude<float>(std::span<const float> src_real,
                                             std::span<const float> src_img,
                                             std::span<float> dst,
                                             int len);


/// double
template<>
IppStatus compute_real_imag_magnitude<double>(std::span<const double> src_real,
                                              std::span<const double> src_img,
                                              std::span<double> dst,
                                              int len);
}  // namespace ipp::wrappers
