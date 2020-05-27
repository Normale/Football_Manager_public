//#include <iostream>
//#include "cassert"
//#include "stdexcept"
//#include "../include/manager.hpp"
//#include "../include/team.hpp"
//#include "../include/my_football_player.hpp"
//#include "../include/read_players.hpp"
//
//#include "array"
//
//using namespace std;


//typedef struct parameters {
//    string name = "name";
//    uint8_t age = 5;
//    uint16_t nationality_id = 0;
//    string nationality = nationalities[nationality_id];
//    array<uint8_t, 27> position_values = {89, 53, 62, 91, 82, 89, 61, 53, 82, 62, 91, 89, 92, 91, 66, 89, 61, 53, 82,
//                                          62, 91,
//                                          89, 92, 91, 66, 92};
//    uint8_t preferred_position = 0;
//    uint64_t price = 500'000'000;
//    uint32_t salary = 50'000;
//} parameter_struct;
//
//void check_name(Person &person, string name) {
//    assert(person.get_name() == name);
//}
//
//void check_age(Person &person, uint8_t age) {
//    assert(person.get_age() == age);
//}
//
//void check_nationality(Person &person, string nationality) {
//    assert(person.get_nationality() == nationality);
//}
//
//void person_test(Person &person, const parameter_struct &params) {
//    //Person construction test
//
//    check_name(person, params.name);
//    check_age(person, params.age);
//    check_nationality(person, params.nationality);
//}
//
//void manager_test(const parameter_struct &params) {
//    Manager m1(params.name, params.age, params.nationality_id);
//    person_test(m1, params);
//
//    //earn() and spend() tests
//    uint64_t x = 1000000, y = 1000;
//    assert(m1.get_money() == 0);
//    m1.earn(x);
//    assert(m1.get_money() == x);
//    m1.spend(y);
//    assert(m1.get_money() == (x - y));
//
//    //spending more money than you have should throw an error
//    try {
//        m1.spend(2 * x);
//    } catch (logic_error &error) {
//        cerr << "Error succesfuly caught: " << error.what() << endl;
//    }
//}
//
//void football_player_test(Football_player &f1, const parameter_struct &params) {
//    person_test(f1, params);
//
//    //Football_player construction test
//    for (int i = 0; i < 27; i++) {
//        assert(f1.get_position_rating(i) == params.position_values[i]);
//    }
//    assert(f1.get_main_position() == positions[params.preferred_position]);
//    assert(f1.get_price() == params.price);
//    assert(f1.get_salary() == params.salary);
//
//}
//
//void raw_football_player_test(const parameter_struct &params) {
//
//    Football_player f1(params.name, params.age, params.nationality_id,
//                       params.position_values, params.preferred_position, params.price, params.salary);
//    football_player_test(f1, params);
//}
//
//int training_test(Hired_football_player &myFootballPlayer, uint16_t no_trainings,
//                  uint8_t break_time, uint8_t effectiveness) {
//    int begin_rating = myFootballPlayer.get_current_rating();
//    int day = 0;
//    for (int i = 0; i < no_trainings; i++) {
//        myFootballPlayer.train(effectiveness);
//        day += (1 + break_time);
//    }
//    return myFootballPlayer.get_current_rating() - begin_rating;
//}
//
//
//int matches_test(Hired_football_player &myFootballPlayer, uint16_t no_matches, uint8_t break_time, uint8_t result,
//                 bool reserve = false) {
//    int begin_rating = myFootballPlayer.get_current_rating();
//    for (int i = 0; i < no_matches; i++) {
//        myFootballPlayer.play_match(result, reserve);
//        myFootballPlayer.rest();
//    }
//    return myFootballPlayer.get_current_rating() - begin_rating;
//}
//
//
//void hired_football_player_test(const parameter_struct &params) {
//    //Hired_football_player construction test
//    //by default current_position = 0
//    Hired_football_player hired_football_player(params.name, params.age, params.nationality_id, params.position_values,
//                                                params.preferred_position, params.price, params.salary);
//
//    assert(hired_football_player.get_current_rating() == params.position_values[0]);
//    assert(hired_football_player.get_current_position() == positions[0]);
//
//    //set_current_position() test
//    hired_football_player.set_current_position(1);
//    assert(hired_football_player.get_current_rating() == params.position_values[1]);
//    assert(hired_football_player.get_current_position() == positions[1]);
//
//    assert(hired_football_player.get_sell_price() == params.price / 2);
//    //days_since_last_match() and play_match() test
//    uint16_t day = 0;
//    hired_football_player.play_match(2, false);
//    assert(hired_football_player.days_since_last_match(day) == 0);
//    day = 5;
//    assert(hired_football_player.days_since_last_match(day) == 5);
//
//    //train() test
//    assert(training_test(hired_football_player, 50, 1, 2) == 1); //succesful training
//    assert(hired_football_player.get_current_rating() == 90); // after succesful trainng, rating should be bigger
//    assert(training_test(hired_football_player, 1, 1, 1) == 0);
//    assert(training_test(hired_football_player, 50, 0, 1) == 0); //trainings without break makes no effect
//    Hired_football_player hired_football_player_2(params.name, params.age, params.nationality_id, params.position_values,
//                                                  params.preferred_position, params.price, params.salary);
//
//    // match is more effective training //testing if it works
//    assert(matches_test(hired_football_player_2, 10, 7, 2, false) == 1);
//    // you need 7 days break between matches, if not, the players will not get better (but its possible to play a match)
//    assert(matches_test(hired_football_player_2, 10, 6, 2, false) == 0);
//    // immediately after match, rating of player should decrease a bit
//    assert(matches_test(hired_football_player_2, 1, 0, 0, false) < 0);
//}
//
//
//int train_team_test(Team &team, uint16_t no_trainings, uint16_t no_upgrades) {
//    uint16_t before_training_score = team.get_team_power();
//    for (int i = 0; i < no_upgrades; i++) {
//        team.upgrade_trainer();
//    }
//    for (int i = 0; i < no_trainings; i++) {
//        team.train_team();
//        team.rest();
//    }
//    return team.get_team_power() - before_training_score;
//
//}
//
//
//void team_test(const parameter_struct &params) {
//    //team creation test
//    string team_name = "Neuer gonna give you up";
//    Team team(team_name);
//    assert(team.get_team_name() == team_name);
//
//    //add_new_player() and swap_players() tests
//    for (int i = 0; i < 15; i++) {
//        Football_player tmp_player(params.name + (char) i, params.age, params.nationality_id,
//                                   params.position_values,
//                                   params.preferred_position, params.price, params.salary);
//        team.add_new_player(tmp_player);
//        team.swap_players(i + 15, i);
//    }
//    assert(team.get_team_power() == (11 * params.position_values[1]));
//    assert(team.get_weekly_cost() > (15 * params.salary));
//    assert(team.play_match(11 * 53) == 0);
//
//    //set_formation() test
//    uint8_t test_formation[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//    team.set_formation(test_formation);
//    assert(team.get_team_power() == (11 * 89));
//
//    //swap_players() test
//    array<uint8_t, 27> test_pos_values = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
//                                          100, 100,
//                                          100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
//    Football_player test_player("Test", "Player", params.age, params.nationality_id,
//                                test_pos_values, params.preferred_position, params.price, params.salary);
//    team.add_new_player(test_player);
//    team.swap_players(31, 1);
//    assert(team.get_team_power() == (10 * 53 + 100));
//
//    //Playing match without whole squad should throw error
//    // play_match() and remove_player() tests
//    team.remove_player(1);
//    try {
//        team.play_match(1000);
//    } catch (logic_error &error) {
//        cerr << error.what() << endl;
//    }
//    team.add_new_player(test_player);
//    team.remove_player("Player");
//    try {
//        team.play_match(1000);
//    } catch (logic_error &error) {
//        cerr << error.what() << endl;
//    }
//
//    //train_team() and upgrade_trainer() tests
//    //training after upgrades should have better effect than before
//    int without_upgrades = train_team_test(team, 100, 0);
//    assert(without_upgrades > 0);
//    int with_upgrades = train_team_test(team, 100, 10);
//    assert(with_upgrades > 0);
//    assert(with_upgrades > without_upgrades);
//}
//
//
//void reading_print(const std::vector<Football_player>& player_list){
//    for (const auto& player : player_list){
//        std::cout << player.get_name() << std::endl;
//    }
//}
//int main() {
////    parameter_struct params;
////    manager_test(params);
////    raw_football_player_test(params);
////    hired_football_player_test(params);
////    team_test(params);
//    std::vector<Football_player> player_list = read_players();
//    reading_print(player_list);
//    std::cout << "End" << std::endl;
//    return 0;
//}
