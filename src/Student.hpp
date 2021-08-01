#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"

class Student : public Person {
   public:
    Student(const std::string&,
            const std::string&,
            const std::string&,
            const Pesel&,
            Gender,
            unsigned int);

    Student(std::string&&,
            std::string&&,
            std::string&&,
            Pesel&&,
            Gender,
            unsigned int);

    Student(const Person&, unsigned int);
    Student(Person&&, unsigned int);

    Student(const Student& student) = default;
    Student(Student&& student) = default;

    Student& operator=(const Student& student) = default;
    Student& operator=(Student&& student) = default;

    // Getter
    [[nodiscard]] unsigned int get_index_num() const { return index_num_; }

    // Setter
    void set_index_num(unsigned int index_num) { index_num_ = index_num; }

    friend std::ostream& operator<<(std::ostream&, const Student&);

   private:
    unsigned int index_num_{};
};

#endif /* STUDENT_HPP */