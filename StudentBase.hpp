#ifndef STUDENTBASE_HPP
#define STUDENTBASE_HPP
#include "Student.hpp"
#include <forward_list>

class StudentBase {
public:
  StudentBase() = default;

  // Add student
  void add_student(Student&);
  // Display students list
  void display_list() const;

private:
  std::forward_list<Student> student_list_;
};
#endif /* STUDENTBASE_HPP */