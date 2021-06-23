#include "Student.hpp"
#include "StudentBase.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>

int main() {
  StudentBase base{};
  try {
    base.read_from_file("Test.csv");
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  base.display_list();

  return 0;
}
