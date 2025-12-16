//
// Created by userk on 5/11/25.
//

#pragma once


namespace ipp::wrappers {


/// float
template<>
IppStatus apply_floor<float>(std::span<const float> src, std::span<float> dst, int len);

/// double
template<>
IppStatus apply_floor<double>(std::span<const double> src, std::span<double> dst, int len);


}

