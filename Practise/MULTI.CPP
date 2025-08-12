#include <iostream.h>
#include <conio.h>
int main() {
    int num,i;
    clrscr();

    cout<<"Enter the number for the multiplication table: ";
    cin>>num;

    for (i = 1; i <= 10; i++) {
	cout<< num <<"*"<<i <<"="<< num * i;
	cout<<"\n" ;
    }
    getch();
    return 0;
}
