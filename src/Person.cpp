#include "Person.hpp"

std::string get_string_to_char(std::istream& in, char delimiter) {
    std::string temp{};
    for (char current_char{}; in >> current_char;) {
        if (current_char == delimiter) {
            in.putback(current_char);
            break;
        }
        temp.push_back(current_char);
    }
    return temp;
}

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

std::istream& operator>>(std::istream& in, Person& person) {
    static constexpr char delim{','};
    char delim1{}, delim2{}, delim3{}, delim4{};
    person.name_ = get_string_to_char(in, delim);
    in >> delim1;
    person.surname_ = get_string_to_char(in, delim);
    in >> delim2;
    person.address_ = get_string_to_char(in, delim);
    in >> delim3 >> person.pesel_ >> delim4 >> person.gender_;
    if (delim1 != delim || delim2 != delim || delim3 != delim ||
        delim4 != delim || !person.pesel_.is_valid()) {
        in.clear(std::ios_base::failbit);
    }
    return in;
}

bool operator==(const Person& person1, const Person& person2) {
    return person1.name_ == person2.name_ &&
           person1.surname_ == person2.surname_ &&
           person1.address_ == person2.address_ &&
           person1.pesel_ == person2.pesel_ &&
           person1.gender_ == person2.gender_;
}