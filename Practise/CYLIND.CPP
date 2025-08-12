#include<iostream.h>
#include<conio.h>
class cylinder{

	float radius,height;
	float area,volume;
	public:
	void getdata();
	void putdata();

	};


void cylinder::getdata()
	{
	cout<<"enter radius of cylinder";
	cin>>radius;
	cout<<"enter height of cylinder";
	cin>>height;
	}


void cylinder::putdata()
	{
	volume=3.14*radius*radius*height;
	area=3.14*radius*radius+height;
	cout<<"area of cylinder"<<area;
	cout<<"volume of cylinder"<<volume;
	}
int main()
{
cylinder c1;
c1.getdata();
c1.putdata();
getch();
return 0;
}
