#include "Student.hpp"
#include "StudentBase.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>

int main()
{
	Student studentFirst{ "Tom", "Kowalski", "Krakow", 23456, Pesel{771002, 2851, 5}, Gender::male };
	Student studentSecond{ "Mateusz", "Borek", "Debica", 12345, Pesel{111111, 1111, 1}, Gender::male };
	Student studentThird{ "Krzysztof", "Stanowski", "NieWiem", 23456, Pesel{222222, 1111, 1}, Gender::male };
	StudentBase base{};

	base.add_student(studentSecond);
	base.add_student(studentFirst);
	base.add_student(studentThird);

	base.display_list();
	base.sort_by_pesel();
	base.display_list();


	return 0;
}
