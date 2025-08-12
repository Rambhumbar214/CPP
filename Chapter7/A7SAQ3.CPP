#include <iostream>
using namespace std;

// Base class 1: Employee
class Employee {
protected:
    string name;       // Employee name
    string designation; // Employee designation

public:
    // Constructor to initialize Employee details
    Employee(string n, string d) {
        name = n;
        designation = d;
    }

    // Method to display Employee details
    void displayEmployeeDetails() const {
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
    }
};

// Base class 2: Project
class Project {
protected:
    int pid;         // Project ID
    string title;    // Project title

public:
    // Constructor to initialize Project details
    Project(int p, string t) {
        pid = p;
        title = t;
    }

    // Method to display Project details
    void displayProjectDetails() const {
        cout << "Project ID: " << pid << endl;
        cout << "Project Title: " << title << endl;
    }
};

// Derived class: EmpProj (inherits from both Employee and Project)
class EmpProj : public Employee, public Project {
private:
    int duration;    // Project duration in months

public:
    // Constructor to initialize EmpProj details
    EmpProj(string n, string d, int p, string t, int dur)
        : Employee(n, d), Project(p, t) {
        duration = dur;
    }

    // Method to display EmpProj details
    void displayEmpProjDetails() const {
        displayEmployeeDetails(); // Display Employee details
        displayProjectDetails();  // Display Project details
        cout << "Duration: " << duration << " months" << endl;
    }

    // Get duration for sorting
    int getDuration() const {
        return duration;
    }
};

// Function to display the master table
void displayMasterTable(EmpProj empProjList[], int n) {
    cout << "----- Master Table -----\n";
    for (int i = 0; i < n; i++) {
        empProjList[i].displayEmpProjDetails();
        cout << "------------------------\n";
    }
}

// Function to display project details in ascending order of duration
void displayProjectsByDuration(EmpProj empProjList[], int n) {
    // Sorting by duration using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (empProjList[j].getDuration() > empProjList[j + 1].getDuration()) {
                // Swap the elements if they are in the wrong order
                EmpProj temp = empProjList[j];
                empProjList[j] = empProjList[j + 1];
                empProjList[j + 1] = temp;
            }
        }
    }

    cout << "----- Projects Sorted by Duration -----\n";
    for (int i = 0; i < n; i++) {
        empProjList[i].displayProjectDetails();
        cout << "Duration: " << empProjList[i].getDuration() << " months\n";
        cout << "------------------------\n";
    }
}

int main() {
    // Array to store employee-project details
    EmpProj empProjList[100];  // Maximum of 100 entries
    int n = 0;  // To track the number of records
    int choice;
    string name, designation, title;
    int pid, duration;

    while (true) {
        cout << "----- Menu -----\n";
        cout << "1. Add Employee and Project\n";
        cout << "2. Display Master Table\n";
        cout << "3. Display Projects Sorted by Duration\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character left by cin

        switch (choice) {
            case 1: {
                // Adding Employee and Project details
                cout << "Enter Employee Name: ";
                getline(cin, name);
                cout << "Enter Employee Designation: ";
                getline(cin, designation);
                cout << "Enter Project ID: ";
                cin >> pid;
                cin.ignore();
                cout << "Enter Project Title: ";
                getline(cin, title);
                cout << "Enter Project Duration (in months): ";
                cin >> duration;
                cin.ignore();

                // Create an EmpProj object and add it to the list
                EmpProj newEmpProj(name, designation, pid, title, duration);
                empProjList[n++] = newEmpProj; // Add to the array
                break;
            }
            case 2: {
                // Display the master table
                displayMasterTable(empProjList, n);
                break;
            }
            case 3: {
                // Display projects sorted by duration
                displayProjectsByDuration(empProjList, n);
                break;
            }
            case 4: {
                // Exit the program
                cout << "Exiting...\n";
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
