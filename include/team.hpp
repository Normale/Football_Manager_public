#ifndef FOOTBALL_MANAGER_TEAM_HPP
#define FOOTBALL_MANAGER_TEAM_HPP

#include "string"
#include "vector"
#include "algorithm"
#include "cstdlib"
#include "utils.hpp"


#include "my_football_player.hpp"
#include "constants.h"

class Team {
private:
    std::string team_name = "Neuer Gonna Give You Up";

    int formation_id = 0;
    formation_t formation = formations[formation_id];
    int team_power = 0;

    uint8_t trainer_effectiveness = 1;


    uint32_t upgrade_cost = 10;

    uint32_t weekly_cost = 0;
    uint32_t weekly_income;

    std::vector<Hired_football_player> players_list;

    //check if team is valid, ex: there are 11 players playing
//    bool check_validity();

    void update_parameters();
    void update_team_power();
    void update_weekly_cost();
    void update_weekly_income();

public:
    Team(string name) : team_name(name){};
    Team() = default;

    string get_team_name() const;
    int get_team_power() const {return team_power;};
    int get_power_tier() const;

    uint8_t get_trainer_effectiveness() const;

    const std::vector<Hired_football_player>& get_players_list() const;

    //in_index, out_index - index of player (in player_list) who should be swapped
    void swap_players(uint8_t in_index, uint8_t out_index);

    //change formation of team and rearrange players positions to fit into new one
    void set_formation(int formation_id);
    int get_formation_id() const{return formation_id;};

    //returns result (chance):
    //-1 = LOSE (40%)
    // 0 - DRAW (20%)
    // 1 = WIN  (40%)
    int play_match(uint32_t day);

    void add_new_player(int id, Football_player &player);

    void remove_player(uint8_t index);

    void upgrade_trainer();

    //calls My_football_player.train() in every player of player_list()
    void train_team(uint32_t day);
    int32_t get_upgrade_cost() const{return upgrade_cost;};



    //returns weekly cost of team maintenance
    int get_weekly_cost() const{return weekly_cost;};
    int get_weekly_income() const{return weekly_income;};

    int get_no_players_in_team() const{return players_list.size();}

};


#endif //FOOTBALL_MANAGER_TEAM_HPP
