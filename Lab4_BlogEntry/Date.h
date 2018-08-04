
#ifndef DATE_H
#define DATE_H

#include <stdexcept>
#include <iostream>

using namespace std;

class Date {
  public:
    /* Default constructor.
     @pre: none
     @post: creates a date that represents the current date*/
    Date();
    
    /* Constructor.
     @pre: none
     @post: creates a date that represents the specific date */
    Date(int day, int month, int year) throw (logic_error);

    /* Getter for day of month
     @pre: none
     @post: getter for day
     @return value of day */
    int getDay() const;
    
    /* Getter for Month
     @pre: none
     @post: getter for month
     @return value of month */
    int getMonth() const;
    
    /* Getter for year
     @pre: none
     @post: getter for year
     @return value of year */
    int getYear() const;

     /* Show contents of the Blog Entry - for testing/debugging only
      @pre: none
      @post: Contents of the BlogEntry*/
    void showStructure() const;
    
    /* Checking Leap year
     @pre: year is greater than 1901 A.D
     @post: static method. Return true if the specified year
     @return: return true if the specified year, else returns false.*/
    static bool isLeapYear(int year);
    
    /* Checking days in a specified month
     @pre: year is greater than 1901 A.D
     @post: static method. Return the numer of days in the specified month*/
    static int daysInMonth(int month, int year);

    // Programming Exercise 2
    int getDayOfWeek() const;

    // Programming Exercise 3
    bool operator<(const Date& rhs) const;
    bool operator==(const Date& rhs) const;
    bool operator>(const Date& rhs) const;

    /* Output the date in the same format as the showStructure function
     @pre: none
     @post: outputs the date in the same format as the showStructure function*/
    friend ostream& operator<<(ostream& out, const Date& date);

  private:
    int day; // must be an integer > 0, and depends on month and year
    int month; // must be an integer smaller than 13 and bigger than 0
    int year; // integer starts from 1

};

#endif
