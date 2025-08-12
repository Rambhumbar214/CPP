#include <iostream>
using namespace std;

class Department {
private:
    int dept_id;
    char dept_name[50];
    int establishment_year;
    int no_of_faculty;
    int no_of_students;

public:
    // Constructor to initialize department details
    Department() {
        dept_id = 0;
        dept_name[0] = '\0';
        establishment_year = 0;
        no_of_faculty = 0;
        no_of_students = 0;
    }

    // Member function to accept department details
    void acceptDetails() {
        cout << "Enter Department ID: ";
        cin >> dept_id;
        cin.ignore();  // To clear the input buffer
        cout << "Enter Department Name: ";
        cin.getline(dept_name, 50);
        cout << "Enter Establishment Year: ";
        cin >> establishment_year;
        cout << "Enter Number of Faculty: ";
        cin >> no_of_faculty;
        cout << "Enter Number of Students: ";
        cin >> no_of_students;
    }

    // Member function to display department details
    void displayDetails() const {
        cout << "\nDepartment ID: " << dept_id << endl;
        cout << "Department Name: " << dept_name << endl;
        cout << "Establishment Year: " << establishment_year << endl;
        cout << "Number of Faculty: " << no_of_faculty << endl;
        cout << "Number of Students: " << no_of_students << endl;
    }

    // Function to get the department ID
    int getDeptID() const {
        return dept_id;
    }

    // Function to get the establishment year
    int getEstablishmentYear() const {
        return establishment_year;
    }

    // Function to display details of a specific department by department ID
    static void displayByDeptID(Department departments[], int n, int dept_id) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (departments[i].getDeptID() == dept_id) {
                departments[i].displayDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Department with ID " << dept_id << " not found." << endl;
        }
    }

    // Function to display details of departments based on establishment year
    static void displayByEstablishmentYear(Department departments[], int n, int year) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (departments[i].getEstablishmentYear() == year) {
                departments[i].displayDetails();
                found = true;
            }
        }
        if (!found) {
            cout << "No departments found for the year " << year << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of departments: ";
    cin >> n;

    Department departments[n];

    // Accept department details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Department " << (i + 1) << ":\n";
        departments[i].acceptDetails();
    }

    // Display department details by ID
    int dept_id;
    cout << "\nEnter Department ID to display details: ";
    cin >> dept_id;
    Department::displayByDeptID(departments, n, dept_id);

    // Display department details by establishment year
    int year;
    cout << "\nEnter establishment year to display departments: ";
    cin >> year;
    Department::displayByEstablishmentYear(departments, n, year);

    return 0;
}
