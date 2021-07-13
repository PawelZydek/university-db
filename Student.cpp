#include "Student.hpp"

#include <algorithm>
#include <array>
#include <utility>

std::string parseToChar(std::istream& in, char delim) {
    std::string str{};
    for (char ch{}; in >> ch;) {
        if (ch == delim) {
            in.putback(ch);
            break;
        }
        str.push_back(ch);
    }
    return str;
}

Student::Student(const std::string& name,
                 const std::string& surname,
                 const std::string& address,
                 unsigned int id_number,
                 const Pesel& pesel,
                 Gender gender)
    : name_{name},
      surname_{surname},
      address_{address},
      pesel_{pesel},
      id_number_{id_number},
      gender_{gender} {}

// TODO: Overload << operator for Student
std::ostream& operator<<(std::ostream& out, const Student& student) {
    return out << student.get_name() << ',' << student.get_surname() << ','
               << student.get_address() << ',' << student.get_id_number() << ','
               << student.get_pesel().get_string() << ','
               << student.get_gender();
}

std::istream& operator>>(std::istream& in, Student& student) {
    static constexpr char delim{','};  // CSV format
    std::array<char, 5> sep{};
    student.name_ = parseToChar(in, delim);
    in >> sep[0];
    student.surname_ = parseToChar(in, delim);
    in >> sep[1];
    student.address_ = parseToChar(in, delim);
    in >> sep[2] >> student.id_number_ >> sep[3] >> student.pesel_ >> sep[4] >>
        student.gender_;

    for (char ch : sep) {
        if (ch != delim) {
            in.clear(std::ios_base::failbit);
        }
    }
    return in;
}

// Setters implementation
void Student::set_gender(Gender) {
    gender_ = Gender::other;
}

void Student::set_name(const std::string& name) {
    name_ = name;
}

void Student::set_surname(const std::string& surname) {
    surname_ = surname;
}

void Student::set_address(const std::string& address) {
    address_ = address;
}

void Student::set_id_number(unsigned int id_number) {
    id_number_ = id_number;
}
void Student::set_pesel(Pesel& pesel) {
    pesel_ = pesel;
}

// Getters implementation
[[nodiscard]] std::string Student::get_name() const {
    return name_;
}

[[nodiscard]] std::string Student::get_surname() const {
    return surname_;
}

[[nodiscard]] std::string Student::get_address() const {
    return address_;
}

[[nodiscard]] unsigned int Student::get_id_number() const {
    return id_number_;
}

[[nodiscard]] Pesel Student::get_pesel() const {
    return pesel_;
}

[[nodiscard]] Gender Student::get_gender() const {
    return gender_;
}
