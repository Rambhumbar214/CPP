/*1.Write a C++ program to accept length and width of a rectangle. Calculate and display perimeter 
as well as area of a rectangle by using inline function.*/

#include <iostream>
using namespace std;

class Rectangle {
private:
    float length, width;

public:
    void acceptDimensions() {
        cout << "Enter length and width of the rectangle: ";
        cin >> length >> width;
    }
    
    inline float calculatePerimeter() {
        return 2 * (length + width);
    }
    
    inline float calculateArea() {
        return length * width;
    }
    
    void displayResults() {
        cout << "Perimeter of rectangle: " << calculatePerimeter() << endl;
        cout << "Area of rectangle: " << calculateArea() << endl;
    }
};

int main() {
    Rectangle rect;
    rect.acceptDimensions();
    rect.displayResults();
    return 0;
}
