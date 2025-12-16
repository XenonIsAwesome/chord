//
// Created by userk on 5/12/25.
//

#pragma once

#ifdef INTEL_PRESENT
#if __has_include(<ipp/ippversion.h>)
#include <ipp/ipp.h>
#elif __has_include(<ippversion.h>)
#    include <ipp.h>
#else
#    error "IPP Version not supported"
#endif
#endif


namespace chord {

/**
 * All the statuses that can be returned after calling a function from library.
 */
enum class Status {
    Ok,
    Warning,
    InvalidParamter,
    MemoryError,
    CpuNotSupported,
    RegExpError,
    NotImplemented,
    Unknown,
    OutOfRange
};


/**
 * Algorithem type for calculations.
 */
enum class AlgoType : int {
    Auto = 0x00000000,
    Direct = 0x00000001,
    FFT = 0x00000002,
    Mask = 0x000000FF,
};


/**
 * The enumeration defines the type of code to be used in some operations:
 *    1. Basic -> no prefrence to speed or accuracy.
 *    2. Faster -> faster but less accurate.
 *    3. Accurate -> more accurate but slower.
 */
enum class AlgoChoice { Basic, Faster, Accurate };


/**
 * Sizes used for FFT / DFT calculations.
 */
struct WorkBufferSizes {
    int size_spec;  // FFT specification structure size value
    int size_init;  // Buffer size value for FFT initialization function
    int size_buffer;  // size value of the FFT external work buffer
};


}  // namespace chord
