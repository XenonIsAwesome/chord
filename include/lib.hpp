#ifndef INCLUDE_LIB_HPP
#define INCLUDE_LIB_HPP
/**
 * MACRO to be called at the start of
 * every function inside the chord namespace (except init).
 * It makes sure the init function will be called only once
 * with the first call of a function from chord namespace.
 */
#define AUTO_INIT() std::call_once(chord_once_flag, chord::impl::init)

#include "chord_status.hpp"

#include <complex>
#include <span>

namespace chord {

/**
 * @brief Call the initialization function of library implemented.
 *
 * IPP - ippInit()
 * NEON - ne10_init()
 */
inline void init();


/**
 * Multiplies each element by a constant value.
 *
 * @tparam T supports: float, complex float.
 *
 * @param src_dst The source sequence, then results are placed here.
 * @param val The value to multiply all elements with.
 *
 * @return StatusResult.
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert size to int, too big"
 *     - "Can't convert size to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error"
 */
template<typename T>
StatusResult multiply_with_scalar(std::span<T> src_dst, T val);


/**
 * Multiplies each element by a constant value.
 *
 * @tparam T supports: float, complex float.
 *
 * @param src The source sequence.
 * @param val The value to multiply all elements with.
 * @param dst The destination sequence.
 *
 * @return StatusResult.
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert size to int, too big"
 *     - "Can't convert size to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error"
 */
template<typename T>
StatusResult multiply_with_scalar(std::span<const T> src, T val, std::span<T> dst);


/**
 * Raises e to the power of each vector element.
 *
 * @tparam T supports: complex float, float
 *
 * @param src The source sequence.
 * @param dst The destination sequence.
 *
 * The functionality can be described as follows:\n
 * src = { 4.885,  -0.543, -3.809, -4.953 }\n
 * dst = { 132.324, 0.581,  0.022,  0.007 }
 *
 * @return StatusResult.
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error".
 *     - "Incorrect value for data size."
 * - Warning:
 *     - "Overflow in the operation."
 *     - "Underflow in the operation."
 */
template<typename T>
StatusResult compute_exponential(std::span<const T> src, std::span<T> dst);


/**
 * @brief Up-samples a signal, conceptually increasing its sampling rate by an integer factor.
 *
 * The functionality can be described as follows:\n
 * dst[factor * n + phase] = src[n], 0 ≤ n < src_size\n
 * dst[factor * n + m] = 0, 0 ≤ n < src_size, 0 ≤ m < factor, m ≠ phase\n
 * dst_size = factor * src_size.
 *
 * @tparam T supports: float, double, complex float
 *
 * @param src Source sequence (the signal to be up-sampled).
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
 * @return StatusResult.
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal" // NOT SUPPOSED TO BE EQUAL
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 *     - "Sampling factor is less than or equal to zero."
 *     - "Phase value is out of range, range is 0 ≤ phase < factor."
 */
template<typename T>
StatusResult
compute_up_sample(std::span<const T> src, std::span<T> dst, int factor, int* phase, int* dst_size);


/**
 * @brief Computes truncated integer value and remaining fraction part for each vector element.
 *
 * This function computes an integer value and a remainder of each element of the vector given.
 * The integer value is stored in the corresponding element of the dst_int vector and
 * the remainder is stored in the corresponding element of the dst_frac vector.
 *
 * The functionality can be described as follows:\n
 * src      = { -1.883, -0.265, 0.176, 1.752 }
 * dst_int  = { -1.000,  0.000, 0.000, 1.000 }
 * dst_frac = { -0.883, -0.265, 0.176, 0.752 }
 *
 * @tparam T supports: float, double
 *
 * @param src Source sequence.
 * @param dst_int The first destination vector, containing the integer value.
 * @param dst_frac The second destination vector, containing the remainder value.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParameter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 */
template<typename T>
StatusResult
integer_fraction_split(std::span<const T> src, std::span<T> dst_int, std::span<T> dst_frac);


/**
 * @brief Computes a signed fractional part for each element.
 *
 * This function computes a fractional part of each element of the src vector. The result is stored
 * in the corresponding element of the dst vector.
 *
 * The functionality can be described as follows:\n
 * src = { -1.883, -0.265, 0.176, 1.752 }\n
 * dst = { -0.883, -0.265, 0.176, 0.752 }
 *
 * @tparam T supports: float, double
 *
 * @param src Source sequence.
 * @param dst The destination vector.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParameter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 */
template<typename T>
StatusResult compute_fractional_part(std::span<const T> src, std::span<T> dst);


/**
 * Divides each element of a vector by a constant value.
 *
 * @tparam T supports: float, complex float
 *
 * @param src Source sequence.
 * @param divider divisor.
 * @param dst The destination vector.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 *     - "An attempt to divide by zero."
 */
template<typename T>
StatusResult divide_by_scalar(std::span<const T> src, T divider, std::span<T> dst);


/**
 * Divides each element of a vector by a constant value.
 *
 * @tparam T supports: float, complex float
 *
 * @param src_dst The source sequence, then results are placed here.
 * @param divider Divisor.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParameter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 *     - "An attempt to divide by zero."
 */
template<typename T>
StatusResult divide_by_scalar(std::span<T> src_dst, T divider);


/**
 * @brief Divides the elements of two vectors accordingly.
 *
 * @tparam T supports: complex float
 *
 * @param src_divided Source sequence, values which will be divided from.
 * @param src_divisors Source sequence, values which will be used as divisors.
 * @param dst Destination sequnce, results will be put here.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 *     - "An attempt to divide by zero."
 */
template<typename T>
StatusResult divide_list_by_list(std::span<const T> src_divided,
                                 std::span<const T> src_divisors,
                                 std::span<T> dst);


/**
 * @brief Divides the elements of two vectors accordingly.
 *
 * @tparam T supports: complex float
 *
 * @param src_divided Source sequence, values which will be divided from, results will be placed
 * here.
 * @param src_divisors_dst Source sequence, values which will be used as divisors.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 *     - "An attempt to divide by zero."
 */
template<typename T>
StatusResult divide_list_by_list(std::span<const T> src_divided, std::span<T> src_divisors_dst);


/**
 * @brief Substract elements of one sequence with the elements of another.
 *
 * This function subtracts the elements of the vector src_minuend from the elements of the vector
 * src_subtrahend, and stores the result in dst or in src_subtrahend.
 *
 * The functionality can be described as follows:\n
 * terminolagy: result = minuend - subtrahend
 *
 * dst[i] = src_minuend[i] - src_subtrahend[i]\n
 * src_minuend    = { 10.5, 20.25, 30.75 }\n
 * src_subtrahend = { 1.5 , 5.125, 15.625 }\n
 * dst            = { 9.0, 15.125, 15.125 }
 *
 * @tparam T supports: float, double, complex float, complex double.
 *
 * @param src_minuend Source sequence, from whose elements the elements of src_subtrahend are to be
 * subtracted.
 * @param src_subtrahend Source sequence, whose elements are to be subtracted.
 * @param dst Destination sequence.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 */
template<typename T>
StatusResult
subtract(std::span<const T> src_minuend, std::span<const T> src_subtrahend, std::span<T> dst);


/**
 * @brief Substract elements of one sequence with the elements of another.
 *
 * This function subtracts the elements of the vector src_minuend from the elements of the vector
 * src_subtrahend, and stores the result in dst or in src_subtrahend.
 *
 * The functionality can be described as follows:\n
 * terminolagy: result = minuend - subtrahend
 *
 * dst[i] = src_minuend[i] - src_subtrahend[i]\n
 * src_minuend    = { 10.5, 20.25, 30.75 }\n
 * src_subtrahend = { 1.5 , 5.125, 15.625 }\n
 * dst            = { 9.0, 15.125, 15.125 }
 *
 * @tparam T supports: float, double, complex float, complex double.
 *
 * @param src_dst_minuend Source sequence, from whose elements the elements of src_subtrahend are to
 * be subtracted. The results are placed here.
 * @param src_subtrahend Source sequence, whose elements are to be subtracted.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 */
template<typename T>
StatusResult subtract(std::span<T> src_dst_minuend, std::span<const T> src_subtrahend);


/**
 * @brief Computes a square of each element of a sequence.
 *
 * @tparam T supports: float
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 */
template<typename T>
StatusResult apply_square(std::span<const T> src, std::span<T> dst);


/**
 * @brief Computes a square of each element of a sequence.
 *
 * @tparam T supports: float
 *
 * @param src_dst Source sequence, then results are placed here.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 */
template<typename T>
StatusResult apply_square(std::span<T> src_dst);


/**
 * @brief Reverses the order of elements in a sequence.
 *
 * @tparam T supports: float, complex float
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 */
template<typename T>
StatusResult apply_flip(std::span<const T> src, std::span<T> dst);


/**
 * @brief Reverses the order of elements in a sequence.
 *
 * @tparam T supports: float, complex float
 *
 * @param src_dst Source sequence, in the end results are placed here.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 */
template<typename T>
StatusResult apply_flip(std::span<T> src_dst);


/**
 * Computes absolute values of sequence elements.
 *
 * @tparam T supports: float, complex float
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 */
template<typename T>
StatusResult apply_absolute(std::span<const T> src, std::span<T> dst);


/**
 * Computes absolute values of sequence elements.
 *
 * @tparam T supports: float, complex float
 *
 * @param src_dst Source sequence, in the end results are placed here.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 */
template<typename T>
StatusResult apply_absolute(std::span<T> src_dst);


/**
 * @brief Computes the magnitudes of complex elements.
 *
 * The functionality can be described as follows:\n
 * Formula: magn[ n ] = ( (src[ n ].re)^2 + (src[ n ].im)^2 ) ^ 1/2
 *
 * src = { {3.0f, 4.0f}, {1.0f, 1.0f}, {-5.0f, 12.0f} }\n
 * dst = {  5.0f,         1.4142f,      13.0f         }
 *
 * @tparam T float / double
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 */
template<typename T>
StatusResult compute_complex_magnitude(std::span<const std::complex<T>> src, std::span<T> dst);


/**
 * @brief Computes the magnitudes of complex elements.
 *
 * The functionality can be described as follows:\n
 * Formula: magn [ n ] = ( src_real[ n ]^2 + src_img[ n ]^2 ) ^ 1/2
 *
 * src_real = { 3.0f, 1.0f, 0.0f, -5.0f }\n
 * src_img =  { 4.0f, 1.0f, 2.0f, 12.0f }\n
 * dst =   { 5.0f, 1.4142f, 2.0f, 13.0f }
 *
 * @tparam T float / double
 *
 * @param src_real Source Sequence of the imaginary numbers.
 * @param src_img Source Sequence of the real numbers.
 * @param dst Destination sequence.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 */
template<typename T>
StatusResult compute_real_imag_magnitude(std::span<const T> src_real,
                                         std::span<const T> src_img,
                                         std::span<T> dst);


/**
 * @brief Creates a slope vector.
 *
 * Fills given dst with slope vector values.
 * The functionality can be described as follows:\n
 * Formula: pDst[n] = offset + slope * n , 0 ≤ n < len
 *
 * dst = { , , , , }\n
 * offset = 2.0f\n
 * slope = 1.5f
 *
 * dst = { 2.0, 3.5, 5.0, 6.5, 8.0 }
 *
 * @tparam T float / double
 *
 * @param dst Destination sequence.
 * @param offset Offset value.
 * @param slope Slope coefficient.
 *
 * @return StatusResult
 * - Ok: "No error."
 * - OutOfRange:
 *     - "Sizes of dst and src not equal"
 *     - "Can't convert to int, too big"
 *     - "Can't convert to int, too small"
 * - InvalidParamter:
 *     - "Null pointer error."
 *     - "Incorrect value for data size."
 */
template<typename T>
StatusResult fill_slope(std::span<T> dst, T offset, T slope);


/**
 * Performs element by element addition of two sequences.
 *
 * @tparam T supports: float, complex float
 *
 * @param src1 First source sequence.
 * @param src2 Second source sequence.
 * @param dst Destination sequence.
 *
 * @return
 */
template<typename T>
StatusResult combine(std::span<const T> src1, std::span<const T> src2, std::span<T> dst);


/**
 * Performs element by element addition of two sequences.
 *
 * @tparam T supports: float, complex float
 *
 * @param src First source sequence.
 * @param src_dst Second source sequence, in the end results are placed here.
 *
 * @return
 */
template<typename T>
StatusResult combine(std::span<const T> src, std::span<T> src_dst);


/**
 *
 * If pointer to dst not given, places result in src.
 *
 * @tparam T supports: complex float, float
 *
 * @param src Source sequence.
 * @param scalar value to be added to all elements in src.
 * @param dst Destination sequence.
 *
 * @return
 *
 */
template<typename T>
StatusResult combine_with_scalar(std::span<const T> src, T scalar, std::span<T> dst);


/**
 *
 * If pointer to dst not given, places result in src.
 *
 * @tparam T supports: complex float, float
 *
 * @param src_dst Source sequence, in the end results are placed here.
 * @param scalar value to be added to all elements in src.
 *
 * @return
 *
 */
template<typename T>
StatusResult combine_with_scalar(std::span<T> src_dst, T scalar);


/**
 * Computes integer value rounded toward minus infinity for each element.
 *
 * The functionality can be described as follows:\n
 * src = { -0.883, -0.265, 0.176, 0.752 }\n
 * dst = { -1.000, -1.000, 0.000, 0.000 }
 *
 * @tparam T supports: float, double
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 *
 * @return StatusResult
 */
template<typename T>
StatusResult apply_floor(std::span<const T> src, std::span<T> dst);


/**
 * Calculates the complex conjugate values.
 *
 * The functionality can be described as follows:\n
 * The complex input     is: z = a + bi \n
 * The complex conjugate is: z = a - bi
 *
 * For exmple: \n
 * src: { (1 + 2i), (-3 + 4i), (0 - 1i), (5 + 0i) } \n
 * dst: { (1 - 2i), (-3 - 4i), (0 + 1i), (5 + 0i) } \n
 *
 * @tparam T supports: float, double
 *
 * @param src Source sequence of complex values.
 * @param dst Destination sequence of complex conjugate values.
 *
 * @return StatusResult
 */
template<typename T>
StatusResult compute_complex_conjugates(std::span<const std::complex<T>> src,
                                        std::span<std::complex<T>> dst);


/**
 * Calculates the complex conjugate values.
 *
 * The functionality can be described as follows:\n
 * The complex input     is: z = a + bi \n
 * The complex conjugate is: z = a - bi
 *
 * For exmple: \n
 * src: { (1 + 2i), (-3 + 4i), (0 - 1i), (5 + 0i) } \n
 * dst: { (1 - 2i), (-3 - 4i), (0 + 1i), (5 + 0i) } \n
 *
 * @tparam T supports: float, double
 *
 * @param src_dst Source sequence of complex values, in the end results are placed here.
 *
 * @return StatusResult
 */
template<typename T>
StatusResult compute_complex_conjugates(std::span<std::complex<T>> src_dst);


/**
 * @brief Returns the minimum value and the index of the minimum element.
 *
 * This function returns the minimum value of the input src and stores the result in min.
 * The function also stores the index of the minimum element in index. If there are several equal
 * minimum elements, the first index from the beginning is returned.
 *
 * @tparam T supports: float
 *
 * @param src Source sequence.
 * @param min The minimum value found.
 * @param index Index of the minimum element.
 *
 * @return
 */
template<typename T>
StatusResult find_minimum_and_index(std::span<const T> src, T& min, int& index);


/**
 * @brief Returns the minimum value.
 *
 * This function returns the minimum value of the input src and stores the result in min.
 * The function also stores the index of the minimum element in index. If there are several equal
 * minimum elements, the first index from the beginning is returned.
 *
 * @tparam T supports: float
 *
 * @param src Source sequence.
 * @param min The minimum value found.
 *
 * @return
 */
template<typename T>
StatusResult find_minimum(std::span<const T> src, T& min);


/**
 * @brief Returns the maximum value and the index of the maximum element.
 *
 * This function returns the maximum value of the input src and stores the result in min.
 * The function also stores the index of the maximum element in index. If there are several equal
 * maximum elements, the first index from the beginning is returned.
 *
 * @tparam T supports: float
 *
 * @param src Source sequence.
 * @param max The maximum value found.
 * @param index Index of the maximum element.
 *
 * @return
 *
 */
template<typename T>
StatusResult find_maximum_and_index(std::span<const T> src, T& max, int& index);


/**
 * @brief Returns the maximum value.
 *
 * This function returns the maximum value of the input src and stores the result in min.
 * The function also stores the index of the maximum element in index. If there are several equal
 * maximum elements, the first index from the beginning is returned.
 *
 * @tparam T supports: float
 *
 * @param src Source sequence.
 * @param max The maximum value found.
 *
 * @return
 *
 */
template<typename T>
StatusResult find_maximum(std::span<const T> src, T& max);


/**
 * Computes the dot product of two vectors.
 *
 * Formula: \n
 * 0 <= n <= (len - 1) \n
 * dp = ∑(src1[n] * src2[n])
 *
 * @tparam T supports: float
 *
 * @param src1 First source sequence.
 * @param src2 Second source sequence.
 * @param dst Destination sequence
 *
 * @return
 */
template<typename T>
StatusResult compute_dot_product(std::span<const T> src1, std::span<const T> src2, T& dst);


/**
 * Computes the dot product of two vectors.
 *
 * Formula: \n
 * 0 <= n <= (len - 1) \n
 * dp = ∑(src[n] * src_complex[n])
 *
 * @tparam T supports: float
 *
 * @param src Source sequence.
 * @param src_complex Source sequence of complex numbers.
 * @param dst Destination sequence
 *
 * @return
 */
template<typename T>
StatusResult compute_complex_dot_product(std::span<const T> src,
                                         std::span<const std::complex<T>> src_complex,
                                         std::complex<T>& dst);


/**
 * Computes the bitwise XOR of two vectors.
 *
 * Formula: dst[i] = src1[i] ⊕ src2[i]
 *
 * src1 = {0xFFFF, 0x0F0F, 0x1234, 0x0000} \n
 * src2 = {0xAAAA, 0XF0F0, 0XFFFF, 0X1234} \n
 * dst  = {0x5555, 0xFFFF, 0xEDCB, 0x1234}
 *
 * @tparam T supports: unsigned short
 *
 * @param src1 First source sequence
 * @param src2 Second source sequence
 * @param dst Destination sequence
 *
 * @return
 */
template<typename T>
StatusResult compute_xor(std::span<const T> src1, std::span<const T> src2, std::span<T> dst);


/**
 * Computes the bitwise XOR of two vectors.
 *
 * Formula: dst[i] = src1[i] ⊕ src2[i]
 *
 * src1 = {0xFFFF, 0x0F0F, 0x1234, 0x0000} \n
 * src2 = {0xAAAA, 0XF0F0, 0XFFFF, 0X1234} \n
 * dst  = {0x5555, 0xFFFF, 0xEDCB, 0x1234}
 *
 * @tparam T supports: unsigned short
 *
 * @param src1 First source sequence, in the end results are placed here.
 * @param src2 Second source sequence
 *
 * @return
 */
template<typename T>
StatusResult compute_xor(std::span<T> src1, std::span<const T> src2);


/**
 * @brief Computes the mean value of a vector.
 *
 * This function computes the mean (average) of the src, and stores the result in mean.
 *
 * The mean of src is defined by the formula:
 * 0 <= n <= len - 1 \n
 * mean = (1 / len) ∑src[n]
 *
 * @tparam T supports: float
 *
 * @param src Source sequence.
 * @param mean Result average of src.
 * @param algo Algorithm type preffered.
 *
 * @return
 */
template<typename T>
StatusResult
compute_mean_value(std::span<const T> src, T& mean, AlgoChoice algo = AlgoChoice::Basic);


/**
 * @brief Generates a tone with a given frequency, phase and magnitude.
 *
 * This function generates the tone with the specified frequency(freq), phase and
 magnitude(magn).\n
 * The function computes len samples of the tone, and stores them in res.
 *
 * For real tones, each generated value x[n] is defined as: \n
 * x[n] = magn * cos(2πn * freq + phase)
 *
 * For complex tones, x[n] is defined as: \n
 * x[n] = magn * (cos(2πn * freq + phase) + j * sin(2πn *rFreq + phase))
 *
 * @tparam T samples type,   supports: complex float
 * @tparam U arguments type, supports: float
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
 * @return
 */
template<typename T, typename U>
StatusResult generate_tone(std::span<T> res,
                           U magn,
                           U freq,
                           U& phase,
                           int len,
                           AlgoChoice algo = AlgoChoice::Basic);


/**
 * Computes sizes of the FFT specification structure and required working buffers.
 *
 * @tparam T supports: complex float
 *
 * @param order FFT order. The input signal length is N= 2^order.
 * @param flag Specifies the result normalization method.
 * @param sizes_to_update holds the values of the buffer sizes.
 *
 * @return
 */
template<typename T>
StatusResult generate_FFT_sizes(int order, int flag, WorkBufferSizes& sizes_to_update);


/**
 * @brief: Computes the sum of the elements of a vector.
 *
 * This function computes the sum of the elements of the src and stores the result in pSum.\n
 * The sum of the elements of src is defined by the formula:
 *
 * 0 <= n <= len -1
 * sum = ∑src[n]
 *
 * @tparam T supports: float, complex float, int
 *
 * @param src Source sequence.
 * @param sum Sum result.
 * @param algo Algorithm type preffered.
 *
 * @return
 */
template<typename T>
StatusResult compute_sum(std::span<const T> src, T& sum, AlgoChoice algo = AlgoChoice::Basic);


/**
 * Raises each element of a vector to a constant power.
 *
 * The formula: res[i] = bases[i] ^ scalar
 *
 * @tparam T supports: float
 *
 * @param bases Source sequence, holds the bases.
 * @param scalar Constant value to put the bases to the power of.
 * @param res Destination sequence.
 *
 * @return
 */
template<typename T>
StatusResult apply_raise_power_with_scalar(std::span<const T> bases, T scalar, std::span<T> res);


/**
 * Raises each element of the bases to the power of corresponding element of the exponents(expos).
 *
 * @tparam T supports: float
 *
 * @param bases Source sequence, holds the bases.
 * @param expos Second source sequence, holds the exponents.
 * @param res Destination sequence.
 *
 * @return
 */
template<typename T>
StatusResult
apply_raise_power(std::span<const T> bases, std::span<const T> expos, std::span<T> res);


/**
 * @brief Computes sizes of the DFT work buffer and required working buffers.
 *
 * @tparam T supports: complex float
 *
 * @param len Length of the DFT transform.
 * @param flag Specifies the result normalization method.
 * @param sizes_to_update holds the values of the buffer sizes.
 *
 * @return
 */
template<typename T>
StatusResult generate_DFT_sizes(int len, int flag, WorkBufferSizes& sizes_to_update);


/**
 * @brief Computes complex exponent of each vector element.
 *
 * The functionality can be described as follows:\n
 * The complex input     is: z = a + bi \n
 * The complex conjugate is: z = a - bi
 *
 * @tparam T supports: float
 *
 * @param src Source sequence.
 * @param dst Destination sequence.
 *
 * @return
 */
template<typename T>
StatusResult compute_complex_exponent(std::span<const T> src, std::span<std::complex<T>> dst);

}  // namespace chord

#include "lib.tpp"

#endif