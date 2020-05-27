#ifndef FOOTBALL_MANAGER_CONSTANTS_H
#define FOOTBALL_MANAGER_CONSTANTS_H


#include <array>

#define FILEPATH "players.txt"
#define BEGINNING_RANDOM_INDEX 8000 //Should be in range 0-8000, 0 = easiest game, 8000 = hardest game
#define NUMBER_OF_PLAYERS_IN_MARKET 3
#define NUMBER_OF_PLAYERS_IN_FILE 10000
#define TIER_01_BORDER  5756
#define TIER_12_BORDER  1588

const char *const nationalities[] = {"Portugal", "Argentina", "Brazil", "Uruguay", "Germany", "Poland", "Spain",
                                     "Belgium", "Chile", "Croatia", "Wales", "Italy", "Slovenia", "France", "Gabon",
                                     "Sweden", "Netherlands", "Denmark", "Slovakia", "England", "Colombia", "Austria",
                                     "Greece", "Czech Republic", "Costa Rica", "Armenia", "Bosnia Herzegovina",
                                     "Ivory Coast", "Senegal", "Switzerland", "Morocco", "Guinea", "Egypt", "Algeria",
                                     "Cameroon", "Serbia", "Japan", "Turkey", "Ecuador", "Montenegro", "Korea Republic",
                                     "Kenya", "Iceland", "Mexico", "Norway", "DR Congo", "Ukraine", "Russia", "Finland",
                                     "Republic of Ireland", "United States", "Venezuela", "Ghana", "Uzbekistan",
                                     "Nigeria", "Canada", "Paraguay", "Romania", "Albania", "Burkina Faso",
                                     "Cape Verde", "New Zealand", "Northern Ireland", "Syria", "Peru", "Scotland",
                                     "Bulgaria", "Angola", "Australia", "South Africa", "Jamaica", "Tunisia",
                                     "Mozambique", "Iran", "Mali", "Cuba", "Hungary", "Belarus", "Saudi Arabia",
                                     "China PR", "Israel", "Benin", "Georgia", "Dominican Republic", "Lithuania",
                                     "Kosovo", "Moldova", "Bolivia", "Togo", "FYR Macedonia", "Guinea Bissau",
                                     "Honduras", "Congo", "Chad", "Curacao", "Sierra Leone", "Gambia", "Iraq",
                                     "Trinidad & Tobago", "Zimbabwe", "Cyprus", "Latvia", "Niger", "Liechtenstein",
                                     "Oman", "Tanzania", "Zambia", "Libya", "Haiti", "Madagascar", "Estonia",
                                     "Guatemala", "New Caledonia", "Korea DPR", "Bermuda", "Comoros", "Panama",
                                     "Palestine", "Equatorial Guinea", "Eritrea", "Luxembourg", "Kuwait", "Suriname",
                                     "Uganda", "Mauritania", "El Salvador", "Central African Rep.", "Azerbaijan",
                                     "St Kitts Nevis", "Fiji", "Guam", "Lebanon", "Qatar", "Philippines", "Somalia",
                                     "Kazakhstan", "Montserrat", "Ethiopia", "Mauritius", "India", "Liberia",
                                     "Puerto Rico", "Namibia", "Faroe Islands", "Guyana", "Thailand", "Barbados",
                                     "Antigua & Barbuda", "Gibraltar", "São Tomé & Príncipe", "Grenada", "Belize",
                                     "Burundi", "Turkmenistan", "Swaziland", "Malta", "St Lucia", "Sudan", "Vietnam",
                                     "Afghanistan", "Sri Lanka", "Kyrgyzstan", "Brunei Darussalam", "San Marino",
                                     "Hong Kong"};
const char *const positions[] = {"CAM", "CB", "CDM", "CF", "CM", "LAM", "LB", "LCB", "LCM", "LDM", "LF", "LM", "LS",
                                 "LW", "LWB", "RAM", "RB", "RCB", "RCM", "RDM", "RF", "RM", "RS", "RW", "RWB", "ST", "GK", "GK"};

typedef struct formation {
    std::string name;
    std::array<uint8_t, 11> formation_positions;
} formation_t;


const std::vector<formation> formations = {
        formation_t{.name =  "4-4-3", .formation_positions =  {27, 1, 7, 17, 8, 18, 11, 21, 10, 20, 25}}, //0
        formation_t{.name = "CAM X11", .formation_positions={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}} //1
};
#endif //FOOTBALL_MANAGER_CONSTANTS_H

