#include <iostream>
#include <iomanip>  // For using manipulators like setw, setprecision
#include <cstring>
using namespace std;

class Employee {
private:
    int emp_no;                // Employee number
    char name[50];             // Employee name
    float basic;               // Basic salary
    float da;                  // Dearness Allowance
    float hra;                 // House Rent Allowance
    float allowances;          // Other allowances

public:
    // Constructor to initialize the employee details
    Employee() {
        emp_no = 0;
        basic = 0.0;
        da = 0.0;
        hra = 0.0;
        allowances = 0.0;
        name[0] = '\0';
    }

    // Function to accept employee details
    void acceptDetails() {
        cout << "Enter Employee Number: ";
        cin >> emp_no;
        cin.ignore();  // To clear the input buffer
        cout << "Enter Employee Name: ";
        cin.getline(name, 50);
        cout << "Enter Basic Salary: ";
        cin >> basic;
        cout << "Enter Dearness Allowance (DA): ";
        cin >> da;
        cout << "Enter House Rent Allowance (HRA): ";
        cin >> hra;
        cout << "Enter Other Allowances: ";
        cin >> allowances;
    }

    // Function to display employee details
    void displayDetails() const {
        cout << left << setw(15) << "Employee No" 
             << setw(20) << "Employee Name" 
             << setw(15) << "Basic Salary" 
             << setw(15) << "DA" 
             << setw(15) << "HRA" 
             << setw(15) << "Allowances" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << setw(15) << emp_no
             << setw(20) << name
             << setw(15) << basic
             << setw(15) << da
             << setw(15) << hra
             << setw(15) << allowances << endl;
    }

    // Function to generate a pay slip
    void generatePaySlip() const {
        float gross_salary = basic + da + hra + allowances;
        float tax = gross_salary * 0.10;  // Assuming 10% tax
        float net_salary = gross_salary - tax;

        cout << "\nPay Slip for Employee No: " << emp_no << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << left << setw(15) << "Employee Name" << setw(20) << name << endl;
        cout << setw(15) << "Basic Salary" << setw(20) << fixed << setprecision(2) << basic << endl;
        cout << setw(15) << "DA" << setw(20) << fixed << setprecision(2) << da << endl;
        cout << setw(15) << "HRA" << setw(20) << fixed << setprecision(2) << hra << endl;
        cout << setw(15) << "Allowances" << setw(20) << fixed << setprecision(2) << allowances << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << setw(15) << "Gross Salary" << setw(20) << fixed << setprecision(2) << gross_salary << endl;
        cout << setw(15) << "Tax (10%)" << setw(20) << fixed << setprecision(2) << tax << endl;
        cout << setw(15) << "Net Salary" << setw(20) << fixed << setprecision(2) << net_salary << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    // Array of Employee objects
    Employee employees[n];

    // Accept employee details
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for Employee " << (i + 1) << ":" << endl;
        employees[i].acceptDetails();
    }

    // Display employee details
    cout << "\nEmployee Details:" << endl;
    for (int i = 0; i < n; ++i) {
        employees[i].displayDetails();
    }

    // Generate pay slip for each employee
    for (int i = 0; i < n; ++i) {
        employees[i].generatePaySlip();
    }

    return 0;
}
