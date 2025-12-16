//
// Created by userk on 6/10/25.
//

#pragma once


using u_short = unsigned short;


namespace ipp::wrappers {


/// unsigned short
template<>
IppStatus compute_xor<u_short>(std::span<const u_short> src1, std::span<const u_short> src2, std::span<u_short> dst, int len);


/// unsigned short
template<>
IppStatus compute_xor_inplace<u_short>(std::span<u_short> src1, std::span<u_short> src2, int len);


}
