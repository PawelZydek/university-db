#include "UniversityBase.hpp"
#include <algorithm>
#include <fstream>
#include <random>
#include <unordered_set>

void UniversityBase::add(const Student& student) {
    people_.push_back(std::make_shared<Student>(student));
}

void UniversityBase::add(Student&& student) {
    people_.push_back(std::make_shared<Student>(std::move(student)));
}

void UniversityBase::add(const Employee& employee) {
    people_.push_back(std::make_shared<Employee>(employee));
}

void UniversityBase::add(Employee&& employee) {
    people_.push_back(std::make_shared<Employee>(std::move(employee)));
}

void UniversityBase::display(std::ostream& out) const {
    out << "Employees:\n";
    for (const auto& person_ptr : people_) {
        if (const auto employee_ptr{
                dynamic_cast<Employee*>(person_ptr.get())}) {
            out << *employee_ptr << '\n';
        }
    }
    out << "Students:\n";
    for (const auto& person_ptr : people_) {
        if (const auto student_ptr{dynamic_cast<Student*>(person_ptr.get())}) {
            out << *student_ptr << '\n';
        }
    }
}

std::optional<std::shared_ptr<Person>> UniversityBase::search_by_surname(
    std::string_view surname) const {
    std::optional<std::shared_ptr<Person>> output_ptr{};
    for (const auto& person_ptr : people_) {
        if (person_ptr->get_surname() == surname) {
            output_ptr = person_ptr;
        }
    }
    return output_ptr;
}

std::optional<std::shared_ptr<Person>> UniversityBase::search_by_pesel(
    const Pesel& pesel) const {
    std::optional<std::shared_ptr<Person>> output_ptr{};
    for (const auto& person_ptr : people_) {
        if (person_ptr->get_pesel() == pesel) {
            output_ptr = person_ptr;
        }
    }
    return output_ptr;
}

void UniversityBase::sort_by_pesel() {
    std::sort(people_.begin(), people_.end(),
              [](auto& person_ptr1, auto& person_ptr2) {
                  return person_ptr1->get_pesel() < person_ptr2->get_pesel();
              });
}

void UniversityBase::sort_by_surname() {
    std::sort(people_.begin(), people_.end(),
              [](auto& person_ptr1, auto& person_ptr2) {
                  return person_ptr1->get_surname() <
                         person_ptr2->get_surname();
              });
}

void UniversityBase::erase_by_index(unsigned int index_num) {
    people_.erase(
        std::remove_if(
            people_.begin(), people_.end(),
            [index_num](auto& person_ptr) {
                auto student_ptr = dynamic_cast<Student*>(person_ptr.get());
                return student_ptr && student_ptr->get_index_num() == index_num;
            }),
        people_.end());
}

int random_number_gen(int min, int max) {
    static std::mt19937_64 mersenne{std::random_device()()};
    std::uniform_int_distribution roll{min, max};
    return roll(mersenne);
}

enum class PersonChoice { student, employee };

std::shared_ptr<Person> get_random_person(PersonChoice choice) {
    static constexpr int arr_size{6};
    static constexpr std::array<std::string_view, arr_size> names{
        "Jan", "Anna", "Adam", "Maria", "Lukasz", "Katarzyna"};
    static constexpr std::array<std::string_view, arr_size> surnames{
        "Nowak", "Kowalski", "Wojcik", "Kowalczyk", "Kaminski", "Lewandowski"};
    static constexpr std::array<std::string_view, arr_size> addresses{
        "Warsaw", "Cracow", "Lodz", "Poznan", "Wroclaw", "Gdansk"};

    Pesel pesel{{5, 6, 0, 2, 1, 0, 1, 6, 1, 3, 7}};

    if (choice == PersonChoice::student) {
        auto student_ptr = std::make_shared<Student>(
            names[random_number_gen(0, arr_size - 1)].data(),
            surnames[random_number_gen(0, arr_size - 1)].data(),
            addresses[random_number_gen(0, arr_size - 1)].data(), pesel,
            static_cast<Gender>(
                random_number_gen(0, static_cast<int>(Gender::maxGender))),
            random_number_gen(10000, 99999));
        return student_ptr;
    } else {
        auto employee_ptr = std::make_shared<Employee>(
            names[random_number_gen(0, arr_size - 1)].data(),
            surnames[random_number_gen(0, arr_size - 1)].data(),
            addresses[random_number_gen(0, arr_size - 1)].data(), pesel,
            static_cast<Gender>(
                random_number_gen(0, static_cast<int>(Gender::maxGender) - 1)),
            random_number_gen(8000, 22000));
        return employee_ptr;
    }
}

