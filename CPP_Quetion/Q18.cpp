/*. Design two base classes Employee (Name, Designation) and Project (Project_Id, title). Derive 
a class Emp_Proj(Duration) from Employee and Project. Write a menu driven program to 
a. Build a master table. Display a master table 
b. Display Project details in the ascending order of duration. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Employee {
protected:
    string Name;
    string Designation;

public:
    Employee(string name, string designation) : Name(name), Designation(designation) {}
    void displayEmployee() const {
        cout << "Name: " << Name << ", Designation: " << Designation;
    }
};

class Project {
protected:
    int Project_Id;
    string Title;

public:
    Project(int id, string title) : Project_Id(id), Title(title) {}
    void displayProject() const {
        cout << ", Project ID: " << Project_Id << ", Title: " << Title;
    }
};

class Emp_Proj : public Employee, public Project {
private:
    int Duration;

public:
    Emp_Proj(string name, string designation, int id, string title, int duration)
        : Employee(name, designation), Project(id, title), Duration(duration) {}
    
    void display() const {
        displayEmployee();
        displayProject();
        cout << ", Duration: " << Duration << " days" << endl;
    }
    int getDuration() const { return Duration; }
};

void displayMasterTable(const vector<Emp_Proj>& records) {
    cout << "\nMaster Table:\n";
    for (const auto& record : records) {
        record.display();
    }
}

void displaySortedByDuration(vector<Emp_Proj>& records) {
    sort(records.begin(), records.end(), [](const Emp_Proj& a, const Emp_Proj& b) {
        return a.getDuration() < b.getDuration();
    });
    cout << "\nProjects Sorted by Duration:\n";
    for (const auto& record : records) {
        record.display();
    }
}

int main() {
    vector<Emp_Proj> records;
    int choice;
    do {
        cout << "\nMenu:\n1. Add Employee-Project Record\n2. Display Master Table\n3. Display Projects by Duration\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, designation, title;
            int id, duration;
            cout << "Enter Name, Designation, Project ID, Title, Duration: ";
            cin >> name >> designation >> id >> title >> duration;
            records.emplace_back(name, designation, id, title, duration);
        } else if (choice == 2) {
            displayMasterTable(records);
        } else if (choice == 3) {
            displaySortedByDuration(records);
        }
    } while (choice != 4);

    return 0;
}
