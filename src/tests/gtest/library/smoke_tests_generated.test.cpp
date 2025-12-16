#include <gtest/gtest.h>
#include <chord/lib.hpp>
#include "smoke_tests_generated.hpp"


TEST(LIB_GeneratedSmokeTests, AllFunctionsCompileAndLink) {
    EXPECT_NO_THROW({
        chord::StatusResult result = chord::multiply_with_scalar<float>(std::span<float>(), {}); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::multiply_with_scalar<float>(std::span<float>(), {}, std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::compute_exponential<float>(std::span<float>(), std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::compute_fractional_part<float>(std::span<float>(), std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::divide_by_scalar<float>(std::span<float>(), {}, std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::divide_by_scalar<float>(std::span<float>(), {}); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::divide_list_by_list<float>(std::span<float>(), std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::subtract<float>(std::span<float>(), std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::apply_square<float>(std::span<float>(), std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::apply_square<float>(std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::apply_flip<float>(std::span<float>(), std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::apply_flip<float>(std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::apply_absolute<float>(std::span<float>(), std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::apply_absolute<float>(std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::compute_complex_magnitude<float>(std::span<std::complex<float>>(), std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::fill_slope<float>(std::span<float>(), {}, {}); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::combine<float>(std::span<float>(), std::span<float>(), std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::combine<float>(std::span<float>(), std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::combine_with_scalar<float>(std::span<float>(), {}, std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::combine_with_scalar<float>(std::span<float>(), {}); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::apply_floor<float>(std::span<float>(), std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::compute_complex_conjugates<float>(std::span<std::complex<float>>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::find_minimum_and_index<float>(std::span<float>(), FLOAT, INT); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::find_minimum<float>(std::span<float>(), FLOAT); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::find_maximum_and_index<float>(std::span<float>(), FLOAT, INT); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::find_maximum<float>(std::span<float>(), FLOAT); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::compute_dot_product<float>(std::span<float>(), std::span<float>(), FLOAT); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::compute_sum<float>(std::span<float>(), FLOAT, {}); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::apply_raise_power_with_scalar<float>(std::span<float>(), {}, std::span<float>()); (void)result;
    });

    EXPECT_NO_THROW({
        chord::StatusResult result = chord::compute_complex_exponent<float>(std::span<float>(), std::span<std::complex<float>>()); (void)result;
    });

}