//
// Created by mayak on 8/5/25.
//

#pragma once

/// copied from scorpion

#include <type_traits>
#include <vector>

/// Check if type A is of type B regardless of nestness

/// Anything that evaluates to this evaluates to false
/// Generic specialization that gets evaluated to if first type is not of second type
template <typename Specific, template<typename...> class Ref>
struct is_specialization : std::false_type {};

/// Anything that evaluates to this evaluates to true
/// Specific specialization that gets evaluated to if first type is of second type
template <template<typename...> class Ref, typename... Args>
struct is_specialization<Ref<Args...>, Ref> : std::true_type {};

/// Get inner type (can be optional)

/// If no wrapper, get T in optional
template <typename T>
struct getInnerType {
    using optional_type = T;
};

/// If wrapper, get inner type in type (inner only) and optional_type (inner if exists)
template <template <typename> typename Wrap, typename Inner>
struct getInnerType<Wrap<Inner>> {
    using type = Inner;
    using optional_type = Inner;
};

template <typename T>
using getInnerType_t = typename getInnerType<T>::type;

template <typename T>
using getInnerType_t_opt = typename getInnerType<T>::optional_type;

