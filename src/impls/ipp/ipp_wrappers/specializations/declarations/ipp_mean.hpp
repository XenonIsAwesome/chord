//
// Created by userk on 6/10/25.
//

#pragma once

#include <chord_structs.hpp>

namespace ipp::wrappers {

/// float
template<>
IppStatus
compute_mean_value<float>(std::span<const float> src, float& mean, chord::AlgoChoice algo, int len);

}
