#include "UniversityBase.hpp"

int main() {
    Student student{"Jan",        "Kowalski",
                    "Warszawa",   Pesel{{8, 0, 1, 0, 2, 8, 1, 8, 4, 9, 9}},
                    Gender::male, 12345};

    Employee employee{"Anna",         "Nowak",
                      "Krakow",       Pesel{{9, 2, 0, 9, 2, 3, 1, 2, 9, 7, 8}},
                      Gender::female, 7777};

    UniversityBase base{};
    base.add(student);
    base.add(employee);

    base.display(std::cout);

    return 0;
}
