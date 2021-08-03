#include "UniversityBase.hpp"
#include "catch_amalgamated.hpp"

#include <sstream>
#include <string_view>

SCENARIO("Should add Students and Employees to the base and display the list",
         "[universitybase][add][display]") {
    GIVEN("A UniversityBase object, a Student and an Employee") {
        UniversityBase base{};
        Student student{"Jan",        "Kowalski",
                        "Warszawa",   Pesel{{8, 0, 1, 0, 2, 8, 1, 8, 4, 9, 9}},
                        Gender::male, 12345};

        Employee employee{
            "Anna",         "Nowak",
            "Krakow",       Pesel{{9, 2, 0, 9, 2, 3, 1, 2, 9, 7, 8}},
            Gender::female, 7777};

        static constexpr std::string_view str{
            "Employees:\nAnna,Nowak,Krakow,92092312978,female,7777\n"
            "Students:\nJan,Kowalski,Warszawa,80102818499,male,12345\n"};

        WHEN("They are added to the base and displayed to a stream") {
            base.add(student);
            base.add(employee);

            std::stringstream stream{};
            base.display(stream);

            THEN("The obtained string should match the str string") {
                REQUIRE(stream.str() == str);
            }
        }
    }
}

SCENARIO("Should search by a surname string",
         "[universitybase][search][surname]") {
    GIVEN("A Student object added to a base object") {
        UniversityBase base{};
        Student student{"Jan",        "Kowalski",
                        "Warszawa",   Pesel{{8, 0, 1, 0, 2, 8, 1, 8, 4, 9, 9}},
                        Gender::male, 12345};
        base.add(student);
        WHEN("search_by_surname is called") {
            auto optional_ptr = base.search_by_surname(student.get_surname());

            THEN("It should return shared_ptr with student's data") {
                REQUIRE(optional_ptr.has_value());
                auto student_ptr =
                    dynamic_cast<Student*>(optional_ptr.value().get());
                REQUIRE(student_ptr);
                REQUIRE(*student_ptr == student);
            }
        }
    }
}

SCENARIO("Should search by a Pesel", "[universitybase][search][pesel]") {
    GIVEN("A Student object added to a base object") {
        UniversityBase base{};
        Student student{"Jan",        "Kowalski",
                        "Warszawa",   Pesel{{8, 0, 1, 0, 2, 8, 1, 8, 4, 9, 9}},
                        Gender::male, 12345};
        base.add(student);
        WHEN("search_by_pesel is called") {
            auto optional_ptr = base.search_by_pesel(student.get_pesel());

            THEN("It should return shared_ptr with student's data") {
                REQUIRE(optional_ptr.has_value());
                auto student_ptr =
                    dynamic_cast<Student*>(optional_ptr.value().get());
                REQUIRE(student_ptr);
                REQUIRE(*student_ptr == student);
            }
        }
    }
}