//
// Created by userk on 6/10/25.
//

#pragma once


namespace ipp::wrappers {

/// float
template<>
IppStatus find_maximum<float>(std::span<float> src, float& max, int len);

/// double
template<>
IppStatus find_maximum<double>(std::span<double> src, double& max, int len);

/// float
template<>
IppStatus find_maximum_index<float>(std::span<const float> src, float& max, int& index, int len);

}


