#ifndef GENDER_HPP
#define GENDER_HPP

#include <iostream>

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

std::ostream& operator<< (std::ostream&, const Gender);

#endif /* GENDER_HPP */