/*Write a C++ program to check minimum and maximum of two integer number (use inline 
function and conditional operator) */
#include <iostream>
using namespace std;

inline int getMax(int a, int b) {
    return (a > b) ? a : b;
}

inline int getMin(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int num1, num2;
    
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    cout << "Maximum: " << getMax(num1, num2) << endl;
    cout << "Minimum: " << getMin(num1, num2) << endl;
    
    return 0;
}
