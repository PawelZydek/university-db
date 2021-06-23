#include "Gender.hpp"
#include <array>
#include <string_view>
#include <algorithm>

using namespace std::string_view_literals;
static constexpr std::array<std::string_view, 8> genderStringLiterals{
    "agender"sv,  "androgynous"sv, "female"sv,    "genderfluid"sv,
    "intersex"sv, "male"sv,        "nonbinary"sv, "other"sv};

std::ostream& operator<<(std::ostream &out, const Gender gender) {
  if (static_cast<int>(gender) >= genderStringLiterals.size() ||
      static_cast<int>(gender) < 0) {
    out.clear(std::ios_base::failbit);
    return out;
  }
  return out << genderStringLiterals[static_cast<size_t>(gender)];
}

std::istream& operator>> (std::istream& in, Gender& gender)
{
    std::string str{};
    for(char ch{}; in >> ch; )
    {
        if(isalpha(ch)){
            ch = tolower(ch);
            str.push_back(ch);
            if(std::find(genderStringLiterals.cbegin(), genderStringLiterals.cend(),
            str) != genderStringLiterals.cend()){
                break;
            }
        } else{
            in.putback(ch);
            break;
        }
    }
    auto it = std::find(genderStringLiterals.cbegin(), genderStringLiterals.cend(),
        str);
    auto distance = std::distance(genderStringLiterals.cbegin(), it);
    if (it == genderStringLiterals.cend() || 
        distance >= static_cast<int>(Gender::maxGender))
    {
        in.clear(std::ios_base::failbit);
        return in;
    }
    gender = static_cast<Gender>(distance);
    return in;
}