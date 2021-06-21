#include "Student.hpp"
#include "StudentBase.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>

int main()
{
	using namespace std::chrono;

	Student studentFirst{ "Tom", "Kowalski", "Krakow", 23456, Pesel{771002, 2851, 5}, Gender::male };
	Student studentSecond{ "Mateusz", "Borek", "Debica", 12345, Pesel{111111, 1111, 1}, Gender::male };
	StudentBase base{};

	auto start{ steady_clock::now() };
	for(int i = 0; i < 1000000; ++i)
	{
		base.add_student(studentFirst);
		base.add_student(studentSecond);
	}
	auto end{ steady_clock::now() };
	std::cout << std::fixed << duration<double>{ end - start }.count() << "s\n";

	return 0;
}
