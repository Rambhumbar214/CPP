/*. Create a class String which contains a character pointer (Use new and delete operator). Write a 
C++ program to overload following operators: 
a. < To compare length of two strings 
b. == To check equality of two strings 
c. + To concatenate two strings */

#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;
    int length;

public:
    // Constructor
    String(const char* s = "") {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    // Copy Constructor
    String(const String& s) {
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Overload < operator to compare string lengths
    bool operator<(const String& s) const {
        return length < s.length;
    }

    // Overload == operator to check equality of strings
    bool operator==(const String& s) const {
        return strcmp(str, s.str) == 0;
    }

    // Overload + operator to concatenate strings
    String operator+(const String& s) const {
        char* temp = new char[length + s.length + 1];
        strcpy(temp, str);
        strcat(temp, s.str);
        String result(temp);
        delete[] temp;
        return result;
    }

    // Function to display string
    void display() const {
        cout << str << endl;
    }
};

int main() {
    String s1("Hello"), s2("World"), s3("Hello");
    
    cout << "String 1: ";
    s1.display();
    cout << "String 2: ";
    s2.display();

    // Comparing lengths
    if (s1 < s2)
        cout << "String 1 is shorter than String 2\n";
    else
        cout << "String 1 is not shorter than String 2\n";

    // Checking equality
    if (s1 == s3)
        cout << "String 1 and String 3 are equal\n";
    else
        cout << "String 1 and String 3 are not equal\n";

    // Concatenation
    String s4 = s1 + s2;
    cout << "Concatenated String: ";
    s4.display();

    return 0;
}