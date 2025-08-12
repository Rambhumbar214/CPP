/*Write the definition for a class Cylinder that contains data members radius and height. The class 
has the following member functions: 
a. void setradius(float) to set the radius of data member. 
b. void setheight(float) to set the height of data member. 
c. float volume( ) to calculate and return the volume of the cylinder. 
Write a C++ program to create cylinder object and display its volume.*/

#include <iostream>


class Cylinder {
private:
    float radius;
    float height;

public:
    // Member function to set the radius
    void setradius(float r) {
        radius = r;
    }

    // Member function to set the height
    void setheight(float h) {
        height = h;
    }

    // Member function to calculate and return the volume
    float volume() {
        return 3.14 * radius * radius * height;
    }
};

int main() {
    Cylinder cyl;
    float r, h;

    // Prompt user to enter radius and height
    std::cout << "Enter the radius of the cylinder: ";
    std::cin >> r;
    std::cout << "Enter the height of the cylinder: ";
    std::cin >> h;

    // Set the radius and height of the cylinder
    cyl.setradius(r);
    cyl.setheight(h);

    // Display the volume of the cylinder
    std::cout << "The volume of the cylinder is: " << cyl.volume() << std::endl;

    return 0;
}
