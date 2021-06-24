#include "Menu.hpp"
#include <array>
#include <iostream>
#include <limits>
#include <string>
#include <utility>

void clear_std_cin() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Menu::add_student() {
  std::cout << "Enter student data (separate by commas):\n";
  Student student{};
  std::cin >> student;

  if (std::cin) {
    base_.add_student(student);
  } else {
    clear_std_cin();
    std::cerr << "Saving student data failed!\n";
  }
}

void Menu::display_list() const {
  std::cout << "Current student list:\n";
  base_.display_list();
}

void Menu::sort_by_pesel() {
  std::cout << "Sorting the student database by pesel...\n";
  base_.sort_by_pesel();
}

void Menu::sort_by_surname() {
  std::cout << "Sorting the student database by surname...\n";
  base_.sort_by_surname();
}

void Menu::erase_by_id() {
  std::cout << "Enter the id of the student you want to erase:\n";
  unsigned int id{};
  std::cin >> id;
  try {
    base_.erase_by_id(id);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}

void Menu::read_from_file() {
  std::cout << "Enter the path to the file you want to read the list from:\n";
  std::string path{};
  std::cin >> path;

  try {
    base_.read_from_file(path);
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}

void Menu::write_to_file() const {
  std::cout << "Enter the path to the file you want to write the list to:\n";
  std::string path{};
  std::cin >> path;

  base_.write_to_file(path);
}

void Menu::search_by_pesel() const {
  std::cout << "Enter the pesel of the person you want to search for:\n";
  Pesel pesel{};
  std::cin >> pesel;

  if (std::cin) {
    auto found = base_.search_by_pesel(pesel);
    if (found.has_value()) {
      std::cout << "Found the student with that pesel:\n" << found.value();
    } else {
      std::cerr << "Person with that pesel does not exist!\n";
    }
  } else {
    clear_std_cin();
    std::cout << "Saving pesel failed!\n";
  }
}

void Menu::search_by_surname() const {
  std::cout << "Enter the surname of the person you want to search for:\n";
  std::string surname{};
  std::cin >> surname;

  if (std::cin) {
    auto found = base_.search_by_surname(surname);
    if (found.has_value()) {
      std::cout << "Found the student with that surname:\n" << found.value();
    } else {
      std::cerr << "Person with that surname does not exist!\n";
    }
  } else {
    clear_std_cin();
    std::cout << "Saving surname failed!\n";
  }
}

void Menu::select_menu() {
  using namespace std::string_view_literals;
  ;
  static std::array<std::string_view, 9> functionNames{
      "add_student"sv,     "display_list"sv,    "sort_by_pesel"sv,
      "sort_by_surname"sv, "erase_by_id"sv,     "read_from_file"sv,
      "write_to_file"sv,   "search_by_pesel"sv, "search_by_surname"sv,
  };

  int count{1};
  for (auto &strView : functionNames) {
    std::cout << count << '.' << strView << '\n';
    ++count;
  }

  std::cout << "Select the function:\n";
  int index{};
  std::cin >> index;

  switch (index) {
  case 1:
    add_student();
    return;
  case 2:
    display_list();
    return;
  case 3:
    sort_by_pesel();
    return;
  case 4:
    sort_by_surname();
    return;
  case 5:
    erase_by_id();
    return;
  case 6:
    read_from_file();
    return;
  case 7:
    write_to_file();
    return;
  case 8:
    search_by_pesel();
    return;
  case 9:
    search_by_surname();
    return;
  default:
    std::cerr << "Invalid function index!\n";
  }
}

void Menu::run() {
  while (true) {
    select_menu();
    std::cout << "Do you want to proceed[Y/n]? ";
    char choice{};
    std::cin >> choice;
    if (choice == 'n' || choice == 'N') {
      break;
    }
  }
}