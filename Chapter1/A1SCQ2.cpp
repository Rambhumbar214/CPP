#include <iostream>
using namespace std;

int main() {
    int n;
    
   
    cout << "Enter a number: ";
    cin >> n;

    bool found = false;

   
    for (int i = 2; i <= n / 2; ++i) {
        bool isPrimeI = true;
        bool isPrimeNMinusI = true;

       
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                isPrimeI = false;
                break;
            }
        }

     
        for (int k = 2; k * k <= (n - i); ++k) {
            if ((n - i) % k == 0) {
                isPrimeNMinusI = false;
                break;
            }
        }

        
        if (isPrimeI && isPrimeNMinusI) {
            cout << n << " can be expressed as the sum of " << i << " and " << (n - i) << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << n << " cannot be expressed as the sum of two prime numbers." << endl;
    }

    return 0;
}
