/*. Create a class Time which contains data members as: Hours, Minutes and Seconds. Write a 
C++ program to perform following necessary member functions: 
a. To read time 
b. To display time in format like: hh:mm:ss 
c. To add two different times (Use Objects as argument)*/

#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    // Function to read time
    void readTime() {
        cout << "Enter time (hh mm ss): ";
        cin >> hours >> minutes >> seconds;
    }

    // Function to display time in hh:mm:ss format
    void displayTime() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds << endl;
    }

    // Function to add two Time objects
    Time addTime(const Time &t) const {
        Time result;
        result.seconds = seconds + t.seconds;
        result.minutes = minutes + t.minutes + result.seconds / 60;
        result.seconds %= 60;
        result.hours = hours + t.hours + result.minutes / 60;
        result.minutes %= 60;
        result.hours %= 24; // Keeping time in 24-hour format
        return result;
    }
};

int main() {
    Time t1, t2, sum;
    
    cout << "Enter first time:\n";
    t1.readTime();
    
    cout << "Enter second time:\n";
    t2.readTime();
    
    sum = t1.addTime(t2);
    
    cout << "\nFirst Time: ";
    t1.displayTime();
    
    cout << "Second Time: ";
    t2.displayTime();
    
    cout << "Sum of Times: ";
    sum.displayTime();
    
    return 0;
}