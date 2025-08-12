#include <iostream>
using namespace std;

// Base class: Car
class Car {
protected:
    string brand;
    string model;
    int year;

public:
    // Constructor to initialize Car details
    Car(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }

    // Method to display car details
    void displayCarDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }

    // Method to simulate driving the car
    void drive() {
        cout << "Driving the car..." << endl;
    }
};

// Derived class: Maruti (extends Car)
class Maruti : public Car {
protected:
    string fuelType;

public:
    // Constructor to initialize Maruti details
    Maruti(string b, string m, int y, string fuel) : Car(b, m, y) {
        fuelType = fuel;
    }

    // Method to display Maruti specific details
    void displayMarutiDetails() {
        displayCarDetails();  // Call the method from Car class
        cout << "Fuel Type: " << fuelType << endl;
    }

    // Method specific to Maruti class (e.g., start engine)
    void startEngine() {
        cout << "Maruti engine started..." << endl;
    }
};

// Derived class: Maruti800 (extends Maruti)
class Maruti800 : public Maruti {
private:
    int mileage;

public:
    // Constructor to initialize Maruti800 details
    Maruti800(string b, string m, int y, string fuel, int mile) : Maruti(b, m, y, fuel) {
        mileage = mile;
    }

    // Method to display Maruti800 specific details
    void displayMaruti800Details() {
        displayMarutiDetails();  // Call the method from Maruti class
        cout << "Mileage: " << mileage << " km/l" << endl;
    }

    // Method specific to Maruti800 class (e.g., specific feature)
    void compactDesign() {
        cout << "Maruti 800 is known for its compact design!" << endl;
    }

    // Overriding a method from Maruti and Car
    void drive() {
        cout << "Driving the Maruti 800..." << endl;
    }
};

int main() {
    // Creating an object of Maruti800 class
    Maruti800 myCar("Maruti", "800", 2005, "Petrol", 18);

    // Displaying the details and using methods from Car, Maruti, and Maruti800
    cout << "Car Details:\n";
    myCar.displayMaruti800Details();  // Displays details of Car, Maruti, and Maruti800

    cout << "\nFeatures and Actions:\n";
    myCar.startEngine();      // Method from Maruti class
    myCar.compactDesign();    // Method from Maruti800 class
    myCar.drive();            // Overridden method in Maruti800 class

    return 0;
}
