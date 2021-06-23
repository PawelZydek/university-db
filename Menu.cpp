#include "Menu.hpp"
#include <string>
#include <iostream>
#include <limits>

void Menu::add_student()
{
    std::cout << "Enter student data (separate by commas):\n";
    Student student{};
    std::cin >> student;

    if(std::cin)
    {
        base_.add_student(student);
    }
    else
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Saving student data failed!\n";
    }
}

void Menu::