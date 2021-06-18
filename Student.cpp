#include "Student.hpp"
#include <string_view>
#include <array>
#include <utility>

Student::Student(const std::string& name, const std::string& surname, const std::string& address, unsigned int id_number, pesel_type pesel, Gender gender)
	: name_{name}, surname_{surname}, address_{address}, id_number_{id_number}, pesel_{pesel}, gender_{gender}
	{
	}

	std::ostream& operator<< (std::ostream& out, const Gender gender)
	{
		using namespace std::string_view_literals; //Don't worry ;)

		static constexpr std::array<std::string_view, 8> genderStringLiterals{
			"agender"sv, "androgynous"sv, "female"sv, "genderfluid"sv, 
			"intersex"sv, "male"sv, "nonbinary"sv, "other"sv
		};

		return out << genderStringLiterals[static_cast<size_t>(gender)];
	}

	//TODO: Overload << operator for Student
	std::ostream& operator<< (std::ostream& out, const Student& student)
	{

	}