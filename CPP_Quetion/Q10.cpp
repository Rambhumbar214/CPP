/*Write a C++ program to print area of circle, square and rectangle using inline function. */
#include <iostream>
#define PI 3.1416

// Inline function to calculate the area of a circle
inline double areaCircle(double radius) {
    return PI * radius * radius;
}

// Inline function to calculate the area of a square
inline double areaSquare(double side) {
    return side * side;
}

// Inline function to calculate the area of a rectangle
inline double areaRectangle(double length, double breadth) {
    return length * breadth;
}

int main() {
    double radius, side, length, breadth;

    // Input and calculate area of the circle
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;
    std::cout << "Area of the circle: " << areaCircle(radius) << std::endl;

    // Input and calculate area of the square
    std::cout << "Enter the side length of the square: ";
    std::cin >> side;
    std::cout << "Area of the square: " << areaSquare(side) << std::endl;

    // Input and calculate area of the rectangle
    std::cout << "Enter the length and breadth of the rectangle: ";
    std::cin >> length >> breadth;
    std::cout << "Area of the rectangle: " << areaRectangle(length, breadth) << std::endl;

    return 0;
}
