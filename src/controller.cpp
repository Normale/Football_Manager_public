#include <controller.hpp>
using namespace std;
void Controller::start() {
    bool wanna_play = UI::start_menu();
    if (wanna_play) {

        read_players_from_file();
//        string player_name = UI::get_parameter("Please enter your name");
//        uint8_t player_age = UI::get_option("Please enter your age");
//        uint16_t player_nationality = UI::get_option("Please enter your nationality");
        manager = Manager("Your name", 20, 5);
//        string team_name = UI::get_parameter("Please enter your TEAM name");
        team = Team("Your Team");
        get_random_team();
        play_game();

    }
}


void Controller::read_players_from_file() {
    std::fstream f_in;
    f_in.open("players.txt", std::ios::in);
//    std::vector<Football_player> player_list;
    string line, word;

    string name;
    uint16_t age;
    uint16_t nationality;
    uint16_t max_rating;
    std::vector<int> positions_values;
    uint16_t preferred_position;
    uint32_t price;
    uint32_t salary;

    while (getline(f_in, line)) {
        std::stringstream s(line);
        positions_values.clear();
        getline(s, word, ',');
        name = word;
        //It seems kinda more efficient than splitting.
        for (int i = 1; getline(s, word, ','); i++) {
            int tmp = stoi(word);
            switch (i) {
                case 1:
                    age = tmp;
                case 2:
                    nationality =  tmp;
                case 3:
                    max_rating = tmp;
                case 4:
                    price = tmp;
                case 5:
                    salary =  tmp;
                case 6:
                    preferred_position =  tmp;
                default:
                    positions_values.push_back(tmp);
            }
        }
        Football_player tmp_player(name, age, nationality, max_rating, preferred_position, price, salary,
                                   positions_values);
        market.push_back(tmp_player);
    }
//    for (const auto& player: market){
//        std::cout << player.get_main_position() << std::endl;
//    }
}

void Controller::get_random_team() {
    int random_range_max = random_int(BEGINNING_RANDOM_INDEX, NUMBER_OF_PLAYERS_IN_FILE);
    int random_range_min = random_range_max - 500;

    std::vector<int> goalkeeper = {26};
//    std::vector<string> goalkeeper = {"GK"};
    fill_position_in_team(goalkeeper, 1, random_range_min, random_range_max);

    std::vector<int> defense = {1, 2, 6, 7, 9, 14, 16, 17, 19, 24};
//    std::vector<string> defense = {"LB", "LCB", "CB", "RCB", "RB", "LWB", "LDM", "CDM", "RDM", "RWB"};
    fill_position_in_team(defense, 4, random_range_min, random_range_max);
    std::vector<int> midfielders = {0, 4, 5, 8, 11, 15, 18, 21};
//    std::vector<string> midfielders = {"CM", "LCM", "LM", "RCM", "RM", "LAM", "CAM", "RAM"};
    fill_position_in_team(midfielders, 4, random_range_min, random_range_max);

    std::vector<int> offense = {3, 10, 12, 13, 20, 22, 23, 25};
//    std::vector<string> offense = {"ST", "LS", "RS", "LW", "LF", "CF", "RF", "RW"};
    fill_position_in_team(offense, 2, random_range_min, random_range_max);

//        std::vector<string> all = (const std::vector<std::basic_string<char>> &) positions;
    fill_position_in_team(defense, 2, random_range_min, random_range_max);
    fill_position_in_team(midfielders, 2, random_range_min, random_range_max);
    fill_position_in_team(offense, 2, random_range_min, random_range_max);

}

void Controller::fill_position_in_team(const std::vector<int>& desired_positions, int number_of_players, int range_begin,
                                       int range_end) {
    for (int i = range_begin; (number_of_players != 0 && i < range_end); i++) {
        if (!check_if_player_available(i)) {
            continue;
        }
        for (const auto& position : desired_positions) {
            if (market[i].get_main_position_id() == position) {
                team.add_new_player(i, market[i]);
                taken.push_back(i);
                number_of_players--;
            }
        }

    }
}

bool Controller::check_if_player_available(int id) {
    for (int i : taken) {
        if (i == id) {
            return false;
        }
    }
    return true;
}

