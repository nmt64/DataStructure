
#ifndef DATE_H
#define DATE_H

#include <stdexcept>
#include <iostream>

using namespace std;

class Date {
  public:
    Date();
    Date(int day, int month, int year) throw (logic_error);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void showStructure() const;

    static bool isLeapYear(int year);
    static int daysInMonth(int month, int year);

    // Programming Exercise 2
    int getDayOfWeek() const;

    // Programming Exercise 3
    bool operator<(const Date& rhs) const;
    bool operator==(const Date& rhs) const;
    bool operator>(const Date& rhs) const;

    friend ostream& operator<<(ostream& out, const Date& date);

  private:
    int day; // must be an integer > 0, and depends on month and year
    int month; // must be an integer smaller than 13 and bigger than 0
    int year; // integer starts from 1

};

#endif
