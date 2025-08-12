/*2.Write a C++ program to design a class complex to represent complex number. The complex class 
uses an external function (as a friend function) to add two complex number. The function should 
return an object of type complex representing the sum of two complex Numbers.*/

#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Friend function to add two Complex numbers
    friend Complex add(const Complex& c1, const Complex& c2);

    // Function to display the complex number
    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

// Definition of the friend function
Complex add(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    Complex num1(3.5, 2.5);
    Complex num2(1.5, 4.5);

    Complex sum = add(num1, num2);

    std::cout << "First complex number: ";
    num1.display();

    std::cout << "Second complex number: ";
    num2.display();

    std::cout << "Sum of the complex numbers: ";
    sum.display();

    return 0;
}
