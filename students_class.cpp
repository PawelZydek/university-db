#include "students_class.hpp"

Students::Students(const std::string& name, const std::string& surname, const std::string& address, unsigned int id_number, uint64_t pesel, type_sex sex)
	: name_(name), surname_(surname), address_(address), id_number_(id_number), pesel_(pesel), sex_(sex)
	{

	}

	void Students::display_database()
	{
		std::cout << name_ << " " << surname_ << " " << id_number_ << " " << pesel_ << " " << address_ << " "; //<< type_sex::Agender << "\n";
	}

	void search_by_surname()
	{

	}
