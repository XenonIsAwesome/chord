//
// Created by userk on 5/4/25.
//


#include <chord/lib.hpp>
#include <vector>


int main() {
    const std::vector<float> a = {1, 2, 3};
    std::vector<float> d_a(3);

    float m = 0;
    chord::compute_mean_value<float>(a, m);

    std::cout << chord::combine_with_scalar<float>(a, 4.3, d_a);

    for (auto val : d_a) {
        std::cout << val << std::endl;
    }


    std::vector<float> b = {1, 2, 3};

    if (!chord::multiply_with_scalar<float>(b, 4.3)) {
        std::cout << "GGGGGGGGGG";
    };

    for (auto val : b) {
        std::cout << val << std::endl;
    }

    return 0;
}
