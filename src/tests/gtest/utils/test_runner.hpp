//
// Created by userk on 6/3/25.
//

#pragma once

#include <gtest/gtest.h>
#include <iostream>


namespace gtest_utils {
int inline run_tests(int argc, char* argv[], const char *module_name, int tests_reps) {
    std::cout << module_name << " tests main!" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    int result;
    for (int i = 0; i < tests_reps; i++) {
        result = RUN_ALL_TESTS();

        if (result != 0) {
            break;
        }
    }

    if (!result) {
        std::cout << "ALL TESTS PASSED SUCCESSFULLY" << std::endl;
    } else {
        std::cout << "SOME TESTS FAILED" << std::endl;
    }
    return result;
}
}
