/*. Write a C++ program to display factors of a number. */

#include <iostream>
using namespace std;

void displayFactors(int num) {
    cout << "Factors of " << num << " are: ";
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    
    displayFactors(number);
    
    return 0;
}