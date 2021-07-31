#include "Pesel.hpp"
#include "catch_amalgamated.hpp"

SCENARIO("Should check Pesel's validity", "[pesel][valid]") {
    GIVEN("A valid Pesel") {
        auto pesel = GENERATE(Pesel{{0, 2, 2, 3, 3, 0, 4, 6, 2, 3, 7}},
                              Pesel{{8, 6, 1, 0, 2, 7, 1, 6, 1, 6, 4}},
                              Pesel{{9, 2, 0, 2, 0, 4, 3, 7, 8, 3, 4}},
                              Pesel{{9, 4, 0, 7, 0, 9, 9, 1, 9, 7, 7}},
                              Pesel{{7, 4, 1, 2, 0, 6, 7, 6, 7, 1, 5}});

        WHEN("It's validity is checked") {
            THEN("It should return true") { REQUIRE(pesel.is_valid()); }
        }
    }
}