#include "Gender.hpp"
#include <ctype.h>
#include <algorithm>
#include <array>
#include <string_view>
#include <utility>

using namespace std::string_view_literals;
using pair_type = std::pair<std::string_view, Gender>;
static constexpr std::array<pair_type, 8> genderStringPairs{
    pair_type{"agender"sv, Gender::agender},
    pair_type{"androgynous"sv, Gender::androgynous},
    pair_type{"female"sv, Gender::female},
    pair_type{"genderfluid"sv, Gender::genderfluid},
    pair_type{"intersex"sv, Gender::intersex},
    pair_type{"male"sv, Gender::male},
    pair_type{"nonbinary"sv, Gender::nonbinary},
    pair_type{"other"sv, Gender::other}};

std::ostream& operator<<(std::ostream& out, const Gender gender) {
    auto it = std::ranges::find_if(
        genderStringPairs,
        [gender](const auto& pair) { return gender == pair.second; });

    if (it != genderStringPairs.cend()) {
        return out << it->first;
    }
    return out << "undefined";
}

Gender string_to_gender(std::string_view str) {
    auto it = std::ranges::find_if(genderStringPairs, [str](const auto& pair) {
        return str == pair.first;
    });

    return (it != genderStringPairs.cend()) ? it->second : Gender::other;
}

std::istream& operator>>(std::istream& in, Gender& gender) {
    std::string str{};
    for (char ch{}; in >> ch;) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            str.push_back(ch);
            if (std::ranges::find_if(genderStringPairs,
                                     [&str](const auto& pair) {
                                         return str == pair.first;
                                     }) != genderStringPairs.cend()) {
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