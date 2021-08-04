#include "UniversityBase.hpp"

int main() {
    UniversityBase base{};
    base.generate_data(4);

    base.write_to_file();

    base.display();

    base.read_students_from_file("students.csv");
    base.read_employees_from_file("employees.csv");

    base.display();

    return 0;
}
