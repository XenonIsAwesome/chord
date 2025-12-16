//
// Created by mayak on 7/2/25.
//

#pragma once


namespace ipp::wrappers {

template<>
IppStatus apply_absolute<float>(std::span<const float> src, std::span<float> dst, int len);


template<>
IppStatus apply_absolute<double>(std::span<const double> src, std::span<double> dst, int len);


template<>
IppStatus apply_absolute_inplace<float>(std::span<float> src_dst, int len);


template<>
IppStatus apply_absolute_inplace<double>(std::span<double> src_dst, int len);

}  // namespace ipp::wrappers
