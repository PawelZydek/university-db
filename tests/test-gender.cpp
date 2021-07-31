#include <sstream>
#include <string_view>
#include <utility>

#include "Gender.hpp"
#include "catch_amalgamated.hpp"

using pair_type = std::pair<std::string_view, Gender>;
using namespace std::string_view_literals;
static constexpr std::array<pair_type, 9> genderStringPairs{
    pair_type{"agender"sv, Gender::agender},
    pair_type{"androgynous"sv, Gender::androgynous},
    pair_type{"female"sv, Gender::female},
    pair_type{"genderfluid"sv, Gender::genderfluid},
    pair_type{"intersex"sv, Gender::intersex},
    pair_type{"male"sv, Gender::male},
    pair_type{"nonbinary"sv, Gender::nonbinary},
    pair_type{"other"sv, Gender::other},
    pair_type{"SomeGarbage"sv, Gender::other}};

SCENARIO("Should parse the gender from a stream", "[gender][stream][input]") {
    GIVEN("A stream containing a gender string") {
        auto [string, gender] = GENERATE(
            genderStringPairs[0], genderStringPairs[1], genderStringPairs[2],
            genderStringPairs[3], genderStringPairs[4], genderStringPairs[5],
            genderStringPairs[6], genderStringPairs[7], genderStringPairs[8]);
        std::stringstream stream{string.data()};

        WHEN("Gender is obtained from the stream") {
            Gender gend{};
            stream >> gend;

            THEN("It should be the corresponding enum value") {
                REQUIRE(gend == gender);
            }
        }
    }
}

SCENARIO("Should output the gender to the stream", "[gender][stream][output]") {
    GIVEN("A gender output to a stream") {
        auto [string, gender] = GENERATE(
            genderStringPairs[0], genderStringPairs[1], genderStringPairs[2],
            genderStringPairs[3], genderStringPairs[4], genderStringPairs[5],
            genderStringPairs[6], genderStringPairs[7]);
        std::stringstream stream{};
        stream << gender;

        WHEN("A string is obtained from the stream") {
            std::string str{stream.str()};

            THEN("It should be the corresponding string") {
                REQUIRE(str == string);
            }
        }
    }
}