void UniversityBase::generate_data(int count) {
    for (int i{0}; i < count; ++i) {
        PersonChoice choice{static_cast<PersonChoice>(random_number_gen(0, 1))};
        people_.push_back(get_random_person(choice));
    }
}

void UniversityBase::set_salary_by_pesel(const Pesel& pesel,
                                         unsigned int salary) {
    auto person_iterator = std::find_if(
        people_.begin(), people_.end(), [&pesel](auto& person_ptr) {
            return person_ptr->get_pesel() == pesel;
        });

    if (person_iterator == people_.end()) {
        return;
    }
    auto employee_ptr = dynamic_cast<Employee*>((*person_iterator).get());
    if (employee_ptr) {
        employee_ptr->set_salary(salary);
    }
}

void UniversityBase::sort_by_salary() {
    std::vector<size_t> indeces{};
    indeces.reserve(people_.size());
    std::vector<std::shared_ptr<Employee>> employees{};
    for (size_t i{0}; i < people_.size(); ++i) {
        if (auto employee_ptr =
                std::dynamic_pointer_cast<Employee>(people_[i])) {
            indeces.push_back(i);
            employees.push_back(std::move(employee_ptr));
        }
    }
    indeces.shrink_to_fit();

    std::sort(employees.begin(), employees.end(),
              [](auto& employee_ptr1, auto& employee_ptr2) {
                  return employee_ptr1->get_salary() <
                         employee_ptr2->get_salary();
              });

    for (size_t i{0}; i < indeces.size(); ++i) {
        people_[indeces[i]] = std::move(employees[i]);
    }
}

void UniversityBase::write_employees_to_file(std::string_view file_path) const {
    std::ofstream employee_file{file_path.data()};

    employee_file << "Name,Surname,Address,Pesel,Gender,Salary\n";
    for (const auto& person_ptr : people_) {
        if (const auto employee_ptr =
                dynamic_cast<Employee*>(person_ptr.get())) {
            employee_file << *employee_ptr << '\n';
        }
    }
    employee_file.close();
}

void UniversityBase::write_students_to_file(std::string_view file_path) const {
    std::ofstream student_file{file_path.data()};

    student_file << "Name,Surname,Address,Pesel,Gender,IndexNumber\n";
    for (const auto& person_ptr : people_) {
        if (const auto student_ptr = dynamic_cast<Student*>(person_ptr.get())) {
            student_file << *student_ptr << '\n';
        }
    }
    student_file.close();
}

void UniversityBase::write_to_file(std::string_view employee_path,
                                   std::string_view student_path) const {
    write_employees_to_file(employee_path);
    write_students_to_file(student_path);
}

void UniversityBase::read_employees_from_file(std::string_view file_path) {
    std::ifstream file_stream{file_path.data()};

    if (!file_stream) {
        throw std::runtime_error{"the file does not exist"};
    }

    std::string tag{};
    std::getline(file_stream, tag);

    for (Employee employee{}; file_stream >> employee;) {
        people_.push_back(std::make_shared<Employee>(std::move(employee)));
    }
    file_stream.close();
}

void UniversityBase::read_students_from_file(std::string_view file_path) {
    std::ifstream file_stream{file_path.data()};

    if (!file_stream) {
        throw std::runtime_error{"the file does not exist"};
    }

    std::string tag{};
    std::getline(file_stream, tag);

    for (Student student{}; file_stream >> student;) {
        people_.push_back(std::make_shared<Student>(std::move(student)));
    }
    file_stream.close();
}