#ifndef STUDENTBASE_HPP
#define STUDENTBASE_HPP
#include "Student.hpp"
#include <forward_list>

class StudentBase {
public:
  StudentBase() = default;

  // Add student
  void add_student(const Student &);
  // Display students list
  void display_list() const;

  // Sorting functions
  void sort_by_pesel();
  void sort_by_surname();

  void erase_by_id(unsigned int);

  void write_to_file(const std::string &);
  void read_from_file(const std::string &);

private:
  std::forward_list<Student> student_list_;
};
#endif /* STUDENTBASE_HPP */