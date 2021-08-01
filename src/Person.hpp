#ifndef PERSON_HPP
#define PERSON_HPP

#include "Pesel.hpp"
#include <utility>
#include <string>
#include <string_view>

class Person
{
public:
    Person(const std::string&, const std::string&, const std::string&, const Pesel&, Gender);
    Person(std::string&&, std::string&&, std::string&&, Pesel&&, Gender);
    Person(const Person& person) = default;
    Person(Person&& person) = default;

    Person& operator= (const Person& person) = default;
    Person& operator= (Person&& person) = default;

    virtual ~Person();

    // Getters
    [[nodiscard]] std::string get_name() const      { return name_; }
    [[nodiscard]] std::string get_surname() const   { return surname_; }
    [[nodiscard]] std::string get_address() const   { return address_; }
    [[nodiscard]] Pesel get_pesel() const           { return pesel_; }
    [[nodiscard]] Gender get_gender() const         { return gender_; }

    // Setters
    void set_name(std::string&& name)               { name_ = name; }
    void set_name(const std::string& name)          { name_ = name; }
    void set_surname(std::string&& surname)         { surname_ = surname; }
    void set_surname(const std::string& surname)    { surname_ = surname; }
    void set_address(std::string&& address)         { address_ = address; }
    void set_address(const std::string& address)    { address_ = address; }
    void set_pesel(Pesel&& pesel)                   { pesel_ = pesel; }
    void set_pesel(const Pesel& pesel)              { pesel_ = pesel; }
    void set_gender(Gender gender)                  { gender_ = gender; }

private:
    std::string name_{};
    std::string surname_{};
    std::string address_{};
    Pesel pesel_{};
    Gender gender_{};
};

#endif /* PERSON_HPP */