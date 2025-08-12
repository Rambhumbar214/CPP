/*.Write a C++ program to subtract two integer numbers of two different classes using friend 
function.*/
#include <iostream>
using namespace std;

class ClassA;
class ClassB;

class ClassA {
private:
    int numA;
public:
    ClassA(int a) : numA(a) {}
    friend int subtract(const ClassA &a, const ClassB &b);
};

class ClassB {
private:
    int numB;
public:
    ClassB(int b) : numB(b) {}
    friend int subtract(const ClassA &a, const ClassB &b);
};

// Friend function to subtract numbers of two different classes
int subtract(const ClassA &a, const ClassB &b) {
    return a.numA - b.numB;
}

int main() {
    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    
    ClassA objA(a);
    ClassB objB(b);
    
    cout << "Subtraction result: " << subtract(objA, objB) << endl;
    return 0;
}
