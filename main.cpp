#include "Student.hpp"
#include "StudentBase.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>

void find_by_pesel(const StudentBase& base, const Pesel& pesel)
{
  auto found = base.search_by_pesel(pesel);
  if(found.has_value())
  {
    std::cout << "Student found!\n" << found.value() << '\n';
  }
  else
  {
    std::cout << "Student with pesel " << pesel.get_string() << " not found\n";
  }
}

int main() {
  StudentBase base{};
  try {
    base.read_from_file("Test.csv");
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  base.display_list();

  Pesel pesel{ 771002, 2851, 5 };
  Pesel peselBad{ 123456, 7890, 5 };

  find_by_pesel(base, pesel);
  find_by_pesel(base, peselBad);

  return 0;
}
