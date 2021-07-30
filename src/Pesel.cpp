#include "Pesel.hpp"

#include <array>
#include <cmath>
#include <iomanip>
#include <sstream>

static constexpr int peselLen{11};

Pesel::Pesel(const std::array<uint8_t, 11>& numbers) : pesel_(numbers) {}

int Pesel::get_day() const { return pesel_.at(4) * 10 + pesel_.at(5); }

int Pesel::get_month() const {
    int monthNum{pesel_.at(2) * 10 + pesel_.at(3)};
    switch (pesel_.at(2)) {
        case 8:
        case 9:
            return monthNum - 80;
        case 0:
        case 1:
            return monthNum;
        case 2:
        case 3:
            return monthNum - 20;
        case 4:
        case 5:
            return monthNum - 40;
        case 6:
        case 7:
            return monthNum - 60;
        default:
            return -1;
    }
}

int Pesel::get_year() const {
    int lastTwoDigits{pesel_.at(0) * 10 + pesel_.at(1)};
    switch (pesel_.at(2)) {
        case 8:
        case 9:
            return 1800 + lastTwoDigits;
        case 0:
        case 1:
            return 1900 + lastTwoDigits;
        case 2:
        case 3:
            return 2000 + lastTwoDigits;
        case 4:
        case 5:
            return 2100 + lastTwoDigits;
        case 6:
        case 7:
            return 2200 + lastTwoDigits;
        default:
            return -1;
    }
}

bool isLeap(int year) {
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
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
        default:
            return 0;
    }
}

bool Pesel::validation_date() const {
    int day = get_day();
    int month = get_month();
    int year = get_year();
    if (month < 1 || month > 12 || day < 1 || day > getDayCount(month, year)) {
        return false;
    }

    return true;
}

bool Pesel::validation_check_digit() const {
    static constexpr std::array<uint8_t, 10> weights{1, 3, 7, 9, 1,
                                                     3, 7, 9, 1, 3};

    int sum{0};
    for (size_t i{0}; i < weights.size(); ++i) {
        sum += pesel_.at(i) * weights[i];
    }
    auto modulo = sum % 10;
    return modulo == 0 && pesel_.at(10) == 0 || 10 - modulo == pesel_.at(10);
}

std::string Pesel::get_string() const {
    std::string str{};
    str.reserve(11);
    for (auto num : pesel_) {
        str.push_back(static_cast<char>(num + '0'));
    }
    return str;
}

bool Pesel::is_valid() const {
    if (validation_check_digit() && validation_date()) {
        // Both function return true on success
        return true;
    }
    return false;
}

std::istream& operator>>(std::istream& in, Pesel& pesel) {
    char ch{};
    for (size_t i = 0; i < peselLen; ++i) {
        in >> ch;
        if (!isdigit(ch)) {
            in.putback(ch);
            in.clear(std::ios_base::failbit);
            return in;
        }
        pesel.pesel_[i] = ch - '0';
    }

    return in;
}

bool operator<(const Pesel& pesel1, const Pesel& pesel2) {
    for (size_t i{0}; i < peselLen; ++i) {
        if (pesel1.pesel_.at(i) > pesel2.pesel_.at(i)) {
            return false;
        } else if (pesel1.pesel_.at(i) < pesel2.pesel_.at(i)) {
            return true;
        }
    }
    return false;
}

bool operator==(const Pesel& pesel1, const Pesel& pesel2) {
    return std::equal(pesel1.pesel_.cbegin(), pesel1.pesel_.cend(),
                      pesel2.pesel_.cbegin());
}
