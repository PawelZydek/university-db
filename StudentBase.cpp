#include "StudentBase.hpp"
#include <algorithm>
#include <fstream>
#include <functional>

// Add student implementation
void StudentBase::add_student(const Student &student) {
  student_list_.push_front(student);
}
// Student list implementation
void StudentBase::display_list() const {
  for (const auto &student : student_list_) {
    std::cout << student << '\n';
  }
}

void StudentBase::sort_by_pesel() {
  student_list_.sort(
      [](auto &st1, auto &st2) { return st1.get_pesel() < st2.get_pesel(); });
}

void StudentBase::sort_by_surname() {
  student_list_.sort([](auto &st1, auto &st2) {
    return st1.get_surname() < st2.get_surname();
  });
}

void StudentBase::erase_by_id(unsigned int idNum) {
  auto before = student_list_.cbefore_begin();
  auto current = student_list_.cbegin();
  for (const auto &student : student_list_) {
    if (current->get_id_number() == idNum) {
      student_list_.erase_after(before);
      return;
    }
    ++before;
    ++current;
  }
  throw std::runtime_error{"Student with id number " + std::to_string(idNum) +
                           " is not registered"};
}

void StudentBase::write_to_file(const std::string &path) const {
  std::ofstream stream{path};

  for (const auto &student : student_list_) {
    stream << student << '\n';
  }
}

void StudentBase::read_from_file(const std::string &path) {
  std::ifstream stream{path};
  if (!stream) {
    throw std::runtime_error{"File named" + path + " does not exist"};
  }

  for (Student st{}; stream >> st;) {
    add_student(st);
  }
}

std::optional<Student> StudentBase::search_by_pesel(const Pesel &pesel) const {
  std::optional<Student> value{};
  auto it = std::find_if(
      student_list_.cbegin(), student_list_.cend(),
      [&pesel](const auto &student) { return student.get_pesel() == pesel; });

  if (it != student_list_.cend()) {
    value = *it;
  }
  return value;
}

std::optional<Student>
StudentBase::search_by_surname(const std::string &surname) const {
  std::optional<Student> value{};

  auto it = std::find_if(student_list_.cbegin(), student_list_.cend(),
                         [&surname](const auto &student) {
                           return student.get_surname() == surname;
                         });

  if (it != student_list_.cend()) {
    value = *it;
  }
  return value;
}