void Controller::play_game() {
    bool wanna_quit = false;
    while (!wanna_quit) {
        UI::clear_screen();

//        day++;
        day == 4'294'967'295 ? (day = 1) : (day++);
        UI::print_day(day, manager.get_money(), team.get_weekly_cost() - team.get_weekly_income());

        if (day % 7 == 0) {
            manager.earn(team.get_weekly_income());
            bool can_afford = manager.spend(team.get_weekly_cost());
            if (!can_afford) {
            }
        }
        bool next_day = false;
        while (!next_day) {
            int option = UI::daily_menu();
            int team_power = team.get_team_power();
            int team_power_tier = team.get_power_tier();

            //Depending on tier, player gets different players
            // 0 = TIER 1 (60-70), ~4500 players
            // 1 = TIER 2 (70-75), ~4000 players
            // 2 = TIER 3 (75-100) ~1500 players
            std::vector<int> players_ids = get_players_from_market(team_power_tier);
            switch (option) {
                case 1: {
                    int choice = UI::market_menu(players_ids, market);
                    if (choice == 9) {
                        break;
                    } else {
                        int id = players_ids[choice];
                        buy_player(id);
                        break;
                    }
                }
                case 2:
                    team.train_team(day);
                    UI::team_trained();
                    break;
                case 3: {
                    int result = team.play_match(day);
                    UI::match_result(result);
                    int earned = team.get_weekly_cost() * (result + 2);
                    UI::money_earned(earned);
                    manager.earn(earned);
                    break;
                }
                case 4:
                    UI::clear_screen();
                    manage_team();
                    break;
                case 5:
                    next_day = true;
                    break;
                    //MANAGE TEAM;
                case 9:
                    wanna_quit = UI::exit_menu();
                    next_day = wanna_quit;
                    break;
                default:
                    break;
            }
        }
    }
    UI::lost_screen();


}
int Controller::get_random_player(int range_min, int range_max){
    int id = random_int(range_min, range_max);
    if (!check_if_player_available(id)){
        id = get_random_player(range_min, range_max);
    }
    return id;

}

std::vector<int> Controller::get_players_from_market(int tier) {
    int random_range_max=0, random_range_min=0;
    std::vector<int> players{};
    switch (tier) {
        //first 70: 5756
        //first 75: 1588
        // 0 --- 1588(75) --- 5756 --- 10000
        case 0:
            random_range_max = 10000;
            random_range_min = 5756;
            break;
        case 1:
            random_range_max = 5756 + 1;
            random_range_min = 1588 - 1;
            break;
        case 2:
            random_range_max = 1588;
            random_range_min = 0;
            break;
        default:
            random_range_max = 10000;
            random_range_min = 5756;
            break;
    }
    for (int i=0; i < NUMBER_OF_PLAYERS_IN_MARKET; i++){
        int player_id = get_random_player(random_range_min, random_range_max);
        players.push_back(player_id);
    }
    return players;

}

void Controller::buy_player(int id) {
    if (!check_if_player_available(id)) {
        UI::err_player_taken();
        return;
    }
    Football_player chosen = market[id];
    int chosen_price = chosen.get_price();
    if (chosen_price < manager.get_money()) {
        manager.spend(chosen_price);
        team.add_new_player(id, chosen);
        taken.push_back(id);
        UI::player_bought();
    } else {
        UI::err_cant_afford();
    }
}

void Controller::manage_team() {
    int option = UI::manage_team_menu();
    int max_id = team.get_no_players_in_team() - 1;
    switch (option) {
        case 1: {
            UI::print_team_players(team);
            std::tuple<uint8_t, uint8_t> to_swap = UI::swap_menu(max_id);
            team.swap_players(std::get<0>(to_swap), std::get<1>(to_swap));
        }
        case 2: {
            UI::print_team_players(team);
            int id_to_sell = UI::sell_menu(max_id);
            if (id_to_sell == 9){
                break;
            }
            int sell_price = (int)team.get_players_list()[id_to_sell].get_price() / 2;
            manager.earn(sell_price);
            team.remove_player(id_to_sell);
            UI::money_earned(sell_price);
        }
        case 3: {
            bool upgrade = UI::upgrade_menu(team.get_upgrade_cost(), manager.get_money(),
                                            team.get_trainer_effectiveness());
            if (upgrade) {
                manager.spend(team.get_upgrade_cost());
                team.upgrade_trainer();
            }
        }
        case 4: {
            int current_formation = team.get_formation_id();
            int formation_id = UI::formation_change_menu(current_formation);
            if (formation_id == 9){
                break;
            }
            team.set_formation(formation_id);
        }
        case 5:
            UI::print_team_stats(team);
            break;
        case 6:
            UI::inspect_player_menu(team);
            break;
        default:
            break;
    }

}




