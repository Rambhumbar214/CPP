/*Create a class Time containing members as: - hours - minutes - seconds 
Write a C++ program for overloading operators >> and << to accept and display a Time 
also write a member function to display time in total seconds. */


#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    // Overloading >> operator to input time
    friend istream& operator>>(istream &input, Time &t) {
        cout << "Enter hours: ";
        input >> t.hours;
        cout << "Enter minutes: ";
        input >> t.minutes;
        cout << "Enter seconds: ";
        input >> t.seconds;
        return input;
    }

    // Overloading << operator to display time
    friend ostream& operator<<(ostream &output, const Time &t) {
        output << t.hours << ":" << t.minutes << ":" << t.seconds;
        return output;
    }
    
    // Function to display total time in seconds
    int toSeconds() const {
        return (hours * 3600) + (minutes * 60) + seconds;
    }
};

int main() {
    Time t;
    cin >> t;
    cout << "Time Entered: " << t << endl;
    cout << "Total seconds: " << t.toSeconds() << endl;
    return 0;
}
