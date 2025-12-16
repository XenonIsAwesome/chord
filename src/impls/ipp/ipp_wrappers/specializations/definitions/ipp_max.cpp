//
// Created by userk on 6/10/25.
//

#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"

#include <iostream>


template<>
IppStatus ipp::wrappers::find_maximum(std::span<double> src, double& max, int len) {
    return ippsMax_64f(src.data(), len, &max);
}


template<>
IppStatus ipp::wrappers::find_maximum(std::span<float> src, float& max, int len) {
    return ippsMax_32f(src.data(), len, &max);
}


template<>
IppStatus ipp::wrappers::find_maximum_index(std::span<const float> src, float& max, int& index, int len) {
    return ippsMaxIndx_32f(src.data(), len, &max, &index);
}
