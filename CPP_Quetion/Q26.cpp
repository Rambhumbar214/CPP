/*. Create a Base class Train containing protected data members as Train_no, Train_Name. Derive a 
class Route(Route_id, Source, Destination) from Train class. Also derive a class Reservation 
(Number_of_Seats, Train_Class, Fare, Travel_Date) from Route. Write a C++ program 
to perform following necessary functions: 
a. Enter details of n reservations 
b. Display details of all reservations 
c. Display reservation details of a specified Train class*/

#include <iostream>
#include <vector>
using namespace std;

class Train {
protected:
    int Train_no;
    string Train_Name;

public:
    Train(int no, string name) : Train_no(no), Train_Name(name) {}
};

class Route : public Train {
protected:
    int Route_id;
    string Source, Destination;

public:
    Route(int no, string name, int rid, string src, string dest) : Train(no, name), Route_id(rid), Source(src), Destination(dest) {}
};

class Reservation : public Route {
private:
    int Number_of_Seats;
    string Train_Class;
    float Fare;
    string Travel_Date;

public:
    Reservation(int no, string name, int rid, string src, string dest, int seats, string tclass, float fare, string date)
        : Route(no, name, rid, src, dest), Number_of_Seats(seats), Train_Class(tclass), Fare(fare), Travel_Date(date) {}

    void displayReservation() const {
        cout << "Train No: " << Train_no << "\nTrain Name: " << Train_Name
             << "\nRoute ID: " << Route_id << "\nSource: " << Source << "\nDestination: " << Destination
             << "\nSeats: " << Number_of_Seats << "\nClass: " << Train_Class
             << "\nFare: " << Fare << "\nTravel Date: " << Travel_Date << "\n\n";
    }

    string getTrainClass() const {
        return Train_Class;
    }
};

int main() {
    vector<Reservation> reservations;
    int n;
    cout << "Enter number of reservations: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int no, rid, seats;
        string name, src, dest, tclass, date;
        float fare;

        cout << "Enter Train No, Train Name, Route ID, Source, Destination, Seats, Class, Fare, Travel Date: ";
        cin >> no >> name >> rid >> src >> dest >> seats >> tclass >> fare >> date;

        reservations.push_back(Reservation(no, name, rid, src, dest, seats, tclass, fare, date));
    }

    cout << "\nAll Reservations:\n";
    for (const auto &res : reservations) {
        res.displayReservation();
    }

    string searchClass;
    cout << "\nEnter Train Class to search: ";
    cin >> searchClass;

    cout << "\nReservations for class " << searchClass << ":\n";
    for (const auto &res : reservations) {
        if (res.getTrainClass() == searchClass) {
            res.displayReservation();
        }
    }

    return 0;
}