/*Q2.Write a C++ program to create a class Person that contains data members as Person_Name, City, 
Mob_No. Write a C++ program to perform following functions: 
a. To accept and display Person information 
b. To search the Person details of a given mobile number 
c. To search the Person details of a given city. 
(Use Function Overloading)*/

#include <iostream>
#include <vector>
using namespace std;

class Person {
private:
    string Person_Name;
    string City;
    string Mob_No;

public:
    void acceptDetails() {
        cout << "Enter Name: ";
        cin >> Person_Name;
        cout << "Enter City: ";
        cin >> City;
        cout << "Enter Mobile Number: ";
        cin >> Mob_No;
    }

    void displayDetails() const {
        cout << "Name: " << Person_Name << ", City: " << City << ", Mobile No: " << Mob_No << endl;
    }

    bool searchByMobile(const string& mob) const {
        return Mob_No == mob;
    }

    bool searchByCity(const string& city) const {
        return City == city;
    }
};

void searchPerson(const vector<Person>& persons, const string& key, bool byMobile) {
    bool found = false;
    for (const auto& person : persons) {
        if ((byMobile && person.searchByMobile(key)) || (!byMobile && person.searchByCity(key))) {
            person.displayDetails();
            found = true;
        }
    }
    if (!found) {
        cout << "No records found." << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of persons: ";
    cin >> n;

    vector<Person> persons(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter details for person " << i + 1 << ":" << endl;
        persons[i].acceptDetails();
    }

    int choice;
    do {
        cout << "\nMenu:\n1. Display All Persons\n2. Search by Mobile Number\n3. Search by City\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (const auto& person : persons) {
                person.displayDetails();
            }
        } else if (choice == 2) {
            string mobile;
            cout << "Enter Mobile Number: ";
            cin >> mobile;
            searchPerson(persons, mobile, true);
        } else if (choice == 3) {
            string city;
            cout << "Enter City: ";
            cin >> city;
            searchPerson(persons, city, false);
        }
    } while (choice != 4);
    
    return 0;
}