/*Write a C++ program to overload function Volume and find Volume of Cube, Cylinder and 
Sphere.*/
#include <iostream>
#include <cmath> // For M_PI constant

// Function to calculate the volume of a cube
double Volume(double side) {
    return std::pow(side, 3);
}

// Function to calculate the volume of a cylinder
double Volume(double radius, double height) {
    return M_PI * std::pow(radius, 2) * height;
}

// Function to calculate the volume of a sphere
double Volume(double radius, bool isSphere) {
    return (4.0 / 3.0) * M_PI * std::pow(radius, 3);
}

int main() {
    double side, radius, height;

    // Calculate volume of a cube
    std::cout << "Enter the side length of the cube: ";
    std::cin >> side;
    std::cout << "Volume of the cube: " << Volume(side) << std::endl;

    // Calculate volume of a cylinder
    std::cout << "Enter the radius and height of the cylinder: ";
    std::cin >> radius >> height;
    std::cout << "Volume of the cylinder: " << Volume(radius, height) << std::endl;

    // Calculate volume of a sphere
    std::cout << "Enter the radius of the sphere: ";
    std::cin >> radius;
    std::cout << "Volume of the sphere: " << Volume(radius, true) << std::endl;

    return 0;
}
