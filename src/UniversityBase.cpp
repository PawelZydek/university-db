#include "UniversityBase.hpp"

#include <algorithm>

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

std::optional<std::shared_ptr<Person>> UniversityBase::search_by_surname(
    std::string_view surname) const {
    std::optional<std::shared_ptr<Person>> output_ptr{};
    for (const auto& person_ptr : people_) {
        if (person_ptr->get_surname() == surname) {
            output_ptr = person_ptr;
        }
    }
    return output_ptr;
}

std::optional<std::shared_ptr<Person>> UniversityBase::search_by_pesel(
    const Pesel& pesel) const {
    std::optional<std::shared_ptr<Person>> output_ptr{};
    for (const auto& person_ptr : people_) {
        if (person_ptr->get_pesel() == pesel) {
            output_ptr = person_ptr;
        }
    }
    return output_ptr;
}

void UniversityBase::sort_by_pesel() {
    std::sort(people_.begin(), people_.end(),
              [](auto& person_ptr1, auto& person_ptr2) {
                  return person_ptr1->get_pesel() < person_ptr2->get_pesel();
              });
}

void UniversityBase::sort_by_surname() {
    std::sort(people_.begin(), people_.end(),
              [](auto& person_ptr1, auto& person_ptr2) {
                  return person_ptr1->get_surname() <
                         person_ptr2->get_surname();
              });
}

void UniversityBase::erase_by_index(unsigned int index_num) {
    people_.erase(
        std::remove_if(
            people_.begin(), people_.end(),
            [index_num](auto& person_ptr) {
                auto student_ptr = dynamic_cast<Student*>(person_ptr.get());
                return student_ptr && student_ptr->get_index_num() == index_num;
            }),
        people_.end());
}