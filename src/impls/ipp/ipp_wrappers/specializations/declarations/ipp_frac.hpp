//
// Created by userk on 6/9/25.
//

#pragma once

namespace ipp::wrappers {

/// float
template<>
IppStatus compute_fractional_part(std::span<const float> src, std::span<float> dst, int len);


/// double
template<>
IppStatus compute_fractional_part(std::span<const double> src, std::span<double> dst, int len);


}


