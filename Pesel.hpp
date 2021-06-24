#ifndef PESEL_HPP
#define PESEL_HPP

#include "Gender.hpp"

#include <array>
#include <cstdint>
#include <iostream>
#include <string>

/**
 *A structure that stores a PESEL number (Universal Electronic System for
 *Registration of the Population).
 * @authors Jakub Stępień raxonpc
 */
class Pesel {
public:
  Pesel(const std::array<uint8_t, 11> &);

  Pesel() = default;

  /**
   * The day of the birth month of the owner of the PESEL number,
   * if the PESEL number is correct, is from 1 to 31.
   */
  int get_day() const;
  /**
   * Returns the month of year from 1 to 12, if the PESEL number is correct.
   */
  int get_month() const;
  /**
   * The function returns year of birth of the owner of the PESEL number.
   */
  int get_year() const;

  /**
   * If the pesel is correct, it returns false.
   */
  bool is_valid() const;

  [[nodiscard]] std::string get_string() const;

  friend std::istream &operator>>(std::istream &, Pesel &);
  friend bool operator<(const Pesel &pesel1, const Pesel &pesel2);
  friend bool operator==(const Pesel &pesel1, const Pesel &pesel2);

private:
  /**
   * Array holding pesel numbers
   */
  std::array<uint8_t, 11> pesel_;

  // Validation functions
  bool validation_date() const;
  bool validation_check_digit() const;
};
#endif /* PESEL_HPP */
