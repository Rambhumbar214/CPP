#include <iostream.h>
#include <conio.h>

int main() {
    int n;
  clrscr();
    cout << "Enter the value of n: ";
    cin >> n;

    int totalSum = 0;

    // Loop to calculate the sum for each (1+2+...+i) and accumulate it
    for (int i = 1; i <= n; ++i) {
        totalSum += (i * (i + 1)) / 2; // Sum of first i natural numbers
    }

    cout << "The total sum of the series is: " << totalSum << endl;
  getch(); 
  return 0;
}
