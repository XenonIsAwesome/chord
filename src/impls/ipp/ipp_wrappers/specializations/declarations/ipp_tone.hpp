//
// Created by userk on 6/11/25.
//

#pragma once

namespace ipp::wrappers {

/// complex float
template<>
IppStatus generate_tone<std::complex<float>, float>(std::span<std::complex<float>> res,
                                                    float magn,
                                                    float freq,
                                                    float& phase,
                                                    int len,
                                                    chord::AlgoChoice algo);

}
