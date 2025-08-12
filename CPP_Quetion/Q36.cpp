/* Implement the following class hierarchy: 
Employee: code, ename, desg 
Manager (derived from Employee): year_of_experience, salary 
Define appropriate functions to accept and display details. 
Create n objects of the manager class and display the records. 
Write main function that uses the above class and its member functions.*/

#include <iostream>
#include <vector>
using namespace std;

class Employee {
protected:
    int code;
    string ename;
    string desg;

public:
    void acceptEmployeeDetails() {
        cout << "Enter Employee Code: ";
        cin >> code;
        cout << "Enter Employee Name: ";
        cin >> ename;
        cout << "Enter Designation: ";
        cin >> desg;
    }
    void displayEmployeeDetails() const {
        cout << "Code: " << code << ", Name: " << ename << ", Designation: " << desg << endl;
    }
};

class Manager : public Employee {
private:
    int year_of_experience;
    double salary;

public:
    void acceptManagerDetails() {
        acceptEmployeeDetails();
        cout << "Enter Years of Experience: ";
        cin >> year_of_experience;
        cout << "Enter Salary: ";
        cin >> salary;
    }
    void displayManagerDetails() const {
        displayEmployeeDetails();
        cout << "Experience: " << year_of_experience << " years, Salary: " << salary << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of managers: ";
    cin >> n;
    
    vector<Manager> managers(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter details for Manager " << i + 1 << ":" << endl;
        managers[i].acceptManagerDetails();
    }
    
    cout << "\nManager Details:\n";
    for (const auto& mgr : managers) {
        mgr.displayManagerDetails();
    }
    
    return 0;
}