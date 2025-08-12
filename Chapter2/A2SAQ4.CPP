#include <iostream.h>
#include <string.h>


class StringOperations {
private:
    string value;
public:

    StringOperations(string val = "") : value(val) {}

    // a. Find the length of the string
    int length() {
        return value.length();
    }

    // b. Concatenate two strings
    string concatenate(const string& other) {
        return value + other;
    }

    // c. Reverse the string
    string reverse() {
        string rev = value;
        int n = rev.length();
        for (int i = 0; i < n / 2; i++) {
            swap(rev[i], rev[n - i - 1]);
        }
        return rev;
    }

    // d. Compare two strings
    string compare(const string& other) {
        if (value == other) {
            return "Strings are equal";
        } else if (value > other) {
            return "First string is greater";
        } else {
            return "Second string is greater";
        }
    }

    // Set the value of the string (if needed)
    void setValue(const string& val) {
        value = val;
    }

    // Get the value of the string
    string getValue() const {
        return value;
    }
};

int main() {
    StringOperations str1("Hello");
    StringOperations str2("World");

    // Find the length of the string
    cout << "Length of str1: " << str1.length() << endl;

    // Concatenate two strings
    cout << "Concatenated string: " << str1.concatenate(str2.getValue()) << endl;

    // Reverse the string
    cout << "Reversed str1: " << str1.reverse() << endl;

    // Compare two strings
    cout << "Comparison result: " << str1.compare(str2.getValue()) << endl;

    return 0;
}
