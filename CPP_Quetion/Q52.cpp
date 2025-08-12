/*.Write a C++ program to calculate following series: 
(1) + (1+2) + (1+2+3) + (1+2+3+4) + ... +(1+2+3+4+...+n)*/
#include <iostream>
using namespace std;

int calculateSeries(int n) {
    int sum = 0, totalSum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
        totalSum += sum;
    }
    return totalSum;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    int result = calculateSeries(n);
    cout << "The sum of the series is: " << result << endl;
    
    return 0;
}
