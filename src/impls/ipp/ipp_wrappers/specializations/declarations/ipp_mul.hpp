//
// Created by userk on 5/8/25.
//

#pragma once


namespace ipp::wrappers {


/// inplace float
template<>
IppStatus multiply_with_scalar_inplace(std::span<float> src_dst, float val, int src_size);


/// inplace complex float
template<>
IppStatus multiply_with_scalar_inplace<std::complex<float>>(std::span<std::complex<float>> src_dst,
                                       std::complex<float> val, int src_size);


/// float
template<>
IppStatus multiply_with_scalar<float>(std::span<const float> src, float val, std::span<float> dst, int size);


/// complex float
template<>
IppStatus multiply_with_scalar<std::complex<float>>(std::span<const std::complex<float>> src,
                               std::complex<float> val,
                               std::span<std::complex<float>> dst, int size);

}  // namespace ipp::wrappers
