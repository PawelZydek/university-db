#include "Person.hpp"

Person::Person(const std::string& name,
               const std::string& surname,
               const std::string& address,
               const Pesel& pesel,
               Gender gender)
    : name_{name},
      surname_{surname},
      address_{address},
      pesel_{pesel},
      gender_{gender} {
    if (!pesel_.is_valid()) {
        throw std::runtime_error{"not a valid pesel"};
    }
}

Person::Person(std::string&& name,
               std::string&& surname,
               std::string&& address,
               Pesel&& pesel,
               Gender gender)
    : name_{std::move(name)},
      surname_{std::move(surname)},
      address_{std::move(address)},
      pesel_{std::move(pesel)},
      gender_{gender} {
    if (!pesel_.is_valid()) {
        throw std::runtime_error{"not a valid pesel"};
    }
}

Person::~Person() {}

// Setters
void Person::set_pesel(Pesel&& pesel) {
    if (!pesel.is_valid()) {
        throw std::runtime_error{"not a valid pesel"};
    }
    pesel_ = std::move(pesel);
}

void Person::set_pesel(const Pesel& pesel) {
    if (!pesel.is_valid()) {
        throw std::runtime_error{"not a valid pesel"};
    }
    pesel_ = pesel;
}

std::ostream& operator<<(std::ostream& out, const Person& person) {
    return out << person.name_ << ',' << person.surname_ << ','
               << person.address_ << ',' << person.pesel_ << ','
               << person.gender_;
}