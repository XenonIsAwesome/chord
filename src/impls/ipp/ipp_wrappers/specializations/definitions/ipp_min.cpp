//
// Created by userk on 6/9/25.
//

#include "ipp/cast_to_ipp/cast_to_ipp.hpp"
#include "ipp/ipp_wrappers/ipp_wrappers.hpp"

#include <iostream>


template<>
IppStatus ipp::wrappers::find_minimum(std::span<const double> src, double& min, int len) {
    return ippsMin_64f(src.data(), len, &min);
}


template<>
IppStatus ipp::wrappers::find_minimum(std::span<const float> src, float& min, int len) {
    return ippsMin_32f(src.data(), len, &min);
}


template<>
IppStatus ipp::wrappers::find_minimum_index(std::span<const float> src, float& min, int& index, int len) {
    return ippsMinIndx_32f(src.data(), len, &min, &index);
}


template<>
IppStatus ipp::wrappers::find_minimum_index(std::span<const double> src, double& min, int& index, int len) {
    return ippsMinIndx_64f(src.data(), len, &min, &index);
}
