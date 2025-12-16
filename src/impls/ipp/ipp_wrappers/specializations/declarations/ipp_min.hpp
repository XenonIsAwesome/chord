//
// Created by userk on 6/9/25.
//

#pragma once

namespace ipp::wrappers {

/// float
template<>
IppStatus find_minimum<float>(std::span<const float> src, float& min, int len);

/// double
template<>
IppStatus find_minimum<double>(std::span<const double> src, double& min, int len);

/// float
template<>
IppStatus find_minimum_index<float>(std::span<const float> src, float& min, int& index, int len);


/// double
template<>
IppStatus find_minimum_index<double>(std::span<const double> src, double& min, int& index, int len);

}

