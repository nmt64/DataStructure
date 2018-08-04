// Timer.h

#ifndef TIMER_H
#define TIMER_H

#include <ctime>
#include <stdexcept>
#include <iostream>

using namespace std;


class Timer {
  public:
    /*pre: none
     post: constructor.
           Initialize the intenal timer values so that the timer is ready to measure time*/
    Timer();
    
    /*pre: the clock function is working correctly
     post: marsk the beginning of a time interval (stars the timers)*/
    void start() throw (runtime_error);
    
    /*pre: the beginning of a tim interval has been marked
     *post: marks the end of a time interval (stop the timer)*/
    void stop() throw (logic_error);
    
    /*pre: the beginning and end of a time interval have been marked
     *returns the length of the interval in seconds*/
    double getElapsedTime() const throw (logic_error);

  private:
    
    
    clock_t beginTime;      // value that denote the beginning of a time interval
    clock_t duration;       // value that denote the length of a time interval
    bool timerWasStarted;   // function checking if the time was started or not
                            // i don't use it
};

#endif	// ifndef TIMER_H

/* Default constructor
 @pre: none
 @post: constructor.
        Initialize the intenal timer values so that the timer is ready to measure time*/
Timer:: Timer(): timerWasStarted(false), beginTime(-1), duration(-1) {
    //
}

/*pre: the clock function is working correctly
 post: mark the beginning of a time interval (stars the timers)*/
void Timer:: start() throw (runtime_error){
    beginTime = clock();
    if (beginTime == -1)
        throw runtime_error("The clock funtion is not working correctly");
}

/*pre: the beginning of a tim interval has been marked
 *post: marks the end of a time interval (stop the timer)*/
void Timer:: stop() throw (logic_error){
    if (beginTime == -1)
        throw logic_error ("The beginning of a time interval has not been marked");
    else
        duration = clock() - beginTime;
}

/*pre: the beginning and end of a time interval have been marked
 *returns the length of the interval in seconds*/
double Timer::getElapsedTime() const throw (logic_error){
    if (beginTime == -1 || duration == -1)
        throw logic_error ("The beginning and end of a time interval have not been marked");
    else
        return (double)duration/CLOCKS_PER_SEC;
}

