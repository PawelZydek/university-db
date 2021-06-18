#include "Student.hpp"
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