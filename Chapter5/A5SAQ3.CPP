#include<iostream.h>
#include<conio.h>
class shape{
 float a,r,h;

 public:

 void calculate(int a)
 {
 cout<<"volume of cube is"<<a*a*a<<endl;
 }
 void calculate(float r,float h)
 {
 cout<<"volume of cylinder is"<<3.14*r*r*h<<endl;
 }
 void calculate(float r)
 {
 cout<<"volume of sphere is"<<1.33*3.14*r*r*r<<endl;
 }

};

int main()
{
int e;
clrscr();
cout<<"enter r"<<endl;
cin>>e;
shape cube,cylinder,sphere;
cube.calculate(6);
cylinder.calculate(9.4,18.7);
sphere.calculate(e);
getch();
return 0;
}