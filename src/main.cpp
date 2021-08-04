#include "UniversityBase.hpp"

int main() {
    UniversityBase base{};
    base.generate_data(10);

    base.write_to_file();

    base.display();

    return 0;
}
