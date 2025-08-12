/*Write a C++ program to create a class employee containing salary as a data member. Write 
necessary member functions to overload the operator unary pre and post decrement "--" 
for decrementing salary*/

#include <iostream>
using namespace std;

class Employee {
private:
    double salary;

public:
    // Constructor
    Employee(double sal) : salary(sal) {}

    // Function to display salary
    void displaySalary() const {
        cout << "Salary: " << salary << endl;
    }

    // Overloading pre-decrement operator (--salary)
    Employee& operator--() {
        --salary;
        return *this;
    }

    // Overloading post-decrement operator (salary--)
    Employee operator--(int) {
        Employee temp = *this;
        salary--;
        return temp;
    }
};

int main() {
    double initialSalary;
    cout << "Enter employee salary: ";
    cin >> initialSalary;

    Employee emp(initialSalary);
    cout << "\nOriginal Salary: ";
    emp.displaySalary();
    
    --emp; // Pre-decrement
    cout << "After Pre-Decrement: ";
    emp.displaySalary();
    
    emp--; // Post-decrement
    cout << "After Post-Decrement: ";
    emp.displaySalary();
    
    return 0;
}