//
// Created by userk on 5/11/25.
//

#pragma once



namespace ipp::wrappers {

/// float
template<>
IppStatus integer_fraction_split(std::span<const float> src,
                                 std::span<float> dst_int,
                                 std::span<float> dst_frac,
                                 int len);


}  // namespace ipp::wrappers
