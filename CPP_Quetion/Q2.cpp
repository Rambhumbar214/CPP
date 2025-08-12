/*Write a C++ program to create a class Array that contains one float array as member. Overload 
the Unary ++ and -- operators to increase or decrease the value of each element of an array. Use 
friend function for operator function. */

#include <iostream>
#include <vector>

class Array {
private:
    std::vector<float> elements;

public:
    // Constructor to initialize the array with given size and default value
    Array(size_t size, float value = 0.0f) : elements(size, value) {}

    // Function to set the value at a specific index
    void setValue(size_t index, float value) {
        if (index < elements.size()) {
            elements[index] = value;
        } else {
            std::cerr << "Index out of bounds." << std::endl;
        }
    }

    // Function to display the array elements
    void display() const {
        for (float elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    // Friend function to overload the prefix increment operator
    friend Array& operator++(Array& arr) {
        for (float& elem : arr.elements) {
            ++elem;
        }
        return arr;
    }

    // Friend function to overload the prefix decrement operator
    friend Array& operator--(Array& arr) {
        for (float& elem : arr.elements) {
            --elem;
        }
        return arr;
    }

    // Friend function to overload the postfix increment operator
    friend Array operator++(Array& arr, int) {
        Array temp = arr;
        ++arr; // Reuse the prefix increment
        return temp;
    }

    // Friend function to overload the postfix decrement operator
    friend Array operator--(Array& arr, int) {
        Array temp = arr;
        --arr; // Reuse the prefix decrement
        return temp;
    }
};

int main() {
    Array arr(5, 1.0f); // Create an Array of size 5, initialized with 1.0
    std::cout << "Original array: ";
    arr.display();

    ++arr; // Prefix increment
    std::cout << "After prefix increment: ";
    arr.display();

    arr++; // Postfix increment
    std::cout << "After postfix increment: ";
    arr.display();

    --arr; // Prefix decrement
    std::cout << "After prefix decrement: ";
    arr.display();

    arr--; // Postfix decrement
    std::cout << "After postfix decrement: ";
    arr.display();

    return 0;
}
