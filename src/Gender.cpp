#include "Gender.hpp"

#include <algorithm>
#include <array>
#include <string_view>

using namespace std::string_view_literals;
static constexpr std::array<std::string_view, 8> genderStringLiterals{
    "agender"sv,  "androgynous"sv, "female"sv,    "genderfluid"sv,
    "intersex"sv, "male"sv,        "nonbinary"sv, "other"sv};

std::ostream& operator<<(std::ostream& out, const Gender gender) {
    // Bounds check
    if (static_cast<size_t>(gender) >= genderStringLiterals.size() ||
        static_cast<size_t>(gender) < 0) {
        out.clear(std::ios_base::failbit);
        return out;
    }

    return out << genderStringLiterals[static_cast<size_t>(gender)];
}

Gender string_to_gender(std::string_view str) {
    auto it = std::ranges::find(genderStringLiterals, str);
    auto distance = std::distance(genderStringLiterals.cbegin(), it);

    if (it == genderStringLiterals.cend() ||
        distance >= static_cast<int>(Gender::maxGender)) {
        return Gender::other;
    }
    return static_cast<Gender>(distance);
}

std::istream& operator>>(std::istream& in, Gender& gender) {
    std::string str{};
    for (char ch{}; in >> ch;) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            str.push_back(ch);
            if (std::ranges::find(genderStringLiterals, str) !=
                genderStringLiterals.cend()) {
                break;
            }
        } else {
            in.putback(ch);
            break;
        }
    }

    gender = string_to_gender(str);
    return in;
}