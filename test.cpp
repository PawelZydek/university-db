#include "Pesel.hpp"
#include "Student.hpp"
#include "gtest/gtest.h"
#include <array>
#include <random>
#include <sstream>
#include <string_view>

int randomNumberGen(int min, int max) {
  static std::mt19937_64 mersenne{std::random_device()()};
  std::uniform_int_distribution gen{min, max};
  return gen(mersenne);
}

TEST(peselTests, ShouldCheckPeselValidity) {
  Pesel validPesel{610209, 6495, 4};
  Pesel invalidCheckDigitPesel{610209, 6495, 5};
  Pesel invalidDatePesel{2613209, 6495, 4};
  EXPECT_TRUE(validPesel.is_valid());
  EXPECT_FALSE(invalidCheckDigitPesel.is_valid());
  EXPECT_FALSE(invalidDatePesel.is_valid());
}

TEST(peselTests, ShouldReturnDate) {
  // 11.5.1908
  Pesel pesel{8'05'11, 6667, 4};
  EXPECT_EQ(11, pesel.get_day());
  EXPECT_EQ(5, pesel.get_month());
  EXPECT_EQ(1908, pesel.get_year());
  // 17.9.1973
  Pesel pesel1{73'09'17, 1173, 9};
  EXPECT_EQ(17, pesel1.get_day());
  EXPECT_EQ(9, pesel1.get_month());
  EXPECT_EQ(1973, pesel1.get_year());
  // 22.11.2007
  Pesel pesel2{7'31'22, 1115, 9};
  EXPECT_EQ(22, pesel2.get_day());
  EXPECT_EQ(11, pesel2.get_month());
  EXPECT_EQ(2007, pesel2.get_year());
}

TEST(peselTests, ShouldCompare) {
  Pesel pesel1{8'05'11, 6667, 4};
  Pesel pesel2{1'25'32, 6667, 4};
  Pesel pesel3{1'25'32, 6667, 3};

  EXPECT_TRUE(pesel2 < pesel1);
  EXPECT_TRUE(pesel3 < pesel2);
}
