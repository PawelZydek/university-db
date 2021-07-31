#include "Pesel.hpp"
#include "catch_amalgamated.hpp"


// VALIDATION TESTS
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

SCENARIO("Should check Pesel's validity", "[pesel][invalid][check_digit]") {
    GIVEN("An invalid Pesel") {
        // Invalid check_digit
        auto pesel = GENERATE(Pesel{{0, 2, 2, 3, 3, 0, 4, 6, 2, 3, 3}},
                              Pesel{{8, 6, 1, 0, 2, 7, 1, 6, 1, 6, 2}},
                              Pesel{{9, 2, 0, 2, 0, 4, 3, 7, 8, 3, 1}},
                              Pesel{{9, 4, 0, 7, 0, 9, 9, 1, 9, 7, 9}},
                              Pesel{{7, 4, 1, 2, 0, 6, 7, 6, 7, 1, 4}});

        WHEN("It's validity is checked") {
            THEN("It should return false") { REQUIRE_FALSE(pesel.is_valid()); }
        }
    }
}

SCENARIO("Should check Pesel's validity", "[pesel][invalid][date]") {
    GIVEN("An invalid Pesel") {
        // All have valid check_digits: 1, 2 - invalid month; 3, 4 - invalid day
        auto pesel = GENERATE(Pesel{{0, 2, 3, 9, 3, 0, 4, 6, 2, 3, 6}},
                              Pesel{{8, 6, 5, 9, 2, 7, 1, 6, 1, 6, 5}},
                              Pesel{{0, 2, 2, 2, 3, 2, 5, 1, 6, 2, 0}},
                              Pesel{{8, 7, 0, 4, 4, 2, 8, 1, 4, 6, 0}}
        );

        WHEN("It's validity is checked") {
            THEN("It should return false") { REQUIRE_FALSE(pesel.is_valid()); }
        }
    }
}

SCENARIO("Should check Pesel's validity", "[pesel][invalid][digits]")
{
    GIVEN("An invalid Pesel") {
        // Both have valid check_digits, but contain a non-digit number
        auto pesel = GENERATE(Pesel{{0, 2, 2, 3, 3, 0, 4, 6, 14, 3, 5}},
                              Pesel{{8, 6, 1, 0, 2, 7, 1, 6, 17, 6, 8}}
        );

        WHEN("It's validity is checked") {
            THEN("It should return false") { REQUIRE_FALSE(pesel.is_valid()); }
        }
    }
}