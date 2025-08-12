/*.Write a C++ program to read two float numbers. Perform arithmetic binary operations +,-,*,/ on 
these numbers using inline function. Display the resultant value.*/
#include <iostream>
using namespace std;

class Arithmetic {
public:
    inline float add(float a, float b) { return a + b; }
    inline float subtract(float a, float b) { return a - b; }
    inline float multiply(float a, float b) { return a * b; }
    inline float divide(float a, float b) { return (b != 0) ? a / b : 0; }
};

int main() {
    float num1, num2;
    cout << "Enter two float numbers: ";
    cin >> num1 >> num2;

    Arithmetic calc;
    
    cout << "Addition: " << calc.add(num1, num2) << endl;
    cout << "Subtraction: " << calc.subtract(num1, num2) << endl;
    cout << "Multiplication: " << calc.multiply(num1, num2) << endl;
    if (num2 != 0) {
        cout << "Division: " << calc.divide(num1, num2) << endl;
    } else {
        cout << "Division by zero is not allowed." << endl;
    }
    
    return 0;
}
