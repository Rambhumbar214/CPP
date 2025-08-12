/*Write a C++ program to read student information such as rollno, name and percentage of n 
students. Write the student information using file handling*/

#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float percentage;

    void accept() {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Percentage: ";
        cin >> percentage;
    }

    void display() {
        cout << "Roll No: " << rollNo << "\nName: " << name << "\nPercentage: " << percentage << "\n";
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    
    ofstream outFile("students.txt");
    if (!outFile) {
        cout << "Error opening file!";
        return 1;
    }
    
    Student students[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter details for student " << i + 1 << "\n";
        students[i].accept();
        outFile << students[i].rollNo << ", " << students[i].name << ", " << students[i].percentage << "\n";
    }
    outFile.close();
    
    cout << "\nStudent details written to file successfully!\n";
    
    return 0;
}