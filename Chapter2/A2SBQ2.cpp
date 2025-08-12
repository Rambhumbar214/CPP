#include <iostream>
#include <iomanip>  // For using manipulators like setw and setfill
#include <cstring>
using namespace std;

class Bus {
private:
    int bus_no;              // Bus number
    char bus_name[50];       // Bus name
    int no_of_seats;         // Number of seats
    char starting_point[50]; // Starting point
    char destination[50];    // Destination

public:
    // Constructor to initialize the bus details
    Bus() {
        bus_no = 0;
        no_of_seats = 0;
        bus_name[0] = '\0';
        starting_point[0] = '\0';
        destination[0] = '\0';
    }

    // Function to accept bus details
    void acceptDetails() {
        cout << "Enter Bus No: ";
        cin >> bus_no;
        cin.ignore();  // To clear input buffer before getting string input
        cout << "Enter Bus Name: ";
        cin.getline(bus_name, 50);
        cout << "Enter Number of Seats: ";
        cin >> no_of_seats;
        cin.ignore();  // To clear input buffer before getting string input
        cout << "Enter Starting Point: ";
        cin.getline(starting_point, 50);
        cout << "Enter Destination: ";
        cin.getline(destination, 50);
    }

    // Function to display bus details
    void displayDetails() const {
        cout << left << setw(10) << bus_no
             << setw(20) << bus_name
             << setw(15) << no_of_seats
             << setw(20) << starting_point
             << setw(20) << destination << endl;
    }

    // Function to get the bus number
    int getBusNo() const {
        return bus_no;
    }

    // Function to get the starting point
    const char* getStartingPoint() const {
        return starting_point;
    }

    // Function to get the destination
    const char* getDestination() const {
        return destination;
    }

    // Static function to display buses based on starting and destination points
    static void displayByStartEnd(Bus buses[], int n, const char* start, const char* end) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (strcmp(buses[i].getStartingPoint(), start) == 0 && strcmp(buses[i].getDestination(), end) == 0) {
                buses[i].displayDetails();
                found = true;
            }
        }
        if (!found) {
            cout << "No buses found from " << start << " to " << end << ".\n";
        }
    }
};

int main() {
    int n, choice;
    char start[50], end[50];
    
    cout << "Enter the number of buses: ";
    cin >> n;

    // Create an array of Bus objects
    Bus buses[n];

    do {
        cout << "\nMenu:\n";
        cout << "1. Accept details of " << n << " buses\n";
        cout << "2. Display all bus details\n";
        cout << "3. Display buses from specified starting point to destination\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Accept bus details for all buses
            for (int i = 0; i < n; ++i) {
                cout << "\nEnter details for Bus " << (i + 1) << ":\n";
                buses[i].acceptDetails();
            }
            break;

        case 2:
            // Display details of all buses
            cout << "\nBus No" << setw(20) << "Bus Name" << setw(15) << "Seats" 
                 << setw(20) << "Starting Point" << setw(20) << "Destination" << endl;
            cout << "---------------------------------------------------------------\n";
            for (int i = 0; i < n; ++i) {
                buses[i].displayDetails();
            }
            break;

        case 3:
            // Display buses based on user input for starting point and destination
            cin.ignore();  // Clear input buffer before taking string input
            cout << "\nEnter the starting point: ";
            cin.getline(start, 50);
            cout << "Enter the destination: ";
            cin.getline(end, 50);
            cout << "\nBuses from " << start << " to " << end << ":\n";
            cout << "\nBus No" << setw(20) << "Bus Name" << setw(15) << "Seats" 
                 << setw(20) << "Starting Point" << setw(20) << "Destination" << endl;
            cout << "---------------------------------------------------------------\n";
            Bus::displayByStartEnd(buses, n, start, end);
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
