#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
using namespace std;

int main() {
    int decimalNumber;
clrscr();
   
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    
    cout << "Hexadecimal equivalent: " << hex << uppercase << decimalNumber << endl;
getch();
    return 0;
}
