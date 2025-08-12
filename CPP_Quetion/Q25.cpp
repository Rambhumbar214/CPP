/*Write a C++ program to create a class Item with data members Item_code, Item_name, Item_Price. 
Write member functions to accept and display item information and also display number of objects 
created for a class. (Use Static data member and Static member function)*/

#include <iostream>
using namespace std;

class Item {
private:
    int Item_code;
    string Item_name;
    float Item_Price;
    static int count; // Static data member

public:
    // Constructor to initialize item details
    Item(int code, string name, float price) {
        Item_code = code;
        Item_name = name;
        Item_Price = price;
        count++; // Increment count for each object created
    }

    // Function to display item details
    void displayItem() const {
        cout << "Item Code: " << Item_code << "\n";
        cout << "Item Name: " << Item_name << "\n";
        cout << "Item Price: " << Item_Price << "\n";
    }

    // Static function to display total objects created
    static void displayCount() {
        cout << "Total Items Created: " << count << "\n";
    }
};

// Initialize static member
int Item::count = 0;

int main() {
    Item item1(101, "Laptop", 75000.50);
    Item item2(102, "Smartphone", 30000.75);
    Item item3(103, "Tablet", 20000.25);
    
    cout << "Item Details:\n";
    item1.displayItem();
    item2.displayItem();
    item3.displayItem();
    
    // Display total count of objects
    Item::displayCount();
    
    return 0;
}