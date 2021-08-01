#ifndef PERSON_HPP
#define PERSON_HPP

#include "Pesel.hpp"
#include <utility>
#include <string>

class Person
{
public:
    Person(std::string, std::string, std::string, Pesel, Gender);
    Person() = default;

    virtual ~Person();

private:
    std::string name_{};
    std::string surname_{};
    std::string address_{};
    Pesel pesel_{};
    Gender gender_{};
};

#endif /* PERSON_HPP */