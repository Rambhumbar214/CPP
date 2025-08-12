#include<iostream.h>
#include<conio.h>

int main() {
    int number;
   int factorial = 1;
    clrscr();
    cout << "Enter a positive integer: ";
    cin >> number;

    if (number < 0) {
	cout << "Factorial of a negative number doesn't exist.";
    } else {
	for (int i = 1; i <= number; ++i) {
	    factorial *= i;
	}
	cout << "Factorial of " << number << " = " << factorial;
    }
		      getch();
    return 0;
}


