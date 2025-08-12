
#include<iostream.h>
#include<conio.h>
class date
{
int dd,mm,yyyy;
public:

date(int d,int m, int y)
{
	dd=d;
	mm=m;
	yyyy=y;
}
void disp()
{
	if(mm>12)
	{
	cout<<"Invalid month"<<endl;
	}
	else
	{
	cout<<"input:"<<dd<<"/"<<mm<<"/"<<yyyy<<endl;
	if(mm==1)
	{
	  cout<<"Output:"<<dd<<"/"<<"jan"<<"/"<<yyyy;
	}
	 else if(mm==2)
	{
	 cout<<"Output:"<<dd<<"/"<<"feb"<<"/"<<yyyy;
	}
	else if(mm==3)
	{
	cout<<"Output:"<<dd<<"/"<<"march"<<"/"<<yyyy;
	 }
	 else if(mm==4)
	{
	 cout<<"Output:"<<dd<<"/"<<"april"<<"/"<<yyyy;
	}
	 else if(mm==5)
	{
	cout<<"Output:"<<dd<<"/"<<"may"<<"/"<<yyyy;
	}
	else if(mm==6)
	{
	cout<<"Output:"<<dd<<"/"<<"june"<<"/"<<yyyy;
	 }
	else if(mm==7)
	 {
	cout<<"Output:"<<dd<<"/"<<"july"<<"/"<<yyyy;
	}
	else if(mm==8)
	{
	cout<<"Output:"<<dd<<"/"<<"aug"<<"/"<<yyyy;
	}
	else if(mm==9)
	{
	cout<<"Output:"<<dd<<"/"<<"sep"<<"/"<<yyyy;
	 }
	 else if(mm==10)
	{
	cout<<"Output:"<<dd<<"/"<<"oct"<<"/"<<yyyy;
	}
	else if(mm==11)
	{
	cout<<"Output:"<<dd<<"/"<<"nov"<<"/"<<yyyy;
	}
	else if(mm==12)
	 {
	cout<<"Output:"<<dd<<"/"<<"dec"<<"/"<<yyyy;
	}
	}
	}

};
void main()
{
int d,m,y;
clrscr();
cout<<"enter a date";
cin>>d;
cout<<"enter a month";
cin>>m;
cout<<"enter a year";
cin>>y;
date d1(d,m,y);
d1.disp();
getch();
 }
