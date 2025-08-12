#include <iostream.h>
#include<conio.h>

class Point {

    int x, y; 

public:
    
    Point() {
        x = 0;
        y = 0;
        cout << "Default Constructor: Point (" << x << ", " << y << ")" << endl;
    }

   
    Point(int x_val, int y_val) {
        x = x_val;
        y = y_val;
        cout << "Parameterized Constructor: Point (" << x << ", " << y << ")" << endl;
    }

    
    Point(const Point &p) {
        x = p.x;
        y = p.y;
        cout << "Copy Constructor: Point (" << x << ", " << y << ")" << endl;
    }

    
    void display() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
};

int main() {

    Point p1; // Point (0, 0)

  
    Point p2(5, 10); // Point (5, 10)

    
    Point p3 = p2; // Copy constructor: Copies p2 into p3

  
    cout << "\nDisplaying Points:" << endl;
    p1.display();  
    p2.display();  
    p3.display();  
    return 0;
}
