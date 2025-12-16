//
// Created by userk on 5/12/25.
//

#pragma once


namespace ipp::wrappers {

/// float
template<>
IppStatus substract_by_list<float>(std::span<float> src_minuend,
                                   std::span<float> src_subtrahend,
                                   std::span<float> dst,
                                   int len);


/// double
template<>
IppStatus substract_by_list<double>(std::span<double> src_minuend,
                                    std::span<double> src_subtrahend,
                                    std::span<double> dst,
                                    int len);


/// complex float
template<>
IppStatus substract_by_list<std::complex<float>>(std::span<std::complex<float>> src_minuend,
                                                 std::span<std::complex<float>> src_subtrahend,
                                                 std::span<std::complex<float>> dst,
                                                 int len);


/// complex double
template<>
IppStatus substract_by_list<std::complex<double>>(std::span<std::complex<double>> src_minuend,
                                                  std::span<std::complex<double>> src_subtrahend,
                                                  std::span<std::complex<double>> dst,
                                                  int len);


/// float inplace
template<>
IppStatus substract_by_list_inplace<float>(std::span<float> src_minuend_dst,
                                           std::span<const float> src_subtrahend,
                                           int len);


/// double inplace
template<>
IppStatus substract_by_list_inplace<double>(std::span<double> src_minuend_dst,
                                            std::span<const double> src_subtrahend,
                                            int len);


/// complex float inplace
template<>
IppStatus
substract_by_list_inplace<std::complex<float>>(std::span<std::complex<float>> src_minuend_dst,
                                               std::span<const std::complex<float>> src_subtrahend,
                                               int len);


/// complex double inplace
template<>
IppStatus substract_by_list_inplace<std::complex<double>>(
    std::span<std::complex<double>> src_minuend_dst,
    std::span<const std::complex<double>> src_subtrahend,
    int len);

}  // namespace ipp::wrappers
