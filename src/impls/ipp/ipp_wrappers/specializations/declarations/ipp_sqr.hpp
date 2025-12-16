//
// Created by userk on 5/14/25.
//

#pragma once


namespace ipp::wrappers {

/// float
template<>
IppStatus apply_square<float>(std::span<const float> src, std::span<float> dst, int len);


/// inplace float
template<>
IppStatus apply_square_inplace<float>(std::span<float> src, int len);

}
