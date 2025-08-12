/*Write a C++ program to create two classes Rectangle1 and Rectangle2. Compare area of both the 
rectangles using friend function. */

#include <iostream>

// Forward declaration of classes
class Rectangle1;
class Rectangle2;

// Friend function declaration
void compareAreas(const Rectangle1& rect1, const Rectangle2& rect2);

class Rectangle1 {
private:
    double length;
    double width;

public:
    // Constructor to initialize dimensions
    Rectangle1(double l, double w) : length(l), width(w) {}

    // Friend function declaration
    friend void compareAreas(const Rectangle1& rect1, const Rectangle2& rect2);
};

class Rectangle2 {
private:
    double length;
    double width;

public:
    // Constructor to initialize dimensions
    Rectangle2(double l, double w) : length(l), width(w) {}

    // Friend function declaration
    friend void compareAreas(const Rectangle1& rect1, const Rectangle2& rect2);
};

// Friend function definition
void compareAreas(const Rectangle1& rect1, const Rectangle2& rect2) {
    double area1 = rect1.length * rect1.width;
    double area2 = rect2.length * rect2.width;

    std::cout << "Area of Rectangle1: " << area1 << std::endl;
    std::cout << "Area of Rectangle2: " << area2 << std::endl;

    if (area1 > area2) {
        std::cout << "Rectangle1 has a larger area." << std::endl;
    } else if (area1 < area2) {
        std::cout << "Rectangle2 has a larger area." << std::endl;
    } else {
        std::cout << "Both rectangles have the same area." << std::endl;
    }
}

int main() {
    // Create instances of Rectangle1 and Rectangle2
    Rectangle1 rect1(5.0, 3.0);
    Rectangle2 rect2(4.0, 4.0);

    // Compare their areas
    compareAreas(rect1, rect2);

    return 0;
}
