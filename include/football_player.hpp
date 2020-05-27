#ifndef FOOTBALL_MANAGER_FOOTBALL_PLAYER_HPP
#define FOOTBALL_MANAGER_FOOTBALL_PLAYER_HPP

#include "person.hpp"
#include "array"
#include "constants.h"

class Football_player : public Person {

protected:
    //position is stored as an index of position in positions
    uint64_t price_;
    uint32_t salary_; //amount of money that manager has to pay weekly to player
    uint16_t overall_;
    //    std::array<uint8_t, 27> positions_values_;
    std::vector<int> positions_values_;
    int main_position_;
public:
//    Football_player(string name, uint8_t age, uint16_t nationality, uint8_t max_val, uint8_t preferred_position,
//                    uint32_t price, uint32_t salary, std::array<uint8_t, 27> positions_values) :
//                    Person(name, age, nationality), overall_(max_val),
//                    main_position_{preferred_position}, price_(price), salary_(salary), positions_values_(positions_values){};
    Football_player(string name, uint8_t age, uint16_t nationality, uint16_t max_val, uint16_t preferred_position,
                    uint32_t price, uint32_t salary, std::vector<int> positions_values) :
            Person(name, age, nationality), overall_(max_val),
            main_position_{preferred_position}, price_(price), salary_(salary), positions_values_(positions_values){};
    Football_player(const Football_player &other) = default;
//    uint8_t get_position_rating(uint8_t position) const{return positions_values_[position];};

    string get_main_position() const {return positions[main_position_];};
    int get_main_position_id() const {return main_position_;}

    uint64_t get_price() const{return price_;};

    uint64_t get_sell_price() const{return price_/2;};

    uint32_t get_salary() const{return salary_;};


    virtual int get_max_rating() const{return overall_;};
};


#endif //FOOTBALL_MANAGER_FOOTBALL_PLAYER_HPP
