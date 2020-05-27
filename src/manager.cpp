//
// Created by bartek on 5/26/20.
//

#include <manager.hpp>

bool Manager::spend(uint32_t amount) {
    money_ -= amount;
    return money_ > 0;
}

