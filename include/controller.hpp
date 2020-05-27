#ifndef FOOTBALL_MANAGER_CONTROLLER_HPP
#define FOOTBALL_MANAGER_CONTROLLER_HPP

#include "string"
#include "vector"
#include "cstdlib"
#include "numeric"

#include "manager.hpp"
#include "team.hpp"
#include "read_players.hpp"
#include "UI.hpp"
#include "utils.hpp"

class Controller {
private:
    uint32_t day=0;
    Manager manager = Manager("unnamed", 20 ,0,1'000'000);
    Team team;
    std::vector <Football_player> market;
    std::vector<int> taken;
    void read_players_from_file();

    //checks if player is available to buy. When he is in club, he can not be bought
    bool check_if_player_available(int id);
    //Takes player of the market and puts it into club.

    void fill_position_in_team(const std::vector<int>& desired_positions, int number_of_players, int range_begin, int range_end);

    void get_random_team();

    int get_random_player(int range_min, int range_max);
    //get 3 players pseudorandomly chosen from "players" vector
    std::vector<int> get_players_from_market(int tier);
    void buy_player(int id);
    void play_game();

    void manage_team();
public:
    Controller() = default;
    void start();

};


#endif //FOOTBALL_MANAGER_CONTROLLER_HPP
