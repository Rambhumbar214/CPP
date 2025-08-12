/* Write a C++ program to define a class Bus with the following specifications: Bus No, Bus 
Name, No of Seats, Starting point, Destination .Write a menu driven program by using 
appropriate manipulators to 
a. Accept details of n buses. 
b. Display all bus details. 
c. Display details of bus from specified starting point to destination*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Bus {
private:
    int busNo;
    string busName;
    int noOfSeats;
    string startPoint;
    string destination;

public:
    void acceptDetails() {
        cout << "Enter Bus Number: ";
        cin >> busNo;
        cout << "Enter Bus Name: ";
        cin.ignore();
        getline(cin, busName);
        cout << "Enter Number of Seats: ";
        cin >> noOfSeats;
        cout << "Enter Starting Point: ";
        cin.ignore();
        getline(cin, startPoint);
        cout << "Enter Destination: ";
        getline(cin, destination);
    }

    void displayDetails() const {
        cout << left << setw(10) << busNo << setw(20) << busName << setw(15) 
             << noOfSeats << setw(20) << startPoint << setw(20) << destination << endl;
    }

    bool matchesRoute(const string &start, const string &end) const {
        return (startPoint == start && destination == end);
    }
};

int main() {
    vector<Bus> buses;
    int choice, n;
    string start, end;
    
    do {
        cout << "\nBus Management System";
        cout << "\n1. Accept bus details";
        cout << "\n2. Display all bus details";
        cout << "\n3. Search bus by route";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number of buses: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    Bus bus;
                    cout << "\nEnter details for Bus " << i + 1 << ":" << endl;
                    bus.acceptDetails();
                    buses.push_back(bus);
                }
                break;
            case 2:
                cout << "\nBus Details:\n";
                cout << left << setw(10) << "Bus No" << setw(20) << "Bus Name" << setw(15) 
                     << "Seats" << setw(20) << "Starting Point" << setw(20) << "Destination" << endl;
                for (const auto &bus : buses) {
                    bus.displayDetails();
                }
                break;
            case 3:
                cout << "Enter Starting Point: ";
                cin.ignore();
                getline(cin, start);
                cout << "Enter Destination: ";
                getline(cin, end);
                cout << "\nBuses from " << start << " to " << end << ":\n";
                for (const auto &bus : buses) {
                    if (bus.matchesRoute(start, end)) {
                        bus.displayDetails();
                    }
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);
    
    return 0;
}