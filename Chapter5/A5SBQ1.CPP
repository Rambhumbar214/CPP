#include<iostream.h>
#include<conio.h>
class r2;
class r1{
	float l,b,a1;
	public:

	void getdata(){
	cout<<"Enter length and Breadth of Rectangle:"<<endl;
	cin>>l>>b;
	}
	void putdata()
	{
	a1=l*b;
	cout<<"Area of Rectangle is:"<<a1<<endl;
	}
	friend int compare(r1 a,r2 a2);
};
class r2{
	float l,b,a2;
	public:

	void getdata(){
	cout<<"Enter length and Breadth of Rectangle:"<<endl;
	cin>>l>>b;
	}
	void putdata()
	{
	a2=l*b;
	cout<<"Area of Rectangle is:"<<a2<<endl;
	}
	friend int compare(r1 a1,r2 a2);
};
int compare(r1 ra1,r2 ra2)
{
int g=ra1.a1;
int h=ra2.a2;
if(g>h)
{
cout<<"Area of Rectangle1 is Greter Than Rectangle2";
}
else
{
cout<<"Area of Rectangle2 is Greter Than Rectangle1";
}
}

int main()
{
clrscr();
r1 ra1;
r2 ra2;
ra1.getdata();
ra1.putdata();
ra2.getdata();
ra2.putdata();
compare(ra1,ra2);
getch();
return 0;
}
