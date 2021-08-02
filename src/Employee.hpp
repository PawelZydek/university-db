#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include "Person.hpp"

class Employee : public Person
{
public:
    Employee(const std::string&,
            const std::string&,
            const std::string&,
            const Pesel&,
            Gender,
            unsigned int);

    Employee(std::string&&,
            std::string&&,
            std::string&&,
            Pesel&&,
            Gender,
            unsigned int);

    Employee(const Person&, unsigned int);
    Employee(Person&&, unsigned int);

    Employee(const Employee& student) = default;
    Employee(Employee&& student) = default;

    Employee() = default;

    Employee& operator=(const Employee& student) = default;
    Employee& operator=(Employee&& student) = default;

    // Getter
    [[nodiscard]] unsigned int get_salary() const { return salary_; }

    // Setter
    void set_salary(unsigned int salary) { salary_ = salary; }

    friend std::ostream& operator<<(std::ostream&, const Employee&);
    friend std::istream& operator>>(std::istream&, Employee&);

private:
    unsigned int salary_{};
};

#endif