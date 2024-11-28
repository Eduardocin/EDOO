#include <iostream>
#include <ctime>
#include "Date.h"


void  Date::init(int month, int day, int year){
    this->month = month;
    this->day = day;
    this->year = year;

}
void Date::init(void){
    time_t sec;
    time(&sec);
    struct tm* timeinfo = localtime(&sec);

    this->month = timeinfo->tm_mon + 1;
    this->day = timeinfo->tm_mday;
    this->year = timeinfo->tm_year + 1900;

}

void Date::print(void) {
    std::cout << month << "-" << day << "-" << year << std::endl;
}

