//
// Created by userk on 5/5/25.
//

#pragma once

#include <chord/chord_structs.hpp>
#include <complex>  // this is for the types in .inl file

namespace ipp::types {

inline IppHintAlgorithm cast_to_ipp(chord::AlgoChoice algo) {
    if (algo == chord::AlgoChoice::Faster) {
        return ippAlgHintFast;
    }
    if (algo == chord::AlgoChoice::Accurate) {
        return ippAlgHintAccurate;
    }
    return ippAlgHintNone;
}

#define X(FromType, ToType)                                 \
    inline ToType cast_to_ipp(const FromType& val) {        \
        return *reinterpret_cast<const ToType*>(&val);      \
    }                                                       \
    inline ToType* cast_to_ipp(FromType* ptr) {             \
        return reinterpret_cast<ToType*>(ptr);              \
    }                                                       \
    inline const ToType* cast_to_ipp(const FromType* ptr) { \
        return reinterpret_cast<const ToType*>(ptr);        \
    }

#include "mapping_types.inl"
#undef X


}  // namespace ipp::types
