#ifndef MENU_HPP
#define MENU_HPP

#include "StudentBase.hpp"

class Menu{
public:
    Menu() = default;

    void add_student();
    void display_list();

    void sort_by_pesel();
    void sort_by_surname();

    void erase_by_id();

    void read_from_file();
    void write_to_file();
    void select_menu();

    void search_by_pesel();
    void search_by_surname();

private:
    StudentBase base_{};
};

#endif