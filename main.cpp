#include "Student.hpp"
#include "StudentBase.hpp"

int main()
{
	Student student1{ "Tom", "Kowalski", "Krakow", 23456, 77100228515, Gender::male };
	Student student2{ "Joanna", "Rand", "detroit", 451234, 63013501363, Gender::female };
	Student student3{ "Peter", "Parker", "Manhattan", 736124, 82061361731, Gender::male };

	std::cout << "Tom is: " << student1.get_gender() << '\n';

	student1.set_name("Pawel");

	std::cout << "\n" << student1 << "\n\n";

	StudentBase Base;

	Base.add_student(student1);
	Base.add_student(student2);
	Base.add_student(student3);

	Base.display_students_list();


	//student2.display_students_list();

}
