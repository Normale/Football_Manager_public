#ifndef FOOTBALL_MANAGER_MANAGER_HPP
#define FOOTBALL_MANAGER_MANAGER_HPP

#include <utility>

#include "person.hpp"

class Manager : public Person {
private:
    int64_t money_=0;
public:
//    using Person::Person;
    Manager(string name, uint8_t age, uint16_t nationality, uint32_t money):
                                                                Person(std::move(name), age, nationality),
                                                                money_(money){};
    bool spend(uint32_t amount);
    void earn(uint32_t amount){money_ += amount;};
    uint64_t get_money() const { return money_;};


    Manager(const string &name, uint8_t age, uint16_t nationality) : Person(name, age, nationality) {}
};



#endif //FOOTBALL_MANAGER_MANAGER_HPP
