#include <sstream>
#include <utility>

#include "Gender.hpp"
#include "catch_amalgamated.hpp"

SCENARIO("Should parse the gender from a stream", "[gender][stream]") {
    using pair_type = std::pair<std::string, Gender>;
    GIVEN("A stream containing a gender string") {
        auto [string, gender] =
            GENERATE(pair_type{"agender", Gender::agender},
                     pair_type{"androgynous", Gender::androgynous},
                     pair_type{"female", Gender::female},
                     pair_type{"genderfluid", Gender::genderfluid},
                     pair_type{"intersex", Gender::intersex},
                     pair_type{"male", Gender::male},
                     pair_type{"nonbinary", Gender::nonbinary},
                     pair_type{"other", Gender::other},
                     pair_type{"SomeGarbage", Gender::other});
        std::stringstream stream{string};

        WHEN("Gender is obtained from the stream") {
            Gender gend{};
            stream >> gend;

            THEN("It should be the corresponding enum value") {
                REQUIRE(gend == gender);
            }
        }
    }
}
