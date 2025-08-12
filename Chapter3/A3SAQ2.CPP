#include <iostream.h>
#include <conio.h>

class SI {

    float pri;
    float time;
    float rate;

public:

    SI(float p, float t, float r = 5.0) {
	pri = p;
	time = t;
	rate = r;
    }


    float CI() {
	return (pri * time * rate) / 100;
    }
};

int main() {
    float pri, time, rate;
    clrscr();

    cout << "Enter principal amount: ";
    cin >> pri;
    cout << "Enter time: ";
    cin >> time;


    cout << "Enter rate of interest: ";
    cin >> rate;


    SI si1(pri, time, rate);


    float interest = si1.CI();
    cout << "The Simple Interest is: " << interest << endl;
	  getch();
    return 0;
}
