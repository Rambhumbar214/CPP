// We use only the basic header for input-output operations.
#include <iostream>

using namespace std;

// Base class: Flight
class Flight {
protected:
    char flightNo[10];  // Flight number
    char flightName[30]; // Flight name

public:
    // Constructor to initialize flight details
    Flight(const char* fNo, const char* fName) {
        strcpy(flightNo, fNo);
        strcpy(flightName, fName);
    }

    // Method to display flight details
    void displayFlightDetails() const {
        cout << "Flight No: " << flightNo << endl;
        cout << "Flight Name: " << flightName << endl;
    }
};

// Derived class: Route (from Flight)
class Route : public Flight {
protected:
    char source[30];
    char destination[30];

public:
    // Constructor to initialize route details
    Route(const char* fNo, const char* fName, const char* src, const char* dest)
        : Flight(fNo, fName) {
        strcpy(source, src);
        strcpy(destination, dest);
    }

    // Method to display route details
    void displayRouteDetails() const {
        displayFlightDetails();
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
    }
};

// Derived class: Reservation (from Route)
class Reservation : public Route {
protected:
    int numSeats;
    char fareClass[15];
    char travelDate[15];

public:
    // Constructor to initialize reservation details
    Reservation(const char* fNo, const char* fName, const char* src, const char* dest, 
                int seats, const char* fare, const char* date)
        : Route(fNo, fName, src, dest) {
        numSeats = seats;
        strcpy(fareClass, fare);
        strcpy(travelDate, date);
    }

    // Method to display reservation details
    void displayReservationDetails() const {
        displayRouteDetails();
        cout << "Number of Seats: " << numSeats << endl;
        cout << "Fare Class: " << fareClass << endl;
        cout << "Travel Date: " << travelDate << endl;
    }

    // Getter for fare class
    const char* getFareClass() const {
        return fareClass;
    }
};

// Function to display all reservation details
void displayAllReservations(Reservation reservations[], int n) {
    cout << "----- All Reservation Details -----\n";
    for (int i = 0; i < n; i++) {
        reservations[i].displayReservationDetails();
        cout << "-----------------------------------\n";
    }
}

// Function to display business class reservation details
void displayBusinessClassReservations(Reservation reservations[], int n) {
    cout << "----- Business Class Reservations -----\n";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(reservations[i].getFareClass(), "Business") == 0) {
            reservations[i].displayReservationDetails();
            cout << "-----------------------------------\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No Business Class Reservations found.\n";
    }
}

int main() {
    Reservation reservations[100];  // Array to store reservations
    int n;
    char flightNo[10], flightName[30], source[30], destination[30], fareClass[15], travelDate[15];
    int numSeats;

    // Input the number of reservations
    cout << "Enter number of reservations: ";
    cin >> n;
    cin.ignore();  // To ignore the newline character after the number input

    // Input reservation details
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Reservation " << i + 1 << ":\n";
        cout << "Flight No: ";
        cin.getline(flightNo, 10);
        cout << "Flight Name: ";
        cin.getline(flightName, 30);
        cout << "Source: ";
        cin.getline(source, 30);
        cout << "Destination: ";
        cin.getline(destination, 30);
        cout << "Number of Seats: ";
        cin >> numSeats;
        cin.ignore();  // To ignore the newline character after the number input
        cout << "Fare Class (Economy/Business): ";
        cin.getline(fareClass, 15);
        cout << "Travel Date (dd-mm-yyyy): ";
        cin.getline(travelDate, 15);

        // Create Reservation object and add it to the list
        Reservation newReservation(flightNo, flightName, source, destination, numSeats, fareClass, travelDate);
        reservations[i] = newReservation;
    }

    // Menu-driven program
    int choice;
    while (true) {
        cout << "\n----- Menu -----\n";
        cout << "1. Display all Reservations\n";
        cout << "2. Display Business Class Reservations\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character after the number input

        switch (choice) {
            case 1:
                displayAllReservations(reservations, n);
                break;
            case 2:
                displayBusinessClassReservations(reservations, n);
                break;
            case 3:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
