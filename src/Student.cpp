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
    : Person{person}, index_num_{index_num}
    {
    }

Student::Student(Person&& person, unsigned int index_num)
    : Person{std::move(person)}, index_num_{index_num}
    {
    }
