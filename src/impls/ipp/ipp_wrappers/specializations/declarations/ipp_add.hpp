//
// Created by userk on 5/14/25.
//

#pragma once


#include <complex>
#include <span>


namespace ipp::wrappers {

/// float
template<>
IppStatus combine<float>(std::span<const float> src1,
                         std::span<const float> src2,
                         std::span<float> dst,
                         int len);


/// complex float
template<>
IppStatus combine<std::complex<float>>(std::span<const std::complex<float>> src1,
                                       std::span<const std::complex<float>> src2,
                                       std::span<std::complex<float>> dst,
                                       int len);


/// float inplace
template<>
IppStatus combine_inplace<float>(std::span<const float> src, std::span<float> src_dst, int len);


/// complex float inplace
template<>
IppStatus combine_inplace<std::complex<float>>(std::span<const std::complex<float>> src,
                                               std::span<std::complex<float>> src_dst,
                                               int len);


// =================================================================================================
//   WITH SCALAR
// -------------------------------------------------------------------------------------------------
/// float
template<>
IppStatus
combine_with_scalar<float>(std::span<const float> src, float scalar, std::span<float> dst, int len);


/// complex float
template<>
IppStatus combine_with_scalar<std::complex<float>>(std::span<const std::complex<float>> src,
                                                   std::complex<float> scalar,
                                                   std::span<std::complex<float>> dst,
                                                   int len);


/// float inplace
template<>
IppStatus combine_with_scalar_inplace<float>(std::span<float> src_dst, float scalar, int len);


/// complex float inplace
template<>
IppStatus combine_with_scalar_inplace<std::complex<float>>(std::span<std::complex<float>> src_dst,
                                                           std::complex<float> scalar,
                                                           int len);

}  // namespace ipp::wrappers
