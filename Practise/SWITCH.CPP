#include<iostream.h>
#include<conio.h>
int main()
{
int a,b,c=0,choice;
clrscr();
cout<<"enter two number";
cin>>a>>b;
cout<<"enter your choice\n";
cout<<"1.Addition\n";
cout<<"2.Substraction\n";
cout<<"3.Multiplication\n";
cout<<"4.Division\n";
cout<<"5.Modules\n";
cin>>choice;

switch(choice)
{
case 1:
c=a+b;
cout<<"Addition of two num is:"<<c;
break;
case 2:
c=a-b;
cout<<"Subtraction of two num is:"<<c;
break;
case 3:
c=a*b;
cout<<"Multiplication of two num is:"<<c;
break;
case 4:
c=a/b;
cout<<"Division of two num is:"<<c;
break;
case 5:
c=a%b;
cout<<"Modulas of two num is:"<<c;
break;
default:
cout<<"invalid";
break;
}
getch();
return 0;
}