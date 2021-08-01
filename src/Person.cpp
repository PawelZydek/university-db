#include "Person.hpp"

Person::Person(std::string name, std::string surname, std::string address, Pesel pesel, Gender gender)
    : name_{std::move(name)}, surname_{std::move(surname)}, address_{std::move(address)},
     pesel_{std::move(pesel)}, gender_{gender}
    {
    }

Person::~Person()
{
}
