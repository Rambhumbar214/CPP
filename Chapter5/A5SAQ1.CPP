#include<iostream.h>
#include<conio.h>

inline float ac(float r)
{
return 3.14*r*r;
}

inline float ar(float l, float b)
{
return l*b;
}

inline float as(float s)
{
return s*s;
}

int main()
{
float r,l,b,s;
clrscr();
cout<<"Enter Radius of Circle:"<<endl;
cin>>r;
cout<<"Area of Circle:"<<ac(r);
cout<<endl;

cout<<"Enter length and Breadth of Rectangle:"<<endl;
cin>>l>>b;
cout<<"Area of Rectangle:"<<ar(l,b);
cout<<endl;

cout<<"Enter Side of Squre:"<<endl;
cin>>s;
cout<<"Area of Squre:"<<as(s);
cout<<endl;

getch();
return 0;
}