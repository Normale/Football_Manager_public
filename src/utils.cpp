//
// Created by bartek on 5/27/20.
//

#include "utils.hpp"

int random_int(int range_min, int range_max) {
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(range_min, range_max);
    std::mt19937 engine(rd());

    int value = distribution(engine);
    return value;
}