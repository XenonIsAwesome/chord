//
// Created by userk on 5/4/25.
//

#pragma once

#include <chord_structs.hpp>
#include <complex>
#include <iostream>

#ifdef INTEL_PRESENT
#if __has_include(<ipp/ippversion.h>)
#include <ipp/ipp.h>
#elif __has_include(<ippversion.h>)
#    include <ipp.h>
#else
#    error "IPP Version not supported"
#endif
#endif

#include <span>


namespace ipp::wrappers {

/**
 * Multiplies each element of a vector by a constant value, places results in src_dst.
 *
 * @tparam T float / complex float
 *
 * @param src_dst src sequence, which will be replaced with the result elements.
 * @param val value to multiply the elements with.
 * @param src_size number of elements in src.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the pSrc, pDst, or pSrcDst pointer is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than, or equal to 0.
 */
template<typename T>
IppStatus multiply_with_scalar_inplace(std::span<T> src_dst, T val, int src_size) = delete;


/**
 * Multiplies each element of a vector by a constant value.
 *
 * @tparam T float / complex float.
 *
 * @param src source sequence.
 * @param val value to multiply the elements with.
 * @param dst destination sequence where result elements will be placed.
 * @param size number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the pSrc, pDst, or pSrcDst pointer is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than, or equal to 0.
 */
template<typename T>
IppStatus multiply_with_scalar(std::span<const T> src, T val, std::span<T> dst, int size) = delete;


/**
 * Computes e to the power of each element of a vector.
 *
 * @tparam T complex float / float
 *
 * @param src source sequence.
 * @param dst destination sequence where result elements will be placed.
 * @param size number of elements.
 *
 * @return IppStatus schronized
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when pSrc or pDst pointer is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 * - ippStsOverflow: In real functions, indicates a warning that the function overflows, that is, at
 *                   least one of elements of pSrc is greater than Ln(FPMAX), where FPMAX is the
 *                   maximum representable floating-point number.
 * - ippStsUnderflow: In real functions, indicates a warning that the function underflows, that is,
 *                    at least one of elements of pSrc is less than Ln(FPMIN) , where FPMIN is the
 *                    minimum positive floating point value.
 */
template<typename T>
IppStatus compute_exponential(std::span<const T> src, std::span<T> dst, int size) = delete;


/**
 * Up-samples a signal, conceptually increasing its sampling rate by an integer factor.
 *
 * @tparam T float / double / complex float
 *
 * @param src Source sequence (the signal to be up-sampled).
 * @param src_size Number of samples in the source array.
 * @param dst Destination sequence where result elements will be placed.
 * @param factor Factor by which the signal is up-sampled. That is, factor -1 zeros are inserted
 *               after each sample of the source src.
 * @param phase Pointer to the phase of an source array sample,\n
 *              which determines where each sample from src lies within each output block of factor
 *              samples in dst. The value of phase is required to be in the range [0; factor -1].\n
 *              It is also a returned output phase which can be used as an input phase for the first
 *              sample in the next block to process.
 * @param dst_size Pointer to the length of the destination sequence.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error if the dst, src, dst_len, or phase pointer is NULL .
 * - ippStsSizeErr: Indicates an error if srcLen is less than or equal to 0.
 * - ippStsSampleFactorErr: Indicates an error if factor is less than or equal to 0.
 * - ippStsSamplePhaseErr: Indicates an error when pPhase is negative, or bigger than or equal to
 *                         factor.
 */
template<typename T>
IppStatus compute_up_sample(std::span<const T> src,
                            int src_size,
                            int factor,
                            int* phase,
                            std::span<T> dst,
                            int* dst_size) = delete;


/**
 * Computes truncated integer value and remaining fraction part for each element.
 *
 * @tparam T float
 *
 * @param src Source sequence.
 * @param dst_int Integer part sequence.
 * @param dst_frac Remainder part sequence.
 * @param len Number of elements in src.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when src or dst_int or dst_frac pointer is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus integer_fraction_split(std::span<const T> src,
                                 std::span<T> dst_int,
                                 std::span<T> dst_frac,
                                 int len) = delete;


/**
 * Computes a signed fractional part for each element.
 *
 * @tparam T float / double
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when src or dst pointer is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus compute_fractional_part(std::span<const T> src, std::span<T> dst, int len) = delete;


/**
 * Divides each element of a vector by a constant value.
 *
 * @tparam T float / complex float
 *
 * @param src Source sequence.
 * @param divider Scalar value used as a divisor.
 * @param dst Destination sequence.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the pSrc , pDst , or pSrcDst pointer is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 * - ippStsDivByZeroErr: Indicates an error when val is equal to 0.
 */
template<typename T>
IppStatus divide_by_scalar(std::span<const T> src, T divider, std::span<T> dst, int len) = delete;


/**
 * Divides each element of a vector by a constant value, and places result in src.
 *
 * @tparam T float / complex float
 *
 * @param src_dst Source sequence, which result will be put in.
 * @param divider Scalar value used as a divisor.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the pSrc , pDst , or pSrcDst pointer is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 * - ippStsDivByZeroErr: Indicates an error when val is equal to 0.
 */
template<typename T>
IppStatus divide_by_scalar_inplace(std::span<T> src_dst, T divider, int len) = delete;


/**
 * @brief Divides the elements of two vectors accordingly, and places result in src1.
 *
 * Formula:
 * src1[i] = src1[i] / src2[i]
 *
 * @tparam T complex float
 *
 * @param src1 Source sequence, values which will be divided from. Later results will be placed
 * here.
 * @param src2 Source sequence, values which will be used as divisors.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when one of the given pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 * - ippStsDivByZeroErr: Indicates an error when val is equal to 0.
 */
template<typename T>
IppStatus divide_list_by_list_inplace(std::span<const T> src1, std::span<T> src2, int len) = delete;


/**
 * @brief Divides the elements of two vectors accordingly.
 *
 * Formula:
 * dst[i] = src1[i] / src2[i]
 *
 * @tparam T complex float
 * @param src1 Source sequence, values which will be divided from.
 * @param src2 Source sequence, values which will be used as divisors.
 * @param dst Destination sequnce, results will be put here.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when one of the given pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 * - ippStsDivByZeroErr: Indicates an error when val is equal to 0.
 */
template<typename T>
IppStatus divide_list_by_list(std::span<const T> src1,
                              std::span<const T> src2,
                              std::span<T> dst,
                              int len) = delete;


/**
 * Subtracts the elements of two vectors.
 *
 * @tparam T float / double / complex float / complex double
 *
 * @param src_minuend Source sequence, from whose elements the elements of src_subtrahend are to be
 * subtracted.
 * @param src_subtrahend Source sequence, whose elements are to be subtracted.
 * @param dst Destination sequence.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when any of the specified pointers is NULL .
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus substract_by_list(std::span<T> src_minuend,
                            std::span<T> src_subtrahend,
                            std::span<T> dst,
                            int len) = delete;


/**
 * Subtracts the elements of two vectors and places result in src_subtrahend.
 *
 * @tparam T float / double / complex float / complex double
 *
 * @param src_minuend_dst Source sequence, from whose elements the elements of src_subtrahend are to
 * be subtracted.
 * @param src_subtrahend Source sequence, whose elements are to be subtracted.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when any of the specified pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus substract_by_list_inplace(std::span<T> src_minuend_dst,
                                    std::span<const T> src_subtrahend,
                                    int len) = delete;


/**
 * Computes a square of each element of a vector.
 *
 * @tparam T float
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the pSrc , pDst , or pSrcDst pointer is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to zero.
 */
template<typename T>
IppStatus apply_square(std::span<const T> src, std::span<T> dst, int len) = delete;


/**
 * Computes a square of each element of a vector, places result in src.
 *
 * @tparam T float
 *
 * @param src Source sequence.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the pSrc , pDst , or pSrcDst pointer is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to zero.
 */
template<typename T>
IppStatus apply_square_inplace(std::span<T> src, int len) = delete;


/**
 * Reverses the order of elements in a vector.
 *
 * @tparam T float / complex float
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when at least one of the specified pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus apply_flip(std::span<const T> src, std::span<T> dst, int len) = delete;


/**
 * Reverses the order of elements in a vector, and puts result in src.
 *
 * @tparam T float / complex float
 *
 * @param src Source sequence.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when at least one of the specified pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus apply_flip_inplace(std::span<T> src, int len) = delete;


/**
 * Computes absolute values of elements.
 *
 * @tparam T float / double
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the src or dst pointer is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus apply_absolute(std::span<const T> src, std::span<T> dst, int len) = delete;


/**
 * Computes absolute values of elements, and puts results in src.
 *
 * @tparam T float / double
 *
 * @param src_dst Source sequence.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the src_dst pointer is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus apply_absolute_inplace(std::span<T> src_dst, int len) = delete;


/**
 * @brief Computes the magnitudes of complex elements.
 *
 * Formula:
 * magn[ n ] = ( (src[ n ].re)^2 + (src[ n ].im)^2 ) ^ 1/2
 *
 * @tparam T float / double
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when any of the specified pointers is NULL .
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus
compute_complex_magnitude(std::span<const std::complex<T>> src, std::span<T> dst, int len) = delete;


/**
 * @brief Computes the magnitudes of complex elements.
 *
 * Formula:
 * magn [ n ] = ( src_real[ n ]^2 + src_img[ n ]^2 ) ^ 1/2
 *
 * @tparam T float / double
 *
 * @param src_real Source Sequence of the imaginary numbers.
 * @param src_img Source Sequence of the real numbers.
 * @param dst Destination sequence.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when any of the specified pointers is NULL .
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus compute_real_imag_magnitude(std::span<const T> src_real,
                                      std::span<const T> src_img,
                                      std::span<T> dst,
                                      int len) = delete;


/**
 * @brief Creates a slope vector.
 *
 * Fills given dst with slope vector values.
 * Formula: pDst[n] = offset + slope * n , 0 ≤ n < len
 *
 * @tparam T float / double
 *
 * @param dst Destination sequence.
 * @param offset Offset value.
 * @param slope Slope coefficient.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the dst pointer is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus fill_slope(std::span<T> dst, T offset, T slope, int len) = delete;


/**
 * Performs element by element addition of two vectors.
 *
 * @tparam T float / complex float
 *
 * @param src1 First source sequence.
 * @param src2 Second source sequence.
 * @param dst Destination sequence.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when src1, src2 or dst pointer is NULL .
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus combine(std::span<const T> src1, std::span<const T> src2, std::span<T> dst, int len) {
    std::cout << "Called combine<" << typeid(T).name() << ">\n";
    static_assert(sizeof(T) == 0, "TYPE NOT IMPLEMENTED");

    return ippStsErr;
}


/**
 * Performs element by element addition of two vectors, places result in src_dst.
 *
 * @tparam T float / complex float
 *
 * @param src First source sequence.
 * @param src_dst Second source sequence.
 * @param len Number of elements.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when src1, src2 or dst pointer is NULL .
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus combine_inplace(std::span<const T> src, std::span<T> src_dst, int len) = delete;


/**
 * Adds a constant value to each element and places the results in src.
 *
 * @tparam T float / complex float
 *
 * @param src Source sequence.
 * @param scalar Value to be added to all elements in src.
 * @param dst Destination sequence.
 * @param len Number of elements in src.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when one of the specified pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to zero.
 */
template<typename T>
IppStatus combine_with_scalar(std::span<const T> src, T scalar, std::span<T> dst, int len) = delete;


/**
 * Adds a constant value to each element and places the result in src_dst.
 *
 * @tparam T float / complex float
 *
 * @param src_dst Source sequence, where the results later will be put.
 * @param scalar Value to be added to all elements in src_dst.
 * @param len Number of elements in src_dst.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when one of the specified pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to zero.
 */
template<typename T>
IppStatus combine_with_scalar_inplace(std::span<T> src_dst, T scalar, int len) = delete;


/**
 * Computes integer value rounded toward minus infinity for each element.
 *
 * For example:\n
 * src = {-0.883, -0.265, 0.176, 0.752}\n
 * dst = {-1.000, -1.000, 0.000, 0.000}
 *
 * @tparam T float / double
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when one of the specified pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus apply_floor(std::span<const T> src, std::span<T> dst, int len) = delete;


/**
 * Calculates the complex conjugate values of and stores them in src.
 *
 * The complex input     is: z = a + bi \n
 * The complex conjugate is: z = a - bi
 *
 * @tparam T float / double
 *
 * @param src Source sequence of complex numbers, updated to hold the conjugate values.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the pSrc , pDst , or pSrcDst pointer is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus compute_complex_conjugates_inplace(std::span<std::complex<T>> src, int len) = delete;


/**
 * Calculates the complex conjugate values.
 *
 * The complex input     is: z = a + bi \n
 * The complex conjugate is: z = a - bi
 *
 * @tparam T float / double
 *
 * @param src Source sequence of complex values.
 * @param dst Destination sequence of complex conjugate values.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the pointer to src or dst is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus compute_complex_conjugates(std::span<std::complex<T>> src,
                                     std::span<std::complex<T>> dst,
                                     int len) = delete;


/**
 * Finds the minimum value out of all the elements.
 *
 * @tparam T float / double
 *
 * @param src Source sequence.
 * @param min The minimum value found.
 * @param len Number of elements in src.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the pMin or pSrc pointer is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus find_minimum(std::span<const T> src, T& min, int len) = delete;


/**
 * @brief Returns the minimum value and the index of the minimum element.
 *
 * This function returns the minimum value of the input src and stores the result in min.
 * The function also stores the index of the minimum element in index. If there are several equal
 * minimum elements, the first index from the beginning is returned.
 *
 * @tparam T float
 *
 * @param src Source sequence.
 * @param min The minimum value found.
 * @param index Index of the minimum element.
 * @param len Number of elements in src.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the pointer to min or src is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus find_minimum_index(std::span<const T> src, T& min, int& index, int len) = delete;


/**
 * @brief Returns the maximum value of a vector.
 *
 * @tparam T double / float
 *
 * @param src Source sequence.
 * @param max The maximum value found.
 * @param len Number of elements in src.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the pointer to max or src is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus find_maximum(std::span<T> src, T& max, int len) = delete;


/**
 * @brief Returns the maximum value of a vector and the index of the maximum element.
 *
 * This function returns the maximum value of the input src, and stores the result in max.
 * The function returns the index of the maximum element and stores it in index.
 * If there are several equal maximum elements, the first index from the beginning is returned.
 *
 * @tparam T float
 *
 * @param src Source sequence.
 * @param max The maximum value found.
 * @param index Index of the maximum element.
 * @param len Number of elements in src.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when the pointer to max or src is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus find_maximum_index(std::span<const T> src, T& max, int& index, int len) = delete;


/**
 * Computes the dot product of two vectors.
 *
 * Formula: \n
 * 0 <= n <= (len - 1) \n
 * dp = ∑ src[n] * src_complex[n]
 *
 * @tparam T float
 *
 * @param src Source sequence.
 * @param src_complex Source sequence of complex numbers.
 * @param dst Destination sequence
 * @param len Number of elements in the vector.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when one of the given pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus compute_complex_dot_product(std::span<T> src,
                                      std::span<std::complex<T>> src_complex,
                                      std::complex<T>& dst,
                                      int len) = delete;


/**
 * Computes the dot product of two vectors.
 *
 * Formula: \n
 *
 * 0 <= n <= (len - 1) \n
 * dp = ∑ src1[n] * src2[n]
 *
 * @tparam T float
 *
 * @param src1 First source sequence.
 * @param src2 Second source sequence.
 * @param dst Destination sequence
 * @param len Number of elements in the vector.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when one of the given pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus compute_dot_product(std::span<T> src1, std::span<T> src2, T& dst, int len) = delete;


/**
 * Computes the bitwise XOR of two vectors.
 *
 * Formula: dst[i] = src1[i] ⊕ src2[i]
 *
 * src1 = {0xFFFF, 0x0F0F, 0x1234, 0x0000} \n
 * src2 = {0xAAAA, 0XF0F0, 0XFFFF, 0X1234} \n
 * dst  = {0x5555, 0xFFFF, 0xEDCB, 0x1234}
 *
 * @tparam T unsigned short
 *
 * @param src1 First source sequence
 * @param src2 Second source sequence
 * @param dst Destination sequence
 * @param len Number of elements in sources.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when any of the specified pointers is NULL .
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus
compute_xor(std::span<const T> src1, std::span<const T> src2, std::span<T> dst, int len) = delete;


/**
 * Computes the bitwise XOR of two vectors, and places the results in src1.
 *
 * Formula: src1[i] = src1[i] ⊕ src2[i]
 *
 * @tparam T unsigned short
 *
 * @param src1 First source sequence, which will hold the results.
 * @param src2 Second source sequence
 * @param len Number of elements in sources.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when any of the specified pointers is NULL .
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus compute_xor_inplace(std::span<T> src1, std::span<T> src2, int len) = delete;


/**
 * @brief Computes the mean value of a vector.
 *
 * This function computes the mean (average) of the src, and stores the result in mean.
 *
 * The mean of src is defined by the formula:
 * 0 <= n <= len - 1 \n
 * mean = (1 / len) ∑ src[n]
 *
 * @tparam T float
 *
 * @param src Source sequence.
 * @param mean Result average of src.
 * @param algo Algorithm type preffered.
 * @param len Number of elements in the src.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when pSrcDst is NULL .
 * - ippStsSizeErr: Indicates an error when len is less than, or equal to zero.
 */
template<typename T>
IppStatus
compute_mean_value(std::span<const T> src, T& mean, chord::AlgoChoice algo, int len) = delete;


/**
 * @brief Generates a tone with a given frequency, phase and magnitude.
 *
 * This function generates the tone with the specified frequency(freq), phase and magnitude(magn).\n
 * The function computes len samples of the tone, and stores them in res.
 *
 * For real tones, each generated value x[n] is defined as: \n
 * x[n] = magn * cos(2πn * freq + phase)
 *
 * For complex tones, x[n] is defined as: \n
 * x[n] = magn * (cos(2πn * freq + phase) + j * sin(2πn *rFreq + phase))
 *
 * @tparam T samples type
 * @tparam U arguments type
 *
 * @param res Destination sequence which will store the samples.
 * @param magn Magnitude of the tone, that is, the maximum value attained by the wave.
 * @param freq Frequency of the tone relative to the sampling frequency.\n It must be in the
 * interval [0.0, 0.5) for real tone and in [0.0, 1.0) for complex tone.
 * @param phase Pointer to the phase of the tone relative to a cosine wave.\n It must be in range
 * [0.0, 2π). You can use the returned value to compute the next continuous data block.
 * @param len Number of samples to be computed.
 * @param algo Algorithm type preffered.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when one of the given pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than, or equal to zero.
 * - ippStsToneMagnErr: Indicates an error when magn is less than, or equal to zero.
 * - ippStsToneFreqErr: Indicates an error when rFreq is negative, or greater than, or equal to 0.5
 * for real tone and to 1.0 for complex tone.
 * - ippStsTonePhaseErr: Indicates an error when the pPhase value is negative, or greater than or
 * equal to IPP_2PI.
 */
template<typename T, typename U>
IppStatus
generate_tone(std::span<T> res, U magn, U freq, U& phase, int len, chord::AlgoChoice algo) = delete;


/**
 * Computes sizes of the FFT specification structure and required working buffers.
 *
 * @tparam T complex float
 *
 * @param order FFT order. The input signal length is N= 2^order.
 * @param flag Specifies the result normalization method.
 * @param sizes_to_update holds the values of the buffer sizes.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when one of the specified pointers is NULL.
 * - ippStsFftOrderErr: Indicates an error when the order value is incorrect.
 * - ippStsFftFlagErr: Indicates an error when the flag value is incorrect.
 */
template<typename T>
IppStatus generate_FFT_sizes(int order, int flag, chord::WorkBufferSizes& sizes_to_update) = delete;


/**
 * @brief: Computes the sum of the elements of a vector.
 *
 * This function computes the sum of the elements of the src and stores the result in pSum.\n
 * The sum of the elements of src is defined by the formula:
 *
 * 0 <= n <= len -1
 * sum = ∑ src[n]
 *
 * @tparam T float / complex float / int
 *
 * @param src Source sequence.
 * @param sum Sum result.
 * @param algo Algorithm type preffered.
 * @param len Number of elements in the src.
 *
 * @return IppStatus:
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when one of the specified pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 */
template<typename T>
IppStatus compute_sum(std::span<const T> src, T& sum, chord::AlgoChoice algo, int len) = delete;


/**
 * Raises each element of a vector to a constant power.
 *
 * The formula: res[i] = bases[i] ^ scalar
 *
 * @tparam T float
 *
 * @param bases Source sequence, holds the bases.
 * @param scalar Constant value to put the bases to the power of.
 * @param res Destination sequence.
 * @param len Number of elements in the bases.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when one of the specified pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 * - ippStsDomain: In real functions, indicates a warning that the argument is out of the function
 * domain, that is, at least one pair of the elements meets the following condition: element of
 * src is finite, less than 0, and scalar is finite, non-integer.
 * - IppStsSingularity: In real functions, indicates a warning that the argument is the singularity
 * point, that is, at least one pair of the elements is as follows: element of src is equal to 0,
 * and scalar is integer and less than 0.
 */
template<typename T>
IppStatus apply_raise_power_with_scalar(std::span<const T> bases,
                                        T scalar,
                                        std::span<T> res,
                                        int len) = delete;


/**
 * Raises each element of the bases to the power of corresponding element of the exponents(expos).
 *
 * @tparam T float
 *
 * @param bases Source sequence, holds the bases.
 * @param expos Second source sequence, holds the exponents.
 * @param res Destination sequence.
 * @param len Number of elements in the bases.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when one of the specified pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 * - IppStsDomain: In real functions, indicates a warning that the argument is out of the function
 * domain, that is, at least one pair of the source elements meets the following condition: element
 * of bases is finite, less than 0, and element of expos is finite, non-integer.
 * - IppStsSingularity: In real functions, indicates a warning that the argument is the singularity
 * point, that is, at least one pair of the elements is as follows: element of bases is equal to 0,
 * and element of expos is integer and less than 0.
 */
template<typename T>
IppStatus
apply_raise_power(std::span<T> bases, std::span<T> expos, std::span<T> res, int len) = delete;


/**
 * @brief Computes sizes of the DFT work buffer and required working buffers.
 *
 * @tparam T complex float
 *
 * @param len Length of the DFT transform.
 * @param flag Specifies the result normalization method.
 * @param sizes_to_update holds the values of the buffer sizes.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when one of the specified pointers is NULL.
 * - ippStsFftFlagErr: Indicates an error when the flag value is incorrect.
 * - ippStsFftOrderErr: Indicates an error when the memory needed to calculate the len value of the
 * DFT transform exceeds the limit.
 * - ippStsSizeErr: Indicates an error when len is less than, or equal to 0.
 */
template<typename T>
IppStatus generate_DFT_sizes(int len, int flag, chord::WorkBufferSizes& sizes_to_update) = delete;


/**
 * @brief Computes complex exponent of each vector element.
 *
 * @tparam T float
 *
 * @param src Source sequence, angles.
 * @param dst Destination sequence.
 * @param len Number of elements in the vectors.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsNullPtrErr: Indicates an error when one of the specified pointers is NULL.
 * - ippStsSizeErr: Indicates an error when len is less than or equal to 0.
 * - ippStsDomain: Indicates a warning that the argument is out of the function domain, that is, at
 * least one of the src elements is equal to ±INF.
 */
template<typename T>
IppStatus
compute_complex_exponent(std::span<const T> src, std::span<std::complex<T>> dst, int len) = delete;


/**
 * @brief Allocates memory aligned to 64-byte boundary.
 *
 * The value of saved in buffer is a pointer to an aligned memory block. \n
 * If no memory is available in the system, then the value saved is NULL. \n
 * To free this block, use the free function.
 *
 * @tparam T float, unsigned char
 *
 * @param len Number of elements to allocate.
 * @param buffer The allocated buffer.
 *
 * @return IppStatus
 * - ippStsNoErr: Indicates no error.
 * - ippStsMemAllocErr: allocation failed.
 */
template<typename T>
IppStatus malloc(int len, T& buffer) = delete;

}  // namespace ipp::wrappers


#include "specializations/all_specialized_declarations.hpp"
