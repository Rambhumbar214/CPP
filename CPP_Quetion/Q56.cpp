/*. Design a two base classes Employee (Name, Designation) and Project(Project_Id, title). 
Derive a class Emp_Proj(Duration) from Employee and Project. Write a menu driven 
program to 
a. Build a master table. 
b. Display a master table 
c. Display Project details in the ascending order of duration.*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Employee {
public:
    string Name, Designation;
    void acceptEmployee() {
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, Name);
        cout << "Enter Designation: ";
        getline(cin, Designation);
    }
};

class Project {
public:
    int Project_Id;
    string Title;
    void acceptProject() {
        cout << "Enter Project ID: ";
        cin >> Project_Id;
        cin.ignore();
        cout << "Enter Project Title: ";
        getline(cin, Title);
    }
};

class Emp_Proj : public Employee, public Project {
public:
    int Duration;
    void acceptEmpProj() {
        acceptEmployee();
        acceptProject();
        cout << "Enter Project Duration (in months): ";
        cin >> Duration;
    }
    void displayEmpProj() {
        cout << "\nEmployee Name: " << Name
             << "\nDesignation: " << Designation
             << "\nProject ID: " << Project_Id
             << "\nProject Title: " << Title
             << "\nDuration: " << Duration << " months\n";
    }
};

bool compareDuration(Emp_Proj a, Emp_Proj b) {
    return a.Duration < b.Duration;
}

int main() {
    vector<Emp_Proj> empProjList;
    int choice, n;
    
    do {
        cout << "\nMenu:\n1. Build Master Table\n2. Display Master Table\n3. Display Projects by Duration\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of employees: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "\nEnter details for Employee " << i + 1 << ":";
                    Emp_Proj e;
                    e.acceptEmpProj();
                    empProjList.push_back(e);
                }
                break;
            
            case 2:
                cout << "\nMaster Table:\n";
                for (auto &e : empProjList) {
                    e.displayEmpProj();
                }
                break;
            
            case 3:
                sort(empProjList.begin(), empProjList.end(), compareDuration);
                cout << "\nProjects sorted by Duration:\n";
                for (auto &e : empProjList) {
                    e.displayEmpProj();
                }
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
