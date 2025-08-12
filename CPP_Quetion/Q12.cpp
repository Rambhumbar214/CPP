/*.Create a base class Flight containing protected data members as Flight_no, Flight_Name. Derive 
a class Route(Source, Destination) from class Flight. Also derive a class Reservation (no_seats, 
class, fare, travel_date) from Route. Write a C++ program to perform the following necessary 
functions. 
a. Enter details of n reservations. 
b. Display reservation details of Business class.*/

#include <iostream>
#include <vector>
#include <string>

class Flight {
protected:
    int Flight_no;
    std::string Flight_Name;

public:
    Flight(int no, const std::string& name)
        : Flight_no(no), Flight_Name(name) {}

    virtual void display() const {
        std::cout << "Flight Number: " << Flight_no << "\n"
                  << "Flight Name: " << Flight_Name << "\n";
    }
};

class Route : public Flight {
protected:
    std::string Source;
    std::string Destination;

public:
    Route(int no, const std::string& name, const std::string& src, const std::string& dest)
        : Flight(no, name), Source(src), Destination(dest) {}

    void display() const override {
        Flight::display();
        std::cout << "Source: " << Source << "\n"
                  << "Destination: " << Destination << "\n";
    }
};

class Reservation : public Route {
private:
    int no_seats;
    std::string seat_class;
    float fare;
    std::string travel_date;

public:
    Reservation(int no, const std::string& name, const std::string& src, const std::string& dest,
                int seats, const std::string& cls, float fr, const std::string& date)
        : Route(no, name, src, dest), no_seats(seats), seat_class(cls), fare(fr), travel_date(date) {}

    const std::string& getSeatClass() const {
        return seat_class;
    }

    void display() const override {
        Route::display();
        std::cout << "Number of Seats: " << no_seats << "\n"
                  << "Class: " << seat_class << "\n"
                  << "Fare: " << fare << "\n"
                  << "Travel Date: " << travel_date << "\n";
    }
};

int main() {
    int n;
    std::cout << "Enter the number of reservations: ";
    std::cin >> n;
    std::cin.ignore(); // To consume the newline character after the integer input

    std::vector<Reservation> reservations;
    reservations.reserve(n);

    for (int i = 0; i < n; ++i) {
        int flight_no, no_seats;
        std::string flight_name, source, destination, seat_class, travel_date;
        float fare;

        std::cout << "\nEnter details for reservation " << i + 1 << ":\n";

        std::cout << "Flight Number: ";
        std::cin >> flight_no;
        std::cin.ignore();

        std::cout << "Flight Name: ";
        std::getline(std::cin, flight_name);

        std::cout << "Source: ";
        std::getline(std::cin, source);

        std::cout << "Destination: ";
        std::getline(std::cin, destination);

        std::cout << "Number of Seats: ";
        std::cin >> no_seats;
        std::cin.ignore();

        std::cout << "Class (Economy/Business): ";
        std::getline(std::cin, seat_class);

        std::cout << "Fare: ";
        std::cin >> fare;
        std::cin.ignore();

        std::cout << "Travel Date (YYYY-MM-DD): ";
        std::getline(std::cin, travel_date);

        reservations.emplace_back(flight_no, flight_name, source, destination,
                                  no_seats, seat_class, fare, travel_date);
    }

    std::cout << "\nBusiness Class Reservations:\n";
    for (const auto& res : reservations) {
        if (res.getSeatClass() == "Business") {
            res.display();
            std::cout << "--------------------------\n";
        }
    }

    return 0;
}
