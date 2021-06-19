#include "Student.hpp"

int main()
{
	Student student{ "Tom", "Kowalski", "Krakow", 23456, 77100228515, Gender::male };

	std::cout << "Tom is: " << student.get_gender() << '\n';

	student.set_name("Pawel");

	std::cout << "\n" << student << "\n";
}
