/*. Write a C++ program to create a text file which stores employee information as emp_id, 
emp_name, emp_sal). Write a menu driven program with the options 
a. Append 
b. Modify 
c. Display 
d. Exit*/


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Employee {
public:
    int emp_id;
    string emp_name;
    double emp_sal;

    void acceptEmployee() {
        cout << "Enter Employee ID: ";
        cin >> emp_id;
        cin.ignore();
        cout << "Enter Employee Name: ";
        getline(cin, emp_name);
        cout << "Enter Employee Salary: ";
        cin >> emp_sal;
    }

    void displayEmployee() {
        cout << "\nEmployee ID: " << emp_id
             << "\nEmployee Name: " << emp_name
             << "\nEmployee Salary: " << emp_sal << "\n";
    }
};

void appendEmployee() {
    ofstream file("employee.txt", ios::app);
    if (!file) {
        cout << "Error opening file!";
        return;
    }
    Employee e;
    e.acceptEmployee();
    file << e.emp_id << " " << e.emp_name << " " << e.emp_sal << "\n";
    file.close();
}

void displayEmployees() {
    ifstream file("employee.txt");
    if (!file) {
        cout << "Error opening file!";
        return;
    }
    Employee e;
    cout << "\nEmployee Records:\n";
    while (file >> e.emp_id) {
        file.ignore();
        getline(file, e.emp_name, ' ');
        file >> e.emp_sal;
        e.displayEmployee();
    }
    file.close();
}

void modifyEmployee() {
    ifstream file("employee.txt");
    if (!file) {
        cout << "Error opening file!";
        return;
    }
    vector<Employee> employees;
    Employee e;
    while (file >> e.emp_id) {
        file.ignore();
        getline(file, e.emp_name, ' ');
        file >> e.emp_sal;
        employees.push_back(e);
    }
    file.close();

    int search_id;
    cout << "Enter Employee ID to modify: ";
    cin >> search_id;
    bool found = false;
    for (auto &emp : employees) {
        if (emp.emp_id == search_id) {
            cout << "Enter new details:\n";
            emp.acceptEmployee();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee ID not found!\n";
        return;
    }

    ofstream outFile("employee.txt");
    for (const auto &emp : employees) {
        outFile << emp.emp_id << " " << emp.emp_name << " " << emp.emp_sal << "\n";
    }
    outFile.close();
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n1. Append Employee\n2. Modify Employee\n3. Display Employees\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                appendEmployee();
                break;
            case 2:
                modifyEmployee();
                break;
            case 3:
                displayEmployees();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
    return 0;
}
