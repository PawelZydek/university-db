#ifndef PESEL_HPP
#define PESEL_HPP

#include "Gender.hpp"

#include <cstdint>

/**
 *A structure that stores a PESEL number (Universal Electronic System for Registration of the Population).
 * @autors Jakub Stępień
 */
struct Pesel
{
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

    /**
     * The day of the birth month of the owner of the PESEL number,
     * if the PESEL number is correct, is from 1 to 31.
     */
    public int get_day();
    /**
     * Returns the month of year from 1 to 12, if the PESEL number is correct.
     */
    public int get_month();
    /**
     * The function returns year of birth of the owner of the PESEL number.
     */
    public int get_year();
    /**
     * Checks if the date in the PESEL number is correct.
     */
    public Gender get_sex();
    private bool validation_data();
    private bool validation_check_digit();
    /**
     * If the pesel is correct, it returns false.
     */
    public bool validation();
};
#endif /* PESEL_HPP */
