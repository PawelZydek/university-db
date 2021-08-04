#ifndef UNIVERSITYBASE_HPP
#define UNIVERSITYBASE_HPP

#include <memory>
#include <vector>
#include "Employee.hpp"
#include "Student.hpp"

#include <optional>

class UniversityBase {
   public:
    void add(const Student&);
    void add(Student&&);
    void add(const Employee&);
    void add(Employee&&);

    void display(std::ostream& out = std::cout) const;

    std::optional<std::shared_ptr<Person>> search_by_surname(
        std::string_view) const;

    std::optional<std::shared_ptr<Person>> search_by_pesel(const Pesel&) const;

    void sort_by_pesel();
    void sort_by_surname();

    void erase_by_index(unsigned int);

    void generate_data(int);

    void set_salary_by_pesel(const Pesel&, unsigned int);

    void sort_by_salary();

    void write_employees_to_file(std::string_view) const;
    void write_students_to_file(std::string_view) const;
    void write_to_file(std::string_view path1 = "employees.csv",
                       std::string_view path2 = "students.csv") const;

   private:
    std::vector<std::shared_ptr<Person>> people_{};
};

#endif /* UNIVERSITYBASE_HPP */