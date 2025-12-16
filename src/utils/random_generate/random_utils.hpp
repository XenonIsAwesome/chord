//
// Created by mayak on 8/5/25.
//

#pragma once

#include "types/concepts.hpp"
#include "types/template_specialization.hpp"

#include <random>

/* TAKEN FROM SCORPION */
namespace random_utils {
/// the default constexpr came from the previous file (generate_random_samples) that been used in
/// the gpu modules tests so I didn't change it.
constexpr size_t DEFAULT_SIZE = 100;
constexpr float DEFAULT_MIN = -1000.f;
constexpr float DEFAULT_MAX = 1000.f;
constexpr int DEFAULT_SEED = 0;

/**
 * @brief the function generate random vector according to the min max and the given seed.
 * @tparam T the type of vector that you want
 * @param size the wanted vector size
 * @param min the min value
 * @param max the max value
 * @param seed the wanted seed
 * @return the random vector
 */
template<AnyArithmetic T>
std::vector<T> generate_random_vector(int size = DEFAULT_SIZE,
                                      size_t seed = DEFAULT_SEED,
                                      getInnerType_t_opt<T> min = DEFAULT_MIN,
                                      getInnerType_t_opt<T> max = DEFAULT_MAX);


/**
 * @brief the function generate random number
 * @tparam T the type of the random number
 * @param min the min value
 * @param max the max value
 * @param seed the wanted seed
 * @return the new random number
 */
template<AnyArithmetic T>
T generate_random_number(getInnerType_t_opt<T> min = DEFAULT_MIN,
                         getInnerType_t_opt<T> max = DEFAULT_MAX,
                         size_t seed = DEFAULT_SEED);


/**
 * @brief helper function to get the initial random generator
 * @tparam T the RealArithmetic
 * @param seed the seed
 * @return the generator
 */
inline std::mt19937 get_random_gen(size_t seed);


/**
 * @brief the function get the random dist according to the given type. uniform_int_distribution for
 * int and uniform_real_distribution for others
 * @tparam T the type
 * @param min the min value
 * @param max the max value
 * @return the random right random distribution
 */
template<RealDecimal T>
std::uniform_real_distribution<T> get_random_dist(T min, T max);


/// template specialization for integers
template<RealIntegral T>
std::uniform_int_distribution<T> get_random_dist(T min, T max);
}  // namespace random_utils


/********************************Definitions************************************************/


template<RealIntegral T>
std::uniform_int_distribution<T> random_utils::get_random_dist(T min, T max) {
    if (min >= max) {
        throw std::invalid_argument("the min value can't be bigger or equal to the max value");
    }
    return std::uniform_int_distribution<T>(min, max);
}


template<RealDecimal T>
std::uniform_real_distribution<T> random_utils::get_random_dist(T min, T max) {
    if (min >= max) {
        throw std::invalid_argument("the min value can't be bigger or equal to the max value");
    }
    return std::uniform_real_distribution<T>(min, max);
}


inline std::mt19937 random_utils::get_random_gen(size_t seed) {
    std::seed_seq seed_sequence = {seed};
    return std::mt19937(seed_sequence);
}


template<AnyArithmetic T>
std::vector<T> random_utils::generate_random_vector(int size,
                                                    size_t seed,
                                                    getInnerType_t_opt<T> min,
                                                    getInnerType_t_opt<T> max) {
    if (size <= 0) {
        throw std::invalid_argument("the size should be positive int bigger than 0");
    }

    /// if it is complex T inner type will return the type of complex else it will return the type.
    std::mt19937 gen = get_random_gen(seed);
    auto dist = get_random_dist(min, max);
    std::vector<T> random_vector(size);

    for (int i = 0; i < size; ++i) {
        if constexpr (ComplexArithmetic<T>) {
            random_vector[i] = T(dist(gen), dist(gen));
        } else if constexpr (RealArithmetic<T>) {
            random_vector[i] = dist(gen);
        } else {
            static_assert(!sizeof(T*),
                          "Only Arithmetic are accepted as T in generate_random_vector");
        }
    }
    return random_vector;
}


template<AnyArithmetic T>
T random_utils::generate_random_number(getInnerType_t_opt<T> min,
                                       getInnerType_t_opt<T> max,
                                       size_t seed) {
    /// if it is complex T inner type will return the type of complex else it will return the type.
    std::mt19937 gen = get_random_gen(seed);
    auto dist = get_random_dist(min, max);

    if constexpr (ComplexArithmetic<T>) {
        return T(dist(gen), dist(gen));
    } else if constexpr (RealArithmetic<T>) {
        return dist(gen);
    } else {
        static_assert(!sizeof(T*), "Only Arithmetic are accepted as T in generate_random_number");
    }
}
