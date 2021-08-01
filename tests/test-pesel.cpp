#include "Pesel.hpp"
#include "catch_amalgamated.hpp"

#include <tuple>
#include <utility>
#include <sstream>

// VALIDATION TESTS
SCENARIO("Should check Pesel's validity (valid)", "[pesel][valid]") {
    GIVEN("A valid Pesel") {
        auto pesel = GENERATE(Pesel{{0, 2, 2, 3, 3, 0, 4, 6, 2, 3, 7}},
                              Pesel{{8, 6, 1, 0, 2, 7, 1, 6, 1, 6, 4}},
                              Pesel{{9, 2, 0, 2, 0, 4, 3, 7, 8, 3, 4}},
                              Pesel{{9, 4, 0, 7, 0, 9, 9, 1, 9, 7, 7}},
                              Pesel{{7, 4, 1, 2, 0, 6, 7, 6, 7, 1, 5}});

        WHEN("It's validity is checked " << pesel) {
            THEN("It should return true") { REQUIRE(pesel.is_valid()); }
        }
    }
}

SCENARIO("Should check Pesel's validity (invalid check_digit)", "[pesel][invalid][check_digit]") {
    GIVEN("An invalid Pesel") {
        // Invalid check_digit
        auto pesel = GENERATE(Pesel{{0, 2, 2, 3, 3, 0, 4, 6, 2, 3, 3}},
                              Pesel{{8, 6, 1, 0, 2, 7, 1, 6, 1, 6, 2}},
                              Pesel{{9, 2, 0, 2, 0, 4, 3, 7, 8, 3, 1}},
                              Pesel{{9, 4, 0, 7, 0, 9, 9, 1, 9, 7, 9}},
                              Pesel{{7, 4, 1, 2, 0, 6, 7, 6, 7, 1, 4}});

        WHEN("It's validity is checked " << pesel) {
            THEN("It should return false") { REQUIRE_FALSE(pesel.is_valid()); }
        }
    }
}

SCENARIO("Should check Pesel's validity (invalid date)", "[pesel][invalid][date]") {
    GIVEN("An invalid Pesel") {
        // All have valid check_digits: 1, 2 - invalid month; 3, 4 - invalid day
        auto pesel = GENERATE(Pesel{{0, 2, 3, 9, 3, 0, 4, 6, 2, 3, 6}},
                              Pesel{{8, 6, 5, 9, 2, 7, 1, 6, 1, 6, 5}},
                              Pesel{{0, 2, 2, 2, 3, 2, 5, 1, 6, 2, 0}},
                              Pesel{{8, 7, 0, 4, 4, 2, 8, 1, 4, 6, 0}});

        WHEN("It's validity is checked " << pesel) {
            THEN("It should return false") { REQUIRE_FALSE(pesel.is_valid()); }
        }
    }
}

SCENARIO("Should check Pesel's validity (invalid digits)", "[pesel][invalid][digits]") {
    GIVEN("An invalid Pesel") {
        // Both have valid check_digits, but contain a non-digit number
        auto pesel = GENERATE(Pesel{{0, 2, 2, 3, 3, 0, 4, 6, 14, 3, 5}},
                              Pesel{{8, 6, 1, 0, 2, 7, 1, 6, 17, 6, 8}});

        WHEN("It's validity is checked " << pesel) {
            THEN("It should return false") { REQUIRE_FALSE(pesel.is_valid()); }
        }
    }
}

// Date tests
SCENARIO("Should check Pesel's date", "[pesel][date]") {
    GIVEN("A Pesel") {
        using tuple_type = std::tuple<int, int, int>;
        using pair_type = std::pair<Pesel, tuple_type>;
        auto [pesel, date] =
            GENERATE(pair_type{Pesel{{7, 2, 0, 2, 2, 9, 6, 7, 6, 8, 5}},
                               tuple_type{29, 2, 1972}},
                     pair_type{Pesel{{0, 0, 0, 8, 1, 4, 6, 7, 8, 3, 3}},
                               tuple_type{14, 8, 1900}},
                     pair_type{Pesel{{0, 0, 4, 6, 2, 6, 7, 5, 5, 4, 7}},
                               tuple_type{26, 6, 2100}},
                     pair_type{Pesel{{1, 2, 3, 0, 1, 7, 7, 2, 1, 6, 4}},
                               tuple_type{17, 10, 2012}});

        auto [day, month, year] = date;

        WHEN("It's date is checked " << pesel) {
            THEN("It should be correct") {
                REQUIRE(pesel.get_day() == day);
                REQUIRE(pesel.get_month() == month);
                REQUIRE(pesel.get_year() == year);
            }
        }
    }
}

SCENARIO("Should output the Pesel to a stream", "[pesel][output][stream]")
{
    GIVEN("A Pesel")
    {
        Pesel pesel{{7,4,0,2,1,9,4,6,2,2,5}};
        std::string str{"74021946225"};

        WHEN("It's output to a stream")
        {
            std::stringstream stream{};
            stream << pesel;

            THEN("It should be correct")
            {
                REQUIRE(stream.str() == str);
            }
        }
    }
}