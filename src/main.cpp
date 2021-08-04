#include "UniversityBase.hpp"

int main() {
    UniversityBase base{};
    base.generate_data(10);

    base.display(std::cout);

    base.sort_by_salary();

    base.display(std::cout);

    return 0;
}
