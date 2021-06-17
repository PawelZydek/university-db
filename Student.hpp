#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "Gender.hpp"
#include <iostream>
#include <string>
#include <cstdint>

class Student {
public:
	using pesel_type = std::uint64_t;

	//TODO: Implement PESEL validation function
	static bool validatePeselNumber(pesel_type);

	Student(const std::string& name, const std::string& surname, const std::string& address, unsigned int id_number, pesel_type pesel, Gender sex);
	Student(const std::string& name, const std::string& surname, const std::string& address, unsigned int id_number, pesel_type pesel);

	//Getters TODO: Implement getters
	[[nodiscard]] std::string get_name() const;
	[[nodiscard]] std::string get_surname() const;
	[[nodiscard]] std::string get_address() const;
	[[nodiscard]] uint64_t get_pesel() const;
	[[nodiscard]] Gender get_sex() const;

	//Setters TODO: Implement setters
	void set_gender(Gender);
	void set_name(const std::string&);
	void set_surname(const std::string&);
	void set_address(const std::string&);
	void set_pesel(pesel_type);

private:
	std::string name_;
	std::string surname_;
	std::string address_;
	uint64_t pesel_;
	const unsigned int id_number_;
	Gender gender_;
};

std::ostream& operator<< (std::ostream& out, const Student& student);

#endif /* STUDENT_HPP */