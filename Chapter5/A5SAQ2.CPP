#include<iostream.h>
#include<conio.h>
class B;
class A{
	int x;
	public:

	void getdata()
	{
	cout<<"Enter an Integer:"<<endl;
	cin>>x;
	}
	friend int sub(A a,B b);
	};

class B{
	int y;
	public:

	void getdata()
	{
	cout<<"Enter an Integer:"<<endl;
	cin>>y;
	}
	friend int sub(A a,B b);
};

int sub(A a1,B b1)
{
  int ans;
  ans=(a1.x-b1.y);
  cout<<"substraction of two integer is:"<<ans;
// return(a1.x - b1.y);

}
void main()
{
clrscr();
A a1;
a1.getdata();
B b1;
b1.getdata();
sub(a1,b1);
getch();
}