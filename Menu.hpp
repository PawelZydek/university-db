#ifndef MENU_HPP
#define MENU_HPP

#include "StudentBase.hpp"
#include <functional>
#include <map>
#include <string_view>

class Menu {
public:
  Menu() = default;

  void add_student();
  void display_list() const;

  void sort_by_pesel();
  void sort_by_surname();

  void erase_by_id();

  void read_from_file();
  void write_to_file() const;

  void search_by_pesel() const;
  void search_by_surname() const;

  void select_menu();
  void run();

private:
  StudentBase base_{};
};

#endif