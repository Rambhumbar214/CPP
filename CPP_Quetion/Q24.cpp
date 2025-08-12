/*.Write a C++ program to create a class Date which contains three data members as dd,mm,yyyy. 
Create and initialize the object by using parameterized constructor and display date in dd-month- 
yyyy format. (Input: 19-12-2014 Output: 19-Dec-2014) Perform validation for month. */

#include <iostream>
using namespace std;

class Date {
private:
    int dd, mm, yyyy;
    string monthNames[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

public:
    // Parameterized constructor with validation
    Date(int d, int m, int y) {
        if (m < 1 || m > 12) {
            cout << "Invalid month! Setting to January.\n";
            mm = 1;
        } else {
            mm = m;
        }
        dd = d;
        yyyy = y;
    }

    // Function to display date in dd-MMM-yyyy format
    void displayDate() const {
        cout << dd << "-" << monthNames[mm - 1] << "-" << yyyy << endl;
    }
};

int main() {
    int day, month, year;
    cout << "Enter date (dd mm yyyy): ";
    cin >> day >> month >> year;
    
    Date date(day, month, year);
    cout << "Formatted Date: ";
    date.displayDate();
    
    return 0;
}
