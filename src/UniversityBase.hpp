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

    void display(std::ostream&) const;

    std::optional<std::shared_ptr<Person>> search_by_surname(
        std::string_view) const;

    std::optional<std::shared_ptr<Person>> search_by_pesel(const Pesel&) const;

    void sort_by_pesel();
    void sort_by_surname();

    void erase_by_index(unsigned int);

   private:
    std::vector<std::shared_ptr<Person>> people_{};
};

#endif /* UNIVERSITYBASE_HPP */