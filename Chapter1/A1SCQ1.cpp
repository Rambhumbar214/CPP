#include <iostream.h>
#include <conio.h>

int main() {
    int n;
  int num = 1;
  clrscr();
 
    cout << "Enter the number of rows for the pyramid: ";
    cin >> n;

  

 
    for (int i = 1; i <= n; ++i) {
        
        for (int j = 1; j <= n - i; ++j) {
            cout << " ";
        }

       
        for (int k = 1; k <= i; ++k) {
            cout << num << " ";
            num++;  
        }

      
        cout << endl;
    }
getch();
    return 0;
}
