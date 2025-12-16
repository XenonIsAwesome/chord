//
// Created by userk on 5/19/25.
//

#pragma once


namespace ipp::wrappers {

/// double
template<>
IppStatus fill_slope<double>(std::span<double> dst, double offset, double slope, int len);


/// float
template<>
IppStatus fill_slope<float>(std::span<float> dst, float offset, float slope, int len);

}
