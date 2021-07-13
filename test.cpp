#include <array>
#include <random>
#include <sstream>
#include <string_view>

#include "Pesel.hpp"
#include "Student.hpp"
#include "gtest/gtest.h"

int randomNumberGen(int min, int max) {
    static std::mt19937_64 mersenne{std::random_device()()};
    std::uniform_int_distribution gen{min, max};
    return gen(mersenne);
}

bool operator==(const Student& st1, const Student& st2) {
    return st1.get_name() == st2.get_name() &&
           st1.get_surname() == st2.get_surname() &&
           st1.get_address() == st2.get_address() &&
           st1.get_id_number() == st2.get_id_number() &&
           st1.get_pesel() == st2.get_pesel() &&
           st1.get_gender() == st2.get_gender();
}

TEST(genderTests, ShouldParseFromStream) {
    static constexpr std::string_view string{"nonbinary"};
    static constexpr Gender gender{Gender::nonbinary};
    std::stringstream stream{string.data()};

    Gender gen{};
    stream >> gen;
    EXPECT_EQ(gender, gen);
}

TEST(studentTests, ShouldParseFromStream) {
    static constexpr std::string_view student{
        "Mateusz,Borek,Debica,12345,77100228515,male"};
    std::stringstream stream{student.data()};
    Student st{"Mateusz",
               "Borek",
               "Debica",
               12345,
               Pesel{{7, 7, 1, 0, 0, 2, 2, 8, 5, 1, 5}},
               Gender::male};

    Student parsedSt{};
    stream >> parsedSt;

    EXPECT_EQ(parsedSt, st);
}

TEST(peselTests, ShouldCheckPeselValidity) {
    Pesel validPesel{{6, 1, 0, 2, 0, 9, 6, 4, 9, 5, 4}};
    Pesel validPesel1{{0, 7, 2, 4, 1, 4, 4, 1, 3, 9, 9}};
    Pesel validPesel2{{5, 4, 0, 8, 0, 4, 5, 6, 2, 4, 6}};

    Pesel invalidCheckDigitPesel{{6, 1, 0, 2, 0, 9, 6, 4, 9, 5, 5}};
    Pesel invalidDatePesel{{2, 6, 1, 3, 2, 0, 9, 6, 4, 9, 5}};
    EXPECT_TRUE(validPesel.is_valid());
    EXPECT_FALSE(invalidCheckDigitPesel.is_valid());
    EXPECT_FALSE(invalidDatePesel.is_valid());
}

TEST(peselTests, ShouldReturnDate) {
    // 11.5.1908
    Pesel pesel{{0, 8, 0, 5, 1, 1, 6, 6, 6, 7, 4}};
    EXPECT_EQ(11, pesel.get_day());
    EXPECT_EQ(5, pesel.get_month());
    EXPECT_EQ(1908, pesel.get_year());
    // 17.9.1973
    Pesel pesel1{{7, 3, 0, 9, 1, 7, 1, 1, 7, 3, 9}};
    EXPECT_EQ(17, pesel1.get_day());
    EXPECT_EQ(9, pesel1.get_month());
    EXPECT_EQ(1973, pesel1.get_year());
    // 22.11.2007
    Pesel pesel2{{0, 7, 3, 1, 2, 2, 1, 1, 1, 5, 9}};
    EXPECT_EQ(22, pesel2.get_day());
    EXPECT_EQ(11, pesel2.get_month());
    EXPECT_EQ(2007, pesel2.get_year());
}

TEST(peselTests, ShouldCompare) {
    Pesel pesel1{{0, 8, 0, 5, 1, 1, 6, 6, 6, 7, 4}};
    Pesel pesel2{{0, 1, 2, 5, 3, 2, 6, 6, 6, 7, 4}};
    Pesel pesel3{{0, 1, 2, 5, 3, 2, 6, 6, 6, 7, 3}};

    EXPECT_TRUE(pesel2 < pesel1);
    EXPECT_TRUE(pesel3 < pesel2);
}
