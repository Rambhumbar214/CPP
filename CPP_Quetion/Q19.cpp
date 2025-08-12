/*Write a C++ program using class which contains two data members as type integer. Create and 
initialize the objects using default constructor, parameterized constructor with default value. 
Write a member function to display maximum from given two numbers for all objects. */

#include <iostream>
using namespace std;

class Number {
private:
    int num1, num2;
public:
    // Default constructor
    Number() : num1(0), num2(0) {}
    
    // Parameterized constructor with default value
    Number(int n1, int n2 = 0) : num1(n1), num2(n2) {}
    
    // Function to display maximum of two numbers
    void displayMax() {
        cout << "Maximum of (" << num1 << ", " << num2 << ") is: " << (num1 > num2 ? num1 : num2) << endl;
    }
};

int main() {
    Number obj1; // Calls default constructor
    Number obj2(10); // Calls parameterized constructor with one argument
    Number obj3(15, 25); // Calls parameterized constructor with two arguments
    
    cout << "Object 1: ";
    obj1.displayMax();
    cout << "Object 2: ";
    obj2.displayMax();
    cout << "Object 3: ";
    obj3.displayMax();
    
    return 0;
}
