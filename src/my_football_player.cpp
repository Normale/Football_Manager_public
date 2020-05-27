//
// Created by bartek on 4/28/2020.
//

#include "../include/my_football_player.hpp"

#include <utility>


uint16_t Hired_football_player::get_current_rating() const {
    return get_position_rating(current_position);
}

string Hired_football_player::get_current_position() const {
    switch (current_position) {
        case 100:
            return "RESERVE";
        case 200:
            return "IDLE";
        default:
            return positions[current_position];
    }
}

void Hired_football_player::set_current_position(uint16_t position_index) {
    current_position = position_index;
}

uint32_t Hired_football_player::days_since_last_training(uint8_t current_day) const {
    return current_day - last_training;
}

void Hired_football_player::train(uint8_t effectiveness, uint32_t day) {
    int days_since_prev_train = days_since_last_training(day);
    if(days_since_prev_train == 0){
        return;
    }else if(days_since_prev_train == 1){
        training_progress += effectiveness;
    }else{
        training_progress += 3 * effectiveness;
    }

    if (training_progress >= 100){
        level_up();
    }
    last_training = day;
}

void Hired_football_player::level_up() {
    for(auto position_value : positions_values_){
        if(position_value == 100){
            continue;
        }else {
            position_value++;
        }
    }
}

Hired_football_player::Hired_football_player(uint32_t id, Football_player &player) : id_(id), Football_player(player){

}

//Hired_football_player::Hired_football_player(string name, uint8_t age, uint16_t nationality, uint8_t maxVal,
//                                             uint8_t preferredPosition, uint32_t price, uint32_t salary,
//                                             std::vector<int> positionsValues, uint16_t id,
//                                             const Football_player &player) : Football_player(std::move(name), age, nationality,
//                                                                                              maxVal, preferredPosition,
//                                                                                              price, salary,
//                                                                                              std::move(positionsValues)),
//                                                                              id_(id){}
