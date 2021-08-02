#include "Student.hpp"
#include "catch_amalgamated.hpp"

#include <sstream>

SCENARIO("Should output the Student to a stream", "[student][output][stream]") {
    GIVEN("A student") {
        Student student{"Jan",        "Kowalski",
                        "Warszawa",   Pesel{{7, 4, 0, 3, 2, 6, 2, 5, 7, 3, 9}},
                        Gender::male, 12345};
        std::string string{"Jan,Kowalski,Warszawa,74032625739,male,12345"};

        WHEN("It's output to a stream") {
            std::stringstream stream{};
            stream << student;

            THEN("It should be in CSV format") {
                REQUIRE(stream.str() == string);
            }
        }
    }
}

SCENARIO("Should parse the Student from a stream",
         "[student][output][stream]") {
    GIVEN("A stream with a Student string") {
        Student student{"Jan",        "Kowalski",
                        "Warszawa",   Pesel{{7, 4, 0, 3, 2, 6, 2, 5, 7, 3, 9}},
                        Gender::male, 12345};
        std::string string{"Jan,Kowalski,Warszawa,74032625739,male,12345"};

        WHEN("It's output to a stream") {
            std::stringstream stream{string};
            Student inputStudent{};
            stream >> inputStudent;

            THEN("It should be correct") { REQUIRE(inputStudent == student); }
        }
    }
}