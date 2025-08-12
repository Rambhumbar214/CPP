
#include <iostream.h>
#include <conio.h>

int main() {
    int num, originalNum, reversedNum = 0, remainder;
    clrscr();
    
    cout << "Enter a number: ";
    cin >> num;

    originalNum = num; 

    
    while (num != 0) {
        remainder = num % 10;           
        reversedNum = reversedNum * 10 + remainder; 
        num /= 10;                      
    }

    
    if (originalNum == reversedNum) {
        cout << originalNum << " is a palindrome." << endl;
    } else {
        cout << originalNum << " is not a palindrome." << endl;
    }
    getch();
    return 0;
}
