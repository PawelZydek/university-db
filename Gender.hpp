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

std::ostream& operator<<(std::ostream&, const Gender);
std::istream& operator>>(std::istream& in, Gender&);

#endif /* GENDER_HPP */