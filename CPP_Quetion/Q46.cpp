/* Write a C++ program to create a class Number which contains two integer data members. Create 
and initialize the object by using default constructor, parameterized constructor. Write a 
member function to display maximum from given two numbers for all objects. */

#include <iostream>
using namespace std;

class Number {
private:
    int num1, num2;

public:
    // Default Constructor
    Number() : num1(0), num2(0) {}
    
    // Parameterized Constructor
    Number(int a, int b) : num1(a), num2(b) {}
    
    // Function to display the maximum of the two numbers
    void displayMax() const {
        cout << "Maximum of " << num1 << " and " << num2 << " is: " << ((num1 > num2) ? num1 : num2) << endl;
    }
};

int main() {
    // Creating objects
    Number n1;
    Number n2(10, 20);
    Number n3(50, 30);
    
    cout << "\nDefault Constructor Object:\n";
    n1.displayMax();
    
    cout << "\nParameterized Constructor Object 1:\n";
    n2.displayMax();
    
    cout << "\nParameterized Constructor Object 2:\n";
    n3.displayMax();
    
    return 0;
}