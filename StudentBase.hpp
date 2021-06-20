#ifndef STUDENTBASE_HPP
#define STUDENTBASE_HPP
#include "Student.hpp"
#include <forward_list>

class StudentBase {
public:
	//Add student
	void add_student(Student&);
	//Display students list
	void display_students_list() const;
private:
	std::forward_list<Student> studensts_list;
};
#endif /* STUDENTBASE_HPP */