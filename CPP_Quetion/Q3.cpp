/* Write a C++ program to create a class Shape with functions to find area of the shape and display 
the name of the shape and other essential components of the class. Create derived classes circle, 
rectangle and trapezoid each having overridden function area and display. Write a suitable 
program to illustrate Virtual Function.*/

#include <iostream>
#include <cmath>

// Base class
class Shape {
public:
    // Virtual function to calculate area
    virtual double area() const = 0;

    // Virtual function to display the name of the shape
    virtual void display() const = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class for Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    // Override area function
    double area() const override {
        return M_PI * radius * radius;
    }

    // Override display function
    void display() const override {
        std::cout << "Shape: Circle" << std::endl;
        std::cout << "Radius: " << radius << std::endl;
        std::cout << "Area: " << area() << std::endl;
    }
};

// Derived class for Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Override area function
    double area() const override {
        return length * width;
    }

    // Override display function
    void display() const override {
        std::cout << "Shape: Rectangle" << std::endl;
        std::cout << "Length: " << length << std::endl;
        std::cout << "Width: " << width << std::endl;
        std::cout << "Area: " << area() << std::endl;
    }
};

// Derived class for Trapezoid
class Trapezoid : public Shape {
private:
    double base1;
    double base2;
    double height;
public:
    Trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {}

    // Override area function
    double area() const override {
        return 0.5 * (base1 + base2) * height;
    }

    // Override display function
    void display() const override {
        std::cout << "Shape: Trapezoid" << std::endl;
        std::cout << "Base1: " << base1 << std::endl;
        std::cout << "Base2: " << base2 << std::endl;
        std::cout << "Height: " << height << std::endl;
        std::cout << "Area: " << area() << std::endl;
    }
};

int main() {
    // Create objects of derived classes
    Shape* shapes[] = {
        new Circle(5.0),
        new Rectangle(4.0, 6.0),
        new Trapezoid(3.0, 4.0, 5.0)
    };

    // Display information about each shape
    for (Shape* shape : shapes) {
        shape->display();
        std::cout << std::endl;
    }

    // Clean up
    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
