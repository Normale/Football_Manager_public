//
// Created by bartek on 5/23/20.
//

#include <UI.hpp>

using namespace std;

//bool UI::is_number(int x) {
//    return (x >= '0' && x <= '9');
//}

bool UI::is_choice_valid(int choice, std::vector<uint8_t> valid_numbers) {
    return std::binary_search(valid_numbers.begin(), valid_numbers.end(), choice);
}

int UI::get_option(const string &display_question="") {
    int option; //Do not change to uint8_t cause cpp treat it as character xD
    cout << display_question << endl;
    do {
        cin >> option;
        //some message if not in range
    } while (option < 1 || option > 255);
    return option;
}

string UI::get_parameter(const string &display_question="") {
    string user_input;
    cout << display_question << endl;
    do {
        cin >> user_input;
        if (user_input.length() > 30) {
            cout << "Please, choose a shorter one" << endl;
        }
    } while (user_input.empty() || user_input.length() > 30);
    return std::move(user_input);
}

bool UI::start_menu() {
    cout << "Welcome to the Football manager. Choose, what would you like to do\n"
            "1. Play new game\n"
            "9. QUIT" << endl;
    return get_option() == 1;
}

bool UI::exit_menu() {
    uint8_t option = get_option("Are you sure you want to quit?\n1 - QUIT\nPRESS ANYTHING TO CONTINUE THE GAME");
    return option == 1;
}

uint8_t UI::daily_menu() {
    int option;
    cout << "1. Enter the Market\n"
            "2. Train team\n"
            "3. Play a match\n"
            "4. Manage Team:\n"
            "5. Go next day.\n\n"
            "9. QUIT THE GAME." << endl;
    do {
        option = get_option();
    } while (!is_choice_valid(option, {1, 2, 3, 4, 5, 9}));
    return option;
}

uint8_t UI::manage_team_menu() {
    int option;
    cout <<
         "1. Swap players belonging to his team\n"
         "2. Sell player\n"
         "3. Upgrade trainer\n"
         "4. Change formation of team\n"
         "5. View team details\n"
         "6. View player details\n"
         "9 - BACK" << endl;
    do {
        option = get_option();
    } while (!is_choice_valid(option, {1, 2, 3, 4, 5, 6, 9}));
    return option;
}

void UI::print_team_stats(const Team &team) {
    cout <<
         team.get_team_name() <<
         "\nPOWER :" <<
         team.get_team_power() <<
         "\nWEEKLY COST:" <<
         team.get_weekly_cost() <<
         "\nWEEKLY INCOMES" <<
         team.get_weekly_income() <<
         "\nTRAINER EFFECTIVENESS" <<
         team.get_trainer_effectiveness() <<
         "\nFORMATION" <<
         team.get_formation_id() << endl;
}

void UI::print_player(const Football_player &player) {
    cout <<
         player.get_name() << " " <<
         player.get_max_rating() << " " <<
         player.get_main_position() << " " <<
         player.get_price() << endl;
}

void UI::print_player(const Hired_football_player &player) {

    cout <<
         player.get_name() << " " <<
         player.get_current_position() << " ";
    if (player.get_current_position() == "RESERVE" || player.get_current_position() == "IDLE"){
        cout << player.get_max_rating() << " ";
    } else {
        cout << player.get_current_rating() << "/" <<
        player.get_max_rating() << " ";
    }
         cout << player.get_salary() << "$" << endl;

}

void UI::detailed_print_player(const Football_player &player) {
    cout << "PLAYER PROFILE" <<
         "Name: " << player.get_name() <<
         "Age: " << player.get_age() <<
         "Nationality" << player.get_nationality() <<
         "Max Rating: " << player.get_max_rating() <<
         "Main Position: " << player.get_main_position() <<
         "Salary: " << player.get_salary() <<
         "Price: " << player.get_price() << endl;
}

void UI::detailed_print_player(const Hired_football_player &player) {
    cout << "PLAYER PROFILE" <<
         "Name: " << player.get_name() <<
         "Age: " << player.get_age() <<
         "Nationality" << player.get_nationality() <<
         "Rating: " << player.get_current_rating() <<
         "Max Rating: " << player.get_max_rating() <<
         "Current Position: " << player.get_current_position() <<
         "Main Position: " << player.get_main_position() <<
         "Salary: " << player.get_salary() <<
         "Price: " << player.get_price() <<
         "Sell price_: " << player.get_sell_price() << endl;
}

void UI::print_team_players(const Team &team) {
    std::vector<Hired_football_player> players = team.get_players_list();
    cout << "ID NAME POS. RATING SALARY" << endl;
    for (int i = 0; i < players.size(); i++) {
        cout << i;
        print_player(players[i]);
    }
}

