//
// Created by userk on 6/11/25.
//


#include "ipp/ipp_wrappers/ipp_wrappers.hpp"


template<>
IppStatus ipp::wrappers::apply_raise_power<float>(std::span<float> bases,
                                                  std::span<float> expos,
                                                  std::span<float> res,
                                                  int len) {
    return ippsPow_32f_A24(bases.data(), expos.data(), res.data(), len);
}


template<>
IppStatus ipp::wrappers::apply_raise_power_with_scalar<float>(std::span<const float> bases,
                                                              float scalar,
                                                              std::span<float> res,
                                                              int len) {
    return ippsPowx_32f_A24(bases.data(), scalar, res.data(), len);
}

