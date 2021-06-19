#include "Student.hpp"
#include "Pesel.hpp"
#include "gtest/gtest.h"
#include <random>
#include <array>
#include <string_view>

int randomNumberGen(int min, int max)
{
    static std::mt19937_64 mersenne{ std::random_device()() }; 
    std::uniform_int_distribution gen{ min, max };
    return gen(mersenne);
}

TEST(peselTests, ShouldCheckPeselValidity)
{
    Pesel validPesel{ 610209, 6495, 4};
    Pesel invalidCheckDigitPesel{ 610209, 6495, 5};
    Pesel invalidDatePesel{ 2613209, 6495, 4 };
    EXPECT_TRUE(validPesel.is_valid());
    EXPECT_FALSE(invalidCheckDigitPesel.is_valid());
    EXPECT_FALSE(invalidDatePesel.is_valid());
}

TEST(peselTests, ShouldReturnDate)
{
    // 11.5.1908
    Pesel pesel{ 80511, 6667, 4};
    EXPECT_EQ(11, pesel.get_day());
    EXPECT_EQ(5, pesel.get_month());
    EXPECT_EQ(1908, pesel.get_year());
    // 17.9.1973
    Pesel pesel1{ 730917, 1173, 9};
    EXPECT_EQ(17, pesel.get_day());
    EXPECT_EQ(9, pesel.get_month());
    EXPECT_EQ(1973, pesel.get_year());
    // 22.11.2007
    Pesel pesel2{ 73122, 1115, 9};
    EXPECT_EQ(22, pesel.get_day());
    EXPECT_EQ(11, pesel.get_month());
    EXPECT_EQ(2007, pesel.get_year());
}

TEST(getterTests, ShouldGetRandomName)
{
    using namespace std::string_view_literals;
    static constexpr std::array<std::string_view, 5> names
    {
        "Wojciech"sv, "Mateusz"sv, "Krzysztof"sv, "Michal"sv, "Tomasz"sv
    };
    size_t index {randomNumberGen(0, 4)};
    Student st{ names[index].data(), "-", "-", 1, 1, Gender::male};
    EXPECT_EQ(names[index], st.get_name());
}

TEST(getterTests, ShouldGetRandomGender)
{
    int index{ randomNumberGen(0, static_cast<int>(Gender::maxGender)) };
    Student st { "-", "-", "-",  1, 1, static_cast<Gender>(index)};

    EXPECT_EQ(static_cast<Gender>(index), st.get_gender());
}