std::tuple<uint8_t, uint8_t> UI::swap_menu(uint8_t max) {
    int first, second;
    std::vector<uint8_t> valid = range(max);
    cout << "SWAP (if you want to leave, swap player with himself)" << endl;
    do {
        first = get_option("Please, pass first player ID");
    } while (!is_choice_valid(first, valid));
    do {
        second = get_option("Please, pass second player ID");
    } while (!is_choice_valid(second, valid));
    return std::make_tuple(first, second);
}

uint8_t UI::market_menu(std::vector<int> player_ids, const std::vector<Football_player> &market) {
    cout << "You randomised those players" << endl;
    for (auto i : player_ids) {
        print_player(market[i]);
    }
    cout << "9. SKIP" << endl;
    uint8_t buy_id;
    do {
        buy_id = get_option("Please, type in the ID of player you would like to buy.\n");
    } while (!is_choice_valid(buy_id, {1, 2, 3, 9}));
    if (buy_id != 9){
        cout << "Trying to buy player!" << endl;
    }
    return buy_id;
}

void UI::print_day(int day, uint32_t money, uint32_t weekly_spendings) {
    cout << "Current Day: " << day <<
         "\nYou have " << money << " $\n" <<
         "You are losing: " << weekly_spendings << "$ every week" << endl;
}

void UI::err_cant_afford() {
    cout << "Sorry, you can not afford this player." << endl;
}

void UI::err_player_taken() {
    cout << "Sorry, you already bought this player." << endl;
}


void UI::match_result(int result) {
    cout << "You played match" << endl;
    switch (result) {
        case -2:
        case -1:
            cout << "Enemy was too strong. LOST." << endl;
            break;
        case 0:
            cout << "Match was close. DRAW" << endl;
            break;
        case 1:
        case 2:
            cout << "YOU WON, CONGRATULATIONS" << endl;
            break;
        default:
            break;
    }

}


void UI::lost_screen() {
    cout << "BYE." << endl;
}

void UI::money_earned(int money) {
    cout << "You earned " << money << "$" << endl;
}

//return 1 = leave without changes.
uint8_t UI::sell_menu(u_int8_t max) {
    std::vector<uint8_t> valid = range(max);
    int id;
    cout << "SELL ( PRESS 9 TO LEAVE)" << endl;
    do {
        id = get_option("Whom do you want to sell? \nRemember, you will get half of its original price. \n(Pass ID)");
        if (id == 9) {
            return 9;
        }
        if (id < 11) {
            cout << "You can not sell first squad player. Move him out of squad first" << endl;
            continue;
        }
    } while (!is_choice_valid(id, valid));
    return id;
}

std::vector<uint8_t> UI::range(uint8_t max) {
    std::vector<uint8_t> range_(max);
    std::iota(std::begin(range_), std::end(range_), 0);
    return range_;
}

bool UI::upgrade_menu(int cost, int money, int current_trainer_effectiveness) {
    if (current_trainer_effectiveness == 10) {
        cout << "You already have MAX trainer level" << endl;
        return false;
    }
    cout << "Trainer Upgrade costs " << cost << '$' << endl;
    if (cost > money) {
        cout << "You have " << money << "$." << "Come back later." << endl;
        return false;
    }
    cout << "Do you want to upgrade?" << endl;
    int option;
    do {
        option = get_option("Press 1 - YES, 9 - NO");
    } while (!is_choice_valid(option, {1, 9}));
    return option == 1;
}


void UI::print_formation(int id) {
    cout << id << ". " << formations[id].name << endl;
}


void UI::print_formations() {
    for (int formation_id = 0; formation_id < formations.size(); formation_id++) {
        print_formation(formation_id);
    }
}


int UI::formation_change_menu(int current) {
    cout << "Your current formation is ";
    print_formation(current);

    print_formations();
    int formation_choice;
    do {
        formation_choice = get_option("Choose, which formation do you want (9 - BACK):");
        if (formation_choice == 9) {
            return 9;
        }
    } while (!is_choice_valid(formation_choice, range(formations.size())));
    cout << "Your formation has been successfully set to ";
    print_formation(formation_choice);
    return formation_choice;
}


void UI::inspect_player_menu(Team &team) {
    print_team_players(team);
    int inspect_player_id;
    do {
        inspect_player_id = UI::get_option("Which player details would you like to see?");
    } while (!is_choice_valid(inspect_player_id, range(team.get_no_players_in_team())));
    detailed_print_player(team.get_players_list()[inspect_player_id]);
}


void UI::team_trained(){
    cout << "Training successfully done." << endl;
}

void UI::clear_screen(){
    system("@cls||clear");
}

void UI::loading() {
    cout << "Loading..." << endl;
}

void UI::player_bought() {
    cout << "Player Bought!" << endl;
}
