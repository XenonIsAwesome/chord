//
// Created by userk on 5/12/25.
//

#pragma once


/**
*
* DivC
Divides each element of a vector by a constant value.
* i for in place


Divides the elements of two vectors.
* ippsDiv_32f   = Not-in-place operations on floating point data.
* ippsDiv_32f_I =     In-place operations on floating point data.
*
Div A
Divides each element of the first vector by
corresponding element of the second vector.
*/

namespace ipp::wrappers {

/// float
template<>
IppStatus
divide_by_scalar<float>(std::span<const float> src, float divider, std::span<float> dst, int len);


/// complex float
template<>
IppStatus divide_by_scalar<std::complex<float>>(std::span<const std::complex<float>> src,
                                                std::complex<float> divider,
                                                std::span<std::complex<float>> dst,
                                                int len);


/// inplace float
template<>
IppStatus divide_by_scalar_inplace<float>(std::span<float> src_dst, float divider, int len);


/// inplace complex float
template<>
IppStatus divide_by_scalar_inplace<std::complex<float>>(std::span<std::complex<float>> src_dst,
                                                        std::complex<float> divider,
                                                        int len);

/// complex float
template<>
IppStatus
divide_list_by_list_inplace<std::complex<float>>(std::span<const std::complex<float>> src1,
                                                 std::span<std::complex<float>> src2,
                                                 int len);


/// float
template<>
IppStatus
divide_list_by_list_inplace<float>(std::span<const float> src1, std::span<float> src2, int len);


/// complex float
template<>
IppStatus divide_list_by_list(std::span<const std::complex<float>> src1,
                              std::span<const std::complex<float>> src2,
                              std::span<std::complex<float>> dst,
                              int len);

}  // namespace ipp::wrappers
