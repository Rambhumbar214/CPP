/*2.Write a C++ program to create a class Distance which contains data members as kilometer, meter. 
Write a program to perform the following functions 
a.To accept distance 
b.To display distance 
c.To overload > operator to compare two distance*/

#include <iostream>
using namespace std;

class Distance {
private:
    int kilometers, meters;

public:
    void acceptDistance() {
        cout << "Enter distance (kilometers meters): ";
        cin >> kilometers >> meters;
    }
    
    void displayDistance() const {
        cout << "Distance: " << kilometers << " km " << meters << " m" << endl;
    }
    
    bool operator>(const Distance& d) const {
        int totalMeters1 = kilometers * 1000 + meters;
        int totalMeters2 = d.kilometers * 1000 + d.meters;
        return totalMeters1 > totalMeters2;
    }
};

int main() {
    Distance d1, d2;
    
    cout << "Enter first distance:" << endl;
    d1.acceptDistance();
    cout << "Enter second distance:" << endl;
    d2.acceptDistance();
    
    cout << "\nFirst ";
    d1.displayDistance();
    cout << "Second ";
    d2.displayDistance();
    
    if (d1 > d2) {
        cout << "\nFirst distance is greater than second distance." << endl;
    } else {
        cout << "\nSecond distance is greater than or equal to first distance." << endl;
    }
    
    return 0;
}