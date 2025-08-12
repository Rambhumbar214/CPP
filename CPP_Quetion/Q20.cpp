/*Create a class College containing data members as College_Id, College_Name, 
Establishment_year, University_Name. Write a C++ program with following functions 
a. Accept n College details 
b. Display College details of specified University 
c. Display College details according to Establishment year (Use Array of Objects and 
Function Overloading). */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class College {
private:
    int College_Id;
    string College_Name;
    int Establishment_Year;
    string University_Name;

public:
    // Function to accept college details
    void acceptDetails() {
        cout << "Enter College ID: ";
        cin >> College_Id;
        cin.ignore();
        cout << "Enter College Name: ";
        getline(cin, College_Name);
        cout << "Enter Establishment Year: ";
        cin >> Establishment_Year;
        cin.ignore();
        cout << "Enter University Name: ";
        getline(cin, University_Name);
    }

    // Function to display college details
    void displayDetails() const {
        cout << "College ID: " << College_Id << "\n"
             << "College Name: " << College_Name << "\n"
             << "Establishment Year: " << Establishment_Year << "\n"
             << "University Name: " << University_Name << "\n"
             << "-----------------------------" << endl;
    }

    // Function to get University Name
    string getUniversityName() const {
        return University_Name;
    }

    // Function to get Establishment Year
    int getEstablishmentYear() const {
        return Establishment_Year;
    }
};

// Function to display colleges of a specific university
void displayByUniversity(const vector<College>& colleges, const string& university) {
    cout << "\nColleges under University: " << university << "\n";
    for (const auto& college : colleges) {
        if (college.getUniversityName() == university) {
            college.displayDetails();
        }
    }
}

// Function to display colleges sorted by establishment year
void displayByEstablishmentYear(vector<College> colleges) {
    sort(colleges.begin(), colleges.end(), [](const College& a, const College& b) {
        return a.getEstablishmentYear() < b.getEstablishmentYear();
    });

    cout << "\nColleges sorted by Establishment Year:\n";
    for (const auto& college : colleges) {
        college.displayDetails();
    }
}

int main() {
    int n;
    cout << "Enter number of colleges: ";
    cin >> n;
    cin.ignore();

    vector<College> colleges(n);
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for College " << i + 1 << ":\n";
        colleges[i].acceptDetails();
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display College details of a specific University\n";
        cout << "2. Display College details sorted by Establishment Year\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string university;
                cout << "Enter University Name: ";
                getline(cin, university);
                displayByUniversity(colleges, university);
                break;
            }
            case 2:
                displayByEstablishmentYear(colleges);
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}