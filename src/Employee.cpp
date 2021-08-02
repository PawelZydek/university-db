#include "Employee.hpp"

Employee::Employee(const std::string& name,
                 const std::string& surname,
                 const std::string& address,
                 const Pesel& pesel,
                 Gender gender,
                 unsigned int salary)
    : Person{name, surname, address, pesel, gender}, salary_{salary} {}

Employee::Employee(std::string&& name,
                std::string&& surname,
                std::string&& address,
                Pesel&& pesel,
                Gender gender,
                unsigned int salary)
: Person{std::move(name), std::move(surname), std::move(address),
            std::move(pesel), gender}, salary_{salary} {}

Employee::Employee(const Person& person, unsigned int salary)
    : Person{person}, salary_{salary}
    {
    }

Employee::Employee(Person&& person, unsigned int salary)
    : Person{person}, salary_{salary}
    {
    }



std::ostream& operator<<(std::ostream& out, const Employee& employee) {
    return out << employee.name_ << Person::formatDelimiter << employee.surname_
               << Person::formatDelimiter << employee.address_
               << Person::formatDelimiter << employee.pesel_
               << Person::formatDelimiter << employee.gender_
               << Person::formatDelimiter << employee.salary_;
}

std::istream& operator>>(std::istream& in, Employee& employee) {
    Person person{};
    char delim{};
    unsigned int salary{};
    in >> person >> delim >> salary;
    if (delim != ',') {
        in.clear(std::ios_base::failbit);
    }
    if (!in) {
        return in;
    }
    employee = Employee{person, salary};
    return in;
}