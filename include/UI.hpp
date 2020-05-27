#ifndef FOOTBALL_MANAGER_UI_HPP
#define FOOTBALL_MANAGER_UI_HPP

#include "string"
#include "vector"
#include "algorithm"
#include "tuple"
#include "numeric"
#include "iostream"
#include <cstdlib>


#include "manager.hpp"
#include "team.hpp"
#include "constants.h"

class UI {
private:
    static std::vector<uint8_t> range(uint8_t max);
public:

    static void loading();
    static void clear_screen();

    //It takes int choice and ORDERED vector of valid numbers. Returns TRUE if choice is in vector.
    static bool is_choice_valid(int choice, std::vector<uint8_t> valid_numbers);

    //get input number from user
    static int get_option(const string& display_question);

    //get input string from user
    static std::string get_parameter(const string& display_question);

    static void team_trained();

    static void print_player(const Football_player& player);
    static void print_player(const Hired_football_player& player);

    static void detailed_print_player(const Football_player& player);
    static void detailed_print_player(const Hired_football_player& player);

    static void print_team_stats(const Team& team);
    static void print_team_players(const Team& team);

    static std::tuple<uint8_t, uint8_t>swap_menu(uint8_t max);
    static uint8_t sell_menu(u_int8_t max);
    static bool upgrade_menu(int cost, int money, int current_trainer_effectiveness);

    static bool start_menu();
    static bool exit_menu();
    static uint8_t daily_menu();
    static void print_day(int day, uint32_t money, uint32_t weekly_spendings);

    static uint8_t market_menu(std::vector<int> player_ids, const std::vector<Football_player>& market);
    static uint8_t manage_team_menu();

    static void lost_screen();

    static void err_cant_afford();
    static void err_player_taken();

    static void match_result(int result);
    static void money_earned(int money);

    static void print_formation(int id);
    static void print_formations();
    static int formation_change_menu(int current);


    static void inspect_player_menu(Team &team);
    static void player_bought();
};


#endif //FOOTBALL_MANAGER_UI_HPP
