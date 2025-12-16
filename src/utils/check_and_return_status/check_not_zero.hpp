//
// Created by mayak on 7/9/25.
//

#pragma once

#include <ranges>


/**
 * Calls are_same_size with given variables which checks that threir sizes are same, if not returns
 * StatusResult with error that sizes found are not equal.
 */
#define CHECK_SIZE_NOT_ZERO_RETURN_STATUS(...)                      \
    if (is_empty(__VA_ARGS__)) {                                    \
        return (chord::StatusResult(chord::Status::InvalidParamter, \
                                    "Given empty span",             \
                                    __func__,                       \
                                    __FILE__,                       \
                                    __LINE__));                     \
    }


template<std::ranges::sized_range... T>
bool is_empty(const T&... seq) {
    return (... || seq.empty());
}
