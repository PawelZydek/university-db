#ifndef UNIVERSITYBASE_HPP
#define UNIVERSITYBASE_HPP

#include <memory>
#include <vector>
#include "Employee.hpp"
#include "Student.hpp"

class UniversityBase {
   public:
    void add(const Student&);
    void add(Student&&);

    void add(const Employee&);
    void add(Employee&&);

    void display(std::ostream&) const;

   private:
    std::vector<std::shared_ptr<Person>> people_{};
};

#endif /* UNIVERSITYBASE_HPP */