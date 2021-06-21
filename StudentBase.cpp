#include "StudentBase.hpp"
#include <algorithm>
#include <functional>

// Add student implementation
void StudentBase::add_student(Student& student) {
  student_list_.push_front(student);
}
// Student list implementation
void StudentBase::display_list() const {
  for (const auto &student : student_list_) {
    std::cout << student << '\n';
  }
}

void StudentBase::sort_by_pesel()
{
  student_list_.sort([](auto& st1, auto& st2)
  { return st1.get_pesel() < st2.get_pesel(); });
}

void StudentBase::sort_by_surname()
{
  student_list_.sort([](auto& st1, auto& st2)
  { return st1.get_surname() < st2.get_surname(); });
}
