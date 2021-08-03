#ifndef UNIVERSITYBASE_HPP
#define UNIVERSITYBASE_HPP

#include "Student.hpp"
#include "Employee.hpp"
#include <memory>
#include <vector>

class UniversityBase
{
public:

private:
    std::vector<std::unique_ptr<Person>> people_{};
};

#endif /* UNIVERSITYBASE_HPP */