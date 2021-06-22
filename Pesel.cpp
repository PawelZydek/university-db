#include "Pesel.hpp"
#include <cmath>
#include <iomanip>
#include <sstream>

Pesel::Pesel(uint32_t birth, uint16_t serial, uint8_t check_digit)
    : date_of_birth_{birth}, serial_number_{serial}, check_digit_{check_digit} {
}

int Pesel::get_day() { return (date_of_birth_ % 100); }

int Pesel::get_month() { return ((date_of_birth_ / 100) % 20); }

int Pesel::get_year() {
  int century = date_of_birth_ % 10'000;
  int year = date_of_birth_ / 10'000;
  century /= 2000;
  century += 20;
  year += (century - 1) * 100;
  return year;
}

Gender Pesel::get_gender() {
  if (serial_number_ & 0b1) {
    return Gender::male;
  }
  return Gender::female;
}

bool isLeap(int year) {
  // year % 400 == 0 //year % 4 == 0  //year % 100 != 0
  if (year & 0b1111 == 0 || year & 0b11 == 0 && year % 25 != 0) {
    return true;
  }
  return false;
}

int getDayCount(int monthNumber, int year) {
  switch (monthNumber) {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
  case 4:
  case 6:
  case 9:
  case 11:
    return 30;
  case 2:
    return isLeap(year) ? 29 : 28;
  }
}

bool Pesel::validation_date() {
  int day = get_day();
  int month = get_month();
  int year = get_year();
  if (1 > month || month > 12 || day < 1 || day > getDayCount(month, year)) {
    return true;
  }

  return false;
}

bool Pesel::validation_check_digit() {
  uint8_t check_digit = 0;
  uint32_t date_of_birth = date_of_birth_;
  uint16_t serial_number = serial_number_;
  check_digit += (date_of_birth % 10) * 3;
  date_of_birth /= 10;
  check_digit += (date_of_birth % 10);
  date_of_birth /= 10;
  check_digit += (date_of_birth % 10) * 9;
  date_of_birth /= 10;
  check_digit += (date_of_birth % 10) * 7;
  date_of_birth /= 10;
  check_digit += (date_of_birth % 10) * 3;
  date_of_birth /= 10;
  check_digit += (date_of_birth % 10);
  check_digit += (serial_number % 10) * 3;
  date_of_birth /= 10;
  check_digit += (serial_number % 10);
  date_of_birth /= 10;
  check_digit += (serial_number % 10) * 9;
  date_of_birth /= 10;
  check_digit += (serial_number % 10) * 7;
  check_digit %= 10;
  // Returns false if the check_digit is valid
  return check_digit != check_digit_;
}

std::string Pesel::get_string() const {
  std::string str{};
  str.reserve(11);
  for (int i = 0; i < birthDateLen - std::log10(date_of_birth_) - 1; ++i) {
    str.push_back('0');
  }
  str += std::to_string(date_of_birth_);
  for (int i = 0; i < serialNumberLen - std::log10(serial_number_) - 1; ++i) {
    str.push_back('0');
  }
  str += std::to_string(serial_number_);
  str += std::to_string(check_digit_);
  return str;
}

bool Pesel::is_valid() {
  if (validation_check_digit() || validation_date()) {
    return false;
  }
  return true;
}

std::istream &operator>>(std::istream &in, Pesel &pesel) {
  std::string str{};
  str.reserve(Pesel::totalLen);
  char ch{};
  for (int i = 0; i < Pesel::totalLen; ++i) {
    in >> ch;
    if (!isdigit(ch)) {
      in.putback(ch);
      in.clear(std::ios_base::failbit);
      return in;
    }
    str.push_back(ch);
  }
  pesel.date_of_birth_ = std::stoi(str.substr(0, Pesel::birthDateLen));
  pesel.serial_number_ =
      std::stoi(str.substr(Pesel::birthDateLen, Pesel::serialNumberLen));
  pesel.check_digit_ = str.back() - '0';

  return in;
}

bool operator<(const Pesel &pesel1, const Pesel &pesel2) {
  if (pesel1.date_of_birth_ != pesel2.date_of_birth_) {
    return pesel1.date_of_birth_ < pesel2.date_of_birth_;
  }
  if (pesel1.serial_number_ != pesel2.serial_number_) {
    return pesel1.serial_number_ < pesel2.serial_number_;
  }
  return pesel1.check_digit_ < pesel2.check_digit_;
}
