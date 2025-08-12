/* Create a class Fraction containing data members as Numerator and Denominator. 
Write a program to overload operators ++ , -- and * to increment, decrement a Fraction and 
multiply two Fraction respectively. (Use constructor to initialize values of an object) */

#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator, denominator;

public:
    // Constructor to initialize fraction
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            cout << "Denominator cannot be zero. Setting to 1." << endl;
            denominator = 1;
        }
    }

    // Overloading ++ (prefix)
    Fraction& operator++() {
        numerator += denominator;
        return *this;
    }

    // Overloading -- (prefix)
    Fraction& operator--() {
        numerator -= denominator;
        return *this;
    }

    // Overloading * for multiplication
    Fraction operator*(const Fraction &f) const {
        return Fraction(numerator * f.numerator, denominator * f.denominator);
    }

    // Display function
    void display() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f1(3, 4), f2(2, 5);
    
    cout << "Fraction 1: ";
    f1.display();
    cout << "Fraction 2: ";
    f2.display();
    
    ++f1;
    cout << "After incrementing Fraction 1: ";
    f1.display();
    
    --f2;
    cout << "After decrementing Fraction 2: ";
    f2.display();
    
    Fraction f3 = f1 * f2;
    cout << "Multiplication Result: ";
    f3.display();
    
    return 0;
}

