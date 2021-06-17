#ifndef students_class_HPP
#define students_class_HPP
#include "type_sex.hpp"
#include <array>
#include <iostream>
#include <string>

class Students {
private:
	std::string name_;
	std::string surname_;
	std::string address_;
	uint64_t pesel_;
	const unsigned int id_number_;
	type_sex sex_;
public:
	Students(const std::string& name, const std::string& surname, const std::string& address, unsigned int id_number, uint64_t pesel, type_sex sex);
	Students(const std::string& name, const std::string& surname, const std::string& address, unsigned int id_number, uint64_t pesel);
	void set_name(std::string);
	std::string get_name();
	void set_surname(std::string);
	std::string get_surname();
	void set_address(std::string);
	std::string get_address();
	//void set_pesel(uint64_t);
	//std::uint64_t get_pesel();
	void set_sex(type_sex);
	type_sex get_sex();
	
	
	void display_database();
	
};
#endif /* students_class_HPP */