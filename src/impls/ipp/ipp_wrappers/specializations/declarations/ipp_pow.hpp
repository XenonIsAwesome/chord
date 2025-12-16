//
// Created by userk on 6/11/25.
//

#pragma once

namespace ipp::wrappers {

/// float
template<>
IppStatus apply_raise_power_with_scalar<float>(std::span<const float> bases,
                                               float scalar,
                                               std::span<float> res,
                                               int len);


/// float
template<>
IppStatus apply_raise_power(std::span<float> bases,
                            std::span<float> expos,
                            std::span<float> res,
                            int len);

}  // namespace ipp::wrappers
