//
// Created by userk on 6/11/25.
//

#pragma once

#include <sys/types.h>

namespace ipp::wrappers {

/// float
template<>
IppStatus malloc<float>(int len, float& buffer);


/// unsigned char
template<>
IppStatus malloc<u_char>(int len, u_char& buffer);

}
