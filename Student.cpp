#include "Student.hpp"
#include <array>
#include <utility>
#include <string_view>

Student::Student(const std::string& name, const std::string& surname, const std::string& address, 
	unsigned int id_number, const Pesel& pesel, Gender gender)
	: name_{ name }, surname_{ surname }, address_{ address }, id_number_{ id_number }, pesel_{ pesel }, gender_{ gender }
{
}

std::ostream& operator<< (std::ostream& out, const Gender gender)
{
	using namespace std::string_view_literals; //Don't worry ;)

	static constexpr std::array<std::string_view, 8> genderStringLiterals{
		"agender"sv, "androgynous"sv, "female"sv, "genderfluid"sv,
		"intersex"sv, "male"sv, "nonbinary"sv, "other"sv
	};

	if( static_cast<int>(gender) >= genderStringLiterals.size() || static_cast<int>(gender) < 0)
	{
		out.clear(std::ios_base::failbit);
		return out;
	}
	return out << genderStringLiterals[static_cast<size_t>(gender)];
}

//TODO: Overload << operator for Student
std::ostream& operator<< (std::ostream& out, const Student& student)
{
	return out << student.get_name() << " " << student.get_surname() << " " << student.get_address() 
		<< " " << student.get_id_number() << " " << student.get_pesel().get_string() << " " << student.get_gender();
}

//Setters implementation
void Student::set_gender(Gender)
{
	gender_ = Gender::other;
}

void Student::set_name(const std::string& name)
{
	name_ = name;
}

void Student::set_surname(const std::string& surname)
{
	surname_ = surname;
}

void Student::set_address(const std::string& address)
{
	address_ = address;
}

void Student::set_id_number(unsigned int id_number)
{
	id_number_ = id_number;
}
void Student::set_pesel(Pesel& pesel)
{
	pesel_ = pesel;
}

//Getters implementation
[[nodiscard]] std::string Student::get_name() const
{
	return name_;
}

[[nodiscard]] std::string Student::get_surname() const
{
	return surname_;
}

[[nodiscard]] std::string Student::get_address() const
{
	return address_;
}

[[nodiscard]] unsigned int Student::get_id_number() const
{
	return id_number_;
}

[[nodiscard]] Pesel Student::get_pesel() const
{
	return pesel_;
}

[[nodiscard]] Gender Student::get_gender() const
{
	return gender_;
}
