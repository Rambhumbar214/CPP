/* Write C++ program to create a class Employee containing data members Emp_no, Emp_Name, 
Designation and Salary. Create and initialize the objects using default, parameterized and Copy 
Constructor. Also write member function to calculate Income tax of the employee which is 20% 
of salary.*/

#include <iostream>
#include <cstring>
using namespace std;

class Employee {
private:
    int Emp_no;
    string Emp_Name;
    string Designation;
    double Salary;

public:
    // Default Constructor
    Employee() : Emp_no(0), Emp_Name("Unknown"), Designation("Unknown"), Salary(0.0) {}
    
    // Parameterized Constructor
    Employee(int eno, string name, string desg, double sal) : Emp_no(eno), Emp_Name(name), Designation(desg), Salary(sal) {}
    
    // Copy Constructor
    Employee(const Employee &e) {
        Emp_no = e.Emp_no;
        Emp_Name = e.Emp_Name;
        Designation = e.Designation;
        Salary = e.Salary;
    }
    
    // Function to calculate Income Tax (20% of Salary)
    double calculateTax() const {
        return Salary * 0.2;
    }
    
    // Function to display employee details
    void display() const {
        cout << "Employee Number: " << Emp_no << endl;
        cout << "Employee Name: " << Emp_Name << endl;
        cout << "Designation: " << Designation << endl;
        cout << "Salary: " << Salary << endl;
        cout << "Income Tax (20%): " << calculateTax() << endl;
    }
};

int main() {
    // Creating Employee objects
    Employee e1;
    Employee e2(101, "John Doe", "Manager", 50000);
    Employee e3(e2); // Copy Constructor
    
    cout << "\nDefault Constructor Employee:\n";
    e1.display();
    
    cout << "\nParameterized Constructor Employee:\n";
    e2.display();
    
    cout << "\nCopy Constructor Employee:\n";
    e3.display();
    
    return 0;
}
