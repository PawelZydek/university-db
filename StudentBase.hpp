#ifndef STUDENTBASE_HPP
#define STUDENTBASE_HPP
#include <memory>
#include <optional>
#include <vector>

#include "Student.hpp"

class StudentBase {
   public:
    StudentBase() = default;

    // Add student
    void add_student(Student&);
    // Display students list
    void display_list() const;

    // Sorting functions
    void sort_by_pesel();
    void sort_by_surname();

    void erase_by_id(unsigned int);

    void write_to_file(const std::string&) const;
    void read_from_file(const std::string&);

    [[nodiscard]] std::optional<Student> search_by_pesel(const Pesel&) const;
    [[nodiscard]] std::optional<Student> search_by_surname(
        const std::string&) const;

   private:
    std::vector<std::shared_ptr<Student> > student_list_;
};
#endif /* STUDENTBASE_HPP */