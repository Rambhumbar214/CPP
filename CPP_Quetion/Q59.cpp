/* Write a C++ program to create a class Department which contains data members as 
Dept_Id, Dept_Name, H.O.D., Number_Of_staff. Write necessary member functions to 
a. Accept details from user for ‘n’ departments and write it in a file “Dept.txt”. 
b. Display details of department from a file.*/


#include <iostream>
#include <fstream>
using namespace std;

class Department {
public:
    int Dept_Id;
    string Dept_Name;
    string HOD;
    int Number_Of_Staff;

    void acceptDetails() {
        cout << "Enter Department ID: ";
        cin >> Dept_Id;
        cin.ignore();
        cout << "Enter Department Name: ";
        getline(cin, Dept_Name);
        cout << "Enter H.O.D. Name: ";
        getline(cin, HOD);
        cout << "Enter Number of Staff: ";
        cin >> Number_Of_Staff;
    }

    void displayDetails() {
        cout << "Department ID: " << Dept_Id << endl;
        cout << "Department Name: " << Dept_Name << endl;
        cout << "H.O.D.: " << HOD << endl;
        cout << "Number of Staff: " << Number_Of_Staff << endl;
    }
};

void writeToFile(int n) {
    ofstream file("Dept.txt", ios::app);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    Department dept;
    for (int i = 0; i < n; i++) {
        dept.acceptDetails();
        file << dept.Dept_Id << "\n" << dept.Dept_Name << "\n" << dept.HOD << "\n" << dept.Number_Of_Staff << "\n";
    }
    file.close();
    cout << "Details saved to file successfully." << endl;
}

void readFromFile() {
    ifstream file("Dept.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    Department dept;
    while (file >> dept.Dept_Id) {
        file.ignore();
        getline(file, dept.Dept_Name);
        getline(file, dept.HOD);
        file >> dept.Number_Of_Staff;
        file.ignore();
        dept.displayDetails();
        cout << "------------------------" << endl;
    }
    file.close();
}

int main() {
    int choice, n;
    do {
        cout << "\n1. Add Department Details\n2. Display Department Details\n3. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter number of departments: ";
                cin >> n;
                writeToFile(n);
                break;
            case 2:
                readFromFile();
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 3);
    return 0;
}
