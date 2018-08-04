//
//  Date.cpp
//  CS120Lab4_TamNguyen
//
//  Created by Nguyen Tam on 2/5/18.
//  Copyright © 2018 Nguyen Tam. All rights reserved.
//

#include <iostream>
#include "Date.h"
#include<ctime>
#include <stdexcept>

using namespace std;

Date :: Date () {
    time_t now = time(NULL);
    struct tm *current = localtime(&now);
    day = current->tm_mday;
    month = current->tm_mon + 1;
    year = current->tm_year + 1900;
}

Date :: Date (int day, int month, int year) throw (logic_error) {
    if (year < 1)
    throw logic_error("year not in valid range");
    if (month > 13 || month < 1)
    throw logic_error("month not in valide range");
    if (day < 1 && day > daysInMonth(month, year))
    throw logic_error("days not in valid range");
    
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date :: getDay () const {
    return day;
}

int Date :: getMonth () const {
    return month;
}

int Date :: getYear() const {
    return year;
}

void Date ::showStructure() const {
    // Outputs data in same form as operator<<.
    // NOTE: could do "cout << *this << endl", but that would not compile
    // if operator<< has not been defined.
    cout << month << "/" << day << "/" << year << endl;
}

bool Date :: isLeapYear( int year ) {
    if(year%400==0)
        return true;
    if(year%100==0)
        return false;
    if(year%4==0)
        return true;
    return false;
}

int Date :: daysInMonth (int month, int year) {
    //months have 31 days
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    //months have 30 days
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    //February
    if (isLeapYear(year))
        return 29;
    else
        return 28;
}

ostream & operator<< (ostream& out, const Date& date) {
    out << date.month << "/" << date.day << "/" << date.year ;
    return out;
}
