#include "catch_amalgamated.hpp"
#include "Employee.hpp"

#include <sstream>

SCENARIO("Should output the Employee to a stream", "[employee][output][stream]") {
    GIVEN("An employee") {
        Employee employee{"Jan",        "Kowalski",
                        "Warszawa",   Pesel{{7, 4, 0, 3, 2, 6, 2, 5, 7, 3, 9}},
                        Gender::male, 222222};
        std::string string{"Jan,Kowalski,Warszawa,74032625739,male,222222"};

        WHEN("It's output to a stream") {
            std::stringstream stream{};
            stream << employee;

            THEN("It should be in CSV format") {
                REQUIRE(stream.str() == string);
            }
        }
    }
}

SCENARIO("Should parse the Employee from a stream",
         "[employee][output][stream]") {
    GIVEN("A stream with an Employee string") {
        Employee employee{"Jan",        "Kowalski",
                        "Warszawa",   Pesel{{7, 4, 0, 3, 2, 6, 2, 5, 7, 3, 9}},
                        Gender::male, 222222};
        std::string string{"Jan,Kowalski,Warszawa,74032625739,male,222222"};

        WHEN("It's output to a stream") {
            std::stringstream stream{string};
            Employee inputEmployee{};
            stream >> inputEmployee;

            THEN("It should be correct") { REQUIRE(inputEmployee == employee); }
        }
    }
}