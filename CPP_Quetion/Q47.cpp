/* Create two base classes Learn_Info(Roll_No, Stud_Name, Class, Percentage) and 
Earn_Info(No_of_hours_worked, Charges_per_hour). Derive a class Earn_Learn_info from 
above two classes. Write necessary member functions to accept and display Student 
information. Calculate total money earned by the student. (Use constructor in derived class)*/

#include <iostream>
using namespace std;

class Learn_Info {
protected:
    int Roll_No;
    string Stud_Name;
    string Class;
    float Percentage;
public:
    void acceptLearnInfo() {
        cout << "Enter Roll No: ";
        cin >> Roll_No;
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, Stud_Name);
        cout << "Enter Class: ";
        cin >> Class;
        cout << "Enter Percentage: ";
        cin >> Percentage;
    }
    void displayLearnInfo() const {
        cout << "Roll No: " << Roll_No << "\nStudent Name: " << Stud_Name
             << "\nClass: " << Class << "\nPercentage: " << Percentage << "%\n";
    }
};

class Earn_Info {
protected:
    int No_of_hours_worked;
    float Charges_per_hour;
public:
    void acceptEarnInfo() {
        cout << "Enter number of hours worked: ";
        cin >> No_of_hours_worked;
        cout << "Enter charges per hour: ";
        cin >> Charges_per_hour;
    }
    void displayEarnInfo() const {
        cout << "Hours Worked: " << No_of_hours_worked << "\nCharges per Hour: " << Charges_per_hour << "\n";
    }
    float calculateEarnings() const {
        return No_of_hours_worked * Charges_per_hour;
    }
};

class Earn_Learn_info : public Learn_Info, public Earn_Info {
public:
    Earn_Learn_info() {}
    void acceptInfo() {
        acceptLearnInfo();
        acceptEarnInfo();
    }
    void displayInfo() const {
        displayLearnInfo();
        displayEarnInfo();
        cout << "Total Money Earned: " << calculateEarnings() << "\n";
    }
};

int main() {
    Earn_Learn_info student;
    student.acceptInfo();
    cout << "\nStudent Information:\n";
    student.displayInfo();
    return 0;
}