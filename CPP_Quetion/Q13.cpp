/*.Write a C++ program to create a class Mobile which contains data members as Mobile_Id, 
Mobile_Name, Mobile_Price. Create and Initialize all values of Mobile object by using 
parameterized constructor. Display the values of Mobile object.*/
#include <iostream>
#include <string>

class Mobile {
private:
    int Mobile_Id;
    std::string Mobile_Name;
    double Mobile_Price;

public:
    // Parameterized constructor
    Mobile(int id, const std::string& name, double price)
        : Mobile_Id(id), Mobile_Name(name), Mobile_Price(price) {}

    // Function to display mobile details
    void display() const {
        std::cout << "Mobile ID: " << Mobile_Id << "\n"
                  << "Mobile Name: " << Mobile_Name << "\n"
                  << "Mobile Price: $" << Mobile_Price << "\n";
    }
};

int main() {
    // Creating and initializing a Mobile object using the parameterized constructor
    Mobile myMobile(101, "SmartPhone X", 999.99);

    // Displaying the values of the Mobile object
    myMobile.display();

    return 0;
}
