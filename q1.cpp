/*
Problem 1: Finding Favorite Times
Problem Description

Wendy has an LED clock radio, which is a 12-hour clock, displaying times from 12:00 to 11:59. The hours do not have leading zeros but minutes may have leading zeros, such as 2:07 or 11:03.

When looking at her LED clock radio, Wendy likes to spot arithmetic sequences in the digits. For example, the times 12:34 and 2:46 are some of her favourite times, since the digits form an arithmetic sequence.

A sequence of digits is an arithmetic sequence if each digit after the first digit is obtained by adding a constant common difference. For example, 1,2,3,4 is an arithmetic sequence with a common difference of 1, and 2,4,6 is an arithmetic sequence with a common difference of 2.

Suppose that we start looking at the clock at noon (that is, when it reads 12:00) and watch the clock for some number of minutes. How many instances are there such that the time displayed on the clock has the property that the digits form an arithmetic sequence?

Input Specification

The input contains one integer D (0 ≤ D ≤ 1 000 000 000), which represents the duration that the clock is observed. For 4 of the 15 available marks, D ≤ 10 000.

Output Specification

Output the number of times that the clock displays a time where the digits form an arithmetic sequence starting from noon (12:00) and ending after D minutes have passed, possibly including the ending time.

Sample Input 1

34

Output for Sample Input 1 1

Explanation of Output for Sample Input 1

Between 12:00 and 12:34, there is only the time 12:34 for which the digits form an arithmetic sequence.

Sample Input 2

180

Output for Sample Input 2

11

Explanation of Output for Sample Input 2

Between 12:00 and 3:00, the following times form arithmetic sequences in their digits (with the difference shown:

12:34 (difference 1),
1:11 (difference 0),
1:23 (difference 1),
1:35 (difference 2),
1:47 (difference 3),
1:59 (difference 4),
2:10 (difference -1),
2:22 (difference 0),
2:34 (difference 1),
2:46 (difference 2),
2:58 (difference 3).
*/

#include <iostream>

// The input contains one integer D (minutes) (0 ≤ D ≤ 1 000 000 000), 
// which represents the duration that the clock is observed.

// 0-1 0-9 : 0-9 0-9

// first approach: for i = 0, i++, until i = D
// represent each 4 digits of the clock with integers 

// create a class called clock which we will make our clock instance from 
    // properties of the class will be: hour1, hour2, minute1, minute2 (hour1 hour2 : minute1 minute2)
    // methods of the class will be: 
        // void timeForward() - which moves the time forward with the same restrictions a clock will have
        // bool isSequence() - which checks the differences between hour1, hour2, minute1, and minute2, and if the differences are the same then we return true 
// we then loop from 0 to D, incrementing the clock by 1(ie. moving the clock forward by 1 minute) 
// and then checking if the difference between all the digits of the clock are the same
// if they are the same then we increment our output by 1 

class Clock {
    // methods of the class will be: 
    public: 
    // properties of the class will be: hour1, hour2, minute1, minute2 (hour1 hour2 : minute1 minute2)
    int hour1;
    int hour2;
    int minute1; 
    int minute2; 
    // ctor 
    Clock(int hour1, int hour2, int minute1, int minute2): hour1(hour1), hour2(hour2), minute1(minute1), minute2(minute2) {} 
    // void timeForward() - which moves the time forward with the same restrictions a clock will have
    void timeForward(); 
    void incrementHour(); 
    // bool isSequence() - which checks the differences between hour1, hour2, minute1, and minute2, and if the differences are the same then we return true 
    int isSequence(); 
};

void Clock::incrementHour() {
    // Increment the hours by 1
    hour2++;
    if (hour2 == 10) {
        hour2 = 0;
        hour1++;
    }
    if (hour1 == 1 && hour2 == 3) {
        hour1 = 0;
        hour2 = 1; 
    }
}

// void timeForward() - which moves the time forward with the same restrictions a clock will have
void Clock::timeForward() {
    minute2++;
    if (minute2 == 10) {
        minute2 = 0;
        minute1++;

        if (minute1 == 6) {
            minute1 = 0;
            incrementHour();
        }
    }
    return; 
}

int Clock::isSequence() {
    // for isSequence, if hour1 is 0, we do not use it in our calculations
    // only check hour2, minute1, and minute2 
    //std::cout << "The time is - " << hour1 << hour2 << ":" << minute1 << minute2 << std::endl;

    if (hour1 == 0) {
        if ((hour2 - minute1 == minute1 - minute2)) {
            //std::cout << hour2 - minute1 << " " << minute1 - minute2 << " or "; 
            //std::cout << minute2 - minute1 << " " << minute1 - hour2 << std::endl;
            return 1; 
        }
        else {
            return 0; 
        }
    }
    // if hour1 is not zero, then we use it in our calculations 
    else {
        if ((hour1 - hour2 == hour2 - minute1 && hour2 - minute1 == minute1 - minute2)) {
            //std::cout << hour1 - hour2 << " " <<  hour2 - minute1 << " " << minute1 - minute2 << " or "; 
            //std::cout << minute2 - minute1 << " " << minute1 - hour2 << " " << hour2 - hour1 << std::endl;
            return 1; 
        }
        else {
            return 0; 
        }
    }
    return 0; 
}

int main() {
    // create our clock instance
    Clock ledClock(1, 2, 0, 0); 
    // std::cout << ledClock.hour1 << std::endl; // checking if the class is initialized properly
    // create a for loop, from int i - 0 to D and increment then check 
    int input = 0;
    std::cin >> input;  
    int output = 0; 
    for (int i = 0; i <= input; i++) {
        //std::cout << "Minute " << i << " has passed" << std::endl;
        output += ledClock.isSequence(); 
        ledClock.timeForward(); 
    }

    std::cout << output << std::endl;

    return 0;
}