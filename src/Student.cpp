#include "Student.hpp"

Student::Student(const std::string& name,
                 const std::string& surname,
                 const std::string& address,
                 const Pesel& pesel,
                 Gender gender,
                 unsigned int index_num)
    : Person{name, surname, address, pesel, gender}, index_num_{index_num} {}

Student::Student(std::string&& name,
                 std::string&& surname,
                 std::string&& address,
                 Pesel&& pesel,
                 Gender gender,
                 unsigned int index_num)
    : Person{std::move(name), std::move(surname), std::move(address),
             std::move(pesel), gender},
      index_num_{index_num} {}

Student::Student(const Person& person, unsigned int index_num)
    : Person{person}, index_num_{index_num} {}

Student::Student(Person&& person, unsigned int index_num)
    : Person{std::move(person)}, index_num_{index_num} {}

std::ostream& operator<<(std::ostream& out, const Student& student) {
    return out << student.name_ << Person::formatDelimiter << student.surname_
               << Person::formatDelimiter << student.address_
               << Person::formatDelimiter << student.pesel_
               << Person::formatDelimiter << student.gender_
               << Person::formatDelimiter << student.index_num_;
}

std::istream& operator>>(std::istream& in, Student& student) {
    Person person{};
    char delim{};
    unsigned int id_number{};
    in >> person >> delim >> id_number;
    if (delim != ',') {
        in.clear(std::ios_base::failbit);
    }
    if (!in) {
        return in;
    }
    student = Student{person, id_number};
    return in;
}
