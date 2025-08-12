#include <iostream.h>
#include <iomanip.h>
#include <conio.h>

int main() {
    int decimal;
      clrscr();

    cout << "Enter a decimal number: ";
    cin >> decimal;


    cout << "Hexadecimal equivalent: " << hex << decimal << endl;
	getch();
    return 0;
}
