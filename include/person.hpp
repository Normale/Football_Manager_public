#ifndef FOOTBALL_MANAGER_PERSON_HPP
#define FOOTBALL_MANAGER_PERSON_HPP

#include "string"
#include "vector"
#include "constants.h"
using std::string;



class Person {
private:
    string name_;
    uint8_t age_;
    uint16_t nationality_; //nationality is stored as an index of element in nationalities
public:
    Person(string name, uint8_t age, uint16_t nationality) : name_(name),
                                                             age_(age), nationality_(nationality) {
    };
    Person(const Person& other) = default;
    string get_name() const { return name_; };

    uint8_t get_age() const { return age_; };

    string get_nationality() const { return nationalities[nationality_]; };

};

#endif //FOOTBALL_MANAGER_PERSON_HPP
