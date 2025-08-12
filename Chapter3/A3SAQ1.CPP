#include<iostream.h>
#include<conio.h>
class Number{
       int x,y;
       public:
       Number()
       {
	 x=20;
	 y=30;
       }
       Number(int a,int b)
       {
       x=a;
       y=b;
	}
       void findmax()
       {
       if(x>y)
       cout<<"x is maximum";
       else
       cout<<"y is maximum";
       }
};
void main()
{
int a,b;
clrscr();
cout<<"enter a number:";
cin>>a;
cout<<"enter b number:";
cin>>b;
Number n1;
Number n2(10,20);
Number n3(a,b);
n1.findmax();
n2.findmax();
n3.findmax();
getch();
}