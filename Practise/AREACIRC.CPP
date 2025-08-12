#include<iostream.h>
#include<conio.h>
	void circle()
	{
		float a,r;
		cout<<"enter radius of circle:"<<endl;
		cin>>r;
		a=3.14*r*r;
		cout<<"area of circle is:"<<a<<endl;
	}

	void circle1(float r)
	{
		float a;
		a=3.14*r*r;
		cout<<"area of circle is:"<<a<<endl;
	}

	int circle3()
	{
		int a,r;
		cout<<"enter radius of circle:"<<endl;
		cin>>r;
		a=3.14*r*r;
	      return a;
	}

	int circle4(float r)
	{
	float a;
	return a=3.14*r*r ;

	}
int main()
{

	float r,a;

	clrscr();

	circle();

	cout<<"enter radius of circle:"<<endl;
	cin>>r;
	circle1(r);

	circle3();
	cout<<"area of circle is:"<<a<<endl;

	cout<<"enter radius of circle:"<<endl;
	cin>>r;
	circle4(r);
	cout<<"area of circle is:"<<a<<endl;


getch();
return 0;
}