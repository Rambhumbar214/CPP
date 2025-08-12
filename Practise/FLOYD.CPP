#include <iostream.h>
#include <conio.h>


int main() {
    int rows, num = 1;
    clrscr();

    cout << "Enter the number of rows for Floyd's Triangle: ";
    cin >> rows;

    cout << "Floyd's Triangle:" << endl;

    for (int i = 1; i <= rows; i++) {
	for (int j = 1; j <= i; j++) {
	    cout << num ;
	    num++;
	}
     cout <<"\n";
    }
    getch();
    return 0;
}
