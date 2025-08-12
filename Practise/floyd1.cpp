#include <iostream.h>
#include<conio.h>

int main() {
    int rows, number = 1;
clrscr();
   
    cout << "Enter the number of rows for the Floyd Triangle: ";
    cin >> rows;

    cout << "Floyd Triangle:\n";
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << number << " ";
            number++;
        }
        cout << endl; 
    }
getch();
    return 0;
}
