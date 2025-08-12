
#include<iostream.h>
#include<conio.h>
class cylinder
{
float radius;
float height,area,volume;
public:
void getdata()
{
cout<<"enter radius";
  cin>>radius;
cout<<"enter height";
  cin>>height;
}
void putdata()
{
  volume=3.14*radius*radius*height;
  cout<<"volume of cylinder"<<volume;
  area=2*3.14*radius*radius;
  cout<<"area of cylinder"<<area;
}
};
void main()
{
clrscr();
  cylinder c1;
  c1.getdata();
  c1.putdata();
  getch();
  return 0;
}
