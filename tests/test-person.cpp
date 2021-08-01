#include <sstream>
#include "Person.hpp"
#include "catch_amalgamated.hpp"
#include <assert.h>

SCENARIO("Should output the Person to a stream", "[person][stream][output]") {
    GIVEN("A Person object") {
        Person person{};
        std::string str{"Jan,Kowalski,Warszawa,70080837171,male"};
        try {
            person =
                Person{"Jan", "Kowalski", "Warszawa",
                       Pesel{{7, 0, 0, 8, 0, 8, 3, 7, 1, 7, 1}}, Gender::male};
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            assert(false && "Exception thrown during construction");
        }
        WHEN("It's output to a stream") {
            std::stringstream outputStream{};
            outputStream << person;
            THEN("It should be in CSV format") {
                REQUIRE(outputStream.str() == str);
            }
        }
    }
}