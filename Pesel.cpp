#include "Pesel.hpp"

int Pesel::get_day()
{
    return (date_of_birth_%100);
}

int Pesel::get_month()
{
    return ((date_of_birth_/100)%20);
}

int Pesel::get_year()
{
    int century=date_of_birth_%1e4;
    int year=date_of_birth/1e4;
    century/=20;
    if (0==year){
        year+=100;
    }
    if (4==century){
        century=19;
    }else{
        century+=20;
    }
    year+=100*century;
    return year;
}

int Gender Pesel::get_sex()
{
    if (serial_number_&1){
        return Gender::male;
    }
    return Gender::female;
}

bool Pesel::validation_data()
{
    int day=get_day();
    int month=get_month();
    int year=get_year();
    if (1>month||month>12 || day<1){
        return true;
    }
    if (2==month){
        if(!year&3){
            if(year%25==0){
                if(!year&15){
                    if(day>29){
                        return true;
                    }
                }else{
                    if(day>28){
                        return true;
                    }
                }
            }else{
                if(day>29){
                    return true;
                }
            }
        }else{
            if(day>28){
                return true;
            }
        }
    }else if(((month&1) && (month<7)) || ((!(month&1)) && (month>6)){
        if(day>31){
            return true;
        }
    }else{
        if(day>30){
            return true;
        }
    }
    return false;
}

bool Pesel::validation_check_digit()
{
    uint8_t check_digit=0;
    uint32_t date_of_birth=date_of_birth_;
    uint16_t serial_number=serial_number_;
    check_digit+=(date_of_birth%10)*3;
    date_of_birth/=10;
    check_digit+=(date_of_birth%10);
    date_of_birth/=10;
    check_digit+=(date_of_birth%10)*9;
    date_of_birth/=10;
    check_digit+=(date_of_birth%10)*7;
    date_of_birth/=10;
    check_digit+=(date_of_birth%10)*3;
    date_of_birth/=10;
    check_digit+=(date_of_birth%10);
    check_digit+=(serial_number%10)*3;
    date_of_birth/=10;
    check_digit+=(serial_number%10);
    date_of_birth/=10;
    check_digit+=(serial_number%10)*9;
    date_of_birth/=10;
    check_digit+=(serial_number%10)*7;
    check_digit%=10;
    return check_digit!=check_digit_;
}

bool Pesel::validation()
{
    if(validation_check_digit() || validation_data()){
        return true;
    }
    return false;
}
