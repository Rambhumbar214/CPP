#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:
    // Constructor to initialize complex numbers
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Function to display the complex number
    void display() const {
        cout << real;
        if (imag >= 0) cout << " + " << imag << "i" << endl;
        else cout << " - " << -imag << "i" << endl;
    }

    // Friend function to add two complex numbers
    friend Complex addComplex(const Complex& c1, const Complex& c2);
};

// Friend function definition
Complex addComplex(const Complex& c1, const Complex& c2) {
    // Adding real and imaginary parts separately
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    Complex c1(4.5, 3.2);  // First complex number
    Complex c2(1.5, 2.8);  // Second complex number

    cout << "First complex number: ";
    c1.display();
    cout << "Second complex number: ";
    c2.display();

    // Adding two complex numbers using the friend function
    Complex result = addComplex(c1, c2);

    cout << "Sum of complex numbers: ";
    result.display();

    return 0;
}
