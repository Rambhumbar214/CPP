/*.Create a class String which contains a character pointer (Use new and delete operator) 
Write a C++ program to overload following operators 
a. ! To reverse the case of each alphabet from given string. 
b. [ ] To print a character present at specified index*/

#include <iostream>
#include <cstring> // For std::strlen and std::strcpy
#include <cctype>  // For std::islower and std::toupper

class String {
private:
    char* str; // Pointer to dynamically allocated character array
    std::size_t length; // Length of the string

public:
    // Default constructor
    String(const char* s = "") {
        length = std::strlen(s);
        str = new char[length + 1];
        std::strcpy(str, s);
    }

    // Copy constructor
    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Overload the '!' operator to reverse the case of each alphabet character
    void operator!() {
        for (std::size_t i = 0; i < length; ++i) {
            if (std::islower(str[i]))
                str[i] = std::toupper(str[i]);
            else if (std::isupper(str[i]))
                str[i] = std::tolower(str[i]);
        }
    }

    // Overload the '[]' operator to access character at specified index
    char& operator[](std::size_t index) {
        if (index >= length) {
            std::cerr << "Index out of bounds" << std::endl;
            // Returning the first character as a fallback; in real scenarios, consider throwing an exception
            return str[0];
        }
        return str[index];
    }

    // Function to print the string
    void print() const {
        std::cout << str << std::endl;
    }
};

int main() {
    String s("Hello, World!");

    std::cout << "Original string: ";
    s.print();

    // Reverse the case of each alphabet character
    !s;
    std::cout << "After reversing case: ";
    s.print();

    // Access and print character at index 7
    std::size_t index = 7;
    std::cout << "Character at index " << index << ": " << s[index] << std::endl;

    return 0;
}
