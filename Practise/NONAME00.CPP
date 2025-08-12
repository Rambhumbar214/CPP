#include<iostream.h>
#include<conio.h>
check_greter(int &a,int &b)
{
if(a>b)
{
cout << "\nThe a is greater than b";
}
else
{
cout << "\nThe b is greater than a";
}
return 0;
}
sum(int &a, int &b)
{
return a+b;
}
check_eo(int &c)
{
if(c%2==0)
{
cout << "\n The c is even";
}
else
{
cout << "\n The c is odd";
}
	  return 0;
}

int main()
{
int a,b,c;
clrscr();
cout << "Enter two numbers\n";
cin >>a >>b;
cout << "\nThe Number of A is"<<a;
cout << "\nThe Number of B is"<<b;
check_greter(a,b);
c=sum(a,b);
cout << "\nThe number of c is"<<c;
check_eo(c);
getch();
return 0;
}