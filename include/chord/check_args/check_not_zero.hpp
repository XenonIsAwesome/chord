//
// Created by mayak on 7/9/25.
//

#pragma once

#include <chord/chord_status.hpp>
#include <ranges>

namespace utils::check {
/**
 * Calls are_same_size with given variables which checks that threir sizes are same, if not returns
 * StatusResult with error that sizes found are not equal.
 */
#define CHECK_NOT_EMPTY_RETURN_STATUS(...)                          \
    if (utils::check::is_empty(__VA_ARGS__)) {                      \
        return (chord::StatusResult(chord::Status::InvalidParamter, \
                                    "Given empty span",             \
                                    __func__,                       \
                                    __FILE__,                       \
                                    __LINE__));                     \
    }


/**
 * Checks if given sequence is empty.
 *
 * @tparam T
 * @param seq
 * @return True if sequence is empty, false otherwise.
 *
 * @note span wrapping empty but with allocated memory will return not empty.
 */
template<std::ranges::sized_range... T>
bool is_empty(const T&... seq) {
    return (... || seq.empty());
}

}  // namespace utils::check
