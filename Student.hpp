#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <cstdint>
#include <string>

enum class Gender {
	agender,
	androgynous,
	female,
	genderfluid,
	intersex,
	male,
	nonbinary,
	other,
	maxGender,
};

class Student {
public:
	//TODO: Make a separate struct
	using pesel_type = std::uint64_t;

	Student(const std::string&, const std::string&, const std::string&, unsigned int, pesel_type, Gender);

	//Getters TODO: Implement getters
	[[nodiscard]] std::string get_name() const;

	[[nodiscard]] std::string get_surname() const;

	[[nodiscard]] unsigned int get_id_number() const;

	[[nodiscard]] std::string get_address() const;

	[[nodiscard]] uint64_t get_pesel() const;

	[[nodiscard]] Gender get_gender() const;

	//Setters TODO: Implement setters
	void set_gender(Gender);

	void set_name(const std::string&);

	void set_surname(const std::string&);

	void set_id_number(unsigned int);

	void set_address(const std::string&);

	void set_pesel(pesel_type);

private:
	std::string name_;
	std::string surname_;
	std::string address_;
	uint64_t pesel_;
	unsigned int id_number_;
	Gender gender_;
};

std::ostream& operator<< (std::ostream&, const Student&);
std::ostream& operator<< (std::ostream&, const Gender);


#endif /* STUDENT_HPP */