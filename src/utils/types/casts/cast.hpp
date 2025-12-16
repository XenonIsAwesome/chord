//
// Created by userk on 5/4/25.
//

#pragma once

#include <limits>
#include <stdexcept>


namespace safe_cast {

/**
 * Casts size_t variable to int varibale safetly, making sure its in  the rang of int.
 *
 * @param num number to convert
 * @param num_converted number converted to int
 *
 * @note not checking int min limit cause size_t starts at zero, so recieved number can't be smaller
 * then int min limit.
 */
inline void cast(const size_t num, int& num_converted) {
    if (num > static_cast<size_t>(std::numeric_limits<int>::max())) {
        throw std::out_of_range("Can't convert to int, too big");
    }

    num_converted = static_cast<int>(num);
}

}  // namespace safe_cast
