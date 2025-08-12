#include<iostream.h>
#include<conio.h>
class Number{
	int no,i,sum;
	public:
	Number(int n)
	{
	no=n;

	}
	void putdata()
	{
	sum=0;
	for(i=1; i<=no; i++)
	{
	sum+=i;
	}
	cout<<"sum of numbers between 1 to n:"<<sum<<endl;
	}


};
void main()
{
int no;
clrscr();
cout<<"enter a number :"<<endl;
cin>>no;
Number n1(no);
n1.putdata();
getch();
}