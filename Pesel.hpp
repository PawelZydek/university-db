#ifndef PESEL_HPP
#define PESEL_HPP

#include "Gender.hpp"

#include <cstdint>

/**
 *A structure that stores a PESEL number (Universal Electronic System for Registration of the Population).
 * @autors Jakub Stępień
 */
class Pesel
{
public:
    Pesel(uint32_t birth, uint16_t serial, uint8_t check_digit);

    /**
     * The day of the birth month of the owner of the PESEL number,
     * if the PESEL number is correct, is from 1 to 31.
     */
    int get_day();
    /**
     * Returns the month of year from 1 to 12, if the PESEL number is correct.
     */
    int get_month();
    /**
     * The function returns year of birth of the owner of the PESEL number.
     */
    int get_year();
    /**
     * Checks if the date in the PESEL number is correct.
     */
    Gender get_gender();

    /**
     * If the pesel is correct, it returns false.
     */
    bool is_valid();

private:
  /**
   * Date of birth in the owner of the PESEL number in the YYMMDD format.
   */
  uint32_t date_of_birth_;
  /**
   * Serial number with gender indication.
   */
  uint16_t serial_number_;
  /**
   * Check digit.
   */
  uint8_t check_digit_;

  // Validation functions
  bool validation_date();
  bool validation_check_digit();
};
#endif /* PESEL_HPP */
