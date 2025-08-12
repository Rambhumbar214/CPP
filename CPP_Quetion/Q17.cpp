/*Q1.Write a C++ program to implement a class printdata to overload print function as follows: 
void print(int) - outputs value followed by the value of the integer. 
Eg. print(10) outputs - value 10 
void print(char *) – outputs value followed by the string in double quotes. 
Eg. print(“hi”) outputs value “hi”*/

#include <iostream>

class printdata {
public:
    // Function to print integer values
    void print(int value) const {
        std::cout << "value " << value << std::endl;
    }

    // Function to print string values
    void print(const char* str) const {
        std::cout << "value \"" << str << "\"" << std::endl;
    }
};

int main() {
    printdata pd;

    // Testing the print function with an integer
    pd.print(10); // Outputs: value 10

    // Testing the print function with a string
    pd.print("hi"); // Outputs: value "hi"

    return 0;
}
