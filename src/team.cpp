//
// Created by bartek on 4/26/2020.
//

#include "../include/team.hpp"


using namespace std;
string Team::get_team_name() const {
    return team_name;
}


int Team::get_power_tier() const {
    return (get_team_power() - 600) / 88;
}

uint8_t Team::get_trainer_effectiveness() const {
    return trainer_effectiveness;
}

const std::vector<Hired_football_player> &Team::get_players_list() const {
    return players_list;
}

void Team::swap_players(uint8_t in_index, uint8_t out_index) {
    std::swap(players_list[in_index], players_list[out_index]);
    update_parameters();
}

void Team::update_team_power() {
    int score = 0;
    for (int i = 0; i < 11; i++) {
        score += players_list[i].get_current_rating();
    }

    team_power = score;
}

void Team::update_weekly_cost() {
    int64_t cost = 0;
    for (const auto &player : players_list) {
        cost += player.get_salary();
    }
    weekly_cost = (uint32_t) cost;

}

void Team::update_weekly_income() {
    weekly_income = (weekly_cost * 3) / 4;
}

void Team::set_formation(int id) {
    formation_id = id;
    formation = formations[formation_id];
}

void Team::update_parameters() {
    update_team_power();
    update_weekly_cost();
    update_weekly_income();
}


int Team::play_match(uint32_t day) {
    int result = random_int(-2, 2);
    uint8_t tmp_effectiveness = trainer_effectiveness;
    switch (result) {
        case 1:
        case 2:
            trainer_effectiveness *= 2;
            break;
        case -1:
        case -2:
            trainer_effectiveness = 0;
            break;
        default:
            break;
    }
    train_team(day);
    trainer_effectiveness = tmp_effectiveness;
    return result;
}

void Team::upgrade_trainer() {
    trainer_effectiveness += 1;
}

void Team::add_new_player(int id, Football_player &player) {
    Hired_football_player new_player = Hired_football_player((uint32_t) id, player);
    int no_players = get_no_players_in_team();
    if(no_players <= 11){
        new_player.set_current_position(formation.formation_positions[no_players]);
    }else if (no_players < 18) {
        new_player.set_current_position(100);
    } else {
        new_player.set_current_position(200);
    };
    players_list.push_back(new_player);

    no_players++;
    if (no_players >= 11){
        update_parameters();

    }
}

void Team::train_team(uint32_t day) {
    for (auto player: players_list) {
        player.train(day, trainer_effectiveness);
    }
}

void Team::remove_player(uint8_t index) {
    players_list.erase(players_list.begin() + index - 1);
}


