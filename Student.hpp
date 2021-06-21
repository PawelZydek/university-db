#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Gender.hpp"
#include "Pesel.hpp"
#include <iostream>
#include <cstdint>
#include <string>

class Student {
public:
	Student(const std::string&, const std::string&, const std::string&, unsigned int, const Pesel&, Gender);

	//Getters TODO: Implement getters
	[[nodiscard]] std::string get_name() const;

	[[nodiscard]] std::string get_surname() const;

	[[nodiscard]] unsigned int get_id_number() const;

	[[nodiscard]] std::string get_address() const;

	[[nodiscard]] Pesel get_pesel() const;

	[[nodiscard]] Gender get_gender() const;

	//Setters TODO: Implement setters
	void set_gender(Gender);

	void set_name(const std::string&);

	void set_surname(const std::string&);

	void set_id_number(unsigned int);

	void set_address(const std::string&);

	void set_pesel(Pesel&);

private:
	std::string name_{};
	std::string surname_{};
	std::string address_{};
	Pesel pesel_{};
	unsigned int id_number_{};
	Gender gender_{};
};

std::ostream& operator<< (std::ostream&, const Student&);


#endif /* STUDENT_HPP */