#ifndef FOOTBALL_MANAGER_MY_FOOTBALL_PLAYER_HPP
#define FOOTBALL_MANAGER_MY_FOOTBALL_PLAYER_HPP

#include "football_player.hpp"

class Hired_football_player : public Football_player {
private:
    uint8_t training_progress = 0; // value in 0-99, if reaches 100, player is upgraded
    uint32_t last_training = 0;
    uint16_t id_;

    //index of element in positions
    // or 100 - Reserve
    // or 200 - not belonging to active squad, nor to reserve
    uint16_t current_position = 0;

    void level_up();

public:
//    Hired_football_player(uint16_t id, string name, uint8_t age, uint16_t nationality, uint8_t max_val, uint8_t preferred_position,
//    uint32_t price, uint32_t salary, std::vector<int> positions_values) :
//    Football_player(name, age, nationality, max_val, preferred_position, price, salary, positions_values), id_(id){};
//    Hired_football_player(string name, uint8_t age, uint16_t nationality, uint8_t maxVal,
//                          uint8_t preferredPosition, uint32_t price, uint32_t salary,
//                          std::vector<int> positionsValues, uint16_t id,
//                          const Football_player &player);
    Hired_football_player(uint32_t id, Football_player& player);
//    int get_max_rating() const{return positions_values_[main_position_];}
    int get_max_rating() const{return overall_;}

    uint16_t get_current_rating() const;
    uint16_t get_position_rating(uint16_t position) const{return positions_values_[position];};


    string get_current_position() const; //char * ??
    void set_current_position(uint16_t position_index);

    uint32_t days_since_last_training(uint8_t current_day) const;

    //Increments this.training_progress
    //If player had played a match or trained before this day, he does get nothing
    //If there was a break between training, the effects are 3 times bigger
    void train(uint8_t effectiveness, uint32_t day);
};

#endif //FOOTBALL_MANAGER_MY_FOOTBALL_PLAYER_HPP
