#include "StudentBase.hpp"
#include <algorithm>

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
