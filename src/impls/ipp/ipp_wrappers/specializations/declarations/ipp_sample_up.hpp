//
// Created by userk on 5/11/25.
//

#pragma once


namespace ipp::wrappers {

/// float
template<>
IppStatus compute_up_sample(std::span<const float> src,
                            int src_size,
                            int factor,
                            int* phase,
                            std::span<float> dst,
                            int* dst_size);


/// complex float
template<>
IppStatus compute_up_sample(std::span<const std::complex<float>> src,
                            int src_size,
                            int factor,
                            int* phase,
                            std::span<std::complex<float>> dst,
                            int* dst_size);


/// double
template<>
IppStatus compute_up_sample(std::span<const double> src,
                            int src_size,
                            int factor,
                            int* phase,
                            std::span<double> dst,
                            int* dst_size);

}  // namespace ipp::wrappers