//
// Created by mayak on 6/29/25.
//

#include "builtin_math/math_std.hpp"
#include "utils/test_functions_helpers.hpp"

#include <gtest/gtest.h>


TEST(ApplyRaisePower, FloatInput) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<float> bases = {11.485189,
                                8.57778,
                                11.5618,
                                4.121964,
                                16.6503,
                                16.717745,
                                13.068,
                                3.20413,
                                10.418719,
                                6.545623};
    std::vector<float> expos = {1, 2, 3, 2, 1.6, 2.45, -1.2, 6, 3.3, 2};
    std::vector<float> res(10);

    std::vector<float> expected = {11.485189,
                                   73.57830972840001,
                                   1545.526149809032,
                                   16.990587217296003,
                                   90.00679566345397,
                                   992.6253371227823,
                                   0.045766642062043394,
                                   1082.0834866451062,
                                   2284.4795377150836,
                                   42.845180458129};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::apply_raise_power<float>(bases, expos, res);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<float>(expected, res, 1e-3);
}


TEST(ApplyRaisePowerWithScalar, ComplexFloatInput) {
    // SET VALUES -------------------------------------------------------------------------------
    std::vector<std::complex<float>> bases = {{0, 1},
                                              {1.0, 2.0},
                                              {3.69, 1.48},
                                              {0.592, 2.99},
                                              {6.98, 1.95}};

    std::complex<float> scalar = {1.1, 3};

    std::vector<std::complex<float>> res(5);

    std::vector<std::complex<float>> expected = {{-0.001405296325191093, 0.008872691801742525},
                                                 {-0.07717578719777447, -0.04120706913377257},
                                                 {-0.22031596450541785, -1.4366110801974374},
                                                 {0.007894231817196402, -0.0544515629111889},
                                                 {3.898327070135895, -0.16243951476625432}};

    // CALL FUNCTION ----------------------------------------------------------------------------
    math_std::apply_raise_power_with_scalar<std::complex<float>>(bases, scalar, res);

    // COMAPRE RESULTS --------------------------------------------------------------------------
    gtest_utils::test::compare_spans<std::complex<float>>(expected, res, 1e-6);
}
