//
// Created by userk on 5/5/25.
//

#pragma once

#include <complex>
#include <optional>
#include <span>

// Assumes sizes given are valid.
namespace math_std {


enum class FFTFlag { FFT_FLAG_DEFAULT = 0, FFT_FLAG_FAST_HINT = 1, FFT_FLAG_HIGH_PRECISION = 2 };


/**
 * Multiplies each element of a vector by a constant value.
 *
 * @tparam T
 *
 * @param elems Source sequence.
 * @param val Value to multiply with.
 */
template<typename T>
void multiply_with_scalar_inplace(std::span<T> elems, T val);


/**
 * Multiplies each element of a vector by a constant value.
 *
 * @tparam T float / complex float.
 *
 * @param src Source sequence.
 * @param val Value to multiply with.
 * @param dst Destination sequence.
 */
template<typename T>
void multiply_with_scalar(std::span<const T> src, T val, std::span<T> dst);


/**
 * Raises e to the power of each vector element.
 *
 * @tparam T complex float
 *
 * @param src Source sequence.
 * @param dst Destination vector.
 */
template<typename T>
void compute_exponential(std::span<const T> src, std::span<T> dst);


/**
 * Up-samples a signal, conceptually increasing its sampling rate by an integer factor.
 *
 * @tparam T
 *
 * @param input Source sequence (the signal to be up-sampled).
 * @param output Destination sequence where result elements will be placed.
 * @param factor Factor by which the signal is up-sampled. That is, factor -1 zeros are inserted
 *               after each sample of the source src.
 * @param pphase Pointer to the phase of an source array sample,\n
 *              which determines where each sample from src lies within each output block of factor
 *              samples in dst. The value of phase is required to be in the range [0; factor -1].\n
 *              It is also a returned output phase which can be used as an input phase for the first
 *              sample in the next block to process.
 */
template<typename T>
void compute_up_sample(std::span<T> input,
                       std::span<T> output,
                       int factor,
                       int* pphase);  // input as const T


/**
 * Computes integer value rounded down to the nearest whole number (toward minus infinity)
 * for each vector element.
 *
 * @tparam T floating point integers.
 *
 * @param src Source sequence.
 * @param dst Destination vector.
 */
template<std::floating_point T>
void apply_floor(std::span<const T> src, std::span<T> dst);


/**
 * Computes truncated integer value and remaining fraction part for each vector element.
 *
 * @tparam T floating point integers.
 *
 * @param src Source sequence.
 * @param dst_int Integer part of numbers.
 * @param dst_frac Fraction part of numbers.
 */
template<std::floating_point T>
void integer_fraction_split(std::span<const T> src, std::span<T> dst_int, std::span<T> dst_frac);


/**
 * Divides each element of a vector by a constant value.
 *
 * @tparam T
 *
 * @param src Source sequence.
 * @param scalar Scalar value used as a divisor.
 * @param dst Destination sequence.
 *
 * @throws std::logic_error If tried dividing by zero.
 */
template<typename T>
void divide_by_scalar(std::span<const T> src, T scalar, std::span<T> dst);


/**
 * Divides each element of a vector by a constant value, places result in src.
 *
 * @tparam T
 *
 * @param src Source sequence.
 * @param scalar Scalar value used as a divisor.
 *
 * @throws std::logic_error If tried dividing by zero.
 */
template<typename T>
void divide_by_scalar_inplace(std::span<T> src, T scalar);


/**
 * @brief Divides the elements of two vectors accordingly.
 *
 * Formula:
 * dst[i] = src1[i] / src2[i]
 *
 * @tparam T
 *
 * @param src_divided  Source sequence, values which will be divided from. Later results will be
 * placed here.
 * @param src_divisors Source sequence, values which will be used as divisors.
 * @param dst Destination sequnce, results will be put here.
 *
 * @throws std::logic_error If tried dividing by zero.
 */
template<typename T>
void divide_list_by_list(std::span<T> src_divided, std::span<T> src_divisors, std::span<T> dst);


/**
 * @brief Divides the elements of two vectors accordingly, and places result in src1.
 *
 * Formula:
 * src1[i] = src1[i] / src2[i]
 *
 * @tparam T
 *
 * @param src_divided  Source sequence, values which will be divided from. Later results will be
 * placed here.
 * @param src_divisors_dst Source sequence, values which will be used as divisors.
 *
 * @throws std::logic_error If tried dividing by zero.
 */
template<typename T>
void divide_list_by_list_inplace(std::span<const T> src_divided, std::span<T> src_divisors_dst);


/**
 * Subtracts the elements of two vectors.
 *
 * @tparam T
 *
 * @param src_minuend Source sequence, from whose elements the elements of src_subtrahend are to be
 * subtracted.
 * @param src_subtrahend Source sequence, whose elements are to be subtracted.
 * @param dst Destination sequence.
 */
template<typename T>
void compute_substraction(std::span<T> src_minuend, std::span<T> src_subtrahend, std::span<T> dst);


/**
 * Subtracts the elements of two vectors and places result in src_subtrahend.
 *
 * @tparam T
 *
 * @param src_minuend Source sequence, from whose elements the elements of src_subtrahend are to be
 * subtracted.
 * @param src_subtrahend Source sequence, whose elements are to be subtracted.
 */
template<typename T>
void compute_substraction_inplace(std::span<T> src_minuend, std::span<const T> src_subtrahend);


/**
 * Computes a square of each element in src. And puts result in dst.
 *
 * @tparam T
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 */
template<typename T>
void apply_square(std::span<const T> src, std::span<T> dst);


/**
 * Computes a square of each element in src, and replaces src with the results.
 *
 * @tparam T
 *
 * @param src Source sequence, later will hold results.
 */
template<typename T>
void apply_square_inplace(std::span<T> src);


/**
 * Reverses the order of elements in a vector, and puts results in dst.
 *
 * @tparam T
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 */
template<typename T>
void apply_flip(std::span<const T> src, std::span<T> dst);


/**
 * Reverses the order of elements in a vector, and replaces src with the results.
 *
 * @tparam T
 *
 * @param src Source sequence.
 */
template<typename T>
void apply_flip_inplace(std::span<T> src);


/**
 * Computes absolute values of elements, and puts results in dst.
 *
 * @tparam T
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 */
template<typename T>
void apply_absolute(std::span<const T> src, std::span<T> dst);


/**
 * Computes absolute values of elements, and replaces src with the results.
 *
 * @tparam T
 *
 * @param src Source sequence.
 */
template<typename T>
void apply_absolute_inplace(std::span<T> src);


/**
 * Performs element by element addition of two vectors.
 *
 * @tparam T
 *
 * @param src1 First source sequence.
 * @param src2 Second source sequence.
 * @param dst Destination sequence.
 */
template<typename T>
void combine(std::span<const T> src1, std::span<const T> src2, std::span<T> dst);


/**
 * Performs element by element addition of two vectors, places result in src_dst.
 *
 * @tparam T
 *
 * @param src First source sequence.
 * @param src_dst Second source sequence.
 */
template<typename T>
void combine_inplace(std::span<T> src_dst, std::span<const T> src2);


/**
 * Adds a constant value to each element and places the results in src.
 *
 * @tparam T
 *
 * @param src Source sequence.
 * @param scalar Value to be added to all elements in src.
 * @param dst Destination sequence.
 */
template<typename T>
void combine_with_scalar(std::span<const T> src, T scalar, std::span<T> dst);


/**
 * Adds a constant value to each element and places the result in src_dst.
 *
 * @tparam T
 *
 * @param src_dst Source sequence, where the results later will be put.
 * @param scalar Value to be added to all elements in src_dst.
 */
template<typename T>
void combine_with_scalar_inplace(std::span<T> src_dst, T scalar);


/**
 * @brief Finds the minimum value out of all the elements.
 *
 * Puts the found minimal value in min.
 *
 * @tparam T
 *
 * @param src Source sequence.
 * @param min The minimal value found.
 */
template<typename T>
void find_minimum(std::span<const T> src, T& min);


/**
 * @brief Returns the minimum value and the index of the minimum element.
 *
 * This function returns the minimum value of the input src and stores the result in min.
 * The function also stores the index of the minimum element in index. If there are several equal
 * minimum elements, the first index from the beginning is returned.
 *
 * @tparam T
 *
 * @param src Source sequence.
 * @param min The minimum value found.
 * @param index Index of the minimum element.
 */
template<typename T>
void find_minimum_and_index(std::span<const T> src, T& min, int& index);


/**
 * @brief Finds the maximum value out of all the elements.
 *
 * Puts the found maximum value in min.
 *
 * @tparam T
 *
 * @param src Source sequence.
 * @param max The maximum value found.
 */
template<typename T>
void find_maximum(std::span<const T> src, T& max);


/**
 * @brief Returns the maximum value of a vector and the index of the maximum element.
 *
 * This function returns the maximum value of the input src, and stores the result in max.
 * The function returns the index of the maximum element and stores it in index.
 * If there are several equal maximum elements, the first index from the beginning is returned.
 *
 * @tparam T
 *
 * @param src Source sequence.
 * @param max The maximum value found.
 * @param index Index of the maximum element.
 */
template<typename T>
void find_maximum_and_index(std::span<const T> src, T& max, int& index);


/**
 * @brief Computes the mean value of a vector.
 *
 * This function computes the mean (average) of the src, and stores the result in mean.
 *
 * @tparam T
 *
 * @param src Source sequence.
 * @param mean Result average of src.
 */
template<typename T>
void compute_average(std::span<const T> src, T& mean);


/**
 * Raises each element of a vector to a constant power.
 *
 * The formula: res[i] = bases[i] ^ scalar
 *
 * @tparam T
 *
 * @param bases Source sequence, holds the bases.
 * @param scalar Constant value to put the bases to the power of.
 * @param res Destination sequence.
 */
template<typename T>
void apply_raise_power_with_scalar(std::span<const T> bases, T scalar, std::span<T> res);


/**
 * Raises each element of the bases to the power of corresponding element of the exponents(expos).
 *
 * @tparam T
 *
 * @param bases Source sequence, holds the bases.
 * @param expos Second source sequence, holds the exponents.
 * @param res Destination sequence.
 */
template<typename T>
void apply_raise_power(std::span<T> bases, std::span<T> expos, std::span<T> res);


/**
 * @brief Computes the magnitudes of complex elements.
 *
 * Formula:
 * magn [ n ] = ( src_real[ n ]^2 + src_img[ n ]^2 ) ^ 1/2
 *
 * @tparam T
 *
 * @param src_real Source Sequence of the real numbers.
 * @param src_img Source Sequence of the imaginary numbers.
 * @param dst Destination sequence.
 */
template<typename T>
void compute_real_imag_magnitude(std::span<const T> src_real,
                                 std::span<const T> src_img,
                                 std::span<T> dst);


/**
 * @brief Computes the magnitudes of complex elements.
 *
 * Formula:
 * magn[ n ] = ( (src[ n ].re)^2 + (src[ n ].im)^2 ) ^ 1/2
 *
 * @tparam T
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 */
template<typename T>
void compute_complex_magnitude(std::span<const std::complex<T>> src, std::span<T> dst);


/**
 * @brief Creates a slope vector.
 *
 * Fills given dst with slope vector values.
 * Formula: pDst[n] = offset + slope * n , 0 ≤ n < len
 *
 * @tparam T
 *
 * @param dst Destination sequence.
 * @param offset Offset value.
 * @param slope Slope coefficient.
 */
template<typename T>
void fill_slope(std::span<T> dst, T offset, T slope);


/**
 * Computes the bitwise XOR of two vectors.
 *
 * Formula: dst[i] = src1[i] ⊕ src2[i]
 *
 * src1 = {0xFFFF, 0x0F0F, 0x1234, 0x0000} \n
 * src2 = {0xAAAA, 0XF0F0, 0XFFFF, 0X1234} \n
 * dst  = {0x5555, 0xFFFF, 0xEDCB, 0x1234}
 *
 * @tparam T
 *
 * @param src1 First source sequence
 * @param src2 Second source sequence
 * @param dst Destination sequence
 */
template<typename T>
void compute_xor(std::span<T> src1, std::span<T> src2, std::span<T> dst);


/**
 * Computes the bitwise XOR of two vectors, and places the results in src1.
 *
 * Formula: src1[i] = src1[i] ⊕ src2[i]
 *
 * @tparam T
 *
 * @param src1 First source sequence, which will hold the results.
 * @param src2 Second source sequence
 */
template<typename T>
void compute_xor_inplace(std::span<T> src1, std::span<T> src2);


/**
 * Calculates the complex conjugate values.
 *
 * The complex input     is: z = a + bi \n
 * The complex conjugate is: z = a - bi
 *
 * @tparam T
 *
 * @param src Source sequence of complex values.
 * @param dst Destination sequence of complex conjugate values.
 */
template<typename T>
void compute_complex_conjugates(std::span<std::complex<T>> src, std::span<std::complex<T>> dst);


/**
 * Calculates the complex conjugate values of and stores them in src.
 *
 * The complex input     is: z = a + bi \n
 * The complex conjugate is: z = a - bi
 *
 * @tparam T
 *
 * @param src Source sequence of complex numbers, updated to hold the conjugate values.
 */
template<typename T>
void compute_complex_conjugates_inplace(std::span<std::complex<T>> src);


/**
 * @brief Generates a tone with a given frequency, phase and magnitude.
 *
 * This function generates the tone with the specified frequency(freq), phase and magnitude(magn).\n
 * The function computes len samples of the tone, and stores them in res.
 *
 * For real tones, each generated value x[n] is defined as: \n
 * x[n] = magn * cos(2πn * freq + phase)
 *
 * @tparam T
 *
 * @param res Destination sequence which will store the samples.
 * @param magn Magnitude of the tone, that is, the maximum value attained by the wave.
 * @param freq Frequency of the tone relative to the sampling frequency.\n It must be in the
 * interval [0.0, 0.5) for real tone and in [0.0, 1.0) for complex tone.
 * @param phase Pointer to the phase of the tone relative to a cosine wave.\n It must be in range
 * [0.0, 2π). You can use the returned value to compute the next continuous data block.
 */
template<typename T, typename U>
void generate_tone(std::span<T> res, U magn, U freq, U& phase);


/**
 * @brief Generates a tone with a given frequency, phase and magnitude.
 *
 * This function generates the tone with the specified frequency(freq), phase and magnitude(magn).\n
 * The function computes len samples of the tone, and stores them in res.
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
 */
template<typename T, typename U>
void generate_tone_complex(std::span<std::complex<T>> res, U magn, U freq, U& phase);


/**
 * @brief Computes complex exponent of each vector element.
 *
 * @tparam T
 *
 * @param src Source sequence, angles.
 * @param dst Destination sequence.
 */
template<typename T>
void compute_complex_exponent(std::span<const T> src, std::span<std::complex<T>> dst);


/**
 * Computes a signed fractional part for each element of a vector.
 *
 * @tparam T
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 */
template<typename T>
void compute_fractional_part(std::span<const T> src, std::span<T> dst);


/**
 * Returns if a is smaller than b.
 *
 * @tparam T
 *
 * @param a
 * @param b
 *
 * @return true if a smaller than b, false otherwise.
 */
template<typename T>
bool is_smaller(T a, T b);


/**
 * Returns if a is bigger than b.
 *
 * @tparam T
 *
 * @param a
 * @param b
 *
 * @return true if a bigger than b, false otherwise.
 */
template<typename T>
bool is_bigger(T a, T b);


template<typename T>
void compute_complex_dot_product(std::span<T> src,
                                 std::span<std::complex<T>> src_complex,
                                 std::complex<T>& dst);

template<typename T>
void compute_dot_product(std::span<const T> src1, std::span<const T> src2, T& dst);


template<typename T>
void compute_sum(std::span<const T> src, T& sum);


template<typename T>
void compute_mean_value(std::span<const T> src, T& mean);


// template<typename T>
// void generate_FFT_sizes(int order, int flag, chord::WorkBufferSizes& sizes_to_update);

}  // namespace math_std


#include "math_std.tpp"
