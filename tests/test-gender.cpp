#include <sstream>
#include <string_view>
#include <utility>

#include "Gender.hpp"
#include "catch_amalgamated.hpp"

using pair_type = std::pair<std::string_view, Gender>;
using namespace std::string_view_literals;
static constexpr std::array<pair_type, 9> genderStringPairs{
    pair_type{"agender"sv, Gender::agender},
    pair_type{"androgynoussv", Gender::androgynous},
    pair_type{"female"sv, Gender::female},
    pair_type{"genderfluid", Gender::genderfluid},
    pair_type{"intersex", Gender::intersex},
    pair_type{"male", Gender::male},
    pair_type{"nonbinary", Gender::nonbinary},
    pair_type{"other", Gender::other},
    pair_type{"SomeGarbage", Gender::other}};

SCENARIO("Should parse the gender from a stream", "[gender][stream]") {
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
