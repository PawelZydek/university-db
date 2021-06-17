#include "Student.hpp"

Student::Student(const std::string& name, const std::string& surname, const std::string& address, unsigned int id_number, pesel_type pesel, Gender gender)
	: name_{name}, surname_{surname}, address_{address}, id_number_{id_number}, pesel_{pesel}, gender_{gender}
	{
	}

	//TODO: Overload << operator for Student
	std::ostream& operator<< (std::ostream& out, const Student& student)
	{

	}