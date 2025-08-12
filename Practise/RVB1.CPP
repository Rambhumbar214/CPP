#include<iostream.h>
#include<conio.h>

check_greter(int &a,int &b)
  {
	if(a>b)
	{
	cout << "\nThe a is greater than b";
	}
      else if(b>a)
	{
	cout << "\nThe b is greater than a";
	}
	else
	{
	cout << "\nThe a and b are equal";
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
	cout << "\n The c is even ";
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
	cout <<"\n";

	c=sum(a,b);
	cout << "\n";

	cout << "\nThe addition of a and b is stored in c";
	cout << "\nThe number of c is"<<c;
	cout <<"\n";

	check_eo(c);

getch();
return 0;
}