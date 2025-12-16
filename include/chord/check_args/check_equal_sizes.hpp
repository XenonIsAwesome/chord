//
// Created by mayak on 7/8/25.
//

#pragma once


#include <ranges>

/**
 * Calls are_same_size with given variables which checks that threir sizes are same, if not returns
 * StatusResult with error that sizes found are not equal.
 */
#define CHECK_EQUAL_SIZE_RETURN_STATUS(...)                         \
    if (!are_same_size(__VA_ARGS__)) {                              \
        return (chord::StatusResult(chord::Status::InvalidParamter, \
                                    "Sizes of spans are not equal", \
                                    __func__,                       \
                                    __FILE__,                       \
                                    __LINE__));                     \
    }


/**
 * Returns true if all of the given sequences sizes are with the same, false otherwise.
 *
 * @tparam T0 First sequence variable
 * @tparam Ts The rest of the sequence variables
 *
 * @param first First sequnce
 * @param rest The rest of the sequences.
 *
 * @return True if the sizes are the same, false otherwise.
 */
template<std::ranges::sized_range T0, std::ranges::sized_range... Ts>
bool are_same_size(T0 const& first, Ts const&... rest) {
    return ((first.size() == rest.size()) && ...);
}
