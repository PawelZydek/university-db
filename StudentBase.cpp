#include "StudentBase.hpp"
#include "Student.hpp"
#include <algorithm>

//Add student implementation
void StudentBase::add_student(Student& student)
{
	studensts_list.push_front(student);
}
//Student list implementation
void StudentBase::display_students_list() const
{
	for (const auto student : studensts_list)
	{
		std::cout << student.get_name() << " ";
		std::cout << student.get_surname() << " ";
		std::cout << student.get_address() << " ";
		std::cout << student.get_id_number() << " ";
		std::cout << student.get_pesel() << " ";
		std::cout << student.get_gender() << "\n";
	}
}
