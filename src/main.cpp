#include "UniversityBase.hpp"

int main() {
    UniversityBase base{};
    base.generate_data(10);

    base.display(std::cout);

    return 0;
}
