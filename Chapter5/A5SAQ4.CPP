#include <iostream.h>
#include <conio.h>
#include <iomanip.h>

calculate(float p, float n = 10, float r = 7) {
      float pr = p;
	float  y = n;
      float ra = r;
      float  si= (pr * y * ra) / 100;
      cout<<"Simple interest is:"<<setprecision(2)<<si<<endl;
    }

int main() {

    float pri;
    clrscr();
    cout << "Enter the principal amount: ";
    cin >> pri;
    calculate(pri);


    getch();
    return 0;
}
