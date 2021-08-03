#include "UniversityBase.hpp"

void UniversityBase::add(const Student& student) {
    people_.push_back(std::make_shared<Student>(student));
}

void UniversityBase::add(Student&& student) {
    people_.push_back(std::make_shared<Student>(std::move(student)));
}

void UniversityBase::add(const Employee& employee) {
    people_.push_back(std::make_shared<Employee>(employee));
}

void UniversityBase::add(Employee&& employee) {
    people_.push_back(std::make_shared<Employee>(std::move(employee)));
}

void UniversityBase::display(std::ostream& out) const {
    out << "Employees:\n";
    for (const auto& person_ptr : people_) {
        if (const auto employee_ptr{
                dynamic_cast<Employee*>(person_ptr.get())}) {
            out << *employee_ptr << '\n';
        }
    }
    out << "Students:\n";
    for (const auto& person_ptr : people_) {
        if (const auto student_ptr{dynamic_cast<Student*>(person_ptr.get())}) {
            out << *student_ptr << '\n';
        }
    }
}