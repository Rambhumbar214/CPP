#include <iostream.h>
#include <conio.h>

int main() {
    int num;
    clrscr();

    cout << "Enter a number: ";
    cin >> num;

    cout << "Factors of " << num << " are: ";


    for (int i = 1; i <= num; i++) {
	if (num % i == 0) {
	    cout << i << " ";
	}
    }

    cout << endl;
    getch();
    return 0;
}
