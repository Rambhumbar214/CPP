#include <iostream.h>
#include<conio.h>

int main() {
    int num, limit;
clrscr();

    cout << "Enter the number for the multiplication table: ";
    cin >> num;
    cout << "Enter the limit for the table: ";
    cin >> limit;

    cout << "\nMultiplication Table of " << num << " up to " << limit << ":\n";
    for (int i = 1; i <= limit; i++) {
        cout << num << " x " << i << " = " << num * i << endl;
    }
getch();
    return 0;

}
