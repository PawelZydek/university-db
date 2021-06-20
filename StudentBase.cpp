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
	for (const auto& student : studensts_list)
	{
		std::cout << student << '\n';
	}
}
