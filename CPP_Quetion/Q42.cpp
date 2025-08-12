/* Create a class Fraction that contains two data members as numerator and denominator. 
Write a C++ program to overload following operators 
a. ++ Unary (pre and post both) 
b. << and >> Overload as friend functions*/

#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator, denominator;

public:
    // Constructor
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            cout << "Denominator cannot be zero. Setting to 1." << endl;
            denominator = 1;
        }
    }

    // Pre-increment operator
    Fraction& operator++() {
        numerator += denominator;
        return *this;
    }

    // Post-increment operator
    Fraction operator++(int) {
        Fraction temp = *this;
        numerator += denominator;
        return temp;
    }

    // Friend function for overloading >> operator (input)
    friend istream& operator>>(istream &input, Fraction &f) {
        cout << "Enter numerator: ";
        input >> f.numerator;
        cout << "Enter denominator: ";
        input >> f.denominator;
        if (f.denominator == 0) {
            cout << "Denominator cannot be zero. Setting to 1." << endl;
            f.denominator = 1;
        }
        return input;
    }

    // Friend function for overloading << operator (output)
    friend ostream& operator<<(ostream &output, const Fraction &f) {
        output << f.numerator << "/" << f.denominator;
        return output;
    }
};

int main() {
    Fraction f1, f2;
    cout << "Enter first fraction:" << endl;
    cin >> f1;
    
    cout << "Entered fraction: " << f1 << endl;
    
    cout << "Pre-increment: " << ++f1 << endl;
    cout << "Post-increment: " << f1++ << endl;
    cout << "After post-increment: " << f1 << endl;
    
    return 0;
}